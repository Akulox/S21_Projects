#include "headers/s21_sprintf.h"

// Главная функция
int s21_sprintf(char *str, const char *format, ...) {
  if (!str || !format) return -1;  // Проверка валидности параметров

  char *start = str;
  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;
      Specifier specifier = {0};

      getSpecifierFromString(&specifier, &format);
      setSpecifierWidthPrecisionFromList(&specifier, args);
      processSpecifier(&str, args, specifier, start);
    } else {
      *str++ = *format++;
    }
  }

  va_end(args);

  // Сохраняем позицию конца строки перед добавлением '\0'
  char *end = str;
  *str = '\0';

  // Возвращаем количество записанных символов
  return end - start;
}

// Обработка различных типов спецификаторов
void processSpecifier(char **str, va_list args, Specifier specifier,
                      char *start) {
  switch (specifier.type) {
    case PERCENT:
      *(*str)++ = '%';
      break;
    case COUNT:
      *(va_arg(args, int *)) = *str - start;
      break;
    case POINTER:
      handlePointerFromList(str, args, specifier);
      break;
    case CHAR:
      handleCharFromList(str, args, specifier);
      break;
    case STRING:
      handleStringFromList(str, args, specifier);
      break;
    case UINT:
      handleULLIntFromList(str, args, specifier);
      break;
    case INT:
      handleLLIntFromList(str, args, specifier);
      break;
    case DOUBLE:
      handleDoubleFromList(str, args, specifier);
      break;
    default:
      break;
  }
}

// Утилитарные функции для заполнения
void fillWithChar(char **ptr, char ch, s21_size_t count) {
  if (count > 0) {
    s21_memset(*ptr, ch, count);
    *ptr += count;
  }
}

void fillWithSpaces(char **ptr, s21_size_t count) {
  fillWithChar(ptr, ' ', count);
}

void fillWithZeros(char **ptr, s21_size_t count) {
  fillWithChar(ptr, '0', count);
}

// Применение размера к целому числу
void applyIntegerSize(void *value, Size size, Bool isUnsigned) {
  if (isUnsigned) {
    unsigned long int *uval = (unsigned long int *)value;
    switch (size) {
      case SHORT:
        *uval = (unsigned short)*uval;
        break;
      case NORMAL:
        *uval = (unsigned int)*uval;
        break;
      default:
        break;
    }
  } else {
    long int *val = (long int *)value;
    switch (size) {
      case SHORT:
        *val = (short)*val;
        break;
      case NORMAL:
        *val = (int)*val;
        break;
      default:
        break;
    }
  }
}

void setSpecifierWidthPrecisionFromList(Specifier *specifier, va_list args) {
  if (specifier->widthArgRequired) {
    int wid = va_arg(args, int);
    if (wid < 0) {
      wid = -wid;
      specifier->facingLeft = true;
    }
    specifier->width = wid;
  }

  if (specifier->precisionArgRequired) {
    int prec = va_arg(args, int);
    if (prec >= 0) {  // изменено с > -1 для ясности
      specifier->precision = prec;
      specifier->isPrecisionSet = true;
    }
  }

  // Установка точности по умолчанию
  if (!specifier->isPrecisionSet) {
    switch (specifier->type) {
      case DOUBLE:
        specifier->precision = DEFAULT_PRECISION;
        specifier->isPrecisionSet = true;
        break;
      case STRING:
        // Для строк точность не устанавливается по умолчанию
        specifier->isPrecisionSet = false;
        break;
      case CHAR:
        // Для символов точность не применяется
        specifier->isPrecisionSet = false;
        break;
      default:
        specifier->precision = 1;
        specifier->isPrecisionSet = true;
        break;
    }
  }
}

// Обработка символов
void handleCharFromList(char **str, va_list args, Specifier specifier) {
  char buff[BUFFER_SIZE] = {0};
  int ch;

  // Отключаем точность для символов
  specifier.isPrecisionSet = false;

  if (specifier.size == LONG) {
    s21_wchar_t wc = va_arg(args, s21_wint_t);
    s21_wchar_t pseudoString[2] = {wc, 0};
    s21_wcstombs(buff, pseudoString, BUFFER_SIZE);
  } else {
    ch = va_arg(args, int);
    buff[0] = (char)ch;
    buff[1] = '\0';
  }

  // Для символов длина всегда 1, даже для '\0'
  char *ptr = *str;
  s21_size_t charLen = 1;
  s21_size_t totalWidth =
      (charLen < specifier.width) ? specifier.width : charLen;
  s21_size_t spaceFill = totalWidth - charLen;

  // Заполнение слева (если не выравнивание по левому краю)
  if (!specifier.facingLeft) {
    fillWithSpaces(&ptr, spaceFill);
  }

  // Копируем символ
  *ptr++ = buff[0];

  // Заполнение справа (если выравнивание по левому краю)
  if (specifier.facingLeft) {
    fillWithSpaces(&ptr, spaceFill);
  }

  *str = ptr;
}

