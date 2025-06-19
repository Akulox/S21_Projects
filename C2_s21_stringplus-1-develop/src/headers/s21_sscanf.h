#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <ctype.h>
#include <float.h>

#include "../s21_string.h"
#include "baseStruct.h"

void scanf_setSpecifierWidth(Specifier *specifier, const char **ptr);
void scanf_setSpecifierSize(Specifier *specifier, const char **ptr);
void scanf_setSpecifierType(Specifier *specifier, const char **ptr);
int parse_pointer(const char **str, Specifier specifier, va_list args);
int parse_char(const char **str, Specifier specifier, va_list args);
int parse_string(const char **str, Specifier specifier, va_list args);

Bool parse_oct(const char **str, void *value, Specifier specifier);
Bool parse_dec(const char **str, void *value, Specifier specifier);
Bool parse_hex(const char **str, void *value, Specifier specifier);

void parse_format(const char **format, Specifier *specifier);
int parse_char(const char **str, Specifier specifier, va_list args);
int parse_int(const char **str, Specifier specifier, va_list args);
int parse_uint(const char **str, Specifier specifier, va_list args);

int parse_float(const char **str, Specifier specifier, va_list args);
Bool parse_double(const char **str, void *value, Specifier specifier);
Bool nilPointerCheck(const char **str);

void integerAssign(unsigned long num, void *value, Specifier specifier);

IntType intTypeDefiner(const char **str);

void skipSpaces(const char **str);

#endif
