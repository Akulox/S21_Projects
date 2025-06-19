#include "test.h"

// Тест 1: Заполнение всего буфера одинаковым символом
START_TEST(test_memset_compare_full) {
  size_t size = 32;
  char* buf_std = calloc(size, sizeof(char));
  char* buf_s21 = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  memset(buf_std, 42, size);
  s21_memset(buf_s21, 42, size);

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 2: Заполнение нулевой длины — буфер не должен измениться
START_TEST(test_memset_compare_zero_length) {
  size_t size = 32;
  char* buf_std = calloc(size, sizeof(char));
  char* buf_s21 = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  memset(buf_std, 55, size);
  memset(buf_s21, 55, size);

  s21_memset(buf_s21, 99, 0);  // длина 0 — ничего не меняется

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 3: Частичное заполнение буфера
START_TEST(test_memset_compare_partial) {
  size_t size = 64;
  char* buf_std = calloc(size, sizeof(char));
  char* buf_s21 = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  memset(buf_std, 0, size);
  memset(buf_s21, 0, size);

  memset(buf_std, 0xAA, 20);
  s21_memset(buf_s21, 0xAA, 20);

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 4: Заполнение отрицательным значением (будет преобразовано к unsigned
// char)
START_TEST(test_memset_compare_negative_value) {
  size_t size = 16;
  char* buf_std = calloc(size, sizeof(char));
  char* buf_s21 = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  memset(buf_std, 0, size);
  memset(buf_s21, 0, size);

  memset(buf_std, -1, size);
  s21_memset(buf_s21, -1, size);

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 5: Заполнение большого буфера (1 Мб)
START_TEST(test_memset_compare_large) {
  size_t size = 1024 * 1024;
  char* buf_std = calloc(size, sizeof(char));
  char* buf_s21 = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  memset(buf_std, 0, size);
  memset(buf_s21, 0, size);

  memset(buf_std, 'Z', size);
  s21_memset(buf_s21, 'Z', size);

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 6: Заполнение символом '\0' (обнуление)
START_TEST(test_memset_compare_zero_fill) {
  size_t size = 50;
  char* buf_std = calloc(size, sizeof(char));
  char* buf_s21 = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  memset(buf_std, 0xFF, size);
  memset(buf_s21, 0xFF, size);

  memset(buf_std, '\0', size);
  s21_memset(buf_s21, '\0', size);

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 7: Проверка возвращаемого значения (должен возвращать указатель на dest)
START_TEST(test_memset_return_value) {
  size_t size = 16;
  char* buf = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf);

  void* ret = s21_memset(buf, 123, size);
  ck_assert_ptr_eq(ret, buf);

  free(buf);
}
END_TEST

// Тест 8: Заполнение структуры и проверка, что все байты заполнены
typedef struct {
  int a;
  char b;
  short c;
} MyStruct;

START_TEST(test_memset_struct_fill) {
  MyStruct s;
  s21_memset(&s, 0xFF, sizeof(MyStruct));

  unsigned char* p = (unsigned char*)&s;
  for (size_t i = 0; i < sizeof(MyStruct); i++) {
    ck_assert_int_eq(p[i], 0xFF);
  }
}
END_TEST

// Тест 9: Заполнение массива int (проверка байтового заполнения)
START_TEST(test_memset_int_array) {
  int arr_std[4];
  int arr_s21[4];
  memset(arr_std, 0xFF, sizeof(arr_std));
  s21_memset(arr_s21, 0xFF, sizeof(arr_s21));
  ck_assert_mem_eq(arr_s21, arr_std, sizeof(arr_s21));
}
END_TEST

// Тест 10: Заполнение структуры с паддингами
typedef struct {
  char a;
  int b;
  char c;
} TestStruct;

START_TEST(test_memset_struct_padding) {
  TestStruct s;
  s21_memset(&s, 0xAA, sizeof(s));
  unsigned char* p = (unsigned char*)&s;
  for (size_t i = 0; i < sizeof(s); i++) {
    ck_assert_int_eq(p[i], 0xAA);
  }
}
END_TEST

// Тест 11: Заполнение с NULL и нулевой длиной (безопасное поведение)
START_TEST(test_memset_null_zero) {
  void* ret = s21_memset(NULL, 0, 0);
  ck_assert_ptr_eq(ret, NULL);
}
END_TEST

// Тест 12: Заполнение очень большого буфера (10 Мб)
START_TEST(test_memset_very_large) {
  size_t size = 10 * 1024 * 1024;
  char* buf_std = calloc(size, 1);
  char* buf_s21 = calloc(size, 1);
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  memset(buf_std, 0x5A, size);
  s21_memset(buf_s21, 0x5A, size);

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 13: Заполнение отрицательным значением, проверка байтов
START_TEST(test_memset_negative_value_bytes) {
  size_t size = 10;
  char* buf_std = calloc(size, sizeof(char));
  char* buf_s21 = calloc(size, sizeof(char));
  ck_assert_ptr_nonnull(buf_std);
  ck_assert_ptr_nonnull(buf_s21);

  int val = -42;
  memset(buf_std, val, size);
  s21_memset(buf_s21, val, size);

  ck_assert_mem_eq(buf_s21, buf_std, size);

  free(buf_std);
  free(buf_s21);
}
END_TEST

// Тест 14: Заполнение строки с символами и нулём
START_TEST(test_memset_string_fill) {
  char str[10] = "hello";
  s21_memset(str, 'X', 10);
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq((unsigned char)str[i], 'X');
  }
}
END_TEST

// Тест 15: Проверка неправильного использования размера (меньше чем sizeof)
START_TEST(test_memset_wrong_size) {
  char arr[10] = {0};
  s21_memset(arr, 'X', 5);
  ck_assert_int_eq(arr[4], 'X');
  ck_assert_int_eq(arr[5], 0);
}
END_TEST

Suite* tests_memset(void) {
  Suite* s = suite_create("s21_memset_tests");
  TCase* tc_memset = tcase_create("tc_memset");

  tcase_add_test(tc_memset, test_memset_compare_full);
  tcase_add_test(tc_memset, test_memset_compare_zero_length);
  tcase_add_test(tc_memset, test_memset_compare_partial);
  tcase_add_test(tc_memset, test_memset_compare_negative_value);
  tcase_add_test(tc_memset, test_memset_compare_large);
  tcase_add_test(tc_memset, test_memset_compare_zero_fill);
  tcase_add_test(tc_memset, test_memset_return_value);
  tcase_add_test(tc_memset, test_memset_struct_fill);
  tcase_add_test(tc_memset, test_memset_int_array);
  tcase_add_test(tc_memset, test_memset_struct_padding);
  tcase_add_test(tc_memset, test_memset_null_zero);
  tcase_add_test(tc_memset, test_memset_very_large);
  tcase_add_test(tc_memset, test_memset_negative_value_bytes);
  tcase_add_test(tc_memset, test_memset_string_fill);
  tcase_add_test(tc_memset, test_memset_wrong_size);

  suite_add_tcase(s, tc_memset);
  return s;
}
