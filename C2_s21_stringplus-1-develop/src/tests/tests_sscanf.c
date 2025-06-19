#include "test.h"

// Тест для базового чтения строки с ограничением длины
START_TEST(s21_sscanf_string_basic) {
  int a, b;
  char orig[50] = {0};
  char copy[50] = {0};

  a = sscanf("hello world", "%5s", orig);
  b = s21_sscanf("hello world", "%5s", copy);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(orig, copy);
}
END_TEST

// Тест для чтения нескольких строк
START_TEST(s21_sscanf_multiple_strings) {
  int a, b;
  char orig1[50] = {0};
  char orig2[50] = {0};
  char copy1[50] = {0};
  char copy2[50] = {0};

  a = sscanf("hello world", "%s %s", orig1, orig2);
  b = s21_sscanf("hello world", "%s %s", copy1, copy2);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(orig1, copy1);
  ck_assert_str_eq(orig2, copy2);
}
END_TEST

// Тест для чтения строки с пропуском начальных пробелов
START_TEST(s21_sscanf_string_with_spaces) {
  int a, b;
  char orig[50] = {0};
  char copy[50] = {0};

  a = sscanf("   hello world", "%s", orig);
  b = s21_sscanf("   hello world", "%s", copy);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(orig, copy);
}
END_TEST

// Тест для чтения строки с игнорированием ширины
START_TEST(s21_sscanf_string_width_ignore) {
  int a, b;
  char orig[50] = {0};
  char copy[50] = {0};

  a = sscanf("hello world", "%*s%s", orig);
  b = s21_sscanf("hello world", "%*s%s", copy);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(orig, copy);
}
END_TEST

// Тест для чтения строки с пустым входным буфером
START_TEST(s21_sscanf_string_empty_input) {
  int a, b;
  char orig[50] = {0};
  char copy[50] = {0};

  a = sscanf("", "%s", orig);
  b = s21_sscanf("", "%s", copy);

  ck_assert_int_eq(a, b);
}
END_TEST

// Тест для чтения строки с расположением смещения в строке
START_TEST(s21_sscanf_string_offset) {
  int a, b;
  char orig[100] = "prefix_";
  char copy[100] = "prefix_";

  a = sscanf("hello world", "%s", orig + 7);
  b = s21_sscanf("hello world", "%s", copy + 7);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(orig, copy);
}
END_TEST

