#!/bin/bash

make rebuild

rm -f temp_*
rm -rf test_output
mkdir -p test_output/passed test_output/failed

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
    local output_file="test_output/$(echo $command | tr ' ' '_' | tr '/' '_').txt"

    echo "TESTING $command" >> "$output_file"
    echo "<=======s21_cat=========>" >> "$output_file"
    valgrind --tool=memcheck --leak-check=yes ./s21_cat $flags $file 2>&1 | tee "$temp_custom_cat" >> "$output_file"
    echo "<=======================>" >> "$output_file"
    find_mem_error "$command" "$temp_custom_cat" "$output_file"
}

find_mem_error() {
    local command="$1"
    local custom="$2"
    local output_file="$3"
    if grep -Eq "ERROR SUMMARY: [1-9]" "$custom"; then
        echo -e "\e[31m<FAILED>\e[0m $command"
        ((cat_failed++))
        mv "$output_file" "test_output/failed/"
    else
        echo -e "\e[32m<PASSED>\e[0m $command"
        ((cat_passed++))
        mv "$output_file" "test_output/passed/"
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
