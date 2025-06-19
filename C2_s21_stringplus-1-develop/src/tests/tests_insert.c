#include "test.h"

// Тест: стандартная вставка строки в середину другой строки
START_TEST(test_standard_insert) {
  char dest[20] = "Hello, ";
  const char *src = "World!";
  size_t pos = 7;  // Вставка на позицию после "Hello, "
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Hello, World!";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);  // Освобождаем память
}
END_TEST

// Тест: вставка строки в начало другой строки (позиция 0)
START_TEST(test_insert_at_start) {
  char dest[20] = "Hello";
  const char *src = "Hi, ";
  size_t pos = 0;  // Вставка в начало строки
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Hi, Hello";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: вставка строки в конец другой строки (позиция равна длине)
START_TEST(test_insert_at_end) {
  char dest[20] = "Hello";
  const char *src = " World!";
  size_t pos = 5;  // Вставка в конец строки
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Hello World!";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: вставка пустой строки (строка не должна измениться)
START_TEST(test_insert_empty_string) {
  char dest[20] = "Hello";
  const char *src = "";
  size_t pos = 3;  // Вставка пустой строки
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Hello";  // Строка не изменяется
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: попытка вставки в позицию за пределами строки
START_TEST(test_insert_out_of_bounds) {
  char dest[20] = "Hello";
  const char *src = "World!";
  size_t pos = 100;  // Позиция за пределами строки
  char *result_s21 = s21_insert(dest, src, pos);
  ck_assert_ptr_eq(result_s21, NULL);
  // Память не выделялась, освобождать не нужно
}
END_TEST

// Тест: вставка строки в пустую строку (dest пустой)
START_TEST(test_insert_empty_dest) {
  char dest[20] = "";
  const char *src = "Hello";
  size_t pos = 0;  // Вставка в пустую строку
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Hello";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: вставка строки в середину другой строки
START_TEST(test_insert_middle) {
  char dest[20] = "Hello!";
  const char *src = " World";
  size_t pos = 5;  // Вставка после "Hello"
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Hello World!";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: вставка в пустую строку на позицию 0
START_TEST(test_insert_at_zero_empty_dest) {
  char dest[20] = "";
  const char *src = "First";
  size_t pos = 0;  // Вставка в пустую строку в начало
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "First";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: вставка с NULL в качестве строки для вставки (src)
START_TEST(test_insert_null_source) {
  char dest[20] = "Hello";
  const char *src = NULL;
  size_t pos = 3;  // Вставка NULL
  char *result_s21 = s21_insert(dest, src, pos);
  ck_assert_ptr_eq(result_s21, NULL);
}
END_TEST

// Тест: вставка в NULL-строку (dest равен NULL)
START_TEST(test_insert_null_dest) {
  char *dest = NULL;
  const char *src = "Hello";
  size_t pos = 0;  // Вставка в NULL-строку
  char *result_s21 = s21_insert(dest, src, pos);
  ck_assert_ptr_eq(result_s21, NULL);
}
END_TEST

// Тест: оба параметра NULL
START_TEST(test_insert_both_null) {
  char *dest = NULL;
  const char *src = NULL;
  size_t pos = 0;
  char *result_s21 = s21_insert(dest, src, pos);
  ck_assert_ptr_eq(result_s21, NULL);
}
END_TEST

// Тест: вставка с максимальным значением позиции
START_TEST(test_insert_max_position) {
  char dest[20] = "Hello";
  const char *src = "World";
  size_t pos = SIZE_MAX;
  char *result_s21 = s21_insert(dest, src, pos);
  ck_assert_ptr_eq(result_s21, NULL);
}
END_TEST

// Тест: работа с большими строками
START_TEST(test_insert_large_strings) {
  // Создаем большую строку-источник
  char *dest = malloc(1000);
  memset(dest, 'A', 999);
  dest[999] = '\0';

  // Создаем большую строку для вставки
  char *src = malloc(1000);
  memset(src, 'B', 999);
  src[999] = '\0';

  size_t pos = 500;  // Вставка в середину
  char *result_s21 = s21_insert(dest, src, pos);

  // Проверяем результат
  ck_assert_ptr_ne(result_s21, NULL);
  ck_assert_int_eq(strlen(result_s21), 1998);  // 999 + 999

  // Проверяем корректность вставки
  for (int i = 0; i < 500; i++) {
    ck_assert_int_eq(result_s21[i], 'A');
  }
  for (int i = 500; i < 1499; i++) {
    ck_assert_int_eq(result_s21[i], 'B');
  }
  for (int i = 1499; i < 1998; i++) {
    ck_assert_int_eq(result_s21[i], 'A');
  }

  free(result_s21);
  free(dest);
  free(src);
}
END_TEST

// Тест: вставка строки со спецсимволами
START_TEST(test_insert_special_chars) {
  char dest[50] = "Hello";
  const char *src = "\t\n\r Special!";
  size_t pos = 5;
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Hello\t\n\r Special!";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: вставка пустой строки в пустую строку
START_TEST(test_insert_empty_to_empty) {
  char dest[10] = "";
  const char *src = "";
  size_t pos = 0;
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Тест: вставка строки с числами и символами
START_TEST(test_insert_mixed_content) {
  char dest[50] = "Test123";
  const char *src = "!@#$%^&*()";
  size_t pos = 4;  // После "Test"
  char *result_s21 = s21_insert(dest, src, pos);
  const char *expected = "Test!@#$%^&*()123";
  ck_assert_str_eq(result_s21, expected);
  free(result_s21);
}
END_TEST

// Создание тестового набора
Suite *tests_insert(void) {
  Suite *s = suite_create("s21_insert_tests");
  TCase *tc_insert = tcase_create("tc_insert");

  // Добавляем все тесты в набор
  tcase_add_test(tc_insert, test_standard_insert);
  tcase_add_test(tc_insert, test_insert_at_start);
  tcase_add_test(tc_insert, test_insert_at_end);
  tcase_add_test(tc_insert, test_insert_empty_string);
  tcase_add_test(tc_insert, test_insert_out_of_bounds);
  tcase_add_test(tc_insert, test_insert_empty_dest);
  tcase_add_test(tc_insert, test_insert_middle);
  tcase_add_test(tc_insert, test_insert_at_zero_empty_dest);
  tcase_add_test(tc_insert, test_insert_null_source);
  tcase_add_test(tc_insert, test_insert_null_dest);
  tcase_add_test(tc_insert, test_insert_both_null);
  tcase_add_test(tc_insert, test_insert_max_position);
  tcase_add_test(tc_insert, test_insert_large_strings);
  tcase_add_test(tc_insert, test_insert_special_chars);
  tcase_add_test(tc_insert, test_insert_empty_to_empty);
  tcase_add_test(tc_insert, test_insert_mixed_content);

  suite_add_tcase(s, tc_insert);
  return s;
}