// Тест для комбинации строк и чисел
START_TEST(s21_sscanf_string_with_numbers) {
  int a, b;
  char orig[50] = {0};
  int num1 = 0;
  char copy[50] = {0};
  int num2 = 0;

  a = sscanf("hello 123", "%s %d", orig, &num1);
  b = s21_sscanf("hello 123", "%s %d", copy, &num2);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(orig, copy);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(s21_sscanf_1) {
  // s specifier (non-whitespace characters)
  int a, b;
  char s1[6], s2[6];
  const char str[] = "%qwertyuiop";

  a = sscanf(str, "%%%5s", s1);
  b = s21_sscanf(str, "%%%5s", s2);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(s21_sscanf_2) {
  // c specifier (characters)
  int a, b;
  char s1[6] = {0}, s2[6] = {0};
  const char str[] = "\t\nqwertyuiop";

  a = sscanf(str, "%5c", s1);
  b = s21_sscanf(str, "%5c", s2);

  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_3) {
  // n specifier (characters read so far)
  int a, b, c, d = 0;
  char s1[20], s2[20], s3[20], s4[20];
  const char str[] = "qwertyuiop";

  a = sscanf(str, "%5s%n%5s", s1, &c, s2);
  b = s21_sscanf(str, "%5s%n%5s", s3, &d, s4);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
  ck_assert_str_eq(s1, s3);
  ck_assert_str_eq(s2, s4);
}
END_TEST

START_TEST(s21_sscanf_4) {
  int a, b;
  char s1[162], s2[162], s3[162], s4[162];
  const char str[] = "sscanf test4";

  a = sscanf(str, "%25s%25s", s1, s2);
  b = s21_sscanf(str, "%25s%25s", s3, s4);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(s1, s3);
  ck_assert_str_eq(s2, s4);
}
END_TEST

START_TEST(s21_sscanf_5) {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  int f = 0;
  const char str[] = "-12345 228";

  a = sscanf(str, "%d %d", &c, &e);
  b = s21_sscanf(str, "%d %d", &d, &f);

  ck_assert_int_eq(c, d);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_6) {
  int a, b, c, d;
  const char str[] = "12345asdf";

  a = sscanf(str, "%3d", &c);
  b = s21_sscanf(str, "%3d", &d);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_7) {
  int a, b, c, d;
  const char str[] = "123456789123456789asdf";

  a = sscanf(str, "%d", &c);
  b = s21_sscanf(str, "%d", &d);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_8) {
  long a, b, c, d;
  const char str[] = "123456789123456789asdf";

  a = sscanf(str, "%ld", &c);
  b = s21_sscanf(str, "%ld", &d);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_9) {
  int a, b;
  unsigned int c, d;
  const char str[] = "42069";

  a = sscanf(str, "%x", &c);
  b = s21_sscanf(str, "%x", &d);

  ck_assert_int_eq(a, b);
  ck_assert_uint_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_9_u) {
  const char *test_strings[] = {
      "0",                   // Minimum unsigned int
      "1",                   // Typical positive number
      "12345",               // Another typical positive number
      "4294967295",          // UINT_MAX for 32-bit
      "-1",                  // Negative input
      " 42 ",                // Leading and trailing spaces
      "42abc",               // Valid number followed by characters
      "",                    // Empty string
      "abc",                 // Non-numeric input
      "  ",                  // String with only spaces
      "2147483648",          // Larger than INT_MAX but valid unsigned
      "999999999999999999",  // Big number
      "0x1A",                // Hexadecimal representation (invalid for %u)
      "+123",                // Positive number with plus sign
      "0755",  // Octal representation (interpreted as decimal by %u)
      "1.23",  // Floating point number
      "   9876543210   ",  // Large number with leading/trailing spaces
      "\t\n42",            // Number with tab and newline
      "4294967296",        // UINT_MAX + 1 (overflow)
  };
  const size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

  for (size_t i = 0; i < num_tests; ++i) {
    const char *str = test_strings[i];
    int sscanf_ret, s21_sscanf_ret;
    unsigned int sscanf_val = 0, s21_sscanf_val = 0;

    sscanf_ret = sscanf(str, "%u", &sscanf_val);
    s21_sscanf_ret = s21_sscanf(str, "%u", &s21_sscanf_val);

    ck_assert_uint_eq(sscanf_val, s21_sscanf_val);
    ck_assert_int_eq(sscanf_ret, s21_sscanf_ret);
  }
}
END_TEST

START_TEST(s21_sscanf_10) {
  int a, b;
  double c, d;
  const char str[] = "42069";

  a = sscanf(str, "%lf", &c);
  b = s21_sscanf(str, "%lf", &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_11) {
  int a, b;
  double c, d;
  const char str[] = "42.069";

  a = sscanf(str, "%lf", &c);
  b = s21_sscanf(str, "%lf", &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_12) {
  int a, b;
  double c, d;
  const char str[] = ".42e5";

  a = sscanf(str, "%lf", &c);
  b = s21_sscanf(str, "%lf", &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_13) {
  int a, b;
  double c, d;
  const char str[] = "1.+42e5";

  a = sscanf(str, "%lf", &c);
  b = s21_sscanf(str, "%lf", &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

// specificator f d x s n c i (got)

// specificator i
START_TEST(s21_sscanf_14_i) {
  int a, b = 0;
  long int c, d = 0;
  const char str[] = "300";
  const char spec[] = "%li";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_double_eq(c, d);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_15_i) {
  int a, b;
  int c, c1, c2, c3 = 0;
  int d, d1, d2, d3 = 0;
  const char str[] = "-2147483648 2334 1540344 2147483647";
  const char spec[] = "%i %i %i %i";

  a = sscanf(str, spec, &c, &c1, &c2, &c3);
  b = s21_sscanf(str, spec, &d, &d1, &d2, &d3);

  ck_assert_double_eq(c, d);
  ck_assert_double_eq(c1, d1);
  ck_assert_double_eq(c2, d2);
  ck_assert_double_eq(c3, d3);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_16_i) {
  int a, b;
  int c, d;
  const char str[] = "0x1A";
  const char spec[] = "%i";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(n_o_k_p_bI_T_u_e) {
#define SOS                                                                 \
  "12345 12345678901235586 10623417635204152346 InfiNity iNfiNITY nAN Nan " \
  "013.1415926"
#define MIS "%hu %lu %lo %LE %lf %lg %LG %2o %3lf %3Lf %LG"

  short unsigned hu = 0;
  long unsigned lu = 0;
  long unsigned lo = 0;
  unsigned two = 0;
  long double infinity = 0;
  double fInfinity = 0;
  double gNAN = 0;
  long double gNAN2 = 0;
  double lf = 0;
  long double Lf_our = 0;
  long double Lf = 0;
  long double LG = 0;

#define LOM \
  &hu, &lu, &lo, &infinity, &fInfinity, &gNAN, &gNAN2, &two, &lf, &Lf, &LG
#define LOM1 \
  &hu, &lu, &lo, &infinity, &fInfinity, &gNAN, &gNAN2, &two, &lf, &Lf_our, &LG
#define SIDE hu, lu, lo, infinity, fInfinity, gNAN, gNAN2, two, lf, Lf, LG

  int a = sscanf(SOS, MIS, LOM);
  int b = s21_sscanf(SOS, MIS, LOM1);

  ck_assert_double_eq(Lf, Lf_our);
  ck_assert_int_eq(a, b);
}

START_TEST(s21_sscanf_123f) {
  int a, b;
  double foo, fuu;
  long double c, d;
  const char str[] = "3.1415";
  const char spec[] = "%3lf %3Lf";

  a = sscanf(str, spec, &foo, &c);
  b = s21_sscanf(str, spec, &fuu, &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_17_i) {
  int a, b;
  int c, d;
  const char str[] = "052";
  const char spec[] = "%i";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

// specificator f
START_TEST(s21_sscanf_18_f) {
  int a, b;
  float c, d;
  const char str[] = "0.";
  const char spec[] = "%f";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_19_f) {
  int a, b;
  double c, d;
  const char str[] = "0.00002315";
  const char spec[] = "%2lf";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_20_f) {
  int a, b;
  double c, d;
  const char str[] = "4.3232315";
  const char spec[] = "%10lf";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_double_eq(c, d);
}
END_TEST

START_TEST(s21_sscanf_21_ls) {
  int a, b;
  wchar_t ws1[20], ws2[20];
  const char str[] = "   asdfghjkl";
  const char spec[] = "%5ls";

  a = sscanf(str, spec, ws1);
  b = s21_sscanf(str, spec, ws2);

  ck_assert_int_eq(a, b);
  ck_assert_mem_eq(ws1, ws2, 5 * sizeof(wchar_t));
}
END_TEST

START_TEST(s21_sscanf_22_lc) {
  int a, b;
  wchar_t ws1[20], ws2[20];
  const char str[] = "asdfghjkl";
  const char spec[] = "%5lc";

  a = sscanf(str, spec, ws1);
  b = s21_sscanf(str, spec, ws2);

  ck_assert_int_eq(a, b);
  ck_assert_mem_eq(ws1, ws2, 5 * sizeof(wchar_t));
}
END_TEST

// Тестируем scanf формата %p на разные строки с правильными значениями
START_TEST(s21_sscanf_format_p_valid_values) {
  // Массив строковых значений для тестирования
  const char *valid_pointers[] = {"0x1234", "0xFFFFFFFF", "0x0", "0x123ABC"};

  for (size_t i = 0; i < sizeof(valid_pointers) / sizeof(valid_pointers[0]);
       i++) {
    void *expected_pointer = NULL, *result_pointer = NULL;

    // Читаем значение через стандартную библиотеку
    int expected_result = sscanf(valid_pointers[i], "%p", &expected_pointer);

    // Читаем значение через нашу реализацию
    int result_value = s21_sscanf(valid_pointers[i], "%p", &result_pointer);

    // Проверяем равенство адресов и возвращаемых результатов
    ck_assert_ptr_eq(expected_pointer, result_pointer);
    ck_assert_int_eq(result_value, expected_result);
  }
}
END_TEST

// Тестируем scanf формата %p на неправильные значения
START_TEST(s21_sscanf_format_p_invalid_values) {
  // Строки, содержащие некорректные данные
  const char *invalid_pointers[] = {"(nil)", "deadbeef", "Hello World!", "+42",
                                    "-42"};

  for (size_t i = 0; i < sizeof(invalid_pointers) / sizeof(invalid_pointers[0]);
       i++) {
    void *expected_pointer = NULL, *result_pointer = NULL;

    // Стандартная библиотека должна вернуть ошибку чтения
    int expected_result = sscanf(invalid_pointers[i], "%p", &expected_pointer);

    // Наша реализация также должна вернуть ошибку
    int result_value = s21_sscanf(invalid_pointers[i], "%p", &result_pointer);

    // Проверка результата и самого указателя

    ck_assert_ptr_eq(expected_pointer, result_pointer);
    ck_assert_int_eq(result_value, expected_result);
  }
}
END_TEST

// Тестируем работу форматов типа %np с ограничением ширины (%3p)
START_TEST(s21_sscanf_format_p_with_width_limitation) {
  // Массив строковых значений для тестирования
  const char *width_limited_tests[] = {
      "0x1234", "0xFFFFFFFF", "0x0", "0x123ABC", "Hello World!", "+42", "-42"};

  for (size_t i = 0;
       i < sizeof(width_limited_tests) / sizeof(width_limited_tests[0]); i++) {
    void *expected_pointer = NULL, *result_pointer = NULL;

    // Читаем значение через стандартную библиотеку с шириной
    int expected_result =
        sscanf(width_limited_tests[i], "%3p", &expected_pointer);

    // Читаем значение через нашу реализацию с шириной
    int result_value =
        s21_sscanf(width_limited_tests[i], "%3p", &result_pointer);

    // Проверяем равенство адресов и возвращаемых результатов
    ck_assert_ptr_eq(expected_pointer, result_pointer);
    ck_assert_int_eq(result_value, expected_result);
  }
}
END_TEST

START_TEST(s21_sscanf_24_f) {
  const char *test_strings[] = {
      "0.0",           // Minimum floating-point number
      "1.0",           // Typical positive floating-point number
      "123.456",       // Another typical floating-point number
      "-1.0",          // Negative floating-point number
      " 42.0 ",        // Leading and trailing spaces
      "42.0abc",       // Valid floating-point number followed by characters
      "",              // Empty string
      "abc",           // Non-numeric input
      "  ",            // String with only spaces
      "2147483648.0",  // Large floating-point number
      "99999999999999999999.0",  // Very large floating-point number
      "+123.456",              // Positive floating-point number with plus sign
      "1.23e-10",              // Scientific notation
      "   9876543210.123   ",  // Large floating-point number with
      // leading/trailing spaces
      "\t\n42.0",         // Floating-point number with tab and newline
      "3.402823466e+38",  // Approximate FLT_MAX
      "1.175494351e-38",  // Approximate FLT_MIN
      "inf",              // Infinity
      "10e",              // No exponent
  };
  const size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

  for (size_t i = 0; i < num_tests; ++i) {
    const char *str = test_strings[i];
    int sscanf_ret, s21_sscanf_ret;
    float sscanf_val = 0.0f, s21_sscanf_val = 0.0f;

    sscanf_ret = sscanf(str, "%f", &sscanf_val);
    s21_sscanf_ret = s21_sscanf(str, "%f", &s21_sscanf_val);

    ck_assert_float_eq(sscanf_val, s21_sscanf_val);
    ck_assert_int_eq(sscanf_ret, s21_sscanf_ret);
  }
}
END_TEST
//
START_TEST(s21_sscanf_25) {
  int expected, got;
  char k1[10] = {0};
  char k2[10] = {0};

  const char input[] = "Z O h:  d  V";
  const char format[] = "%c %c h: d  %c";
  expected = sscanf(input, format, &k1[0], &k1[1], &k1[2]);
  got = s21_sscanf(input, format, &k2[0], &k2[1], &k2[2]);

  ck_assert_str_eq(k1, k2);
  ck_assert_int_eq(expected, got);
}
END_TEST

START_TEST(s21_sscanf_25_1) {
  int a, b;
  int char11, char12, char21, char22, char31, char32;

  const char input[] = "-1 -2 -3";
  const char format[] = "%d %d %d";
  a = sscanf(input, format, &char11, &char21, &char31);
  b = s21_sscanf(input, format, &char12, &char22, &char32);

  // const char input[] = "Z";
  // const char format[] = "%c";
  // a = sscanf(input, format, &char1);
  // b = s21_sscanf(input, format, &char2);

  ck_assert_int_eq(char11, char12);
  ck_assert_int_eq(char21, char22);
  ck_assert_int_eq(char31, char32);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_literal_match_1) {
  int expected, got;
  char std[4] = {0}, custom[4] = {0};
  const char input[] = "A B C";
  const char format[] = "%c %c %c";

  expected = sscanf(input, format, &std[0], &std[1], &std[2]);
  got = s21_sscanf(input, format, &custom[0], &custom[1], &custom[2]);

  ck_assert_int_eq(expected, got);
  ck_assert_mem_eq(std, custom, 3);
}
END_TEST

START_TEST(s21_sscanf_literal_match_2) {
  int expected, got;
  char std[4] = {0}, custom[4] = {0};
  const char input[] = "A: B; C.";
  const char format[] = "%c: %c; %c.";

  expected = sscanf(input, format, &std[0], &std[1], &std[2]);
  got = s21_sscanf(input, format, &custom[0], &custom[1], &custom[2]);

  ck_assert_int_eq(expected, got);
  ck_assert_mem_eq(std, custom, 3);
}
END_TEST

START_TEST(s21_sscanf_literal_fail) {
  int expected, got;
  char std[4] = {0}, custom[4] = {0};
  const char input[] = "A B C";
  const char format[] = "%c-%c-%c";  // здесь ожидаются дефисы, а не пробелы

  expected = sscanf(input, format, &std[0], &std[1], &std[2]);
  got = s21_sscanf(input, format, &custom[0], &custom[1], &custom[2]);

  ck_assert_int_eq(expected, got);
  ck_assert_mem_eq(std, custom, 3);
}
END_TEST

START_TEST(s21_sscanf_literal_whitespace_variation) {
  int expected, got;
  char std[4] = {0}, custom[4] = {0};
  const char input[] = "Z O h:  d  V";
  const char format[] = "%c %c h: d  %c";

  expected = sscanf(input, format, &std[0], &std[1], &std[2]);
  got = s21_sscanf(input, format, &custom[0], &custom[1], &custom[2]);

  ck_assert_int_eq(expected, got);
  ck_assert_mem_eq(std, custom, 3);
}
END_TEST

START_TEST(s21_sscanf_26) {
  int a, b;
  int num1, num2;
  unsigned oct1, oct2;
  float f1, f2;
  const char input[] = "123 0777 3.14";
  const char format[] = "%d %o %f";

  a = sscanf(input, format, &num1, &oct1, &f1);
  b = s21_sscanf(input, format, &num2, &oct2, &f2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(num1, num2);
  ck_assert_uint_eq(oct1, oct2);
  ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(s21_sscanf_27) {
  int a, b;
  unsigned int hexOrig, hexCopy;
  void *ptrOrig, *ptrCopy;
  int nOrig, nCopy;
  const char input[] = "0xFF 0x12345 ";
  const char format[] = "%x %p %n";

  a = sscanf(input, format, &hexOrig, &ptrOrig, &nOrig);
  b = s21_sscanf(input, format, &hexCopy, &ptrCopy, &nCopy);

  ck_assert_uint_eq(hexOrig, hexCopy);
  ck_assert_ptr_eq(ptrOrig, ptrCopy);
  ck_assert_int_eq(nOrig, nCopy);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_28) {
  int a, b;
  char str1[100], str2[100];
  int num1, num2;
  const char input[] = "hello123world";
  const char format[] = "%5s%3d";

  a = sscanf(input, format, str1, &num1);
  b = s21_sscanf(input, format, str2, &num2);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(s21_sscanf_29) {
  int a, b;
  int num1, num2, num3, num4;
  char char1, char2;
  const char input[] = "100 A 200 B";
  const char format[] = "%d %*c %d %c";

  a = sscanf(input, format, &num1, &num2, &char1);
  b = s21_sscanf(input, format, &num3, &num4, &char2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(num1, num3);
  ck_assert_int_eq(num2, num4);
  ck_assert_int_eq(char1, char2);
}
END_TEST

START_TEST(s21_sscanf_30) {
  int a, b;
  int num1, num2;
  const char input[] = "";
  const char format[] = "%d";

  a = sscanf(input, format, &num1);
  b = s21_sscanf(input, format, &num2);

  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_31) {
  int a, b;
  int num1, num2;
  float f1, f2;
  const char input[] = "   42    3.14   ";
  const char format[] = "%d %f";

  a = sscanf(input, format, &num1, &f1);
  b = s21_sscanf(input, format, &num2, &f2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(num1, num2);
  ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(s21_sscanf_32) {
  int a, b;
  float f1, f2;
  const char input[] = "NAN";
  const char format[] = "%f";

  a = sscanf(input, format, &f1);
  b = s21_sscanf(input, format, &f2);

  ck_assert(isnan(f1) == isnan(f2));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_sscanf_33) {
  const char *test_strings = "0xdeadbeef 12";
  const char *test_formats = "%*p %d";

  int orig = 0;
  int copy = 0;
  int orig_value = 0;
  int copy_value = 0;

  orig = sscanf(test_strings, test_formats, &orig_value);
  copy = s21_sscanf(test_strings, test_formats, &copy_value);

  ck_assert_int_eq(orig_value, copy_value);
  ck_assert_int_eq(orig, copy);
}
END_TEST

START_TEST(s21_sscanf_34) {
  const char *test_strings = "Hello 34";
  const char *test_formats = "%*5s %d";

  int orig = 0;
  int copy = 0;
  int orig_value = 0;
  int copy_value = 0;

  orig = sscanf(test_strings, test_formats, &orig_value);
  copy = s21_sscanf(test_strings, test_formats, &copy_value);

  ck_assert_int_eq(orig_value, copy_value);
  ck_assert_int_eq(orig, copy);
}
END_TEST

START_TEST(s21_sscanf_35) {
  const char *test_strings = "182 56";
  const char *test_formats = "%*d %d";

  int orig = 0;
  int copy = 0;
  int orig_value = 0;
  int copy_value = 0;

  orig = sscanf(test_strings, test_formats, &orig_value);
  copy = s21_sscanf(test_strings, test_formats, &copy_value);

  ck_assert_int_eq(orig_value, copy_value);
  ck_assert_int_eq(orig, copy);
}
END_TEST

START_TEST(s21_sscanf_36) {
  const char *test_strings = "10.005 78";
  const char *test_formats = "%*f  %d";

  int orig = 0;
  int copy = 0;
  int orig_value = 0;
  int copy_value = 0;

  orig = sscanf(test_strings, test_formats, &orig_value);
  copy = s21_sscanf(test_strings, test_formats, &copy_value);

  ck_assert_int_eq(orig_value, copy_value);
  ck_assert_int_eq(orig, copy);
}
END_TEST

START_TEST(s21_sscanf_37) {
  const char *test_strings = "10.005e-3 90";
  const char *test_formats = "%*f  %d";

  int orig = 0;
  int copy = 0;
  int orig_value = 0;
  int copy_value = 0;

  orig = sscanf(test_strings, test_formats, &orig_value);
  copy = s21_sscanf(test_strings, test_formats, &copy_value);

  ck_assert_int_eq(orig_value, copy_value);
  ck_assert_int_eq(orig, copy);
}
END_TEST

// Тест для спецификатора %o (восьмеричные числа)
START_TEST(s21_sscanf_o) {
  int a, b;
  unsigned int oct1, oct2;
  const char str[] = "0123";

  a = sscanf(str, "%o", &oct1);
  b = s21_sscanf(str, "%o", &oct2);

  ck_assert_int_eq(a, b);
  ck_assert_uint_eq(oct1, oct2);
}
END_TEST

// Тест для спецификатора %e (научная нотация)
START_TEST(s21_sscanf_e) {
  int a, b;
  float c, d;
  const char str[] = "1.23e4";

  a = sscanf(str, "%e", &c);
  b = s21_sscanf(str, "%e", &d);

  ck_assert_int_eq(a, b);
  ck_assert_float_eq(c, d);
}
END_TEST

// Тест для спецификатора %g (выбор между %f и %e)
START_TEST(s21_sscanf_g) {
  int a, b;
  float c, d;
  const char str[] = "0.0123";

  a = sscanf(str, "%g", &c);
  b = s21_sscanf(str, "%g", &d);

  ck_assert_int_eq(a, b);
  ck_assert_float_eq(c, d);
}
END_TEST

// Тест для спецификатора %X (шестнадцатеричные числа с заглавными буквами)
START_TEST(s21_sscanf_X) {
  int a, b;
  unsigned int hex1, hex2;
  const char str[] = "ABCDEF";

  a = sscanf(str, "%X", &hex1);
  b = s21_sscanf(str, "%X", &hex2);

  ck_assert_int_eq(a, b);
  ck_assert_uint_eq(hex1, hex2);
}
END_TEST

// Тест для спецификатора %* (игнорирование ввода)
START_TEST(s21_sscanf_ignore) {
  int a, b;
  int num1, num2;
  const char str[] = "123 456";

  a = sscanf(str, "%*d %d", &num1);
  b = s21_sscanf(str, "%*d %d", &num2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(num1, num2);
}
END_TEST

// Тест для комбинации различных спецификаторов
START_TEST(s21_sscanf_combined) {
  int a, b;
  int int1, int2;
  float float1, float2;
  char str1[10], str2[10];

  const char input[] = "42 3.14 hello";
  const char format[] = "%d %f %s";
  a = sscanf(input, format, &int1, &float1, str1);
  b = s21_sscanf(input, format, &int2, &float2, str2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(int1, int2);
  ck_assert_float_eq(float1, float2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Тест для длины h (короткие целые)
START_TEST(s21_sscanf_h) {
  int a, b;
  short int s1, s2;
  const char str[] = "32767";  // SHRT_MAX

  a = sscanf(str, "%hd", &s1);
  b = s21_sscanf(str, "%hd", &s2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(s1, s2);
}
END_TEST

// Тест для длины l (длинные целые)
START_TEST(s21_sscanf_l) {
  int a, b;
  long int l1, l2;
  const char str[] = "2147483648";  // > INT_MAX

  a = sscanf(str, "%ld", &l1);
  b = s21_sscanf(str, "%ld", &l2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(l1, l2);
}
END_TEST

// Тест для длины L (длинные double)
START_TEST(s21_sscanf_L) {
  int a, b;
  long double ld1, ld2;
  const char str[] = "1.234567890123456789";

  a = sscanf(str, "%Lf", &ld1);
  b = s21_sscanf(str, "%Lf", &ld2);

  ck_assert_int_eq(a, b);
  ck_assert_ldouble_eq(ld1, ld2);
}
END_TEST

// Тест для ширины поля
START_TEST(s21_sscanf_width) {
  int a, b;
  int i1, i2;
  const char str[] = "12345";

  a = sscanf(str, "%3d", &i1);
  b = s21_sscanf(str, "%3d", &i2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(i1, i2);
}
END_TEST

// Тест для спецификатора %f (числа с плавающей точкой)
START_TEST(s21_sscanf_f) {
  int a, b;
  float c, d;
  const char str[] = "3.14";
  const char spec[] = "%f";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_float_eq(c, d);
}
END_TEST

// Тест для спецификатора %f с отрицательным числом
START_TEST(s21_sscanf_f_negative) {
  int a, b;
  float c, d;
  const char str[] = "-42.5";
  const char spec[] = "%f";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_float_eq(c, d);
}
END_TEST

// Тест для спецификатора %f с научной нотацией
START_TEST(s21_sscanf_f_scientific) {
  int a, b;
  float c, d;
  const char str[] = "1.23e-2";
  const char spec[] = "%f";

  a = sscanf(str, spec, &c);
  b = s21_sscanf(str, spec, &d);

  ck_assert_int_eq(a, b);
  ck_assert_float_eq(c, d);
}
END_TEST

// Тест для спецификатора %p (указатели)
START_TEST(s21_sscanf_p) {
  int a, b;
  void *p1, *p2;
  const char str[] = "0xABCDEF";
  const char spec[] = "%p";

  a = sscanf(str, spec, &p1);
  b = s21_sscanf(str, spec, &p2);

  ck_assert_int_eq(a, b);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

Suite *tests_sscanf(void) {
  Suite *s = suite_create("s21_sscanf_tests");

  TCase *tc_sscanf = tcase_create("tc_sscanf");

  tcase_add_test(tc_sscanf, s21_sscanf_string_basic);
  tcase_add_test(tc_sscanf, s21_sscanf_multiple_strings);
  tcase_add_test(tc_sscanf, s21_sscanf_string_with_spaces);
  tcase_add_test(tc_sscanf, s21_sscanf_string_width_ignore);
  tcase_add_test(tc_sscanf, s21_sscanf_string_empty_input);
  tcase_add_test(tc_sscanf, s21_sscanf_string_offset);
  tcase_add_test(tc_sscanf, s21_sscanf_string_with_numbers);
  tcase_add_test(tc_sscanf, s21_sscanf_1);
  tcase_add_test(tc_sscanf, s21_sscanf_2);
  tcase_add_test(tc_sscanf, s21_sscanf_3);
  tcase_add_test(tc_sscanf, s21_sscanf_4);
  tcase_add_test(tc_sscanf, s21_sscanf_5);
  tcase_add_test(tc_sscanf, s21_sscanf_6);
  tcase_add_test(tc_sscanf, s21_sscanf_7);
  tcase_add_test(tc_sscanf, s21_sscanf_8);
  tcase_add_test(tc_sscanf, s21_sscanf_9);
  tcase_add_test(tc_sscanf, s21_sscanf_9_u);
  tcase_add_test(tc_sscanf, s21_sscanf_10);
  tcase_add_test(tc_sscanf, s21_sscanf_11);
  tcase_add_test(tc_sscanf, s21_sscanf_12);
  tcase_add_test(tc_sscanf, s21_sscanf_13);
  tcase_add_test(tc_sscanf, s21_sscanf_14_i);
  tcase_add_test(tc_sscanf, s21_sscanf_15_i);
  tcase_add_test(tc_sscanf, s21_sscanf_16_i);
  tcase_add_test(tc_sscanf, s21_sscanf_17_i);
  tcase_add_test(tc_sscanf, s21_sscanf_18_f);
  tcase_add_test(tc_sscanf, s21_sscanf_19_f);
  tcase_add_test(tc_sscanf, s21_sscanf_20_f);
  tcase_add_test(tc_sscanf, s21_sscanf_21_ls);
  tcase_add_test(tc_sscanf, s21_sscanf_22_lc);
  tcase_add_test(tc_sscanf, s21_sscanf_format_p_valid_values);
  tcase_add_test(tc_sscanf, s21_sscanf_format_p_invalid_values);
  tcase_add_test(tc_sscanf, s21_sscanf_format_p_with_width_limitation);
  tcase_add_test(tc_sscanf, n_o_k_p_bI_T_u_e);
  tcase_add_test(tc_sscanf, s21_sscanf_123f);
  tcase_add_test(tc_sscanf, s21_sscanf_24_f);
  tcase_add_test(tc_sscanf, s21_sscanf_25);
  tcase_add_test(tc_sscanf, s21_sscanf_25_1);
  tcase_add_test(tc_sscanf, s21_sscanf_26);
  tcase_add_test(tc_sscanf, s21_sscanf_27);
  tcase_add_test(tc_sscanf, s21_sscanf_28);
  tcase_add_test(tc_sscanf, s21_sscanf_29);
  tcase_add_test(tc_sscanf, s21_sscanf_30);
  tcase_add_test(tc_sscanf, s21_sscanf_31);
  tcase_add_test(tc_sscanf, s21_sscanf_32);
  tcase_add_test(tc_sscanf, s21_sscanf_33);
  tcase_add_test(tc_sscanf, s21_sscanf_34);
  tcase_add_test(tc_sscanf, s21_sscanf_35);
  tcase_add_test(tc_sscanf, s21_sscanf_36);
  tcase_add_test(tc_sscanf, s21_sscanf_37);
  tcase_add_test(tc_sscanf, s21_sscanf_literal_match_1);
  tcase_add_test(tc_sscanf, s21_sscanf_literal_match_2);
  tcase_add_test(tc_sscanf, s21_sscanf_literal_fail);
  tcase_add_test(tc_sscanf, s21_sscanf_literal_whitespace_variation);

  // Тесты для чисел с плавающей точкой
  tcase_add_test(tc_sscanf, s21_sscanf_f);
  tcase_add_test(tc_sscanf, s21_sscanf_f_negative);
  tcase_add_test(tc_sscanf, s21_sscanf_f_scientific);

  // Тесты для указателей и сложных форматных строк
  tcase_add_test(tc_sscanf, s21_sscanf_p);

  // Тесты для дополнительных спецификаторов
  tcase_add_test(tc_sscanf, s21_sscanf_o);
  tcase_add_test(tc_sscanf, s21_sscanf_e);
  tcase_add_test(tc_sscanf, s21_sscanf_g);
  tcase_add_test(tc_sscanf, s21_sscanf_X);

  // Тесты для опций и комбинаций
  tcase_add_test(tc_sscanf, s21_sscanf_ignore);
  tcase_add_test(tc_sscanf, s21_sscanf_combined);

  // Тесты для модификаторов длины
  tcase_add_test(tc_sscanf, s21_sscanf_h);
  tcase_add_test(tc_sscanf, s21_sscanf_l);
  tcase_add_test(tc_sscanf, s21_sscanf_L);

  // Тесты для ширины
  tcase_add_test(tc_sscanf, s21_sscanf_width);

  suite_add_tcase(s, tc_sscanf);

  return s;
}
