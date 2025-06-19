#include "s21_string.h"
// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

// char result[200] = "В современном мире программирование стало неотъемлемой
// частью технологического прогресса. "; const char *str = "Новые идеи.";
// s21_strncat(bigString, shortString, 11); // "Новые идеи." — 11 символов

// result содержит:
// В современном мире программирование стало неотъемлемой частью
// технологического прогресса. Новые идеи.

char *s21_strncat(char *result, const char *str, s21_size_t size) {
  int strLength = s21_strlen(result);

  for (s21_size_t x = 0; x < size && str[x] != '\0'; x += 1) {
    result[strLength + x] = str[x];
    result[strLength + x + 1] = '\0';
  }

  return result;
}
