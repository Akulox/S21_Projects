#include "s21_string.h"
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str. Функция возвращает
// указатель на найденный символ. Пример: char str[] = "Hello, world!"; char
// *result = s21_memchr(str, 'o', 10); Функция вернет указатель на первый символ
// 'o' в первых 10 байтах строки
void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *chr = S21_NULL;
  while (n--) {
    if (*(unsigned char *)str == c) {
      chr = (void *)str;
      break;
    }
    str++;
  }
  return chr;
}
