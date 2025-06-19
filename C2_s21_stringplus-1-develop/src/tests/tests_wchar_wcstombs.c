#include "test.h"

START_TEST(s21_wcstombs_0) {
  char got[100];
  char expected[100];
  const s21_wchar_t *str1 = L"HELL";
  const wchar_t *str2 = L"HELL";
  s21_size_t result = wcstombs(expected, str2, sizeof(expected));
  s21_size_t result2 = s21_wcstombs(got, str1, sizeof(got));
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(result, result2);
}
END_TEST

START_TEST(s21_wcstombs_1) {
  char got[100];
  char expected[100];
  const s21_wchar_t *str1 = L"";
  const wchar_t *str2 = L"";
  s21_size_t result = wcstombs(expected, str2, sizeof(expected));
  s21_size_t result2 = s21_wcstombs(got, str1, sizeof(got));
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(result, result2);
}
END_TEST

START_TEST(s21_wcstombs_2) {
  char got[100];
  char expected[100];
  const unsigned int numbers1[] = {0x3053, 0x306b, 0x3093,
                                   0x306b, 0x3061, 0x306f};
  const unsigned int numbers2[] = {0x3053, 0x306b, 0x3093,
                                   0x306b, 0x3061, 0x306f};

  s21_wchar_t str1[7];
  wchar_t str2[7];
  for (size_t i = 0; i < sizeof(numbers1) / sizeof(numbers1[0]); ++i) {
    str1[i] = (s21_wchar_t)numbers1[i];
  }
  str1[6] = L'\0';
  for (size_t i = 0; i < sizeof(numbers2) / sizeof(numbers2[0]); ++i) {
    str2[i] = (wchar_t)numbers2[i];
  }
  str2[6] = L'\0';
  s21_size_t result = wcstombs(expected, str2, sizeof(expected));
  s21_size_t result2 = s21_wcstombs(got, str1, sizeof(got));

  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(result, result2);
}
END_TEST

START_TEST(s21_wcstombs_3) {
  char got[100];
  const s21_wchar_t *wcstr = S21_NULL;

  s21_size_t result = s21_wcstombs(got, wcstr, sizeof(got));

  ck_assert_str_eq(got, "");
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_wcstombs_4) {
  char got[100];
  char expected[100];
  const unsigned int numbers1[] = {0x771, 0x772};
  const unsigned int numbers2[] = {0x771, 0x772};

  s21_wchar_t str1[3];
  wchar_t str2[3];
  for (size_t i = 0; i < sizeof(numbers1) / sizeof(numbers1[0]); ++i) {
    str1[i] = (s21_wchar_t)numbers1[i];
  }
  str1[2] = L'\0';
  for (size_t i = 0; i < sizeof(numbers2) / sizeof(numbers2[0]); ++i) {
    str2[i] = (wchar_t)numbers2[i];
  }
  str2[2] = L'\0';
  s21_size_t result = wcstombs(expected, str2, sizeof(expected));
  s21_size_t result2 = s21_wcstombs(got, str1, sizeof(got));

  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(result, result2);
}
END_TEST

Suite *tests_wchar_wcstombs(void) {
  Suite *s;
  TCase *tc_wcstombs;
  s = suite_create("wcstombs_tests");
  tc_wcstombs = tcase_create("wcstombs_tc");
  tcase_add_test(tc_wcstombs, s21_wcstombs_0);
  tcase_add_test(tc_wcstombs, s21_wcstombs_1);
  tcase_add_test(tc_wcstombs, s21_wcstombs_2);
  tcase_add_test(tc_wcstombs, s21_wcstombs_3);
  tcase_add_test(tc_wcstombs, s21_wcstombs_4);
  suite_add_tcase(s, tc_wcstombs);

  return s;
}
