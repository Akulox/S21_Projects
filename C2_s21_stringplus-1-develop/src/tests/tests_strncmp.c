#include "test.h"

// Тест: Полное совпадение строк
START_TEST(tests_strncmp_equal) {
  const char* str1 = "zxcv";
  const char* str2 = "zxcv";
  ck_assert_int_eq(strncmp(str1, str2, 4), s21_strncmp(str1, str2, 4));
}
END_TEST

// Тест: Лексикографическое сравнение (меньше)
START_TEST(tests_strncmp_lexicographical_comparison_less) {
  const char* str1 = "zxca";
  const char* str2 = "zxcf";
  ck_assert(strncmp(str1, str2, 4) < 0 && s21_strncmp(str1, str2, 4) < 0);
}
END_TEST

// Тест: Лексикографическое сравнение (больше)
START_TEST(tests_strncmp_lexicographical_comparison_more) {
  const char* str1 = "zxcz";
  const char* str2 = "zxcf";
  ck_assert(strncmp(str1, str2, 4) > 0 && s21_strncmp(str1, str2, 4) > 0);
}
END_TEST

// Тест: Сравнение строк с разными первыми символами
START_TEST(tests_strncmp_dif_fir_ch) {
  const char* str1 = "zxcqwerty";
  const char* str2 = "axcf";
  ck_assert(strncmp(str1, str2, 4) > 0 && s21_strncmp(str1, str2, 4) > 0);
}
END_TEST

// Тест: Граничный случай (n == 0)
START_TEST(tests_strncmp_n_0) {
  const char* str1 = "zxcv";
  const char* str2 = "asdf";
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}
END_TEST

// Тест: выход за границу строки
START_TEST(tests_strncmp_array_boundary) {
  const char* str1 = "zxcv";
  const char* str2 = "zxcv\0\0\0\0\0\0\0";
  ck_assert_int_eq(strncmp(str1, str2, 10), s21_strncmp(str1, str2, 10));
}
END_TEST

// ДОП_ТЕСТ_1: Сравнение строк разной длины, где одна строка - префикс другой
START_TEST(test_strncmp_prefix) {
  const char* str1 = "abc";
  const char* str2 = "abcdef";
  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
}
END_TEST

// ДОП_ТЕСТ_2: Сравнение с пустой строкой
START_TEST(test_strncmp_empty_vs_nonempty) {
  const char* str1 = "";
  const char* str2 = "abc";
  ck_assert_int_eq(strncmp(str1, str2, 3), s21_strncmp(str1, str2, 3));
}
END_TEST

// ДОП_ТЕСТ_3: Сравнение двух пустых строк
START_TEST(test_strncmp_both_empty) {
  const char* str1 = "";
  const char* str2 = "";
  ck_assert_int_eq(strncmp(str1, str2, 1), s21_strncmp(str1, str2, 1));
}
END_TEST

// ДОП_ТЕСТ_4: Сравнение с не-ASCII символами (UTF-8)
START_TEST(test_strncmp_utf8) {
  const char* str1 = "привет";
  const char* str2 = "привeт";  // 'e' вместо 'е' (кириллица и латиница)
  ck_assert_int_eq(strncmp(str1, str2, 6), s21_strncmp(str1, str2, 6));
}
END_TEST

// ДОП_ТЕСТ_5: Сравнение строк, отличающихся только последним символом
START_TEST(test_strncmp_last_char_diff) {
  const char* str1 = "abcd";
  const char* str2 = "abce";
  ck_assert_int_eq(strncmp(str1, str2, 4), s21_strncmp(str1, str2, 4));
}
END_TEST

// ДОП_ТЕСТ_6: Сравнение строк с символами после '\0' (скрытые символы)
START_TEST(test_strncmp_after_null) {
  const char str1[] = {'a', 'b', '\0', 'c', 0};
  const char str2[] = {'a', 'b', '\0', 'd', 0};
  ck_assert_int_eq(strncmp(str1, str2, 4), s21_strncmp(str1, str2, 4));
}
END_TEST

// ДОП_ТЕСТ_7: Сравнение строк с n больше длины обеих строк
START_TEST(test_strncmp_n_greater_than_len) {
  const char* str1 = "abc";
  const char* str2 = "abc";
  ck_assert_int_eq(strncmp(str1, str2, 10), s21_strncmp(str1, str2, 10));
}
END_TEST

Suite* tests_strncmp(void) {
  Suite* s;
  TCase* tc_strncmp;
  s = suite_create("tests_strncmp");
  tc_strncmp = tcase_create("tc_strncmp");
  tcase_add_test(tc_strncmp, tests_strncmp_equal);
  tcase_add_test(tc_strncmp, tests_strncmp_lexicographical_comparison_less);
  tcase_add_test(tc_strncmp, tests_strncmp_lexicographical_comparison_more);
  tcase_add_test(tc_strncmp, tests_strncmp_dif_fir_ch);
  tcase_add_test(tc_strncmp, tests_strncmp_n_0);
  tcase_add_test(tc_strncmp, tests_strncmp_array_boundary);
  tcase_add_test(tc_strncmp, test_strncmp_prefix);
  tcase_add_test(tc_strncmp, test_strncmp_empty_vs_nonempty);
  tcase_add_test(tc_strncmp, test_strncmp_both_empty);
  tcase_add_test(tc_strncmp, test_strncmp_utf8);
  tcase_add_test(tc_strncmp, test_strncmp_last_char_diff);
  tcase_add_test(tc_strncmp, test_strncmp_after_null);
  tcase_add_test(tc_strncmp, test_strncmp_n_greater_than_len);

  suite_add_tcase(s, tc_strncmp);

  return s;
}