// Обработка строк
void handleStringFromList(char **str, va_list args, Specifier specifier) {
  char buff[BUFFER_SIZE] = {0};
  const char *nullStr = "(null)";

  if (specifier.size == LONG) {
    s21_wchar_t *wString = va_arg(args, s21_wchar_t *);
    if (wString) {
      s21_wcstombs(buff, wString, wstrLen(wString) + 1);
      strToStr(buff, str, specifier);
    } else {
      specifier.precision = 6;
      strToStr((char *)nullStr, str, specifier);
    }
  } else {
    char *string = va_arg(args, char *);
    if (string) {
      strToStr(string, str, specifier);
    } else {
      specifier.precision = 6;
      strToStr((char *)nullStr, str, specifier);
    }
  }
}

// Обработка указателей
void handlePointerFromList(char **str, va_list args, Specifier specifier) {
  unsigned long int point = va_arg(args, unsigned long int);
  const char *nilStr = "(nil)";

  if (point) {
    ullToStr(point, str, specifier);
  } else {
    specifier.precision = 5;
    strToStr((char *)nilStr, str, specifier);
  }
}

// Обработка беззнаковых целых чисел
void handleULLIntFromList(char **str, va_list args, Specifier specifier) {
  unsigned long int value = va_arg(args, unsigned long int);
  applyIntegerSize(&value, specifier.size, true);
  ullToStr((unsigned long long int)value, str, specifier);
}

// Обработка знаковых целых чисел
void handleLLIntFromList(char **str, va_list args, Specifier specifier) {
  long int dec = va_arg(args, long int);
  applyIntegerSize(&dec, specifier.size, false);

  if (dec < 0) {
    specifier.belowZero = true;
    dec = -dec;
  }

  ullToStr((unsigned long long int)dec, str, specifier);
}

// Обработка чисел с плавающей точкой
void handleDoubleFromList(char **str, va_list args, Specifier specifier) {
  long double doub;

  if (specifier.size == LONG_FLOAT)
    doub = va_arg(args, long double);
  else
    doub = va_arg(args, double);

  // Простая проверка на бесконечность
  // Бесконечность больше любого конечного числа
  if (doub > 1e308) {  // Положительная бесконечность
    char infStr[] = "inf";
    strToStr(infStr, str, specifier);
    return;
  }

  if (doub < -1e308) {  // Отрицательная бесконечность
    char infStr[] = "-inf";
    strToStr(infStr, str, specifier);
    return;
  }

  // Проверка на NaN
  if (doub != doub) {
    char nanStr[] = "nan";
    strToStr(nanStr, str, specifier);
    return;
  }

  // Обработка обычных чисел
  if (doub < 0) {
    specifier.belowZero = true;
    doub = -doub;
  }

  if (specifier.scientificNotation) {
    my_etod(doub, str, specifier);
  } else if (specifier.chooseNotation) {
    my_gtod(doub, str, specifier);
  } else {
    my_dtoa(doub, str, specifier);
  }
}

// Парсинг спецификатора из строки
void getSpecifierFromString(Specifier *specifier, const char **ptr) {
  setSpecifierFlags(specifier, ptr);
  setSpecifierWidth(specifier, ptr);
  setSpecifierPrecision(specifier, ptr);
  setSpecifierSize(specifier, ptr);
  setSpecifierType(specifier, ptr);
}

// Установка флагов спецификатора
void setSpecifierFlags(Specifier *specifier, const char **ptr) {
  while (1) {
    switch (**ptr) {
      case '-':
        specifier->facingLeft = true;
        break;
      case '+':
        specifier->sign = true;
        break;
      case ' ':
        specifier->space = true;
        break;
      case '#':
        specifier->specialOutputRequired = true;
        break;
      case '0':
        specifier->zeroFill = true;
        break;
      default:
        return;
    }
    (*ptr)++;
  }
}

