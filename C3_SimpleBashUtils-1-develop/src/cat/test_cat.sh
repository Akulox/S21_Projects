#!/bin/bash

make rebuild

rm -f temp_*
rm -rf test_output
mkdir -p test_output/passed test_output/failed

temp_original_cat=$(mktemp)
temp_custom_cat=$(mktemp)

directory="files_for_cat_test"
flag_file="flags_for_cat_test.txt"

cat_passed=0
cat_failed=0

test_cat() {
    local file="$1"
    local flags="$2"
    local shorter_file="${file#*/}"
    local command="cat $flags $shorter_file"
    local output_file="test_output/$(echo $command | tr ' ' '_')"

    echo "TESTING $command" >> "$output_file"
    echo "<=======original========>" >> "$output_file"
    cat $flags $file | tee "$temp_original_cat" >> "$output_file"
    echo "<=======s21_cat=========>" >> "$output_file"
    ./s21_cat $flags $file | tee "$temp_custom_cat" >> "$output_file"
    echo "<=======================>" >> "$output_file"
    find_diff_cat "$command" "$temp_original_cat" "$temp_custom_cat" "$output_file"
}

find_diff_cat() {
    local command="$1"
    local original="$2"
    local custom="$3"
    local output_file="$4"
    if diff -q "$original" "$custom" > /dev/null; then
        echo -e "\e[32m<PASSED>\e[0m $command"
        ((cat_passed++))
        mv "$output_file" "test_output/passed/"
    else
        echo -e "\e[31m<FAILED>\e[0m $command"
        ((cat_failed++))
        mv "$output_file" "test_output/failed/"
    fi
}

echo
echo "Testing cat..."
for test_file in "$directory"/*; do
    while IFS= read -r line; do
        test_cat "$test_file" "$line"
    done < "$flag_file"
done

echo
echo "=========================="
echo "CAT TEST RESULTS:"
echo "Passed: $cat_passed"
echo "Failed: $cat_failed"
echo
echo "ALL TEST RESULTS SAVED AT:"
echo "  test_output"
echo "=========================="


rm -f temp_*
