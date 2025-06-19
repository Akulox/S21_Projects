#include "test.h"

START_TEST(test_standard) {
  const char str[] = "Broadcast!";
  int target = 'd';
  size_t n = strlen(str);

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск символа в начале строки
START_TEST(test_first_char) {
  const char str[] = "Hello";
  int target = 'H';
  size_t n = strlen(str);

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск символа в конце строки
START_TEST(test_last_char) {
  const char str[] = "Hello";
  int target = 'o';
  size_t n = strlen(str);

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: символ отсутствует в строке
START_TEST(test_not_found) {
  const char str[] = "Hello";
  int target = 'z';
  size_t n = strlen(str);

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: пустая строка
START_TEST(test_empty_string) {
  const char str[] = "";
  int target = 'a';
  size_t n = strlen(str);

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск нулевого символа
START_TEST(test_null_char) {
  const char str[] = "abc\0def";
  int target = '\0';
  size_t n = 7;  // Включаем в поиск нулевой символ

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск после нулевого символа
START_TEST(test_after_null_char) {
  const char str[] = "abc\0def";
  int target = 'd';
  size_t n = 7;  // Включаем символы после \0

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск в первых n байтах, символ дальше
START_TEST(test_limited_search) {
  const char str[] = "abcdef";
  int target = 'f';
  size_t n = 3;  // Обрезаем поиск, символ вне диапазона

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск первого из повторяющихся символов
START_TEST(test_multiple_occurrences) {
  const char str[] = "banana";
  int target = 'a';
  size_t n = strlen(str);

  void *result_std = memchr(str, target, n);
  void *result_s21 = s21_memchr(str, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск в массиве байтов
START_TEST(test_binary_data) {
  unsigned char data[] = {0x10, 0x20, 0x30, 0x40, 0x50};
  int target = 0x30;
  size_t n = sizeof(data);

  void *result_std = memchr(data, target, n);
  void *result_s21 = s21_memchr(data, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

// Тест: поиск в массиве байтов, символ отсутствует
START_TEST(test_binary_not_found) {
  unsigned char data[] = {0x10, 0x20, 0x30, 0x40, 0x50};
  int target = 0x99;
  size_t n = sizeof(data);

  void *result_std = memchr(data, target, n);
  void *result_s21 = s21_memchr(data, target, n);

  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

Suite *tests_memchr(void) {
  Suite *s;
  TCase *tc_memchr;
  s = suite_create("s21_memchr_tests");
  tc_memchr = tcase_create("tc_memchr");

  tcase_add_test(tc_memchr, test_standard);
  tcase_add_test(tc_memchr, test_first_char);
  tcase_add_test(tc_memchr, test_last_char);
  tcase_add_test(tc_memchr, test_not_found);
  tcase_add_test(tc_memchr, test_empty_string);
  tcase_add_test(tc_memchr, test_null_char);
  tcase_add_test(tc_memchr, test_after_null_char);
  tcase_add_test(tc_memchr, test_limited_search);
  tcase_add_test(tc_memchr, test_multiple_occurrences);
  tcase_add_test(tc_memchr, test_binary_data);
  tcase_add_test(tc_memchr, test_binary_not_found);

  suite_add_tcase(s, tc_memchr);

  return s;
}
