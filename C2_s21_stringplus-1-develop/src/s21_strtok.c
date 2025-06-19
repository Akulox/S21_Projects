#include "s21_string.h"
Bool s21_check(char c, const char *delim);

// делит строку *str="Привет, как дела, как настроение?" на токены   *delim=","
// - разделители
//  пример
// вход: s21_strtok("Привет, как дела, как настроение?",",")
// вывод:
// Привет
// как дела
// как настроение
char *s21_strtok(char *str, const char *delim) {
  static char *buffer = S21_NULL;
  char *start_ptr = S21_NULL;
  char *result = S21_NULL;

  if (delim != S21_NULL) {
    if (str != S21_NULL) {
      buffer = str;
    }

    if (buffer != S21_NULL) {
      // Пропускаем начальные разделители
      while (*buffer && s21_check(*buffer, delim)) {
        buffer++;
      }

      if (*buffer != '\0') {
        start_ptr = buffer;

        // Ищем следующий разделитель
        while (*buffer && !s21_check(*buffer, delim)) {
          buffer++;
        }

        if (*buffer) {
          *buffer = '\0';
          buffer++;
        } else {
          buffer = S21_NULL;
        }

        result = start_ptr;
      } else {
        buffer = S21_NULL;
      }
    }
  }

  return result;
}
Bool s21_check(char c, const char *delim) {
  Bool ptr = false;
  for (s21_size_t i = 0; i < s21_strlen(delim); i++) {
    if (c == delim[i]) {
      ptr = true;
      break;
    }
  }
  return ptr;
}
