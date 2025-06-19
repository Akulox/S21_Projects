#!/bin/bash

rm -f temp_*
rm -rf test_output
mkdir -p test_output/passed test_output/failed

temp_original_grep=$(mktemp)
temp_custom_grep=$(mktemp)

command_file="AI_generated_testcases/commands_for_grep_test.txt"

grep_passed=0
grep_failed=0

test_grep() {
    local com="$1"
    local command="grep $com"
    local output_file="$(echo $command | tr ' ' '_' | tr '/' '_').txt"

    echo "TESTING $command" >> "$output_file"
    echo "<=======original========>" >> "$output_file"
    grep $com | tee "$temp_original_grep" >> "$output_file"
    echo "<=======s21_grep=========>" >> "$output_file"
    ./s21_grep $com | tee "$temp_custom_grep" >> "$output_file"
    echo "<=======================>" >> "$output_file"
    find_diff_grep "$command" "$temp_original_grep" "$temp_custom_grep" "$output_file"
}

find_diff_grep() {
    local command="$1"
    local original="$2"
    local custom="$3"
    local output_file="$4"
    if diff -q "$original" "$custom" > /dev/null; then
        echo -e "\e[32m<PASSED>\e[0m $command"
        ((grep_passed++))
        mv "$output_file" "test_output/passed/"
    else
        echo -e "\e[31m<FAILED>\e[0m $command"
        ((grep_failed++))
        mv "$output_file" "test_output/failed/"
    fi
}

echo
echo "Testing grep..."
while IFS= read -r line; do
    test_grep "$line"
done < "$command_file"

echo
echo "=========================="
echo "CAT TEST RESULTS:"
echo "Passed: $grep_passed"
echo "Failed: $grep_failed"
echo
echo "ALL TEST RESULTS SAVED AT:"
echo "  test_output"
echo "=========================="


rm -f temp_*
