#include "s21_string.h"
// Копирует n символов из src в dest.

// char src[] = "Hello, s21_memcpy!";
// char dest[50];  // Буфер назначения
//  s21_memcpy(dest, src, 18);

// Исходная строка: Hello, s21_memcpy!
// Скопированная строка: Hello, s21_memcpy!

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}
