#include "s21_string.h"
// Функция strstr ищет первое вхождение подстроки *needle в строке *haystack и
// возвращает указатель на это вхождение. вход: s21_strstr("Эта программа
// написана в Linux Ubuntu","Linux") вывод: Linux Ubuntu
char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  if (needle[0] == '\0') {
    result = (char *)haystack;
  } else {
    if (!(haystack == S21_NULL || needle == S21_NULL)) {
      for (s21_size_t i = 0; result == S21_NULL && haystack[i] != '\0'; i++) {
        s21_size_t j = 0;
        while (haystack[i + j] == needle[j] && needle[j] != '\0') j++;
        if (needle[j] == '\0') result = (char *)haystack + i;
      }
    }
  }

  return result;
}
