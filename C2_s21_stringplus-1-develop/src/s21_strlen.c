#include "s21_string.h"
// Вычисляет длину строки str, не включая завершающий нулевой символ.
// const char *str = "Hello, world!";
// result = s21_strlen(str);

// result = 13
s21_size_t s21_strlen(const char *str) {
  s21_size_t strLength = 0;
  for (; str[strLength];) {
    strLength += 1;
  }
  return strLength;
}
