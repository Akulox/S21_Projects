#!/bin/bash

rm -f temp_*
rm -rf test_output
mkdir -p test_output/passed test_output/failed

temp_custom_grep=$(mktemp)


grep_flags=("-i" "-v" "-c" "-l" "-n" "-h" "-s" "-o")
pattern_file_flags=("-f PRO_testcases/example_pattern.txt")

grep_passed=0
grep_failed=0

test_grep() {
    local pattern="$1"
    local file="$2"
    local flags="$3"
    local command="grep $flags $pattern $file"
    local output_file="$(echo $command | tr ' ' '_' | tr '/' '_').txt"

    echo "TESTING $command" >> "$output_file"
    echo "<=======s21_grep========>" >> "$output_file"
    valgrind --tool=memcheck --leak-check=yes ./s21_grep $flags $pattern $file 2>&1 | tee "$temp_custom_grep" >> "$output_file"
    echo "<=======================>" >> "$output_file"
    find_mem_error "$command" "$temp_custom_grep" "$output_file"
}

find_mem_error() {
    local command="$1"
    local custom="$2"
    local output_file="$3"

    if grep -Eq "ERROR SUMMARY: [1-9]" "$custom"; then
        echo -e "\e[31m<FAILED>\e[0m $command"
        ((grep_failed++))
        mv "$output_file" "test_output/failed/"
    else
        echo -e "\e[32m<PASSED>\e[0m $command"
        ((grep_passed++))
        mv "$output_file" "test_output/passed/"
    fi
}

# Генерация всех комбинаций флагов для grep
echo
echo "Testing grep..."
    for file in "PRO_testcases/example_input.txt" "PRO_testcases/example_input2.txt PRO_testcases/example_input.txt"; do
        for ((i = 0; i < (1 << ${#grep_flags[@]}); i++)); do
            flag_combination=""
            for ((j = 0; j < ${#grep_flags[@]}; j++)); do
                if ((i & (1 << j))); then
                    flag_combination="$flag_combination ${grep_flags[j]}"
                fi
            done
            for pattern_file_flag in "${pattern_file_flags[@]}"; do
                test_grep "$pattern" "$file" "$flag_combination $pattern_file_flag"
            done
        done
    done

echo
echo "=========================="
echo "GREP TEST RESULTS:"
echo "Passed: $grep_passed"
echo "Failed: $grep_failed"
echo "=========================="

rm -f temp_*
