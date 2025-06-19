#include "test.h"

// Тест: проверка соответствия кодов ошибок
START_TEST(tests_strerror_error_code) {
  // Проверяем только стандартные коды ошибок (0-133 обычно определены в
  // системе)
  for (int i = 0; i < 20; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

// Тест: проверка с отрицательным кодом ошибки
START_TEST(tests_strerror_negative_code) {
  int i = -54;
  char *result = s21_strerror(i);

  // Проверяем формат сообщения без вызова strerror
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "Unknown error -54");
}
END_TEST

// Тест: проверка с большим кодом ошибки
START_TEST(tests_strerror_large_value) {
  int i = 134;
  char *result = s21_strerror(i);

  // Проверяем формат без вызова strerror для больших кодов
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "Unknown error 134");
}
END_TEST

// Тест: проверка неизвестной ошибки
START_TEST(tests_strerror_unknown_error) {
  int i = 135;
  char *result = s21_strerror(i);

  // Проверяем формат сообщения
  ck_assert_ptr_nonnull(result);
  ck_assert_str_eq(result, "Unknown error 135");
}
END_TEST

Suite *tests_strerror(void) {
  Suite *s = suite_create("tests_strerror");
  TCase *tc_strerror = tcase_create("tc_strerror");

  tcase_add_test(tc_strerror, tests_strerror_error_code);
  tcase_add_test(tc_strerror, tests_strerror_negative_code);
  tcase_add_test(tc_strerror, tests_strerror_large_value);
  tcase_add_test(tc_strerror, tests_strerror_unknown_error);

  suite_add_tcase(s, tc_strerror);

  return s;
}
