#include "test.h"

// Тест: копирование строки (большой буфер), с сравнением буферов
START_TEST(tests_strncpy_standart) {
  const char* str1 = "zxcvbn";
  char* str2;
  char* str3;
  str2 = malloc(32);
  str3 = malloc(32);
  memset(str2, 42, 32);
  memset(str3, 42, 32);
  strncpy(str2, str1, 32);
  s21_strncpy(str3, str1, 32);
  ck_assert_mem_eq(str2, str3, 32);
  free(str2);
  free(str3);
}
END_TEST

// Копирование строки, когда буфер уже содержит данные, с сравнением буферов и
// указателя
START_TEST(tests_strncpy_buf_not_empt) {
  const char* str1 = "asdfgh";
  char* str2;
  char* str3;
  char* ret;
  str2 = malloc(32);
  str3 = malloc(32);
  strncpy(str2, "zxcvbnmqwertyu", 15);
  ret = strncpy(str3, "zxcvbnmqwertyu", 15);
  strncpy(str2, str1, 10);
  s21_strncpy(str3, str1, 10);
  ck_assert_mem_eq(str2, str3, 15);
  ck_assert_ptr_eq(str3, ret);
  free(str2);
  free(str3);
}
END_TEST

// Тест: копирование 7-ми символов, с сравнением буферов и указателя
START_TEST(tests_strncpy_n_7) {
  const char* str1 = "zxcvbn";
  char* str2;
  char* str3;
  char* ret;
  str2 = malloc(32);
  str3 = malloc(32);
  memset(str2, 42, 32);
  ret = memset(str3, 42, 32);
  strncpy(str2, str1, 7);
  s21_strncpy(str3, str1, 7);
  ck_assert_mem_eq(str2, str3, 32);
  ck_assert_ptr_eq(str3, ret);
  free(str2);
  free(str3);
}
END_TEST

// Тест с нулевой длиной копирования
// Примечание: Мы не используем прямой вызов strncpy с n=0, чтобы избежать
// предупреждений компилятора
START_TEST(tests_strncpy_zero_length) {
  const char* src = "test string";
  char dest[20] = "destination";

  // Проверяем только нашу реализацию с n=0
  char* ret = s21_strncpy(dest, src, 0);

  // Проверяем, что содержимое не изменилось
  ck_assert_str_eq(dest, "destination");

  // Проверяем возвращаемое значение
  ck_assert_ptr_eq(ret, dest);
}
END_TEST

// Тест с копированием части строки (n < длины строки)
START_TEST(tests_strncpy_partial_copy) {
  const char* src = "test string";
  char dest1[20];
  char dest2[20];
  memset(dest1, 'A', 20);
  memset(dest2, 'A', 20);

  strncpy(dest1, src, 4);  // Копируем только "test"
  s21_strncpy(dest2, src, 4);

  ck_assert_mem_eq(dest1, dest2, 20);
}
END_TEST

// Тест с пустой исходной строкой
START_TEST(tests_strncpy_empty_src) {
  const char* src = "";
  char dest1[20];
  char dest2[20];
  memset(dest1, 'A', 20);
  memset(dest2, 'A', 20);

  strncpy(dest1, src, 10);
  s21_strncpy(dest2, src, 10);

  ck_assert_mem_eq(dest1, dest2, 20);
}
END_TEST

// Тест с перекрывающимися буферами
START_TEST(tests_strncpy_overlapping) {
  char buffer1[20] = "test string";
  char buffer2[20] = "test string";

  strncpy(buffer1 + 5, buffer1, 5);
  s21_strncpy(buffer2 + 5, buffer2, 5);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// Тест с очень длинной строкой
START_TEST(tests_strncpy_long_string) {
  const char* src =
      "This is a very long string used to test the strncpy function with "
      "longer inputs to ensure it handles them correctly and efficiently "
      "without any memory issues or unexpected behaviors";
  char* dest1;
  char* dest2;
  size_t len = strlen(src) + 20;  // Дополнительное пространство для нулей

  dest1 = malloc(len);
  dest2 = malloc(len);
  memset(dest1, 'A', len);
  memset(dest2, 'A', len);

  strncpy(dest1, src, len - 10);
  s21_strncpy(dest2, src, len - 10);

  ck_assert_mem_eq(dest1, dest2, len);
  free(dest1);
  free(dest2);
}
END_TEST

// Тест с неанглийскими символами (UTF-8)
START_TEST(tests_strncpy_utf8) {
  const char* src = "Привет, мир！";
  char dest1[50];
  char dest2[50];
  memset(dest1, 'A', 50);
  memset(dest2, 'A', 50);

  strncpy(dest1, src, 30);
  s21_strncpy(dest2, src, 30);

  ck_assert_mem_eq(dest1, dest2, 50);
}
END_TEST

Suite* tests_strncpy(void) {
  Suite* s;
  TCase* tc_strncpy;
  s = suite_create("tests_strncpy");
  tc_strncpy = tcase_create("tc_strncpy");

  // Добавляем оригинальные тесты
  tcase_add_test(tc_strncpy, tests_strncpy_standart);
  tcase_add_test(tc_strncpy, tests_strncpy_buf_not_empt);
  tcase_add_test(tc_strncpy, tests_strncpy_n_7);

  // Добавляем новые тесты
  tcase_add_test(tc_strncpy, tests_strncpy_zero_length);
  tcase_add_test(tc_strncpy, tests_strncpy_partial_copy);
  tcase_add_test(tc_strncpy, tests_strncpy_empty_src);
  tcase_add_test(tc_strncpy, tests_strncpy_overlapping);
  tcase_add_test(tc_strncpy, tests_strncpy_long_string);
  tcase_add_test(tc_strncpy, tests_strncpy_utf8);

  suite_add_tcase(s, tc_strncpy);
  return s;
}
