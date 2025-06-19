#include "s21_string.h"
// Сравнивает не более первых n байтов str1 и str2, используется для
// посимвольного сравнения первых n символов двух строк str1 и str2. Если строка
// 1 и два совпадает возвращает 0. Если строки отличаются, функция возвращает
// разницу кодов первого отличающегося символа: Если символ из str1 больше
// символа из str2 , результат будет положительным числом. Если символ из str1
// меньше символа из str2, результат будет отрицательным числом.

// str1 = "hello";
// str2 = "heloy";
// int result = s21_strncmp(str1, str2, 5);

// на 3 позиции l(ASCII 108) и o(ASCII 111) 108 - 111, результат сравнения будет
// отрицательным числом. result = -3

int s21_strncmp(const char *str_1, const char *str_2, s21_size_t size) {
  int result = 0;

  // while (size--) {
  //   if (*str_1 == *str_2) {
  //     if (!(*str_1)) break;
  //   } else {
  //     result = *str_1 - *str_2;
  //   }
  //   str_1++;
  //   str_2++;
  // }

  for (s21_size_t x = 0; x < size; x += 1) {
    if (str_1[x] == str_2[x]) {
      if (str_1[x]) continue;
      break;
    } else {
      result = str_1[x] - str_2[x];
    }
    break;
  }

  return result;
}
