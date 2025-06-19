#include "test.h"

// Тест: подстрока в начале строки
START_TEST(test_strstr_substr_at_start) {
  const char str[] = "Hello, world!";
  const char substr[] = "Hello";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: подстрока в середине строки
START_TEST(test_strstr_substr_in_middle) {
  const char str[] = "Say hello world";
  const char substr[] = "hello";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: подстрока в конце строки
START_TEST(test_strstr_substr_at_end) {
  const char str[] = "Hello world end";
  const char substr[] = "end";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: подстрока отсутствует
START_TEST(test_strstr_substr_not_found) {
  const char str[] = "Hello, world";
  const char substr[] = "xyz";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: пустая подстрока (по стандарту должна вернуть исходную строку)
START_TEST(test_strstr_empty_substr) {
  const char str[] = "Hello, world";
  const char substr[] = "";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: пустая строка и пустая подстрока
START_TEST(test_strstr_empty_str_and_substr) {
  const char str[] = "";
  const char substr[] = "";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: пустая строка и непустая подстрока
START_TEST(test_strstr_empty_str_nonempty_substr) {
  const char str[] = "";
  const char substr[] = "abc";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: подстрока равна всей строке
START_TEST(test_strstr_substr_equals_str) {
  const char str[] = "Hello";
  const char substr[] = "Hello";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: подстрока длиннее строки
START_TEST(test_strstr_substr_longer_than_str) {
  const char str[] = "Hello";
  const char substr[] = "Hello world Hello world";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: подстрока с повторяющимися символами
START_TEST(test_strstr_repeated_chars) {
  const char str[] = "aaaaaaaab";
  const char substr[] = "aaaab";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Тест: подстрока с символами с высоким ASCII
START_TEST(test_strstr_high_ascii) {
  const char str[] =
      "abc\x7F"
      "def";
  const char substr[] =
      "\x7F"
      "de";

  char *result = s21_strstr(str, substr);
  char *expected = strstr(str, substr);

  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite *tests_strstr(void) {
  Suite *s = suite_create("s21_strstr_tests");
  TCase *tc = tcase_create("tc_strstr");

  tcase_add_test(tc, test_strstr_substr_at_start);
  tcase_add_test(tc, test_strstr_substr_in_middle);
  tcase_add_test(tc, test_strstr_substr_at_end);
  tcase_add_test(tc, test_strstr_substr_not_found);
  tcase_add_test(tc, test_strstr_empty_substr);
  tcase_add_test(tc, test_strstr_empty_str_and_substr);
  tcase_add_test(tc, test_strstr_empty_str_nonempty_substr);
  tcase_add_test(tc, test_strstr_substr_equals_str);
  tcase_add_test(tc, test_strstr_substr_longer_than_str);
  tcase_add_test(tc, test_strstr_repeated_chars);
  tcase_add_test(tc, test_strstr_high_ascii);

  suite_add_tcase(s, tc);
  return s;
}
