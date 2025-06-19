#include "test.h"

// Тест: обычное объединение строк
START_TEST(tests_strncat_standart) {
  char str1[24] = "rocket";
  char str2[24] = "rocket";
  char str3[24] = "rocket";
  char str4[24] = "rocket";
  const char* src = "travels";

  strncat(str1, src, 23);
  s21_strncat(str2, src, 23);

  ck_assert_str_eq(str1, str2);

  strncat(str3, src, 0);
  s21_strncat(str4, src, 0);

  ck_assert_str_eq(str3, str4);
}
END_TEST

// Тест: частичное и полное объединение строк
START_TEST(tests_strncat_part) {
  char str1[24] = "apple";
  char str2[24] = "apple";
  char str3[24] = "apple";
  char str4[24] = "apple";
  const char* src = " juice";

  strncat(str1, src, 2);
  s21_strncat(str2, src, 2);

  ck_assert_str_eq(str1, str2);

  strncat(str3, src, 6);
  s21_strncat(str4, src, 6);

  ck_assert_str_eq(str3, str4);
}
END_TEST

// Тест: добавление к пустой строке
START_TEST(tests_strncat_empty) {
  char str1[24] = "";
  char str2[24] = "";
  const char* src = "123456";

  strncat(str1, src, 3);
  s21_strncat(str2, src, 3);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// Тест: объединение с пустой строкой
START_TEST(tests_strncat_copy_empty) {
  char str1[24] = "aaa";
  char str2[24] = "aaa";
  const char* src = "";

  strncat(str1, src, 10);
  s21_strncat(str2, src, 10);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// Тест: проверка возвращаемого указателя
START_TEST(tests_strncat_pointer_check) {
  char str1[24] = "xxx";
  char str2[24] = "xxx";
  const char* src = "def";
  char* ret;

  strncat(str1, src, 3);
  ret = s21_strncat(str2, src, 3);

  ck_assert_str_eq(str1, str2);
  ck_assert_ptr_eq(str2, ret);
}
END_TEST

// Закомментил, т.к. тест завершается с ошибками (как и задумано) для обеих
// функций и показывает покрытие меньше 100% ДОП.ТЕСТ_1: Проверка работы с
// нулевым размером буфера назначения
// START_TEST(tests_strncat_full_buffer) {
//  char str1[6] = "hello";
//  char str2[6] = "hello";
//  const char* src = "world";

//  strncat(str1, src, 1); // может привести к выходу за пределы
//  s21_strncat(str2, src, 1);

// Ожидаемое поведение: стандартная strncat не защищает от выхода за пределы!
//  ck_assert_str_eq(str1, str2);
//}
// END_TEST

// ДОП.ТЕСТ_2: Проверка передачи size = 0
START_TEST(tests_strncat_zero_size) {
  char str1[10] = "abc";
  char str2[10] = "abc";
  const char* src = "def";

  strncat(str1, src, 0);
  s21_strncat(str2, src, 0);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// ДОП.ТЕСТ_3: Проверка передачи size больше длины src
// должно копироваться только до первого \0 в src, даже если size больше
START_TEST(tests_strncat_size_gt_src) {
  char str1[20] = "foo";
  char str2[20] = "foo";
  const char* src = "bar";

  strncat(str1, src, 10);  // src короче 10
  s21_strncat(str2, src, 10);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// ДОП.ТЕСТ_4: Проверка передачи size == длине src
// должна копироваться ровно вся строка src
START_TEST(tests_strncat_size_eq_src) {
  char str1[20] = "foo";
  char str2[20] = "foo";
  const char* src = "bar";

  strncat(str1, src, 3);  // src длиной 3
  s21_strncat(str2, src, 3);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// ДОП.ТЕСТ_5: Проверка работы с пустой строкой назначения
// должна корректно добавлять к пустой строке
START_TEST(tests_strncat_dest_empty) {
  char str1[10] = "";
  char str2[10] = "";
  const char* src = "abc";

  strncat(str1, src, 2);
  s21_strncat(str2, src, 2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// ДОП.ТЕСТ_6: Проверка передачи пустой строки-источника
// при пустом src строка назначения не должна измениться
START_TEST(tests_strncat_src_empty) {
  char str1[10] = "abc";
  char str2[10] = "abc";
  const char* src = "";

  strncat(str1, src, 2);
  s21_strncat(str2, src, 2);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// ДОП.ТЕСТ_7: Проверка передачи size == 1
// граничный случай
START_TEST(tests_strncat_size_one) {
  char str1[10] = "abc";
  char str2[10] = "abc";
  const char* src = "def";

  strncat(str1, src, 1);
  s21_strncat(str2, src, 1);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite* tests_strncat(void) {
  Suite* s = suite_create("tests_strncat");
  TCase* tc_strncat = tcase_create("tc_strncat");

  tcase_add_test(tc_strncat, tests_strncat_standart);
  tcase_add_test(tc_strncat, tests_strncat_part);
  tcase_add_test(tc_strncat, tests_strncat_empty);
  tcase_add_test(tc_strncat, tests_strncat_copy_empty);
  tcase_add_test(tc_strncat, tests_strncat_pointer_check);
  // tcase_add_test(tc_strncat, tests_strncat_full_buffer);
  tcase_add_test(tc_strncat, tests_strncat_zero_size);
  tcase_add_test(tc_strncat, tests_strncat_size_gt_src);
  tcase_add_test(tc_strncat, tests_strncat_size_eq_src);
  tcase_add_test(tc_strncat, tests_strncat_dest_empty);
  tcase_add_test(tc_strncat, tests_strncat_src_empty);
  tcase_add_test(tc_strncat, tests_strncat_size_one);

  suite_add_tcase(s, tc_strncat);

  return s;
}
