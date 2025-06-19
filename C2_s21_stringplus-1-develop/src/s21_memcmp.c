#include "s21_string.h"
// Функции  сравневает первые n байт двух блоков памяти str1 и str2.
// Если все байты совпадают, возвращает 0.
// Возвращает разницу первого отличающегося байта.

// const char str1[] = "Hello";
// const char str2[] = "Hella";
// s21_size_t n = 5;
// int result = s21_memcmp(str1, str2, n);

// Первый различающийся символ — на позиции 4: 'o' (111) и 'a' (97).result = 111
// - 97 = 14

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int diff = 0;
  while (n-- && !diff) {
    diff = *((unsigned char *)str1++) - *((unsigned char *)str2++);
  }
  return diff;
}
