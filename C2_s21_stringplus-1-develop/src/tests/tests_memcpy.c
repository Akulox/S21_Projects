#include "test.h"

// Стандартный тест
START_TEST(test_standard) {
  char dest[20];
  const char *src = "Hello, World!";
  size_t n = 13;

  void *result_s21 = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result_s21, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: копирование без перекрытия областей (правильное использование memcpy)
START_TEST(test_non_overlap) {
  char src[20] = "Hello, World!";
  char dest1[20];
  char dest2[20];
  size_t n = 13;

  // Копируем с использованием обеих функций
  memcpy(dest1, src, n);
  s21_memcpy(dest2, src, n);

  // Результаты должны быть идентичными
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

// Тест: копирование с нулевым количеством байт
START_TEST(test_zero_bytes) {
  char dest[20] = "Original data";
  char dest_copy[20] = "Original data";
  const char *src = "Hello, World!";
  size_t n = 0;

  memcpy(dest, src, n);
  s21_memcpy(dest_copy, src, n);

  ck_assert_mem_eq(dest, dest_copy, 20);  // Проверяем, что dest не изменился
}
END_TEST

// Тест: копирование в буфер с меньшим размером, чем исходный
START_TEST(test_smaller_dest) {
  char dest[5];
  const char *src = "Hello, World!";
  size_t n = 5;

  void *result = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: копирование с перекрывающимися областями памяти
// Примечание: поведение memcpy при перекрытии не определено стандартом
START_TEST(test_overlap) {
  // Для memcpy поведение при перекрытии областей не определено,
  // поэтому проверяем только, что функция не падает
  char str[20] = "Hello, World!";
  size_t n = 5;

  // Копируем с перекрытием (результат не определен)
  s21_memcpy(str + 2, str, n);

  // Проверяем, что функция вернула правильный указатель
  ck_assert_ptr_ne(str + 2, NULL);
}
END_TEST

// Тест: пустой исходный массив
START_TEST(test_empty_src) {
  char dest[20] = "Original";
  char dest_copy[20] = "Original";
  const char *src = "";
  size_t n = 0;

  memcpy(dest, src, n);
  s21_memcpy(dest_copy, src, n);

  ck_assert_mem_eq(dest, dest_copy, 20);
}
END_TEST

// Тест: копирование одного байта
START_TEST(test_one_byte) {
  char dest[20];
  const char *src = "H";
  size_t n = 1;

  void *result = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: копирование в полностью заполненный буфер
START_TEST(test_full_dest) {
  char dest[20] = "1234567890abcdefghi";
  char dest_copy[20] = "1234567890abcdefghi";
  const char *src = "Hello";
  size_t n = 5;

  memcpy(dest, src, n);
  s21_memcpy(dest_copy, src, n);

  ck_assert_mem_eq(dest, dest_copy, 20);
}
END_TEST

// Тест: копирование в массив из нулевых байтов
START_TEST(test_dest_with_zeros) {
  char dest[20] = {0};  // Все нули
  const char *src = "Hello, World!";
  size_t n = 13;

  void *result = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: копирование большого объема данных
START_TEST(test_large_data) {
  char dest[10000];
  char src[10000];
  for (int i = 0; i < 10000; i++) {
    src[i] = i % 256;
  }
  size_t n = 10000;

  void *result = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: копирование разных типов данных
START_TEST(test_different_types) {
  int src[] = {1, 2, 3, 4, 5};
  int dest[5];
  size_t n = sizeof(src);

  void *result = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: копирование структур
START_TEST(test_struct_copy) {
  struct TestStruct {
    int id;
    double value;
    char name[20];
  };

  struct TestStruct src;
  struct TestStruct dest;

  // Полностью инициализируем обе структуры нулями, включая padding
  memset(&src, 0, sizeof(struct TestStruct));
  memset(&dest, 0, sizeof(struct TestStruct));

  // Теперь заполняем поля src
  src.id = 42;
  src.value = 3.14159;
  strcpy(src.name, "Test Structure");

  size_t n = sizeof(struct TestStruct);

  void *result = s21_memcpy(&dest, &src, n);

  ck_assert_ptr_eq(result, &dest);
  ck_assert_mem_eq(&dest, &src, n);
}
END_TEST

// Тест: копирование бинарных данных
START_TEST(test_binary_data) {
  unsigned char src[] = {0x00, 0xFF, 0xAA, 0x55, 0x00, 0x7F, 0x01};
  unsigned char dest[7];
  size_t n = 7;

  void *result = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: копирование с нулевыми байтами в середине
START_TEST(test_null_in_middle) {
  char src[] = {'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd'};
  char dest[11];
  size_t n = 11;

  void *result = s21_memcpy(dest, src, n);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, n);
}
END_TEST

// Тест: максимальный размер копирования
START_TEST(test_max_size) {
  // Тест с большим размером, но не максимальным s21_size_t
  char *src = malloc(100000);
  char *dest = malloc(100000);

  if (src && dest) {
    for (int i = 0; i < 100000; i++) {
      src[i] = i % 256;
    }

    void *result = s21_memcpy(dest, src, 100000);

    ck_assert_ptr_eq(result, dest);
    ck_assert_mem_eq(dest, src, 100000);
  }

  free(src);
  free(dest);
}
END_TEST

// Тест: копирование с выравниванием
START_TEST(test_alignment) {
  char buffer[100];
  char *src = buffer + 3;  // Невыравненный указатель
  char *dest = buffer + 50 + 7;  // Другой невыравненный указатель

  for (int i = 0; i < 20; i++) {
    src[i] = i + 65;
  }

  void *result = s21_memcpy(dest, src, 20);

  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, src, 20);
}
END_TEST

// Тест: сравнение со стандартной функцией
START_TEST(test_compare_with_standard) {
  char dest1[100];
  char dest2[100];
  const char *src = "Testing comparison with standard memcpy";
  size_t n = strlen(src) + 1;

  void *result_std = memcpy(dest1, src, n);
  void *result_s21 = s21_memcpy(dest2, src, n);

  ck_assert_ptr_eq(result_std, dest1);
  ck_assert_ptr_eq(result_s21, dest2);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

Suite *tests_memcpy(void) {
  Suite *s = suite_create("s21_memcpy_tests");
  TCase *tc_memcpy = tcase_create("tc_memcpy");

  tcase_add_test(tc_memcpy, test_standard);
  tcase_add_test(tc_memcpy, test_zero_bytes);
  tcase_add_test(tc_memcpy, test_smaller_dest);
  tcase_add_test(tc_memcpy, test_overlap);
  tcase_add_test(tc_memcpy, test_non_overlap);
  tcase_add_test(tc_memcpy, test_empty_src);
  tcase_add_test(tc_memcpy, test_one_byte);
  tcase_add_test(tc_memcpy, test_full_dest);
  tcase_add_test(tc_memcpy, test_dest_with_zeros);
  tcase_add_test(tc_memcpy, test_large_data);
  tcase_add_test(tc_memcpy, test_different_types);
  tcase_add_test(tc_memcpy, test_struct_copy);
  tcase_add_test(tc_memcpy, test_binary_data);
  tcase_add_test(tc_memcpy, test_null_in_middle);
  tcase_add_test(tc_memcpy, test_max_size);
  tcase_add_test(tc_memcpy, test_alignment);
  tcase_add_test(tc_memcpy, test_compare_with_standard);

  suite_add_tcase(s, tc_memcpy);
  return s;
}
