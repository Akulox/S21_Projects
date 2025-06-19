#include "test.h"

// tests for specificator "c"
START_TEST(s21_sprintf_c_1) {
  char got[100];
  char expected[100];
  const char *str = "%c";
  ck_assert_int_eq(s21_sprintf(got, str, 'A'), sprintf(expected, str, 'A'));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_2) {
  char got[100];
  char expected[100];
  const char *str = "%-5c%c%c%c%c HeLp Mee!";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(got, str, val, 'B', 'C', 'D', 'E'),
                   sprintf(expected, str, val, 'B', 'C', 'D', 'E'));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_3) {
  char got[100];
  char expected[100];
  const char *str = "%c space_syms!";
  char val = '\t';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_4) {
  char got[100];
  char expected[100];
  const char *str = "%c space_syms!";
  char val = '\0';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_5) {
  char got[100];
  char expected[100];
  const char *str = "%c space_syms!";
  char val = '\n';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_6) {
  char got[100];
  char expected[100];
  const char *str = "%c%c %c  %c space_syms!";
  char val = '#';
  ck_assert_int_eq(s21_sprintf(got, str, val, 'h', 'e', 'k'),
                   sprintf(expected, str, val, 'h', 'e', 'k'));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_7) {
  char got[100];
  char expected[100];
  const char *str = "%.653534c";
  const char val = '#';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_8) {
  char got[100];
  char expected[100];
  const char *str = "%11c";
  const char val = '#';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_9) {
  char got[100];
  char expected[100];
  const char *str = "%10c";
  const char val = '#';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_10) {
  char got[100];
  char expected[100];
  const char *str = "%lc";
  unsigned long val = L'A';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_11) {
  char got[100];
  char expected[100];
  const char *str = "%-4c";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_c_13) {
  char got[100];
  char expected[100];
  const char *str = "%04c";
  char val = 'A';
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST
//
// // tests for specificator "d"
START_TEST(s21_sprintf_d_1) {
  char got[100];
  char expected[100];
  const char *str = "%d";
  int num = 1;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_2) {
  char got[100];
  char expected[100];
  const char *str = "%d";
  int num = -53;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_3) {
  char got[100];
  char expected[100];
  const char *str = "%5d";
  int num = 4;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_4) {
  char got[100];
  char expected[100];
  const char *str = "%011d";
  int num = 4;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_5) {
  char got[100];
  char expected[100];
  const char *str = "%5d";
  int num = -4;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_6) {
  char got[100];
  char expected[100];
  const char *str = "%.5d";
  int num = 4;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_7) {
  char got[100];
  char expected[100];
  const char *str = "%.5d";
  int num = -4;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_8) {
  char got[100];
  char expected[100];
  const char *str = "%13.5d";
  int num = 14;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_9) {
  char got[100];
  char expected[100];
  const char *str = "%d";
  int num = 2147483647;  // max_int

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_10) {
  char got[100];
  char expected[100];
  const char *str = "%d";
  int num = -2147483648;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_11) {
  char got[100];
  char expected[100];
  const char *str = "%010d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_12) {
  char got[100];
  char expected[100];
  const char *str = "%+10d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_13) {
  char got[100];
  char expected[100];
  const char *str = "%+010d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_14) {
  char got[200];
  char expected[200];
  const char *str = "%.11d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_15) {
  char got[100];
  char expected[100];
  const char *str = "%.d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_16) {
  char got[100];
  char expected[100];
  const char *str = "% d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_17) {
  char got[100];
  char expected[100];
  const char *str = "-% -d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_18) {
  char got[100];
  char expected[100];
  const char *str = "-% +d";
  int num = 5475;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_19) {
  char got[100];
  char expected[100];
  const char *str = "%-17d";
  int num = 5475;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_20) {
  char got[100];
  char expected[100];
  const char *str = "%-17.5d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_21) {
  char got[100];
  char expected[100];
  const char *str = "%-+17.5d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_22) {
  char got[100];
  char expected[100];
  const char *str = "%-+17.5d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_23) {
  char got[100];
  char expected[100];
  const char *str = "%+-17.5d";
  int num = 54;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_d_24) {
  char got[100];
  char expected[100];
  const char *str = "%+ld";
  long int num = 2147483647;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST
// // tests for specificator "i"
START_TEST(s21_sprintf_i_1) {
  char got[100];
  char expected[100];
  const char *str = "%i";
  int num = 1;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_2) {
  char got[100];
  char expected[100];
  const char *str = "%i%i%i";

  ck_assert_int_eq((s21_sprintf(got, str, -999, 41, 1314324)),
                   sprintf(expected, str, -999, 41, 1314324));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_3) {
  char got[100];
  char expected[100];
  const char *str = "%i";
  int s21_val = -2147483648;  //?
  int val = -2147483648;      //?
  ck_assert_int_eq((s21_sprintf(got, str, s21_val)),
                   sprintf(expected, str, val));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_4) {
  char got[100];
  char expected[100];
  const char *str = "%i";

  ck_assert_int_eq((s21_sprintf(got, str, 2147483647)),
                   sprintf(expected, str, 2147483647));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_5) {
  char got[100];
  char expected[100];
  const char *str = "%i";

  ck_assert_int_eq((s21_sprintf(got, str, 2147483647)),
                   sprintf(expected, str, 2147483647));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_6) {
  char got[100];
  char expected[100];
  const char *str = "%i";

  ck_assert_int_eq((s21_sprintf(got, str, (int)'a')),
                   sprintf(expected, str, (int)'a'));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_7) {
  char got[100];
  char expected[100];

  const char *str = "%0.*i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, 5, val),
                   sprintf(expected, str, 5, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_8) {
  char got[100];
  char expected[100];

  const char *str = "%0.*i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, 10, val),
                   sprintf(expected, str, 10, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_9) {
  char got[100];
  char expected[100];

  const char *str = "%0.10i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_10) {
  char got[100];
  char expected[100];

  const char *str = "%.i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_11) {
  char got[100];
  char expected[100];

  const char *str = "%10.10i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_12) {
  char got[100];
  char expected[100];

  const char *str = "%10.8i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_13) {
  char got[100];
  char expected[100];

  const char *str = "%15.3i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_14) {
  char got[100];
  char expected[100];

  const char *str = "%8.3i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_15) {
  char got[100];
  char expected[100];

  const char *str = "%-+8.3i";
  int val = 73;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_16) {
  char got[100];
  char expected[100];

  const char *str = "%hi";
  short int val = 32767;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_17) {
  char got[100];
  char expected[100];

  const char *str = "%hi";
  short int val = -32768;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_18) {
  char got[100];
  char expected[100];

  const char *str = "%hi";
  short int val = 0;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_19) {
  char got[100];
  char expected[100];

  const char *str = "%.6hi";
  short int val = -155;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_20) {
  char got[100];
  char expected[100];

  const char *str = "%li";
  long val = 2147483647;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_21) {
  char got[100];
  char expected[100];

  const char *str = "%+li";
  long val = 2147483647;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_22) {
  char got[100];
  char expected[100];

  const char *str = "%14.3li";
  long val = 2147483647;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_23) {
  char got[100];
  char expected[100];

  const char *str = "%3.11li";
  long val = 2147483647;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_i_24) {
  char got[100];
  char expected[100];

  const char *str = "%+3.11li";
  long val = 2147483647;
  ck_assert_int_eq(s21_sprintf(got, str, val), sprintf(expected, str, val));

  ck_assert_str_eq(got, expected);
}
END_TEST
// // tests for specificator "e"
START_TEST(s21_sprintf_e_1) {
  char got[100];
  char expected[100];
  const char *str = "%e";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_2) {
  char got[100];
  char expected[100];
  const char *str = "%Le";
  long double num = 654.4745;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_3) {
  char got[100];
  char expected[100];
  const char *str = "%.6e";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_4) {
  char got[100];
  char expected[100];
  const char *str = "%.10e";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_5) {
  char got[100];
  char expected[100];
  const char *str = "%10e";
  double num = 654.5;
  // s21_sprintf(got, str, num);
  // sprintf(expected, str, num);

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_6) {
  char got[100];
  char expected[100];
  const char *str = "%10.5e";
  double num = 654.5;
  s21_sprintf(got, str, num);
  sprintf(expected, str, num);

  // ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str,
  // num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_7) {
  char got[100];
  char expected[100];
  const char *str = "%5.10e";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_8) {
  char got[100];
  char expected[100];
  const char *str = "%11e";
  double num = 654.5;

  s21_sprintf(got, str, num);
  sprintf(expected, str, num);

  // ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str,
  // num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_9) {
  char got[100];
  char expected[100];
  const char *str = "%.11e";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_10) {
  char got[100];
  char expected[100];
  const char *str = "%+.11e";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_11) {
  char got[100];
  char expected[100];
  const char *str = "%11.1e";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_12) {
  char got[100];
  char expected[100];
  const char *str = "%11.1e";
  double num = -654.115;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_13) {
  char got[100];
  char expected[100];
  const char *str = "%-11.1e";
  double num = -654.115;

  s21_sprintf(got, str, num);
  sprintf(expected, str, num);

  // ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str,
  // num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_14) {
  char got[100];
  char expected[100];
  const char *str = "%-11.1e";
  double num = -654.;

  s21_sprintf(got, str, num);
  sprintf(expected, str, num);

  // ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str,
  // num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_15) {
  char got[100];
  char expected[100];
  const char *str = "%.e";
  double num = 654.;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_16) {
  char got[100];
  char expected[100];
  const char *str = "%.e";
  double num = 654;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_17) {
  char got[100];
  char expected[100];
  const char *str = "%e";
  double num = 654.;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_18) {
  char got[100];
  char expected[100];
  const char *str = "%.11e";
  double num = 654.;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_19) {
  char got[100];
  char expected[100];
  const char *str = "%.11e";
  double num = 123456789.987654321;
  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_20) {
  char got[100];
  char expected[100];
  const char *str = "%e";
  double num = 0.000012345;
  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_e_21) {
  char got[100];
  char expected[100];
  const char *str = "%e";
  double num = 0.0;
  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST
// // tests for specificator "E"
START_TEST(s21_sprintf_E_1) {
  char got[100];
  char expected[100];
  const char *str = "%E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_2) {
  char got[100];
  char expected[100];
  const char *str = "%LE";
  long double num = 654.4745;

  ck_assert_int_eq((s21_sprintf(got, str, num)), sprintf(expected, str, num));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_3) {
  char got[100];
  char expected[100];
  const char *str = "%.6E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_4) {
  char got[100];
  char expected[100];
  const char *str = "%.10E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_5) {
  char got[100];
  char expected[100];
  const char *str = "%10E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_6) {
  char got[100];
  char expected[100];
  const char *str = "%10.5E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_7) {
  char got[100];
  char expected[100];
  const char *str = "%5.10E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_8) {
  char got[100];
  char expected[100];
  const char *str = "%11E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_9) {
  char got[100];
  char expected[100];
  const char *str = "%.11E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_10) {
  char got[100];
  char expected[100];
  const char *str = "%+.11E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_11) {
  char got[100];
  char expected[100];
  const char *str = "%11.1E";
  double num = 654.5;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_12) {
  char got[100];
  char expected[100];
  const char *str = "%11.1E";
  double num = -654.115;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_13) {
  char got[100];
  char expected[100];
  const char *str = "%-11.1E";
  double num = -654.115;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_14) {
  char got[100];
  char expected[100];
  const char *str = "%-11.1E";
  double num = -654.;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_15) {
  char got[100];
  char expected[100];
  const char *str = "%.E";
  double num = 654.;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_16) {
  char got[100];
  char expected[100];
  const char *str = "%.E";
  double num = 654;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_17) {
  char got[100];
  char expected[100];
  const char *str = "%E";
  double num = 654.;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_18) {
  char got[100];
  char expected[100];
  const char *str = "%.11E";
  double num = 654.;

  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_19) {
  char got[100];
  char expected[100];
  const char *str = "%.11E";
  double num = 123456789.987654321;
  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_20) {
  char got[100];
  char expected[100];
  const char *str = "%E";
  double num = 0.000012345;
  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_21) {
  char got[100];
  char expected[100];
  const char *str = "%E";
  double num = 0.0;
  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_E_22) {
  char got[100];
  char expected[100];
  const char *str = "%11.10E";
  double num = 5453.435430;
  ck_assert_int_eq((s21_sprintf(got, str, num)), (sprintf(expected, str, num)));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(simple_near_0e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%e";
  double val = 2;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(simple_0e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%e";
  double val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(simple_0_with_dot) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.0e";
  double val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(simple_e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%e";
  double val = 123.271;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(long_e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%Le";
  long double val = 123.271;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.0Le";
  long double val = 123.271;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_precision_e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.Le";
  long double val = 123.000123124;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(big_precision_e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.11Le";
  long double val = -123.00012124;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.11Le%e%e%e";
  long double val = -123.00012124;
  ck_assert_int_eq(s21_sprintf(str1, format, val, 222.2222, 666., -555.125),
                   sprintf(str2, format, val, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(manyEe) {
  char str1[1024];
  char str2[1024];

  const char *format = "%.11Le%e%E%E";
  long double val = -123.00012124;
  ck_assert_int_eq(s21_sprintf(str1, format, val, 222.2222, 666., -555.125),
                   sprintf(str2, format, val, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(int_e) {
  char str1[1024];
  char str2[1024];

  const char *format = "%Le";
  long double val = -123123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_many) {
  char str1[1024];
  char str2[1024];
  const char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
//
// // tests for specificator "f"
START_TEST(s21_sprintf_f_1) {
  char got[100];
  char expected[100];
  const char *str = "%f%f";

  ck_assert_int_eq((s21_sprintf(got, str, 5.4324, 6546546.4)),
                   sprintf(expected, str, 5.4324, 6546546.4));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_2) {
  char got[100];
  char expected[100];
  const char *str = "%f";
  // s21_sprintf(got, str, -42.0);
  // sprintf(expected, str, -42.0);
  ck_assert_int_eq((s21_sprintf(got, str, -42.0)),
                   sprintf(expected, str, -42.0));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_3) {
  char got[100];
  char expected[100];
  const char *str = "%.6Lf";
  long double input = 9591953915549.53151351131;
  // s21_sprintf(got, str, input);
  // sprintf(expected, str, input);

  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_4) {
  char got[100];
  char expected[100];
  const char *str = "%f";

  ck_assert_int_eq((s21_sprintf(got, str, 0.)), sprintf(expected, str, 0.));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_5) {
  char got[100];
  char expected[100];
  const char *str = "%.2f";

  ck_assert_int_eq((s21_sprintf(got, str, 54.6453)),
                   sprintf(expected, str, 54.6453));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_6) {
  char got[100];
  char expected[100];
  const char *str = "%.3f";

  ck_assert_int_eq((s21_sprintf(got, str, 1.2)), sprintf(expected, str, 1.2));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_7) {
  char got[100];
  char expected[100];
  const char *str = "%f";

  ck_assert_int_eq((s21_sprintf(got, str, NAN)), sprintf(expected, str, NAN));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_8) {
  char got[100];
  char expected[100];
  const char *str = "%f";
  int res1 = s21_sprintf(got, str, INFINITY);
  int res2 = sprintf(expected, str, INFINITY);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_f_9) {
  char got[100];
  char expected[100];
  const char *str = "%.3f";

  ck_assert_int_eq((s21_sprintf(got, str, 0.00)), sprintf(expected, str, 0.00));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_10) {
  char got[100];
  char expected[100];
  const char *str = "%12.10f";

  ck_assert_int_eq((s21_sprintf(got, str, 12.14)),
                   sprintf(expected, str, 12.14));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_11) {
  char got[100];
  char expected[100];
  const char *str = "%+*.*f";
  double input = 10.0;
  ck_assert_int_eq((s21_sprintf(got, str, 14, 11, input)),
                   sprintf(expected, str, 14, 11, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_12) {
  char got[100];
  char expected[100];
  const char *str = "|%-*.*f|";
  double input = 10.0;
  ck_assert_int_eq((s21_sprintf(got, str, 14, 11, input)),
                   sprintf(expected, str, 14, 11, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_13) {
  char got[100];
  char expected[100];
  const char *str = "|%*.*f|";
  double input = 10.0;
  ck_assert_int_eq((s21_sprintf(got, str, 14, 11, input)),
                   sprintf(expected, str, 14, 11, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_14) {
  char got[100];
  char expected[100];
  const char *str = "|%.Lf|";
  long double input = 95919539159.;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_15) {
  char got[100];
  char expected[100];
  const char *str = "|%.Lf|";
  long double input = 95919539159.53151351131;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_16) {
  char got[100];
  char expected[100];
  const char *str = "|%Lf|";
  long double input = 95919539159.;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_17) {
  char got[100];
  char expected[100];
  const char *str = "%Lf %f %f %f %f";
  long double input = 95919539159.;
  double input2 = 4442.424;
  double input3 = 0.424;
  double input4 = 0.;
  double input5 = 0.0;
  ck_assert_int_eq(
      (s21_sprintf(got, str, input, input2, input3, input4, input5)),
      sprintf(expected, str, input, input2, input3, input4, input5));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_18) {
  char got[100];
  char expected[100];

  const char *str = "%Lf %f %17.11f %4.0f %0.11f";
  long double input = 95919539159.;
  double input2 = 4442.424;
  double input3 = 0.424;
  double input4 = 0.;
  double input5 = 0.0;

  ck_assert_int_eq(
      (s21_sprintf(got, str, input, input2, input3, input4, input5)),
      sprintf(expected, str, input, input2, input3, input4, input5));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_f_19) {
  char got[100];
  char expected[100];
  const char *str = "%*.*f";
  double input = 645.5;
  s21_sprintf(got, str, -12, -10, input);
  sprintf(expected, str, -12, -10, input);

  // ck_assert_int_eq((s21_sprintf(got, str, -12, -10, input)),
  //                  sprintf(expected, str, -12, -10, input));
  ck_assert_str_eq(got, expected);
}
END_TEST
// // tests for specificator "g"
START_TEST(s21_sprintf_g_1) {
  char got[100];
  char expected[100];
  const char *str = "%g";
  double input = 5.040003;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_2) {
  char got[100];
  char expected[100];
  const char *str = "%g";
  double input = 0.000123456;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_3) {
  char got[100];
  char expected[100];
  const char *str = "%.4g";
  double input = 0.000123456;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_4) {
  char got[100];
  char expected[100];
  const char *str = "\n(%g) (%g) (%g)\n";
  double input2 = 999.87654321;
  double input3 = 316.4214;
  double input4 = 315.4214;
  int res1 = s21_sprintf(got, str, input2, input3, input4);
  int res2 = sprintf(expected, str, input2, input3, input4);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_5) {
  char got[100];
  char expected[100];
  const char *str = "%+-11g";
  double input = -0.000000652;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_6) {
  char got[100];
  char expected[100];
  const char *str = "%.3g";
  double input = 0.000000652;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_7) {
  char got[100];
  char expected[100];
  const char *str = "%.10g";
  double input = 0.652;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_8) {
  char got[100];
  char expected[100];
  const char *str = "%.0g";
  double input = 0.001;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_g_9) {
  char got[100];
  char expected[100];
  const char *str = "%Lg";
  long double input = 6646641.682334;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST
// // tests for specificator "G"
START_TEST(s21_sprintf_G_1) {
  char got[100];
  char expected[100];
  const char *str = "%G";

  ck_assert_int_eq((s21_sprintf(got, str, 5.040003)),
                   sprintf(expected, str, 5.040003));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_G_2) {
  char got[100];
  char expected[100];
  const char *str = "%G";
  double input = 0.000123456;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_G_3) {
  char got[100];
  char expected[100];
  const char *str = "%G";
  double input = 0.000123456;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_G_4) {
  char got[100];
  char expected[100];
  const char *str = "%G";
  double input = 0.000123456;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_G_5) {
  char got[100];
  char expected[100];
  const char *str = "%+-11G";
  double input = -0.000000652;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_G_6) {
  char got[100];
  char expected[100];
  const char *str = "%.3G";
  double input = 0.000000652;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_G_7) {
  char got[100];
  char expected[100];
  const char *str = "%.10G";
  double input = 0.652;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_G_8) {
  char got[100];
  char expected[100];
  const char *str = "%.0G";
  double input = 0.001;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_G_9) {
  char got[100];
  char expected[100];
  const char *str = "%LG";
  long double input = 6646641.682334;
  int res1 = s21_sprintf(got, str, input);
  int res2 = sprintf(expected, str, input);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST
// // tests for specificator "o"
START_TEST(s21_sprintf_o_1) {
  char got[100];
  char expected[100];
  const char *str = "%o";

  ck_assert_int_eq((s21_sprintf(got, str, 53665)),
                   sprintf(expected, str, 53665));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_o_2) {
  char got[100];
  char expected[100];
  const char *str = "%o";

  ck_assert_int_eq((s21_sprintf(got, str, 0)), sprintf(expected, str, 0));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_o_3) {
  char got[100];
  char expected[100];
  const char *str = "%#3o";

  ck_assert_int_eq((s21_sprintf(got, str, 53665)),
                   sprintf(expected, str, 53665));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_o_4) {
  char got[100];
  char expected[100];
  const char *str = "%lo";

  ck_assert_int_eq((s21_sprintf(got, str, 53665)),
                   sprintf(expected, str, (unsigned long)53665));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_o_5) {
  char got[100];
  char expected[100];
  const char *str = "%ho";

  ck_assert_int_eq((s21_sprintf(got, str, 53665)),
                   sprintf(expected, str, (unsigned short)53665));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_o_6) {
  char got[100];
  char expected[100];
  const char *str = "%lo";

  ck_assert_int_eq((s21_sprintf(got, str, 2147483647)),
                   sprintf(expected, str, (unsigned long)2147483647));
  ck_assert_str_eq(got, expected);
}
END_TEST

// tests for specificator "s"
START_TEST(s21_sprintf_s_1) {
  char got[100];
  char expected[100];
  const char *str = "%s";
  char *input =
      "The quick brown fox jumps over the lazy dog ARGDFL 123456789 ?!;;№:?()";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_2) {
  char got[100];
  char expected[100];
  const char *str = "%.5s";
  char *input =
      "The quick brown fox jumps over the lazy dog ARGDFL 123456789 ?!;;№:?()";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_3) {
  char got[100];
  char expected[100];
  const char *str = "%7s";
  char *input = "Th";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_4) {
  char got[100];
  char expected[100];
  const char *str = "%12s";
  char *input = "Th";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_5) {
  char got[100];
  char expected[100];
  const char *str = "%s";
  char *input = "";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_6) {
  char got[100];
  char expected[100];
  const char *str = "%s";
  char *input = "   I just LOVE the smell of fear!   ";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_7) {
  char got[100];
  char expected[100];
  const char *str = "%s";
  char *input =
      " I don't mean it metaphorically \n rhetorically \t poetically \" "
      "theoretically\"";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_8) {
  char got[100];
  char expected[100];
  const char *str = "%3.6s";
  char *input = "or any other fancy way";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_9) {
  char got[100];
  char expected[100];
  const char *str = "%s\t%s%s";
  char *input = "i'm death";
  char *input2 = " straight";
  char *input3 = " up";
  int res = s21_sprintf(got, str, input, input2, input3);
  int res1 = sprintf(expected, str, input, input2, input3);
  ck_assert_str_eq(got, expected);

  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_s_10) {
  char got[100];
  char expected[100];
  const char *str = "%s";
  char *input = S21_NULL;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_11) {
  char got[100];
  char expected[100];
  const char *str = "%ls";
  wchar_t input[] = L"PICK IT UP";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_14) {
  setlocale(LC_CTYPE, "");
  char got[100];
  char expected[100];
  const char *str = "%ls";
  wchar_t *input = S21_NULL;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_s_15) {
  setlocale(LC_CTYPE, "");
  char got[100];
  char expected[100];
  const char *str = "%.s";
  char *input = "Let's Debug!";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

//
// // tests for specificator "u"
START_TEST(s21_sprintf_u_1) {
  char got[100];
  char expected[100];
  const char *str = "%u";
  unsigned int input = 0;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_2) {
  char got[100];
  char expected[100];
  const char *str = "%u";
  unsigned int input = -645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_3) {
  char got[100];
  char expected[100];
  const char *str = "%u";
  unsigned int input = +645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_4) {
  char got[100];
  char expected[100];
  const char *str = "%.9u";
  unsigned int input = 645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_5) {
  char got[100];
  char expected[100];
  const char *str = "%.11u";
  unsigned int input = 645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_6) {
  char got[100];
  char expected[100];
  const char *str = "%hu";
  unsigned int input = 645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, (unsigned short)input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_7) {
  char got[100];
  char expected[100];
  const char *str = "%lu";
  unsigned long int input = 43426645653;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_8) {
  char got[100];
  char expected[100];
  const char *str = "%7.u";
  unsigned int input = 645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_10) {
  char got[100];
  char expected[100];
  const char *str = "%*u";
  unsigned int input = 645435;
  ck_assert_int_eq((s21_sprintf(got, str, -12, input)),
                   sprintf(expected, str, -12, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_11) {
  char got[100];
  char expected[100];
  const char *str = "%*lu";
  unsigned long input = 2147483647;
  ck_assert_int_eq((s21_sprintf(got, str, -12, input)),
                   sprintf(expected, str, -12, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_12) {
  char got[100];
  char expected[100];
  const char *str = "%07u";
  unsigned int input = 21474;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_13) {
  char got[100];
  char expected[100];
  const char *str = "%-8u|";
  unsigned int input = 21474;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_14) {
  char got[100];
  char expected[100];
  const char *str = "%-08u|";
  unsigned int input = 21474;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_15) {
  char got[100];
  char expected[100];
  const char *str = "%5.5hu";
  unsigned short input = 635;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_u_16) {
  char got[100];
  char expected[100];
  const char *str = "%-.11hu|";
  unsigned short input = 635;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

//
// // tests for specificator "x"
START_TEST(s21_sprintf_x_1) {
  char got[100];
  char expected[100];
  const char *str = "%x";
  int input = 645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_x_2) {
  char got[100];
  char expected[100];
  const char *str = "%x";
  int input = -645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_x_3) {
  char got[100];
  char expected[100];
  const char *str = "%-8x";
  int input = 65351;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_x_4) {
  char got[100];
  char expected[100];
  const char *str = "%#x";
  int input = 65351;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_x_5) {
  char got[100];
  char expected[100];
  const char *str = "%hx";
  unsigned short input = -51;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_x_6) {
  char got[100];
  char expected[100];
  const char *str = "%lx";
  long unsigned int input = 6536454345435451;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_x_7) {
  char got[100];
  char expected[100];
  const char *str = "% x %#x %.8x";
  int input = 65351;
  int input2 = 65354351;
  int input3 = 65;
  int res1 = s21_sprintf(got, str, input, input2, input3);
  int res2 = sprintf(expected, str, input, input2, input3);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_x_8) {
  char got[100];
  char expected[100];
  const char *str = "%lx";
  long unsigned int input = -2147483646;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST
//
// // tests for specificator "X"
START_TEST(s21_sprintf_X_1) {
  char got[100];
  char expected[100];
  const char *str = "%X";
  int input = INT32_MAX;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(s21_sprintf_X_2) {
  char got[100];
  char expected[100];
  const char *str = "%X";
  int input = -645435;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_X_3) {
  char got[100];
  char expected[100];
  const char *str = "%-8X";
  int input = 65351;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_X_4) {
  char got[100];
  char expected[100];
  const char *str = "%#X";
  int input = 65351;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_X_5) {
  char got[100];
  char expected[100];
  const char *str = "%hX";
  unsigned short input = -51;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_X_6) {
  char got[100];
  char expected[100];
  const char *str = "%lX";
  long unsigned int input = 6536454345435451;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_X_7) {
  char got[100];
  char expected[100];
  const char *str = "% X %#X %.8X";
  int input = 65351;
  int input2 = 65354351;
  int input3 = 65;
  ck_assert_int_eq((s21_sprintf(got, str, input, input2, input3)),
                   sprintf(expected, str, input, input2, input3));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_X_8) {
  char got[100];
  char expected[100];
  const char *str = "%lX";
  long unsigned int input = -2147483646;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST
// // tests for specificator "p"
START_TEST(s21_sprintf_p_1) {
  char got[100];
  char expected[100];
  const char *str = "%p";
  char *input = S21_NULL;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_p_2) {
  char got[100];
  char expected[100];
  const char *str = "%p";
  ck_assert_int_eq((s21_sprintf(got, str, str)), sprintf(expected, str, str));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_p_3) {
  char got[100];
  char expected[100];
  const char *str = "%21p\n";
  const char *input = "FUNNY";
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST
//
// // tests for specificator "n"
START_TEST(s21_sprintf_n_1) {
  char got[100];
  char expected[100];
  int n1 = 0, n2 = 0;
  const char *str = "%d%n";
  ck_assert_int_eq((s21_sprintf(got, str, 123, &n1)),
                   sprintf(expected, str, 123, &n2));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_n_2) {
  char got[100];
  char expected[100];
  int n1 = 0, n2 = 0;
  const char *str = "Hi there! I absolutly lost my sense of humor!%n";
  ck_assert_int_eq((s21_sprintf(got, str, &n1)), sprintf(expected, str, &n2));
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_n_3) {
  char got[100];
  char expected[100];
  int n1 = 0, n2 = 0;
  const char *str = "%n Buuut i neeed to tell u sooomething";
  ck_assert_int_eq((s21_sprintf(got, str, &n1)), sprintf(expected, str, &n2));
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_n_4) {
  char got[100];
  char expected[100];
  int n1 = 0, n2 = 0;
  const char *str = "Buuut i neeed to%n tell u sooomething";
  ck_assert_int_eq((s21_sprintf(got, str, &n1)), sprintf(expected, str, &n2));
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(got, expected);
}
END_TEST
// // tests for specificator "%"
START_TEST(s21_sprintf_procent_1) {
  char got[100];
  char expected[100];
  const char *str = "%d %%";
  int input = 1;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_procent_2) {
  char got[100];
  char expected[100];
  const char *str = "%d %%%%";
  int input = 1;
  ck_assert_int_eq((s21_sprintf(got, str, input)),
                   sprintf(expected, str, input));
  ck_assert_str_eq(got, expected);
}
END_TEST
// // different combinations
START_TEST(s21_sprintf_comb_1) {
  char got[100];
  char expected[100];
  const char *str = "%c%d";
  ck_assert_int_eq((s21_sprintf(got, str, 'G', 53432)),
                   sprintf(expected, str, 'G', 53432));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_2) {
  char got[100];
  char expected[100];
  const char *str = "%c %*i";
  ck_assert_int_eq((s21_sprintf(got, str, 'G', 9, 53432)),
                   sprintf(expected, str, 'G', 9, 53432));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_3) {
  char got[100];
  char expected[100];
  const char *str = "%c %#e";
  ck_assert_int_eq((s21_sprintf(got, str, 'G', 524.242)),
                   sprintf(expected, str, 'G', 524.242));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_4) {
  char got[100];
  char expected[100];
  const char *str = "%c %E %f";
  ck_assert_int_eq((s21_sprintf(got, str, 'G', 524.242, 54.324)),
                   sprintf(expected, str, 'G', 524.242, 54.324));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_5) {
  char got[100];
  char expected[100];
  const char *str = "\n%c %#g %G %#o\n";
  int res1 = s21_sprintf(got, str, 'G', 524.242, 5465645.324, 19);
  int res2 = sprintf(expected, str, 'G', 524.242, 5465645.324, 19);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_comb_6) {
  char got[100];
  char expected[100];
  const char *str = "\n%c %#.5g %.11G %#o\n";
  int res1 = s21_sprintf(got, str, 'G', 524.242, 5465645.324, 19);
  int res2 = sprintf(expected, str, 'G', 524.242, 5465645.324, 19);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_comb_7) {
  char got[100];
  char expected[100];
  const char *str = "%c %s %c";
  ck_assert_int_eq((s21_sprintf(got, str, 'G', "HELL", 'O')),
                   sprintf(expected, str, 'G', "HELL", 'O'));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_8) {
  char got[100];
  char expected[100];
  const char *str = "%s %c %.1s";
  ck_assert_int_eq((s21_sprintf(got, str, "HELL", 'O', "FDW")),
                   sprintf(expected, str, "HELL", 'O', "FDW"));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_9) {
  char got[100];
  char expected[100];
  const char *str = "%s %u %x %X";
  ck_assert_int_eq(
      (s21_sprintf(got, str, "HELL", (unsigned int)-5435, 25427, 25427)),
      sprintf(expected, str, "HELL", (unsigned int)-5435, 25427, 25427));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_10) {
  char got[100];
  char expected[100];
  const char *str = "%s %p %n %%";
  void *ptr = (void *)0x12345678;
  int n1 = 0, n2 = 0;
  ck_assert_int_eq((s21_sprintf(got, str, "", ptr, &n1)),
                   sprintf(expected, str, "", ptr, &n2));
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_sprintf_comb_11) {
  char got[100];
  char expected[100];
  const char *str = "%d %5d %-5d";
  int input = 42, input2 = 7, input3 = 123;
  ck_assert_int_eq(s21_sprintf(got, str, input, input2, input3),
                   sprintf(expected, str, input, input2, input3));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_12) {
  char got[100];
  char expected[100];
  const char *str = "%f %.2f %10.4f";
  double input = 3.14159, input2 = 2.71828, input3 = 142.71828;
  ck_assert_int_eq(s21_sprintf(got, str, input, input2, input3),
                   sprintf(expected, str, input, input2, input3));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_13) {
  char got[100];
  char expected[100];
  const char *str = "%x %X %o";
  int input = 255;
  ck_assert_int_eq(s21_sprintf(got, str, input, input, input),
                   sprintf(expected, str, input, input, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_14) {
  char got[100];
  char expected[100];
  const char *str = "Pi: %.2f, Scientific: %.2e";
  double input = 3.14159;
  ck_assert_int_eq(s21_sprintf(got, str, input, input),
                   sprintf(expected, str, input, input));
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_15) {
  char got[100];
  char expected[100];

  const char *str = "%0.*i %d %4.*i %013d %d";
  int input = 71;
  ck_assert_int_eq(
      s21_sprintf(got, str, 6, input, -265454, 4, 5311, 0, -581813581),
      sprintf(expected, str, 6, input, -265454, 4, 5311, 0, -581813581));

  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(s21_sprintf_comb_16) {
  char got[100];
  char expected[100];
  const char *str = "\n%LG %g %G %Lg %.5g\n";
  long double input = 0.000007;

  double input2 = 84.543613;
  double input3 = 456.10100;
  long double input4 = 0.000828;
  double input5 = 0.5;
  int res1 = s21_sprintf(got, str, input, input2, input3, input4, input5);
  int res2 = sprintf(expected, str, input, input2, input3, input4, input5);
  ck_assert_str_eq(got, expected);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sprintf_comb_17) {
  char got[100];
  char expected[100];
  const char *str = "%+li%lu%+d%+Lf";
  long int input = 5432;
  unsigned long input2 = -53423;
  int input3 = 343243432;
  long double input4 = 0.000828;
  ck_assert_int_eq(s21_sprintf(got, str, input, input2, input3, input4),
                   sprintf(expected, str, input, input2, input3, input4));

  ck_assert_str_eq(got, expected);
}
END_TEST

#include "test.h"
#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536
#define M_SQRT2 1.41421356237309504880

#define STRLEN 1000

START_TEST(sprintf_string_1) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "padding:\t[%20s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_2) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "padding:\t[%-20s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_3) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "padding:\t[%*s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, 20, _1);
  int s21_res = s21_sprintf(s21_str, format, 20, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_4) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "trunc:\t[%.5s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_5) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "trunc:\t[%*s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, 4, _1);
  int s21_res = s21_sprintf(s21_str, format, 4, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_6) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "\t[%10.5s]\n\t[%-10.5s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_7) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "\t[%*.*s]\n\t[%-*.*s]\n";
  char *_1 = "Hello, world!";
  int res = sprintf(str, format, 10, 4, _1, 10, 4, _1);
  int s21_res = s21_sprintf(s21_str, format, 10, 4, _1, 10, 4, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_string_8) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "wide string:\t[%s %10ls][%-10ls][%ls]\n";
  char *_1 = "Hello,";
  wchar_t *_2 = L"world!";
  int res = sprintf(str, format, _1, _2, _2, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_1) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "chars:\t[%c%%]\n";
  char _1 = '1';
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_2) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "chars:\t[%4.5c%%]\n";
  char _1 = '1';
  int res = sprintf(str, format, _1);
  int s21_res = s21_sprintf(s21_str, format, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_3) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "chars:\t[%-*c%%]\n";
  char _1 = '1';
  int res = sprintf(str, format, 5, _1);
  int s21_res = s21_sprintf(s21_str, format, 5, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_4) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "chars:\t[%-*%]\t[%10%]\n";
  int res = sprintf(str, format, 5);
  int s21_res = s21_sprintf(s21_str, format, 5);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_5) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "wide char:\t[%c][%-5lc][%5lc][%lc]\n";
  char _1 = 'H';
  wchar_t _2 = L'w', _3 = L'!';
  int res = sprintf(str, format, _1, _2, _3, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_char_6) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "wide char:\t[%hc][%-5lc][%5Lc][%-Lc]\n";
  char _1 = 'H';
  wchar_t _2 = L'w', _3 = L'!';
  int res = sprintf(str, format, _1, _2, _3, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_1) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format =
      "dec:\n(% i) (%d) (%+i) (% +d) (%.6i) (% .6d) (%4.2i) (%4.2d) (%+.0i) "
      "(%+.0d)\n";
  int _1 = 1;
  int _2 = 2;
  int _3 = 3;
  int _4 = 4;
  int _5 = 5;
  int res = sprintf(str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);
  int s21_res =
      s21_sprintf(s21_str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);

  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_int_2) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "dec:\t%i %d %+i %+d %.6i %.6d %4.2i %4.2d %+.0i %+.0d\n";
  int _1 = 0;
  int res = sprintf(str, format, _1, _1, _1, _1, _1, _1, _1, _1, _1, _1);
  int s21_res =
      s21_sprintf(s21_str, format, _1, _1, _1, _1, _1, _1, _1, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_3) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "dec:\t%i %d %+i %+d %.6i %.6d %4.2i %4.2d %+.0i %+.0d\n";
  int _1 = -1;
  int _2 = -2;
  int _3 = -3;
  int _4 = -4;
  int _5 = -5;
  int res = sprintf(str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);
  int s21_res =
      s21_sprintf(s21_str, format, _1, _1, _2, _2, _3, _3, _4, _4, _5, _5);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_4) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "hex:\t%x %x %X %#x\n";
  int _1 = 1;
  int _2 = 10;
  int _3 = 11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_5) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "hex:\t%4x %4x %4X %#4x\n";
  int _1 = 1;
  int _2 = 10;
  int _3 = 11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_6) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "hex:\n(%4.2x) (%4.2x) (%4.2X) (%#4.4X)\n";
  int _1 = 1;
  int _2 = 10;
  int _3 = 11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);

  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_int_7) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "hex:\t%4.2x %4.2x %4.2X %#4.4x\n";
  int _1 = -1;
  int _2 = -10;
  int _3 = -11;

  int res = sprintf(str, format, _1, _2, _2, _3);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _2, _3);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_8) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "hex:\n(%4.2x) (%4.2x) (%4.2X) (%#4.4x)\n";
  int _1 = 0;

  int res = sprintf(str, format, _1, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1, _1);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_int_9) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "hex:\n(%+4.0x) (%+4.0x) (%+4.0X) (%#+4.0x)\n";
  int _1 = 0;

  int res = sprintf(str, format, _1, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_10) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "oct:\t%o %+o %#o %#o\n";
  int _1 = 4;
  int _2 = 10;
  int res = sprintf(str, format, _1, _2, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_11) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "oct: (%-4o) (%+4o) (%-#4o) (%-#5.4o)";
  int _1 = 4;
  int _2 = 10;
  int res = sprintf(str, format, _1, _2, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_12) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "oct:\t% -4o % +4o %-#4o %-#5.4o\n";
  int _1 = -4;
  int _2 = -10;
  int res = sprintf(str, format, _1, _2, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _2);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_13) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "oct:\n(%-4.0o) (%+4.0o) (%-#4.0o) (%-#5.0o)\n";
  int _1 = 0;
  int res = sprintf(str, format, _1, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_14) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "unsign:\t%-*u %+.2u %6.0u %u\n";
  int _1 = 4;
  int _2 = 10;
  int _3 = 0;
  int _4 = -4;
  int res = sprintf(str, format, 4, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 4, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_15) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "wide int:\t%-*hd %+.2d %6.0hu %lu\n";
  short int _1 = 4;
  int _2 = 10;
  short int _3 = 0;
  long int _4 = 40;
  int res = sprintf(str, format, 4, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 4, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_int_16) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "wide int:\t%-*hx %+.2x %6.0hX %lX\n";
  short int _1 = 4;
  int _2 = 10;
  short int _3 = 0;
  long int _4 = 40;
  int res = sprintf(str, format, 4, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 4, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_1) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "round:\t%.*f % .0f %.0f %.16f\n";
  double _1 = M_PI;
  double _2 = M_SQRT2;
  double _3 = M_E;
  double _4 = M_PI;
  int res = sprintf(str, format, 1, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, 1, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_2) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "padding:\n(%*.2lf) (%+7.2lf) (% .2f) (%05.2f)\n";
  double _1 = -1 / M_PI;
  double _2 = M_SQRT2;
  double _3 = M_E;
  double _4 = M_PI;
  int res = sprintf(str, format, -10, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, -10, _1, _2, _3, _4);

  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_float_3) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "sci:\t%E %e % -+10.0E %+.8e\n";
  double _1 = -1 / M_PI;
  double _2 = M_SQRT2 * 100;
  double _3 = M_E / 1e+6;
  double _4 = M_PI;
  int res = sprintf(str, format, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _4);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_float_4) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "sci:\n(%G) (%g) (% +-10.0G) (%+.7g) (%5g) (%.2g)\n";
  double _1 = -1 / M_PI;
  double _2 = M_SQRT2 * 100;
  double _3 = M_E / 1e+6;
  double _4 = M_PI;
  int res = sprintf(str, format, _1, _2, _3, _4, 10.0, 1234.);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _4, 10.0, 1234.);

  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_float_5) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "spec:\t\t%Lf %Le %LE %LG\n";
  long double _1 = -1 / M_PI;
  long double _2 = M_SQRT2 * 100;
  long double _3 = M_E / 1e+6;
  long double _4 = M_PI;
  int res = sprintf(str, format, _1, _2, _3, _4);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _3, _4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_float_6) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  // char *format = "zero:\t%-#+5.0f%#+ 010.2e% 10E%#+ 010g% G\n";
  char *format = "zero:\n(%-+5.0f)(%#+ 10.2e)(% 10E)(%+ 10g)(% G)\n";
  float _1 = 0.0;
  float _2 = 0.0;

  int res = sprintf(str, format, _1, _2, _1, _1, _2);
  int s21_res = s21_sprintf(s21_str, format, _1, _2, _1, _1, _2);

  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(sprintf_ptr_1) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "ptr:\t%p %20p %-20p\n";
  int test_var = 10;
  int *_1 = &test_var;

  int res = sprintf(str, format, _1, _1, _1);
  int s21_res = s21_sprintf(s21_str, format, _1, _1, _1);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
}
END_TEST

START_TEST(sprintf_num_1) {
  char str[STRLEN] = {0};
  char s21_str[STRLEN] = {0};
  char *format = "%s:\t[%n] [%+7n] [% -7n] [%#n]\n";
  char *_1 = "num";
  int out_1 = 0, out_2 = 0, out_3 = 0, out_4 = 0;
  int s21_out_1 = 0, s21_out_2 = 0, s21_out_3 = 0, s21_out_4 = 0;

  int res = sprintf(str, format, _1, &out_1, &out_2, &out_3, &out_4);
  int s21_res = s21_sprintf(s21_str, format, _1, &s21_out_1, &s21_out_2,
                            &s21_out_3, &s21_out_4);
  ck_assert_int_eq(s21_res, res);
  ck_assert_pstr_eq(s21_str, str);
  ck_assert_int_eq(s21_out_1, out_1);
  ck_assert_int_eq(s21_out_2, out_2);
  ck_assert_int_eq(s21_out_3, out_3);
  ck_assert_int_eq(s21_out_4, out_4);
}
END_TEST

Suite *tests_sprintf(void) {
  Suite *s;
  TCase *tc_sprintf;
  s = suite_create("sprintf_tests");
  tc_sprintf = tcase_create("sprintf_tests");

  tcase_add_test(tc_sprintf, sprintf_string_1);
  tcase_add_test(tc_sprintf, sprintf_string_2);
  tcase_add_test(tc_sprintf, sprintf_string_3);
  tcase_add_test(tc_sprintf, sprintf_string_4);
  tcase_add_test(tc_sprintf, sprintf_string_5);
  tcase_add_test(tc_sprintf, sprintf_string_6);
  tcase_add_test(tc_sprintf, sprintf_string_7);
  tcase_add_test(tc_sprintf, sprintf_string_8);

  tcase_add_test(tc_sprintf, sprintf_char_1);
  tcase_add_test(tc_sprintf, sprintf_char_2);
  tcase_add_test(tc_sprintf, sprintf_char_3);
  tcase_add_test(tc_sprintf, sprintf_char_4);
  tcase_add_test(tc_sprintf, sprintf_char_5);
  tcase_add_test(tc_sprintf, sprintf_char_6);

  tcase_add_test(tc_sprintf, sprintf_int_1);
  tcase_add_test(tc_sprintf, sprintf_int_2);
  tcase_add_test(tc_sprintf, sprintf_int_3);
  tcase_add_test(tc_sprintf, sprintf_int_4);
  tcase_add_test(tc_sprintf, sprintf_int_5);
  tcase_add_test(tc_sprintf, sprintf_int_6);
  tcase_add_test(tc_sprintf, sprintf_int_7);
  tcase_add_test(tc_sprintf, sprintf_int_8);
  tcase_add_test(tc_sprintf, sprintf_int_9);
  tcase_add_test(tc_sprintf, sprintf_int_10);
  tcase_add_test(tc_sprintf, sprintf_int_11);
  tcase_add_test(tc_sprintf, sprintf_int_12);
  tcase_add_test(tc_sprintf, sprintf_int_13);
  tcase_add_test(tc_sprintf, sprintf_int_14);
  tcase_add_test(tc_sprintf, sprintf_int_15);
  tcase_add_test(tc_sprintf, sprintf_int_16);

  tcase_add_test(tc_sprintf, sprintf_float_1);
  tcase_add_test(tc_sprintf, sprintf_float_2);
  tcase_add_test(tc_sprintf, sprintf_float_3);
  tcase_add_test(tc_sprintf, sprintf_float_4);
  tcase_add_test(tc_sprintf, sprintf_float_5);
  tcase_add_test(tc_sprintf, sprintf_float_6);

  tcase_add_test(tc_sprintf, sprintf_ptr_1);

  tcase_add_test(tc_sprintf, sprintf_num_1);

  // c spec
  tcase_add_test(tc_sprintf, s21_sprintf_c_1);
  tcase_add_test(tc_sprintf, s21_sprintf_c_2);
  tcase_add_test(tc_sprintf, s21_sprintf_c_3);
  tcase_add_test(tc_sprintf, s21_sprintf_c_4);
  tcase_add_test(tc_sprintf, s21_sprintf_c_5);
  tcase_add_test(tc_sprintf, s21_sprintf_c_6);
  tcase_add_test(tc_sprintf, s21_sprintf_c_7);
  tcase_add_test(tc_sprintf, s21_sprintf_c_8);
  tcase_add_test(tc_sprintf, s21_sprintf_c_9);
  tcase_add_test(tc_sprintf, s21_sprintf_c_10);
  tcase_add_test(tc_sprintf, s21_sprintf_c_11);
  tcase_add_test(tc_sprintf, s21_sprintf_c_13);
  // d spec

  tcase_add_test(tc_sprintf, s21_sprintf_d_1);
  tcase_add_test(tc_sprintf, s21_sprintf_d_2);
  tcase_add_test(tc_sprintf, s21_sprintf_d_3);
  tcase_add_test(tc_sprintf, s21_sprintf_d_4);
  tcase_add_test(tc_sprintf, s21_sprintf_d_5);
  tcase_add_test(tc_sprintf, s21_sprintf_d_6);
  tcase_add_test(tc_sprintf, s21_sprintf_d_7);
  tcase_add_test(tc_sprintf, s21_sprintf_d_8);
  tcase_add_test(tc_sprintf, s21_sprintf_d_9);
  tcase_add_test(tc_sprintf, s21_sprintf_d_10);
  tcase_add_test(tc_sprintf, s21_sprintf_d_11);
  tcase_add_test(tc_sprintf, s21_sprintf_d_12);
  tcase_add_test(tc_sprintf, s21_sprintf_d_13);
  tcase_add_test(tc_sprintf, s21_sprintf_d_14);
  tcase_add_test(tc_sprintf, s21_sprintf_d_15);
  tcase_add_test(tc_sprintf, s21_sprintf_d_16);
  tcase_add_test(tc_sprintf, s21_sprintf_d_17);
  tcase_add_test(tc_sprintf, s21_sprintf_d_18);
  tcase_add_test(tc_sprintf, s21_sprintf_d_19);
  tcase_add_test(tc_sprintf, s21_sprintf_d_20);
  tcase_add_test(tc_sprintf, s21_sprintf_d_21);
  tcase_add_test(tc_sprintf, s21_sprintf_d_22);
  tcase_add_test(tc_sprintf, s21_sprintf_d_23);
  tcase_add_test(tc_sprintf, s21_sprintf_d_24);
  // // i spec
  tcase_add_test(tc_sprintf, s21_sprintf_i_1);
  tcase_add_test(tc_sprintf, s21_sprintf_i_2);
  tcase_add_test(tc_sprintf, s21_sprintf_i_3);
  tcase_add_test(tc_sprintf, s21_sprintf_i_4);
  tcase_add_test(tc_sprintf, s21_sprintf_i_5);
  tcase_add_test(tc_sprintf, s21_sprintf_i_6);
  tcase_add_test(tc_sprintf, s21_sprintf_i_7);
  tcase_add_test(tc_sprintf, s21_sprintf_i_8);
  tcase_add_test(tc_sprintf, s21_sprintf_i_9);
  tcase_add_test(tc_sprintf, s21_sprintf_i_10);
  tcase_add_test(tc_sprintf, s21_sprintf_i_11);
  tcase_add_test(tc_sprintf, s21_sprintf_i_12);
  tcase_add_test(tc_sprintf, s21_sprintf_i_13);
  tcase_add_test(tc_sprintf, s21_sprintf_i_14);
  tcase_add_test(tc_sprintf, s21_sprintf_i_15);
  tcase_add_test(tc_sprintf, s21_sprintf_i_16);
  tcase_add_test(tc_sprintf, s21_sprintf_i_17);
  tcase_add_test(tc_sprintf, s21_sprintf_i_18);
  tcase_add_test(tc_sprintf, s21_sprintf_i_19);
  tcase_add_test(tc_sprintf, s21_sprintf_i_20);
  tcase_add_test(tc_sprintf, s21_sprintf_i_21);
  tcase_add_test(tc_sprintf, s21_sprintf_i_22);
  tcase_add_test(tc_sprintf, s21_sprintf_i_23);
  tcase_add_test(tc_sprintf, s21_sprintf_i_24);
  // // e spec
  tcase_add_test(tc_sprintf, s21_sprintf_e_1);
  tcase_add_test(tc_sprintf, s21_sprintf_e_2);
  tcase_add_test(tc_sprintf, s21_sprintf_e_3);
  tcase_add_test(tc_sprintf, s21_sprintf_e_4);
  tcase_add_test(tc_sprintf, s21_sprintf_e_5);
  tcase_add_test(tc_sprintf, s21_sprintf_e_6);
  tcase_add_test(tc_sprintf, s21_sprintf_e_7);
  tcase_add_test(tc_sprintf, s21_sprintf_e_8);
  tcase_add_test(tc_sprintf, s21_sprintf_e_9);
  tcase_add_test(tc_sprintf, s21_sprintf_e_10);
  tcase_add_test(tc_sprintf, s21_sprintf_e_11);
  tcase_add_test(tc_sprintf, s21_sprintf_e_12);
  tcase_add_test(tc_sprintf, s21_sprintf_e_13);
  tcase_add_test(tc_sprintf, s21_sprintf_e_14);
  tcase_add_test(tc_sprintf, s21_sprintf_e_15);
  tcase_add_test(tc_sprintf, s21_sprintf_e_16);
  tcase_add_test(tc_sprintf, s21_sprintf_e_17);
  tcase_add_test(tc_sprintf, s21_sprintf_e_18);
  tcase_add_test(tc_sprintf, s21_sprintf_e_19);
  tcase_add_test(tc_sprintf, s21_sprintf_e_20);
  tcase_add_test(tc_sprintf, s21_sprintf_e_21);
  // // E spec
  tcase_add_test(tc_sprintf, s21_sprintf_E_1);
  tcase_add_test(tc_sprintf, s21_sprintf_E_2);
  tcase_add_test(tc_sprintf, s21_sprintf_E_3);
  tcase_add_test(tc_sprintf, s21_sprintf_E_4);
  tcase_add_test(tc_sprintf, s21_sprintf_E_5);
  tcase_add_test(tc_sprintf, s21_sprintf_E_6);
  tcase_add_test(tc_sprintf, s21_sprintf_E_7);
  tcase_add_test(tc_sprintf, s21_sprintf_E_8);
  tcase_add_test(tc_sprintf, s21_sprintf_E_9);
  tcase_add_test(tc_sprintf, s21_sprintf_E_10);
  tcase_add_test(tc_sprintf, s21_sprintf_E_11);
  tcase_add_test(tc_sprintf, s21_sprintf_E_12);
  tcase_add_test(tc_sprintf, s21_sprintf_E_13);
  tcase_add_test(tc_sprintf, s21_sprintf_E_14);
  tcase_add_test(tc_sprintf, s21_sprintf_E_15);
  tcase_add_test(tc_sprintf, s21_sprintf_E_16);
  tcase_add_test(tc_sprintf, s21_sprintf_E_17);
  tcase_add_test(tc_sprintf, s21_sprintf_E_18);
  tcase_add_test(tc_sprintf, s21_sprintf_E_19);
  tcase_add_test(tc_sprintf, s21_sprintf_E_20);
  tcase_add_test(tc_sprintf, s21_sprintf_E_21);
  tcase_add_test(tc_sprintf, s21_sprintf_E_22);
  tcase_add_test(tc_sprintf, simple_0_with_dot);
  tcase_add_test(tc_sprintf, simple_near_0e);
  tcase_add_test(tc_sprintf, simple_0e);
  tcase_add_test(tc_sprintf, simple_e);
  tcase_add_test(tc_sprintf, long_e);
  tcase_add_test(tc_sprintf, zero_precision_e);
  tcase_add_test(tc_sprintf, empty_precision_e);
  tcase_add_test(tc_sprintf, big_precision_e);
  tcase_add_test(tc_sprintf, many_e);
  tcase_add_test(tc_sprintf, manyEe);
  tcase_add_test(tc_sprintf, int_e);
  tcase_add_test(tc_sprintf, e_many);
  //
  // // f spec
  tcase_add_test(tc_sprintf, s21_sprintf_f_1);
  tcase_add_test(tc_sprintf, s21_sprintf_f_2);
  tcase_add_test(tc_sprintf, s21_sprintf_f_3);
  tcase_add_test(tc_sprintf, s21_sprintf_f_4);
  tcase_add_test(tc_sprintf, s21_sprintf_f_5);
  tcase_add_test(tc_sprintf, s21_sprintf_f_6);
  tcase_add_test(tc_sprintf, s21_sprintf_f_7);
  tcase_add_test(tc_sprintf, s21_sprintf_f_8);
  tcase_add_test(tc_sprintf, s21_sprintf_f_9);
  tcase_add_test(tc_sprintf, s21_sprintf_f_10);
  tcase_add_test(tc_sprintf, s21_sprintf_f_11);
  tcase_add_test(tc_sprintf, s21_sprintf_f_12);
  tcase_add_test(tc_sprintf, s21_sprintf_f_13);
  tcase_add_test(tc_sprintf, s21_sprintf_f_14);
  tcase_add_test(tc_sprintf, s21_sprintf_f_15);
  tcase_add_test(tc_sprintf, s21_sprintf_f_16);
  tcase_add_test(tc_sprintf, s21_sprintf_f_17);
  tcase_add_test(tc_sprintf, s21_sprintf_f_18);
  tcase_add_test(tc_sprintf, s21_sprintf_f_19);
  // // g spec
  tcase_add_test(tc_sprintf, s21_sprintf_g_1);
  tcase_add_test(tc_sprintf, s21_sprintf_g_2);
  tcase_add_test(tc_sprintf, s21_sprintf_g_3);
  tcase_add_test(tc_sprintf, s21_sprintf_g_4);
  tcase_add_test(tc_sprintf, s21_sprintf_g_5);
  tcase_add_test(tc_sprintf, s21_sprintf_g_6);
  tcase_add_test(tc_sprintf, s21_sprintf_g_7);
  tcase_add_test(tc_sprintf, s21_sprintf_g_8);
  tcase_add_test(tc_sprintf, s21_sprintf_g_9);
  // // G spec
  tcase_add_test(tc_sprintf, s21_sprintf_G_1);
  tcase_add_test(tc_sprintf, s21_sprintf_G_2);
  tcase_add_test(tc_sprintf, s21_sprintf_G_3);
  tcase_add_test(tc_sprintf, s21_sprintf_G_4);
  tcase_add_test(tc_sprintf, s21_sprintf_G_5);
  tcase_add_test(tc_sprintf, s21_sprintf_G_6);
  tcase_add_test(tc_sprintf, s21_sprintf_G_7);
  tcase_add_test(tc_sprintf, s21_sprintf_G_8);
  tcase_add_test(tc_sprintf, s21_sprintf_G_9);
  // // o spec
  tcase_add_test(tc_sprintf, s21_sprintf_o_1);
  tcase_add_test(tc_sprintf, s21_sprintf_o_2);
  tcase_add_test(tc_sprintf, s21_sprintf_o_3);
  tcase_add_test(tc_sprintf, s21_sprintf_o_4);
  tcase_add_test(tc_sprintf, s21_sprintf_o_5);
  tcase_add_test(tc_sprintf, s21_sprintf_o_6);
  // // s spec
  tcase_add_test(tc_sprintf, s21_sprintf_s_1);
  tcase_add_test(tc_sprintf, s21_sprintf_s_2);
  tcase_add_test(tc_sprintf, s21_sprintf_s_3);
  tcase_add_test(tc_sprintf, s21_sprintf_s_4);
  tcase_add_test(tc_sprintf, s21_sprintf_s_5);
  tcase_add_test(tc_sprintf, s21_sprintf_s_6);
  tcase_add_test(tc_sprintf, s21_sprintf_s_7);
  tcase_add_test(tc_sprintf, s21_sprintf_s_8);
  tcase_add_test(tc_sprintf, s21_sprintf_s_9);
  tcase_add_test(tc_sprintf, s21_sprintf_s_10);
  tcase_add_test(tc_sprintf, s21_sprintf_s_11);
  tcase_add_test(tc_sprintf, s21_sprintf_s_14);
  tcase_add_test(tc_sprintf, s21_sprintf_s_15);
  // // u spec
  tcase_add_test(tc_sprintf, s21_sprintf_u_1);
  tcase_add_test(tc_sprintf, s21_sprintf_u_2);
  tcase_add_test(tc_sprintf, s21_sprintf_u_3);
  tcase_add_test(tc_sprintf, s21_sprintf_u_4);
  tcase_add_test(tc_sprintf, s21_sprintf_u_5);
  tcase_add_test(tc_sprintf, s21_sprintf_u_6);
  tcase_add_test(tc_sprintf, s21_sprintf_u_7);
  tcase_add_test(tc_sprintf, s21_sprintf_u_8);
  tcase_add_test(tc_sprintf, s21_sprintf_u_10);
  tcase_add_test(tc_sprintf, s21_sprintf_u_11);
  tcase_add_test(tc_sprintf, s21_sprintf_u_12);
  tcase_add_test(tc_sprintf, s21_sprintf_u_13);
  tcase_add_test(tc_sprintf, s21_sprintf_u_14);
  tcase_add_test(tc_sprintf, s21_sprintf_u_15);
  tcase_add_test(tc_sprintf, s21_sprintf_u_16);
  // // X spec
  tcase_add_test(tc_sprintf, s21_sprintf_x_1);
  tcase_add_test(tc_sprintf, s21_sprintf_x_2);
  tcase_add_test(tc_sprintf, s21_sprintf_x_3);
  tcase_add_test(tc_sprintf, s21_sprintf_x_4);
  tcase_add_test(tc_sprintf, s21_sprintf_x_5);
  tcase_add_test(tc_sprintf, s21_sprintf_x_6);
  tcase_add_test(tc_sprintf, s21_sprintf_x_7);
  tcase_add_test(tc_sprintf, s21_sprintf_x_8);
  // //  x spec
  tcase_add_test(tc_sprintf, s21_sprintf_X_1);
  tcase_add_test(tc_sprintf, s21_sprintf_X_2);
  tcase_add_test(tc_sprintf, s21_sprintf_X_3);
  tcase_add_test(tc_sprintf, s21_sprintf_X_4);
  tcase_add_test(tc_sprintf, s21_sprintf_X_5);
  tcase_add_test(tc_sprintf, s21_sprintf_X_6);
  tcase_add_test(tc_sprintf, s21_sprintf_X_7);
  tcase_add_test(tc_sprintf, s21_sprintf_X_8);
  // // p spec
  tcase_add_test(tc_sprintf, s21_sprintf_p_1);
  tcase_add_test(tc_sprintf, s21_sprintf_p_2);
  tcase_add_test(tc_sprintf, s21_sprintf_p_3);
  // // n spec
  tcase_add_test(tc_sprintf, s21_sprintf_n_1);
  tcase_add_test(tc_sprintf, s21_sprintf_n_2);
  tcase_add_test(tc_sprintf, s21_sprintf_n_3);
  tcase_add_test(tc_sprintf, s21_sprintf_n_4);
  // // % spec
  tcase_add_test(tc_sprintf, s21_sprintf_procent_1);
  tcase_add_test(tc_sprintf, s21_sprintf_procent_2);
  // // combinations
  tcase_add_test(tc_sprintf, s21_sprintf_comb_1);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_2);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_3);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_4);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_5);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_6);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_7);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_8);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_9);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_10);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_11);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_12);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_13);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_14);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_15);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_16);
  tcase_add_test(tc_sprintf, s21_sprintf_comb_17);

  suite_add_tcase(s, tc_sprintf);

  return s;
}
