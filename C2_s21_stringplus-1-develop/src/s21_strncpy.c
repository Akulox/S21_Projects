#include "s21_string.h"
// Копирует до n символов из строки, на которую указывает src, в dest.
// Она копирует не более n символов из строки src в dest, и если длина src
// меньше n, то оставшиеся байты заполняет нулями. char src[10];
// s21_strncpy(src, "Hi", 5);

// Результат:
// src: 'Hi'
// str[0] = 72   // 'H'
// str[1] = 105  // 'i'
// str[2] = 0
// str[3] = 0
// str[4] = 0
// str[5] = 0
// str[6] = 0
// str[7] = 0
// str[8] = 0
// str[9] = 0

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ret = dest;
  s21_size_t i = 0;
  while (*src && i < n) {
    *dest++ = *src++;
    i++;
  };
  for (; i < n; i++) {
    *dest++ = '\0';
  }
  return ret;
}
