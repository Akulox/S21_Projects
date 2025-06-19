#include "test.h"

// Тест: для обычной строки с различными символами
START_TEST(test_symbols) {
  const char *str = "Hello, World!&^!4";

  s21_size_t result_std = strlen(str);
  s21_size_t result_s21 = s21_strlen(str);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: поведение функции на пустой строке
START_TEST(test_empty) {
  const char *str = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

// Тест: как функции справляются с очень длинной строкой
START_TEST(test_length) {
  static char str[1000001];
  for (int i = 0; i < 1000000; i++) {
    str[i] = 's';
  }
  str[1000000] = '\0';

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *tests_strlen(void) {
  Suite *s = suite_create("tests_strlen");
  TCase *tc_strlen = tcase_create("tc_strlen");

  tcase_add_test(tc_strlen, test_symbols);
  tcase_add_test(tc_strlen, test_empty);
  tcase_add_test(tc_strlen, test_length);

  suite_add_tcase(s, tc_strlen);
  return s;
}
