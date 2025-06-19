#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <float.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/s21_sprintf.h"
#include "../headers/s21_sscanf.h"
#include "../headers/s21_strerror.h"
#include "../headers/s21_wchar.h"
#include "../s21_string.h"

// initial
Suite *tests_memchr();
Suite *tests_memcmp();
Suite *tests_memcpy();
Suite *tests_memset();
Suite *tests_strncat();
Suite *tests_strchr();
Suite *tests_strncmp();
Suite *tests_strncpy();
Suite *tests_strcspn();
Suite *tests_strerror();
Suite *tests_strlen();
Suite *tests_strpbrk();
Suite *tests_strrchr();
Suite *tests_strstr();
Suite *tests_strtok();

Suite *tests_sscanf();
Suite *tests_sprintf();

// additional
Suite *tests_to_upper();
Suite *tests_to_lower();
Suite *tests_insert();
Suite *tests_trim();

// other
Suite *tests_wchar_wcstombs();

#endif
