#include "headers/s21_wchar.h"

// Функция преобразует wide-строку (массив широких символов) wcstr в
// многобайтовую строку (UTF-8). Результат записывается в mbstr, не более чем
// count байт (включая завершающий '\0'). Возвращает количество записанных байт
// (без завершающего нуля).
s21_size_t s21_wcstombs(char* mbstr, const s21_wchar_t* wcstr,
                        s21_size_t count) {
  s21_size_t converted = 0;  // Счётчик записанных байт

  // Если входная wide-строка равна NULL
  if (wcstr == S21_NULL) {
    if (mbstr != S21_NULL) {
      *mbstr = '\0';  // Если выходной буфер не NULL, делаем его пустым
    }
    return 0;  // Ничего не скопировано
  }

  // Основной цикл: пока не дошли до конца wide-строки и не превысили лимит по
  // байтам
  while (*wcstr != L'\0' &&
         converted < count - 1) {  // Оставляем место для '\0'
    if (*wcstr < 0x80) {  // Если символ ASCII (один байт)
      mbstr[converted++] = (char)*wcstr;
    } else if (*wcstr <
               0x800) {  // Символ в диапазоне U+0080..U+07FF (2 байта в UTF-8)
      mbstr[converted++] =
          (char)((*wcstr >> 6) | 0xC0);  // Первый байт: 110xxxxx
      mbstr[converted++] =
          (char)((*wcstr & 0x3F) | 0x80);  // Второй байт: 10xxxxxx
    } else {  // Символ в диапазоне U+0800..U+FFFF (3 байта в UTF-8)
      mbstr[converted++] =
          (char)((*wcstr >> 12) | 0xE0);  // Первый байт: 1110xxxx
      mbstr[converted++] =
          (char)(((*wcstr >> 6) & 0x3F) | 0x80);  // Второй байт: 10xxxxxx
      mbstr[converted++] =
          (char)((*wcstr & 0x3F) | 0x80);  // Третий байт: 10xxxxxx
    }
    wcstr++;  // Переход к следующему широкому символу
  }

  // Завершаем строку нулём, если есть место
  if (mbstr != S21_NULL && converted < count) {
    mbstr[converted] = '\0';
  }

  return converted;  // Возвращаем количество записанных байт (без учёта
                     // завершающего нуля)
}
