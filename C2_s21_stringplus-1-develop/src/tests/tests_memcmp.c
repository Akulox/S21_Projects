#include "test.h"

START_TEST(test_standard) {
  const char *str1 = "Takoi Bred";
  const char *str2 = "Takoi Bred";
  size_t n = 8;

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: строки одинаковые, но поиск до конца
START_TEST(test_equal_strings) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World!";
  size_t n = strlen(str1);

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: строки разные, сравнение первых символов
START_TEST(test_different_first_char) {
  const char *str1 = "Hello World!";
  const char *str2 = "Jello World!";
  size_t n = 8;

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: строки разные, символы после первого различия
START_TEST(test_different_after_first) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello W0rld!";
  size_t n = strlen(str1);

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: строки одинаковые, но разная длина
START_TEST(test_different_lengths) {
  const char *str1 = "Hello";
  const char *str2 = "Hello, World!";
  size_t n = strlen(str1);

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: первая строка короче второй
START_TEST(test_first_shorter) {
  const char *str1 = "Hello";
  const char *str2 = "Hello, World!";
  size_t n = strlen(str2);

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: первая строка длиннее второй
START_TEST(test_first_longer) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello";
  size_t n = strlen(str1);

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: одинаковые строки, но сравниваем только часть
START_TEST(test_partial_comparison) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World!";
  size_t n = 5;  // Сравниваем только первые 5 символов

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: символы в строках разные в самом конце
START_TEST(test_diff_at_end) {
  const char *str1 = "Hello World!";
  const char *str2 = "Hello World?";
  size_t n = strlen(str1);

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: пустые строки
START_TEST(test_empty_strings) {
  const char *str1 = "";
  const char *str2 = "";
  size_t n = 0;

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: строка с нулевым символом
START_TEST(test_null_char) {
  const char *str1 = "Hello\0World";
  const char *str2 = "Hello World";
  size_t n = strlen(str1);

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест: строка содержит только нулевые байты
START_TEST(test_zero_bytes) {
  const char *str1 = "\0\0\0";
  const char *str2 = "\0\0\0";
  size_t n = 3;

  int result_std = memcmp(str1, str2, n);
  int result_s21 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

Suite *tests_memcmp(void) {
  Suite *s = suite_create("s21_memcmp_tests");
  TCase *tc_memcmp = tcase_create("tc_memcmp");

  tcase_add_test(tc_memcmp, test_standard);
  tcase_add_test(tc_memcmp, test_equal_strings);
  tcase_add_test(tc_memcmp, test_different_first_char);
  tcase_add_test(tc_memcmp, test_different_after_first);
  tcase_add_test(tc_memcmp, test_different_lengths);
  tcase_add_test(tc_memcmp, test_first_shorter);
  tcase_add_test(tc_memcmp, test_first_longer);
  tcase_add_test(tc_memcmp, test_partial_comparison);
  tcase_add_test(tc_memcmp, test_diff_at_end);
  tcase_add_test(tc_memcmp, test_empty_strings);
  tcase_add_test(tc_memcmp, test_null_char);
  tcase_add_test(tc_memcmp, test_zero_bytes);

  suite_add_tcase(s, tc_memcmp);

  return s;
}