// Установка ширины поля
void setSpecifierWidth(Specifier *specifier, const char **ptr) {
  if (**ptr == '*') {
    specifier->widthArgRequired = true;
    (*ptr)++;
  } else {
    while (**ptr >= '0' && **ptr <= '9') {
      specifier->width = specifier->width * 10 + (**ptr - '0');
      (*ptr)++;
    }
  }
}

// Установка точности
void setSpecifierPrecision(Specifier *specifier, const char **ptr) {
  if (**ptr == '.') {
    (*ptr)++;
    if (**ptr == '*') {
      specifier->precisionArgRequired = true;
      (*ptr)++;
    } else {
      specifier->isPrecisionSet = true;
      specifier->precision = 0;
      while (**ptr >= '0' && **ptr <= '9') {
        specifier->precision = specifier->precision * 10 + (**ptr - '0');
        (*ptr)++;
      }
    }
  }
}

// Установка размера (h, l, L)
void setSpecifierSize(Specifier *specifier, const char **ptr) {
  switch (**ptr) {
    case 'h':
      specifier->size = SHORT;
      (*ptr)++;
      break;
    case 'l':
      specifier->size = LONG;
      (*ptr)++;
      break;
    case 'L':
      specifier->size = LONG_FLOAT;
      (*ptr)++;
      break;
    default:
      break;
  }
}

// Установка типа спецификатора
void setSpecifierType(Specifier *specifier, const char **ptr) {
  switch (*(*ptr)++) {
    case 'c':
      specifier->type = CHAR;
      break;
    case 's':
      specifier->type = STRING;
      break;

    case 'd':
    case 'i':
      specifier->type = INT;
      specifier->intType = DEC;
      break;

    case 'E':
      specifier->upperCaseValues = true;
      /* Falls through */
    case 'e':
      specifier->type = DOUBLE;
      specifier->scientificNotation = true;
      specifier->intType = DEC;
      break;

    case 'f':
      specifier->type = DOUBLE;
      specifier->intType = DEC;
      break;

    case 'G':
      specifier->upperCaseValues = true;
      /* Falls through */
    case 'g':
      specifier->type = DOUBLE;
      specifier->chooseNotation = true;
      specifier->intType = DEC;
      break;

    case 'o':
      specifier->type = UINT;
      specifier->intType = OCT;
      break;

    case 'u':
      specifier->type = UINT;
      specifier->intType = DEC;
      break;

    case 'X':
      specifier->upperCaseValues = true;
      /* Falls through */
    case 'x':
      specifier->type = UINT;
      specifier->intType = HEX;
      break;

    case 'p':
      specifier->type = POINTER;
      specifier->specialOutputRequired = true;
      specifier->intType = HEX;
      break;

    case 'n':
      specifier->type = COUNT;
      break;
    case '%':
      specifier->type = PERCENT;
      break;
    default:
      break;
  }
}

// Получение длины числа в заданной системе счисления
s21_size_t getULL_Length(unsigned long long int value,
                         unsigned long long int dev) {
  s21_size_t res = value ? 1 : 0;

  while (value >= dev) {
    value /= dev;
    res++;
  }
  return res;
}

