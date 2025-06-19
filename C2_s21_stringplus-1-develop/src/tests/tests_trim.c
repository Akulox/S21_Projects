#include "test.h"

START_TEST(test_s21_trim_0) {
  const char *str = S21_NULL;
  const char *str_trim = " ";
  char *result = s21_trim(str, str_trim);
  const char *expected = S21_NULL;
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_1) {
  const char *str = STR_EMPTY;
  const char *str_trim = STR_EMPTY;
  char *result = s21_trim(str, str_trim);
  const char *expected = STR_EMPTY;
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_2) {
  const char *str = "!!!AbCdEfGhIjKlMnOpQrStUvWxYz!!!";
  const char *str_trim = "!";
  char *result = s21_trim(str, str_trim);
  const char *expected = "AbCdEfGhIjKlMnOpQrStUvWxYz";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_3) {
  const char *str = "!@!@!#AbCdEfGhIjKlMnOpQrStUvWxYz!#!@!@";
  const char *str_trim = "!@";
  char *result = s21_trim(str, str_trim);
  const char *expected = "#AbCdEfGhIjKlMnOpQrStUvWxYz!#";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *tests_trim(void) {
  Suite *s;
  TCase *tc_trim;
  s = suite_create("trim_tests");
  tc_trim = tcase_create("trim_tc");
  tcase_add_test(tc_trim, test_s21_trim_0);
  tcase_add_test(tc_trim, test_s21_trim_1);
  tcase_add_test(tc_trim, test_s21_trim_2);
  tcase_add_test(tc_trim, test_s21_trim_3);

  suite_add_tcase(s, tc_trim);

  return s;
}
