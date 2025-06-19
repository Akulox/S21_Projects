#include "headers/s21_strerror.h"

#include "s21_string.h"

// Функция возвращает строковое описание ошибки по её коду errnum. Если код
// ошибки не входит в допустимый диапазон, возвращается строка "Unknown error
// <число>".
/*
 s21_strerror - возвращает строковое описание ошибки по её коду errnum.
 Если код ошибки не входит в допустимый диапазон, возвращается строка
 "Unknown error <число>".

 errnum Код ошибки
 return Указатель на статический буфер с описанием ошибки
 */
void s21_num_to_str(int num, char *str);

char *s21_strerror(int errnum) {
  static char str[112] = {'\0'};

  if (errnum < 0 || errnum >= ERR_LIST_SIZE) {
    char str_num[12];
    s21_num_to_str(errnum, str_num);
    s21_strncpy(str, "Unknown error ", s21_strlen("Unknown error ") + 1);
    s21_strncat(str, str_num, sizeof(str) - s21_strlen(str) - 1);
  } else {
    char *err_list[] = ERR_LIST;
    s21_strncpy(str, err_list[errnum], sizeof(str));
  }
  return str;
}
/*
 s21_num_to_str - преобразует целое число в строку.
 Обрабатывает отрицательные числа, добавляя знак '-'.

 num Число для преобразования
 str Буфер для результата (должен быть достаточно большим)
 */
void s21_num_to_str(int num, char *str) {
  int i = 0;
  Bool is_negative = false;

  if (num < 0) {
    is_negative = true;
    num *= -1;
  }

  do {
    str[i++] = (num % 10) + '0';
    num /= 10;
  } while (num > 0);
  if (is_negative) {
    str[i++] = '-';
  }
  str[i] = '\0';

  for (int j = 0; j < i / 2; j++) {
    char temp = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = temp;
  }
}
