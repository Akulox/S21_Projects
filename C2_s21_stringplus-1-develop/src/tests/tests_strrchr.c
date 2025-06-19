#include "test.h"

START_TEST(test_strrchr_found_middle) {
  const char str[] = "Bad day!";
  char c = 'd';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_found_start) {
  const char str[] = "Bad day!";
  char c = 'B';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_found_end) {
  const char str[] = "Bad day!";
  char c = '!';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_not_found) {
  const char str[] = "Bad day!";
  char c = 'z';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_find_null) {
  const char str[] = "Bad day!";
  char c = '\0';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_empty_string) {
  const char str[] = "";
  char c = 'H';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_long_string) {
  char str[1000];
  for (int i = 0; i < 999; i++) {
    str[i] = (i == 500) ? 'x' : 'a';
  }
  str[999] = '\0';

  char c = 'x';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_multiple_occurrences) {
  const char str[] = "ahahaha";
  char c = 'a';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_only_target) {
  const char str[] = "aaaaaaaa";
  char c = 'a';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_high_ascii) {
  const char str[] = "Bad \x7F day";
  unsigned char c = '\x7F';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_last_character) {
  const char str[] = "Good!";
  char c = '!';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_not_found_with_spaces) {
  const char str[] = "    ";
  char c = 'a';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

START_TEST(test_strrchr_space) {
  const char str[] = "This is a not test string.";
  char c = ' ';

  char *result = s21_strrchr(str, c);
  ck_assert_ptr_eq(result, strrchr(str, c));
}
END_TEST

Suite *tests_strrchr(void) {
  Suite *s = suite_create("s21_strrchr_tests");
  TCase *tc_strrchr = tcase_create("tc_strrchr");

  tcase_add_test(tc_strrchr, test_strrchr_found_middle);
  tcase_add_test(tc_strrchr, test_strrchr_found_start);
  tcase_add_test(tc_strrchr, test_strrchr_found_end);
  tcase_add_test(tc_strrchr, test_strrchr_not_found);
  tcase_add_test(tc_strrchr, test_strrchr_find_null);
  tcase_add_test(tc_strrchr, test_strrchr_empty_string);
  tcase_add_test(tc_strrchr, test_strrchr_long_string);
  tcase_add_test(tc_strrchr, test_strrchr_multiple_occurrences);
  tcase_add_test(tc_strrchr, test_strrchr_only_target);
  tcase_add_test(tc_strrchr, test_strrchr_high_ascii);
  tcase_add_test(tc_strrchr, test_strrchr_last_character);
  tcase_add_test(tc_strrchr, test_strrchr_not_found_with_spaces);
  tcase_add_test(tc_strrchr, test_strrchr_space);

  suite_add_tcase(s, tc_strrchr);
  return s;
}
