#include "test.h"

// Тест 1: Поиск первого совпадения символа из charset в строке
START_TEST(test_strcspn_basic) {
  const char *str = "xyzbxz";
  const char *charset = "abc";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 2: Первый символ строки входит в charset
START_TEST(test_strcspn_first_char_match) {
  const char *str = "xyzbxz";
  const char *charset = "xyz";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 3: Ни один символ не входит в charset
START_TEST(test_strcspn_no_match) {
  const char *str = "xyzbxz";
  const char *charset = "no match";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 4: Пустая строка str
START_TEST(test_strcspn_empty_str) {
  const char *str = "";
  const char *charset = "abc";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 5: Пустой charset
START_TEST(test_strcspn_empty_charset) {
  const char *str = "xyzbxz";
  const char *charset = "";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 6: Оба параметра пустые строки
START_TEST(test_strcspn_both_empty) {
  const char *str = "";
  const char *charset = "";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 7: Строка из одного символа, который входит в charset
START_TEST(test_strcspn_single_char_match) {
  const char *str = "a";
  const char *charset = "a";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 8: Строка из одного символа, который не входит в charset
START_TEST(test_strcspn_single_char_no_match) {
  const char *str = "a";
  const char *charset = "b";

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

// Тест 9: Длинная строка и charset
START_TEST(test_strcspn_long_string) {
  size_t size = 10000;
  char *str = calloc(size + 1, sizeof(char));
  char *charset = calloc(3, sizeof(char));
  ck_assert_ptr_nonnull(str);
  ck_assert_ptr_nonnull(charset);

  memset(str, 'A', size);
  str[size] = '\0';

  charset[0] = 'B';
  charset[1] = 'C';
  charset[2] = '\0';

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);

  free(str);
  free(charset);
}
END_TEST

// Тест 10: Charset содержит нулевой символ (поведение не определено, но
// проверим)
START_TEST(test_strcspn_charset_with_null) {
  const char *str = "abcde";
  const char charset[] = {'x', 'y', '\0', 'z', '\0'};

  size_t res_std = strcspn(str, charset);
  size_t res_s21 = s21_strcspn(str, charset);

  ck_assert_uint_eq(res_s21, res_std);
}
END_TEST

Suite *tests_strcspn(void) {
  Suite *s = suite_create("s21_strcspn_tests");
  TCase *tc_strcspn = tcase_create("tc_strcspn");

  tcase_add_test(tc_strcspn, test_strcspn_basic);
  tcase_add_test(tc_strcspn, test_strcspn_first_char_match);
  tcase_add_test(tc_strcspn, test_strcspn_no_match);
  tcase_add_test(tc_strcspn, test_strcspn_empty_str);
  tcase_add_test(tc_strcspn, test_strcspn_empty_charset);
  tcase_add_test(tc_strcspn, test_strcspn_both_empty);
  tcase_add_test(tc_strcspn, test_strcspn_single_char_match);
  tcase_add_test(tc_strcspn, test_strcspn_single_char_no_match);
  tcase_add_test(tc_strcspn, test_strcspn_long_string);
  tcase_add_test(tc_strcspn, test_strcspn_charset_with_null);

  suite_add_tcase(s, tc_strcspn);
  return s;
}
