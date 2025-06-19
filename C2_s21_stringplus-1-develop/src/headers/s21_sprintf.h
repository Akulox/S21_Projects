#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>

#include "../s21_string.h"
#include "baseStruct.h"

#define BUFFER_SIZE 10240
#define DOUBLE_EPSILON 1E-15L  // Точность для сравнения double
#define DEFAULT_PRECISION 6
#define MIN_EXPONENT_WIDTH 2

// Утилитарные функции
s21_size_t getULL_Length(unsigned long long int value,
                         unsigned long long int dev);
s21_size_t safeSizeTSub(s21_size_t value, s21_size_t sub);
Bool isAlmostAnInt(long double value);
s21_size_t wstrLen(s21_wchar_t *num);

// Функции для заполнения строки символами
void fillWithChar(char **ptr, char ch, s21_size_t count);
void fillWithSpaces(char **ptr, s21_size_t count);
void fillWithZeros(char **ptr, s21_size_t count);

// Функция для преобразования размера числа
void applyIntegerSize(void *value, Size size, Bool isUnsigned);

// Парсинг спецификатора
void getSpecifierFromString(Specifier *specifier, const char **ptr);
void setSpecifierFlags(Specifier *specifier, const char **ptr);
void setSpecifierWidth(Specifier *specifier, const char **ptr);
void setSpecifierPrecision(Specifier *specifier, const char **ptr);
void setSpecifierSize(Specifier *specifier, const char **ptr);
void setSpecifierType(Specifier *specifier, const char **ptr);

// Функции для вывода значений в строку
void strToStr(char *string, char **str, Specifier specifier);
void ullToStr(unsigned long long int value, char **str, Specifier specifier);

// Функции для работы с double
void my_dtoa(long double num, char **str, Specifier specifier);
void my_etod(long double num, char **str, Specifier specifier);
void my_gtod(long double num, char **str, Specifier specifier);
long double normalizeDouble(long double num, int *exponent);

// Обработчики для разных типов данных
void processSpecifier(char **str, va_list args, Specifier specifier,
                      char *start);
void setSpecifierWidthPrecisionFromList(Specifier *specifier, va_list args);
void handlePointerFromList(char **str, va_list args, Specifier specifier);
void handleULLIntFromList(char **str, va_list args, Specifier specifier);
void handleLLIntFromList(char **str, va_list args, Specifier specifier);
void handleDoubleFromList(char **str, va_list args, Specifier specifier);
void handleCharFromList(char **str, va_list args, Specifier specifier);
void handleStringFromList(char **str, va_list args, Specifier specifier);

#endif
