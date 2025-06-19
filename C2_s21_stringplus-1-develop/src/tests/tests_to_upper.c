#include "test.h"

#define LONG_STR 1000

START_TEST(test_s21_to_upper_0) {
  const char *str = S21_NULL;
  char *result = s21_to_upper(str);
  const char *expected = S21_NULL;
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_1) {
  const char *str = STR_EMPTY;
  char *result = s21_to_upper(str);
  char *expected = STR_EMPTY;
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  const char *str = " ";
  char *result = s21_to_upper(str);
  const char *expected = str;
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  const char *str = "qwerty";
  char *result = s21_to_upper(str);
  const char *expected = "QWERTY";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  const char *str = "aZxYrEEyygWvv";
  char *result = s21_to_upper(str);
  const char *expected = "AZXYREEYYGWVV";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_5) {
  const char *str = "hello, upper world!";
  char *result = s21_to_upper(str);
  const char *expected = "HELLO, UPPER WORLD!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_upper_6) {
  const char *str =
      "!, \", #, $, %, &, ', (, ), *, +, -, ., /, "
      ":, ;, <, =, >, ?, @, "
      "[, \\ , ], ^, _, `, {, |, }, ~";
  char *result = s21_to_upper(str);
  const char *expected =
      "!, \", #, $, %, &, ', (, ), *, +, -, ., /, "
      ":, ;, <, =, >, ?, @, "
      "[, \\ , ], ^, _, `, {, |, }, ~";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST;

START_TEST(test_s21_to_upper_7) {
  const char *str = "abcdefghijklmnopqrstuvwxyz";
  char *result = s21_to_upper(str);
  const char *expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST;

START_TEST(test_s21_to_upper_8) {
  const char *str = "HELLO WORLD!";
  char *result = s21_to_upper(str);
  const char *expected = "HELLO WORLD!";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST;

START_TEST(test_s21_to_upper_9) {
  unsigned int ind_start = 'a';
  unsigned int ind_max = ind_start + 26;
  unsigned int code = 'A';
  for (size_t i = ind_start, j = code; i < ind_max; i++, j++) {
    char str[LONG_STR + 1];
    memset(str, i, LONG_STR);
    str[LONG_STR] = '\0';
    char expected[LONG_STR + 1];
    memset(expected, j, LONG_STR);
    expected[LONG_STR] = '\0';
    char *result = s21_to_upper(str);
    ck_assert_str_eq(result, expected);

    free(result);
  }
}
END_TEST;

Suite *tests_to_upper(void) {
  Suite *s;
  TCase *tc_to_upper;
  s = suite_create("to_upper_tests");
  tc_to_upper = tcase_create("to_upper_tc");
  tcase_add_test(tc_to_upper, test_s21_to_upper_0);
  tcase_add_test(tc_to_upper, test_s21_to_upper_1);
  tcase_add_test(tc_to_upper, test_s21_to_upper_2);
  tcase_add_test(tc_to_upper, test_s21_to_upper_3);
  tcase_add_test(tc_to_upper, test_s21_to_upper_4);
  tcase_add_test(tc_to_upper, test_s21_to_upper_5);
  tcase_add_test(tc_to_upper, test_s21_to_upper_6);
  tcase_add_test(tc_to_upper, test_s21_to_upper_7);
  tcase_add_test(tc_to_upper, test_s21_to_upper_8);
  tcase_add_test(tc_to_upper, test_s21_to_upper_9);
  suite_add_tcase(s, tc_to_upper);

  return s;
}