// Преобразование целого числа в строку
void ullToStr(unsigned long long int value, char **str, Specifier specifier) {
  // Расчет префиксов и знака
  s21_size_t octPrefix = 0;
  s21_size_t sign = 0;
  s21_size_t hexPrefix = 0;

  switch (specifier.intType) {
    case OCT:
      octPrefix = (specifier.specialOutputRequired) ? 1 : 0;
      break;
    case DEC:
      sign = (specifier.type != UINT &&
              (specifier.sign || specifier.space || specifier.belowZero))
                 ? 1
                 : 0;
      break;
    case HEX:
      hexPrefix = (specifier.specialOutputRequired && value) ? 2 : 0;
      break;
    default:
      break;
  }

  // Расчет длин и заполнителей
  s21_size_t valueLen = getULL_Length(value, specifier.intType);
  s21_size_t fullValueLen = valueLen + octPrefix;
  s21_size_t minValueLen = specifier.precision;
  s21_size_t zeroFill =
      (fullValueLen > minValueLen) ? 0 : minValueLen - fullValueLen;
  fullValueLen += sign + hexPrefix;

  s21_size_t minInsertLen = specifier.width;
  s21_size_t spaceFill = (fullValueLen + zeroFill > minInsertLen)
                             ? 0
                             : minInsertLen - (fullValueLen + zeroFill);
  s21_size_t insertLen = fullValueLen + zeroFill + spaceFill;

  // Корректировка заполнителей при флаге '0'
  if (specifier.zeroFill && !specifier.facingLeft) {
    zeroFill += spaceFill;
    spaceFill = 0;
  }

  char *ptr = *str;
  char *insertLast = ptr + insertLen;

  // Заполнение слева (если не выравнивание по левому краю)
  if (!specifier.facingLeft) {
    fillWithSpaces(&ptr, spaceFill);
  }

  // Запись префиксов
  if (sign) {
    if (specifier.belowZero)
      *ptr++ = '-';
    else if (specifier.sign)
      *ptr++ = '+';
    else
      *ptr++ = ' ';
  }

  if (octPrefix) {
    *ptr++ = '0';
  }

  if (hexPrefix) {
    *ptr++ = '0';
    *ptr++ = specifier.upperCaseValues ? 'X' : 'x';
  }

  // Заполнение нулями
  fillWithZeros(&ptr, zeroFill);

  // Запись значения
  ptr += valueLen;
  char *valueEnd = ptr;

  while (value > 0) {
    char c = value % specifier.intType;
    if (c > 9) {
      c -= 10;
      c = specifier.upperCaseValues ? c + 'A' : c + 'a';
    } else {
      c += '0';
    }
    *(--ptr) = c;
    value /= specifier.intType;
  }

  ptr = valueEnd;

  // Заполнение справа (если выравнивание по левому краю)
  if (specifier.facingLeft) {
    fillWithSpaces(&ptr, spaceFill);
  }

  *str = insertLast;
}

// Преобразование строки с учетом форматирования
void strToStr(char *string, char **str, Specifier specifier) {
  s21_size_t stringLen = s21_strlen(string);
  s21_size_t outputLen = stringLen;

  // Применяем точность только если она установлена
  if (specifier.isPrecisionSet && specifier.precision < stringLen) {
    outputLen = specifier.precision;
  }

  // Ширина поля
  s21_size_t totalWidth =
      (outputLen < specifier.width) ? specifier.width : outputLen;
  s21_size_t spaceFill = totalWidth - outputLen;

  char *ptr = *str;

  // Заполнение слева (если не выравнивание по левому краю)
  if (!specifier.facingLeft) {
    fillWithSpaces(&ptr, spaceFill);
  }

  // Копируем строку
  s21_memcpy(ptr, string, outputLen);
  ptr += outputLen;

  // Заполнение справа (если выравнивание по левому краю)
  if (specifier.facingLeft) {
    fillWithSpaces(&ptr, spaceFill);
  }

  *str = ptr;
}

// Длина wide-строки
s21_size_t wstrLen(s21_wchar_t *num) {
  s21_size_t res = 0;
  while (*num++) res++;
  return res;
}

