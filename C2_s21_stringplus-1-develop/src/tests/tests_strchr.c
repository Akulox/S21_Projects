#include <stdlib.h>
#include <string.h>

#include "test.h"

// Тест 1: Поиск символа, который есть в строке (первое вхождение)
START_TEST(test_strchr_found) {
  const char* str = "Hello, World!";
  int c = 'o';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 2: Поиск символа, которого нет в строке
START_TEST(test_strchr_not_found) {
  const char* str = "Hello, World!";
  int c = 'z';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 3: Поиск нулевого символа '\0' — должен вернуть указатель на конец
// строки
START_TEST(test_strchr_null_char) {
  const char* str = "Test string";
  int c = '\0';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 4: Пустая строка, поиск любого символа кроме '\0' — всегда NULL
START_TEST(test_strchr_empty_string) {
  const char* str = "";
  int c = 'a';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 5: Пустая строка, поиск '\0' — указатель на начало строки (пустую)
START_TEST(test_strchr_empty_string_null) {
  const char* str = "";
  int c = '\0';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 6: Поиск символа в строке с несколькими вхождениями — должно вернуть
// первое
START_TEST(test_strchr_multiple_occurrences) {
  const char* str = "banana";
  int c = 'a';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 7: Поиск символа с отрицательным значением (будет интерпретировано как
// unsigned char)
START_TEST(test_strchr_negative_char) {
  // Используем массив с байтом 0xFF
  const char str[] = {'a', 'b', 'c', (char)0xFF, 'd', 'e', 'f', '\0'};
  int c = -1;  // 0xFF в unsigned char

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST
// Тест 8: Поиск символа в строке с пробелами и спецсимволами
START_TEST(test_strchr_special_chars) {
  const char* str = " \t\n\r!@#";
  int c = '\n';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 9: Поиск символа в очень длинной строке
START_TEST(test_strchr_long_string) {
  size_t size = 10000;
  char* str = calloc(size + 1, sizeof(char));
  ck_assert_ptr_nonnull(str);

  memset(str, 'A', size);
  str[size] = '\0';

  int c = 'A';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);

  free(str);
}
END_TEST

// Тест 10: Поиск символа '\0' в очень длинной строке
START_TEST(test_strchr_long_string_null) {
  size_t size = 10000;
  char* str = calloc(size + 1, sizeof(char));
  ck_assert_ptr_nonnull(str);

  memset(str, 'A', size);
  str[size] = '\0';

  int c = '\0';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);

  free(str);
}
END_TEST

// Тест 11: Поиск символа в строке с одним символом
START_TEST(test_strchr_single_char) {
  const char* str = "x";
  int c = 'x';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 12: Поиск символа, который встречается в конце строки
START_TEST(test_strchr_last_char) {
  const char* str = "findme";
  int c = 'e';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

// Тест 13: Поиск символа, который встречается в начале строки
START_TEST(test_strchr_first_char) {
  const char* str = "start";
  int c = 's';

  char* res_std = strchr(str, c);
  char* res_s21 = s21_strchr(str, c);

  ck_assert_ptr_eq(res_s21, res_std);
}
END_TEST

Suite* tests_strchr(void) {
  Suite* s = suite_create("s21_strchr_tests");
  TCase* tc_strchr = tcase_create("tc_strchr");

  tcase_add_test(tc_strchr, test_strchr_found);
  tcase_add_test(tc_strchr, test_strchr_not_found);
  tcase_add_test(tc_strchr, test_strchr_null_char);
  tcase_add_test(tc_strchr, test_strchr_empty_string);
  tcase_add_test(tc_strchr, test_strchr_empty_string_null);
  tcase_add_test(tc_strchr, test_strchr_multiple_occurrences);
  tcase_add_test(tc_strchr, test_strchr_negative_char);
  tcase_add_test(tc_strchr, test_strchr_special_chars);
  tcase_add_test(tc_strchr, test_strchr_long_string);
  tcase_add_test(tc_strchr, test_strchr_long_string_null);
  tcase_add_test(tc_strchr, test_strchr_single_char);
  tcase_add_test(tc_strchr, test_strchr_last_char);
  tcase_add_test(tc_strchr, test_strchr_first_char);

  suite_add_tcase(s, tc_strchr);
  return s;
}
