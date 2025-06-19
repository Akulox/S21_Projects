#include "s21_string.h"
// Функция ищет и возвращает последнее вхождения символа "int c" в строке "const
// char * str"
// Если символ найден, возвращает указатель на этот символ в строке.

// const char *str = "Hello, world!";
// char *pos = s21_strchr(str, 'o');

// pos — указатель на str + 8.

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;

  for (int i = s21_strlen(str); i >= 0; i--) {
    if (str[i] == (unsigned char)c) {
      result = (char *)str + i;
      break;
    }
  }

  return result;
}
