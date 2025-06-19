#ifndef S21_WCHAR_H
#define S21_WCHAR_H

#include "../s21_string.h"

typedef int s21_wchar_t;
typedef unsigned int s21_wint_t;

s21_size_t s21_wcstombs(char *mbstr, const s21_wchar_t *wcstr,
                        s21_size_t count);

#endif
