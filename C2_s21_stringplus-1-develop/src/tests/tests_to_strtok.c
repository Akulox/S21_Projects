#include "test.h"

// Тест: базовое разделение строки по одному разделителю
START_TEST(test_strtok_basic) {
  char str1[] = "Hello,World,Test";
  char str2[] = "Hello,World,Test";
  const char *delim = ",";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_str_eq(result, expected);

  result = s21_strtok(S21_NULL, delim);
  expected = strtok(S21_NULL, delim);
  ck_assert_str_eq(result, expected);
}
END_TEST

// Тест: несколько разделителей
START_TEST(test_strtok_multiple_delims) {
  char str1[] = "one;two,three four";
  char str2[] = "one;two,three four";
  const char *delim = " ,;";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_str_eq(result, expected);

  result = s21_strtok(S21_NULL, delim);
  expected = strtok(S21_NULL, delim);
  ck_assert_str_eq(result, expected);
}
END_TEST

// Тест: строка начинается с разделителей
START_TEST(test_strtok_leading_delims) {
  char str1[] = ",,start,,middle,end,,";
  char str2[] = ",,start,,middle,end,,";
  const char *delim = ",";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_str_eq(result, expected);

  result = s21_strtok(S21_NULL, delim);
  expected = strtok(S21_NULL, delim);
  ck_assert_str_eq(result, expected);
}
END_TEST

// Тест: строка состоит только из разделителей
START_TEST(test_strtok_only_delims) {
  char str1[] = ",,,";
  char str2[] = ",,,";
  const char *delim = ",";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: пустая строка
START_TEST(test_strtok_empty_string) {
  char str1[] = "";
  char str2[] = "";
  const char *delim = ",";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: S21_NULL в качестве строки
START_TEST(test_strtok_S21_NULL_string) {
  char str1[] = "token1,token2";
  char str2[] = "token1,token2";
  const char *delim = ",";

  // Первый вызов с валидной строкой
  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_str_eq(result, expected);

  // Второй вызов с S21_NULL
  result = s21_strtok(S21_NULL, delim);
  expected = strtok(S21_NULL, delim);
  ck_assert_str_eq(result, expected);
}
END_TEST

// Тест: разделитель отсутствует в строке (вся строка - один токен)
START_TEST(test_strtok_no_delim_in_string) {
  char str1[] = "nodividerhere";
  char str2[] = "nodividerhere";
  const char *delim = ",";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_str_eq(result, expected);

  result = s21_strtok(S21_NULL, delim);
  expected = strtok(S21_NULL, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: разделители подряд
START_TEST(test_strtok_consecutive_delims) {
  char str1[] = "a,,b,,,c";
  char str2[] = "a,,b,,,c";
  const char *delim = ",";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_str_eq(result, expected);

  result = s21_strtok(S21_NULL, delim);
  expected = strtok(S21_NULL, delim);
  ck_assert_str_eq(result, expected);
}
END_TEST

// Тест: строка без разделителей (один токен)
START_TEST(test_strtok_single_token) {
  char str1[] = "token";
  char str2[] = "token";
  const char *delim = ",";

  char *result = s21_strtok(str1, delim);
  char *expected = strtok(str2, delim);
  ck_assert_str_eq(result, expected);

  result = s21_strtok(S21_NULL, delim);
  expected = strtok(S21_NULL, delim);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite *tests_strtok(void) {
  Suite *s = suite_create("s21_strtok_tests");
  TCase *tc = tcase_create("tc_strtok");

  tcase_add_test(tc, test_strtok_basic);
  tcase_add_test(tc, test_strtok_multiple_delims);
  tcase_add_test(tc, test_strtok_leading_delims);
  tcase_add_test(tc, test_strtok_only_delims);
  tcase_add_test(tc, test_strtok_empty_string);
  tcase_add_test(tc, test_strtok_S21_NULL_string);
  tcase_add_test(tc, test_strtok_no_delim_in_string);
  tcase_add_test(tc, test_strtok_consecutive_delims);
  tcase_add_test(tc, test_strtok_single_token);

  suite_add_tcase(s, tc);
  return s;
}