// Преобразование double в строку (обычная нотация)
void my_dtoa(long double num, char **str, Specifier specifier) {
  Specifier specifierForIntPart = specifier;
  specifierForIntPart.type = INT;
  specifierForIntPart.precision = 1;

  Specifier specifierForFracPart = specifier;
  specifierForFracPart.type = UINT;
  specifierForFracPart.width = 0;

  // Корректировка ширины для целой части
  if (!specifier.chooseNotation || (specifier.chooseNotation && num < 1.0)) {
    specifierForIntPart.width =
        safeSizeTSub(specifier.width, specifier.precision);
    if (specifier.precision || specifier.specialOutputRequired)
      specifierForIntPart.width = safeSizeTSub(specifierForIntPart.width, 1);
  }

  if (specifier.scientificNotation) {
    s21_size_t expLen = getULL_Length(specifier.storedExponent, 10);
    expLen = (expLen < MIN_EXPONENT_WIDTH) ? MIN_EXPONENT_WIDTH : expLen;
    specifierForIntPart.width =
        safeSizeTSub(specifierForIntPart.width, expLen + 2);
  }

  // Разделение на целую и дробную части
  s21_size_t int_part;
  if (specifier.chooseNotation && isAlmostAnInt(num)) {
    int_part = (s21_size_t)(num + 0.5);
    specifierForFracPart.precision = 0;
  } else if (!specifier.precision) {
    int_part = (s21_size_t)(num + 0.5);
  } else {
    int_part = (s21_size_t)num;
  }

  if (specifier.facingLeft) {
    specifierForIntPart.width = 0;
  }

  long double frac_part = (s21_size_t)num ? num - int_part : num + int_part;

  // Масштабирование дробной части
  for (s21_size_t j = 0; j < specifierForFracPart.precision; j++) {
    frac_part *= 10;
  }

  s21_size_t fractULL = (s21_size_t)(frac_part + 0.5);

  // Удаление лишних нулей для g/G формата
  if (specifier.chooseNotation && specifierForFracPart.precision)
    while (fractULL % 10 == 0 || !fractULL) {
      fractULL /= 10;
      specifierForFracPart.precision =
          safeSizeTSub(specifierForFracPart.precision, 1);
    }

  char *start = *str;

  // Вывод целой части
  ullToStr(int_part, str, specifierForIntPart);

  // Вывод десятичной точки
  if (specifierForFracPart.precision || specifier.specialOutputRequired)
    *((*str)++) = '.';

  // Корректировка ширины для дробной части
  if (specifier.facingLeft && !specifier.scientificNotation)
    specifierForFracPart.width = safeSizeTSub(specifier.width, (*str - start));

  // Вывод дробной части
  ullToStr(fractULL, str, specifierForFracPart);
}

// Нормализация числа для научной нотации
long double normalizeDouble(long double num, int *exponent) {
  *exponent = 0;

  if (num == 0.0) return num;

  // Приведение к диапазону [1.0, 10.0)
  while (num >= 10.0) {
    num /= 10.0;
    (*exponent)++;
  }
  while (num > 0 && num < 1.0) {
    num *= 10.0;
    (*exponent)--;
  }

  return num;
}

// Преобразование double в экспоненциальную строку
void my_etod(long double num, char **str, Specifier specifier) {
  Specifier specifierForExponent = {
      .isPrecisionSet = true,
      .precision = MIN_EXPONENT_WIDTH,
      .intType = DEC,
      .sign = true,
      .facingLeft = true,
  };

  int exponent = 0;
  num = normalizeDouble(num, &exponent);

  if (exponent < 0) {
    specifierForExponent.belowZero = true;
    exponent = -exponent;
  }

  char *start = *str;
  my_dtoa(num, str, specifier);

  *((*str)++) = specifier.upperCaseValues ? 'E' : 'e';

  if (specifier.facingLeft) {
    specifierForExponent.width = safeSizeTSub(specifier.width, (*str - start));
  }

  ullToStr(exponent, str, specifierForExponent);
}

// Автоматический выбор нотации (g/G формат)
void my_gtod(long double num, char **str, Specifier specifier) {
  if (!specifier.precision) specifier.precision = 1;

  // Обработка особых случаев
  if (isAlmostAnInt(num) && !(int)num) {
    specifier.precision = 0;
    my_dtoa(num, str, specifier);
    return;
  }

  // Определение экспоненты для принятия решения о формате
  int exponent = (log10l(num) > 0) ? log10l(num) + 1. : log10l(num) - 1.;

  if (exponent > 0) {
    if ((s21_size_t)exponent + 1 > specifier.precision) {
      // Использовать научную нотацию
      specifier.precision = safeSizeTSub(specifier.precision, 1);
      specifier.scientificNotation = true;
      my_etod(num, str, specifier);
    } else {
      // Использовать обычную нотацию
      specifier.precision = safeSizeTSub(specifier.precision, exponent);
      my_dtoa(num, str, specifier);
    }
  } else if (exponent > -5) {
    // Обычная нотация для малых чисел
    specifier.precision += (-exponent) - 1;
    my_dtoa(num, str, specifier);
  } else {
    // Научная нотация для очень малых чисел
    specifier.precision = safeSizeTSub(specifier.precision, 1);
    specifier.scientificNotation = true;
    my_etod(num, str, specifier);
  }
}

// Безопасное вычитание для size_t
s21_size_t safeSizeTSub(s21_size_t value, s21_size_t sub) {
  return (value < sub) ? 0 : value - sub;
}

// Проверка, является ли число близким к целому
Bool isAlmostAnInt(long double value) {
  return fabsl(value - roundl(value)) < DOUBLE_EPSILON;
}
