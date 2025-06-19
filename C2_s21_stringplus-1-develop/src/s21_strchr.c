#include "s21_string.h"
// Функция ищет и возвращает первое вхождения символа "int c" в строке "const
// char * str"
// Если символ найден, возвращает указатель на этот символ в строке.

// const char *str = "Hello, world!";
// char *pos = s21_strchr(str, 'o');

// pos — указатель на str + 4.

char *s21_strchr(const char *str, int c) {
  while (*str) {
    if (*str == (char)c) {
      return (char *)str;
    }
    str++;
  }
  if (!c) {
    return (char *)str;
  }
  return S21_NULL;
}
