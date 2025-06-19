#include "headers/s21_stringCS.h"

// Функция удаляет указанные символы trim_chars с начала и конца строки src.
// Возвращает новую строку (выделенную через calloc) без "лишних" символов по
// краям. Если src или trim_chars == S21_NULL, возвращает S21_NULL.
void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;  // Указатель на результат, изначально NULL

  // Проверка на корректность входных данных
  if (src == S21_NULL || trim_chars == S21_NULL) return res;

  // Указатель на первый символ исходной строки
  const char *first = src;
  // Указатель на последний символ исходной строки (до '\0')
  const char *last = src + s21_strlen(src) - 1;

  // Сдвигаем first вперёд, пока встречаем символы из trim_chars
  while (first <= last && s21_strchr(trim_chars, *first)) first++;

  // Сдвигаем last назад, пока встречаем символы из trim_chars
  while (last >= first && s21_strchr(trim_chars, *last)) last--;

  // Вычисляем длину результирующей строки (от first до last включительно)
  s21_size_t len = last - first + 1;

  // Выделяем память под результат + '\0'
  res = (char *)calloc(len + 1, sizeof(char));
  if (res == S21_NULL)
    return res;  // Если не удалось выделить память, возвращаем NULL

  // Копируем "очищенную" часть строки в результат
  s21_strncpy(res, first, len);

  // Возвращаем указатель на новую строку
  return res;
}
