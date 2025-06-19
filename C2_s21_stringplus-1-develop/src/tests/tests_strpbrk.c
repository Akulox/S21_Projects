#include "test.h"

START_TEST(test_standard) {
  const char *str1 = "qwertyuiop poiuytrewq";
  const char *str2 = "ie";
  char *result_std = strpbrk(str1, str2);
  char *result_s21 = s21_strpbrk(str1, str2);

  ck_assert_str_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_strtoint) {
  const char *str1 = "qwertyuiop poiuytrewq";
  const char *str2 = "4";
  char *result_std = strpbrk(str1, str2);
  char *result_s21 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_emptytofull) {
  const char *str1 = "";
  const char *str2 = "qho";
  char *result_std = strpbrk(str1, str2);
  char *result_s21 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_emptytoempty) {
  const char *str1 = "";
  const char *str2 = "";
  char *result_std = strpbrk(str1, str2);
  char *result_s21 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_emptytostr) {
  const char *str1 = "";
  const char *str2 = "fdgd";
  char *result_std = strpbrk(str1, str2);
  char *result_s21 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_inttoint) {
  const char *str1 = "1234567890987654321";
  const char *str2 = "90";
  char *result_std = strpbrk(str1, str2);
  char *result_s21 = s21_strpbrk(str1, str2);

  ck_assert_str_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_ssym) {
  const char *str1 = "123456789+-&0987654321";
  const char *str2 = "-90";
  char *result_std = strpbrk(str1, str2);
  char *result_s21 = s21_strpbrk(str1, str2);

  ck_assert_str_eq(result_s21, result_std);
}
END_TEST

Suite *tests_strpbrk(void) {
  Suite *s = suite_create("tests_strpbrk");
  TCase *tc_strpbrk = tcase_create("tc_strpbrk");

  tcase_add_test(tc_strpbrk, test_standard);
  tcase_add_test(tc_strpbrk, test_strtoint);
  tcase_add_test(tc_strpbrk, test_emptytofull);
  tcase_add_test(tc_strpbrk, test_emptytoempty);
  tcase_add_test(tc_strpbrk, test_emptytostr);
  tcase_add_test(tc_strpbrk, test_inttoint);
  tcase_add_test(tc_strpbrk, test_ssym);

  suite_add_tcase(s, tc_strpbrk);
  return s;
}
