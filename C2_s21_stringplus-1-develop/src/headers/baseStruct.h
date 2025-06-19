#ifndef S21_BASESTRUCT_H
#define S21_BASESTRUCT_H

#include <limits.h>
#include <stdarg.h>

#include "s21_wchar.h"

typedef enum {
  NONE,
  PERCENT,
  COUNT,
  POINTER,
  CHAR,
  STRING,
  INT,
  UINT,
  DOUBLE,
} Type;

typedef enum {
  NORMAL,
  SHORT,
  LONG,
  LONG_FLOAT,
} Size;

typedef enum {
  FREE,
  OCT = 8,
  DEC = 10,
  HEX = 16,
} IntType;

// Структура для хранения параметров спецификатора формата
typedef struct {
  Type type;  // Тип спецификатора (%d, %s, %f и т.д.)
  Size size;  // Размер (h, l, L)

  // Флаги форматирования
  Bool sign;   // Флаг '+' - всегда показывать знак
  Bool space;  // Флаг ' ' - пробел перед положительным числом
  Bool facingLeft;  // Флаг '-' - выравнивание по левому краю
  Bool zeroFill;  // Флаг '0' - заполнение нулями
  Bool specialOutputRequired;  // Флаг '#' - альтернативная форма вывода

  // Ширина и точность
  Bool isPrecisionSet;  // Установлена ли точность явно
  s21_size_t width;     // Минимальная ширина поля
  s21_size_t precision;  // Точность (кол-во знаков после запятой)

  Bool widthArgRequired;  // Ширина задается через аргумент (*)
  Bool precisionArgRequired;  // Точность задается через аргумент (*)

  // Параметры для чисел
  IntType intType;          // Система счисления (8, 10, 16)
  Bool belowZero;           // Число отрицательное
  Bool scientificNotation;  // Научная нотация (e/E)
  Bool chooseNotation;  // Автоматический выбор нотации (g/G)
  Bool upperCaseValues;  // Использовать заглавные буквы
  s21_size_t storedExponent;  // Хранение экспоненты для научной нотации

  Bool isWidthSet;     // Диапазон считывания для sscanf
  Bool ignoreWriting;  // Игнорировать запись для sscanf

} Specifier;

#endif
