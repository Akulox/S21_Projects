#include "test.h"

#define LONG_STR 1000

START_TEST(test_s21_to_lower_0) {
  const char* str = S21_NULL;
  char* result = s21_to_lower(str);
  const char* expected = S21_NULL;
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_1) {
  const char* str = STR_EMPTY;
  char* result = s21_to_lower(str);
  const char* expected = STR_EMPTY;
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  const char* str = " ";
  char* result = s21_to_lower(str);
  const char* expected = str;
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  const char* str = "QWERTY";
  char* result = s21_to_lower(str);
  const char* expected = "qwerty";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  const char* str = "aZxYrEEyygWvv";
  char* result = s21_to_lower(str);
  const char* expected = "azxyreeyygwvv";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  const char* str = "HELLO, UPPER WORLD!";
  char* result = s21_to_lower(str);
  const char* expected = "hello, upper world!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_6) {
  const char* str =
      "!, \", #, $, %, &, ', (, ), *, +, -, ., /, "
      ":, ;, <, =, >, ?, @, "
      "[, \\ , ], ^, _, `, {, |, }, ~";
  char* result = s21_to_lower(str);
  const char* expected =
      "!, \", #, $, %, &, ', (, ), *, +, -, ., /, "
      ":, ;, <, =, >, ?, @, "
      "[, \\ , ], ^, _, `, {, |, }, ~";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_7) {
  const char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* result = s21_to_lower(str);
  const char* expected = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_8) {
  const char* str = "hello, upper world!";
  char* result = s21_to_lower(str);
  const char* expected = "hello, upper world!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_9) {
  unsigned int ind_start = 'A';
  unsigned int ind_max = ind_start + 26;
  unsigned int code = 'a';
  for (size_t i = ind_start, j = code; i < ind_max; i++, j++) {
    char str[LONG_STR + 1];
    memset(str, i, LONG_STR);
    str[LONG_STR] = '\0';
    char expected[LONG_STR + 1];
    memset(expected, j, LONG_STR);
    expected[LONG_STR] = '\0';
    char* result = s21_to_lower(str);
    ck_assert_str_eq(result, expected);

    free(result);
  }
}
END_TEST

Suite* tests_to_lower(void) {
  Suite* s;
  TCase* tc_to_lower;
  s = suite_create("to_lower_tests");
  tc_to_lower = tcase_create("to_lower_tc");
  tcase_add_test(tc_to_lower, test_s21_to_lower_0);
  tcase_add_test(tc_to_lower, test_s21_to_lower_1);
  tcase_add_test(tc_to_lower, test_s21_to_lower_2);
  tcase_add_test(tc_to_lower, test_s21_to_lower_3);
  tcase_add_test(tc_to_lower, test_s21_to_lower_4);
  tcase_add_test(tc_to_lower, test_s21_to_lower_5);
  tcase_add_test(tc_to_lower, test_s21_to_lower_6);
  tcase_add_test(tc_to_lower, test_s21_to_lower_7);
  tcase_add_test(tc_to_lower, test_s21_to_lower_8);
  tcase_add_test(tc_to_lower, test_s21_to_lower_9);
  suite_add_tcase(s, tc_to_lower);

  return s;
}
