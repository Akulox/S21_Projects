#include "headers/s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int result = 0;
  int countReaded = 0;
  va_list args;
  va_start(args, format);
  const char *str_start = str;

  while (*format) {
    if (isspace(*format)) {
      // Пробелы в формате пропускают любые пробелы в строке
      skipSpaces(&format);
      const char *before_skip = str;
      skipSpaces(&str);
      countReaded += (str - before_skip);
    } else if (*format == '%') {
      Specifier specifier = {0};
      format++;
      parse_format(&format, &specifier);

      if (specifier.type != PERCENT && specifier.type != COUNT) {
        if (specifier.type != CHAR) {
          const char *before_skip = str;
          skipSpaces(&str);
          countReaded += (str - before_skip);
        }
      }

      if (!(*str) && specifier.type != COUNT) {
        result = -1;
        break;
      }

      switch (specifier.type) {
        case NONE:
          break;
        case PERCENT:
          if (*str == '%') {
            str++;
          }
          break;
        case COUNT:
          *va_arg(args, int *) = (int)(str - str_start);
          break;
        case POINTER:
          result += parse_pointer(&str, specifier, args);
          break;
        case CHAR:
          if (!specifier.isWidthSet) {
            specifier.width = 1;
            specifier.isWidthSet = true;
          }
          result += parse_string(&str, specifier, args);
          break;
        case STRING:
          result += parse_string(&str, specifier, args);
          break;
        case INT:
          result += parse_int(&str, specifier, args);
          break;
        case UINT:
          result += parse_uint(&str, specifier, args);
          break;
        case DOUBLE:
          result += parse_float(&str, specifier, args);
          break;
      }
    } else {
      // Формат — обычный символ (литерал): должен строго совпасть
      if (*format == *str) {
        format++;
        str++;
        countReaded++;
      } else {
        // Несовпадение литерала — прекращаем разбор
        break;
      }
    }
  }

  va_end(args);
  return result;
}

// Макрос, которое делает явное присвоение указанного типа "type" по
// void-указателю "value" значение численной переменной "num". Используется в
// функциях считывания для лучшей читаемости кода
#define ASSIGN(type) (*(type *)value = (type)num)

void skipSpaces(const char **str) {
  while (s21_memchr(" \n\t\r\t\v", (int)(**str), 6)) (*str)++;
}

void parse_format(const char **format,
                  Specifier *specifier) {  // "Введите число %23ld %i %c"

  scanf_setSpecifierWidth(specifier, format);
  scanf_setSpecifierSize(specifier, format);
  scanf_setSpecifierType(specifier, format);
}

int parse_uint(const char **str, Specifier specifier, va_list args) {
  Bool result = false;

  long long num = 0;

  if (**str == '-') {
    specifier.belowZero = true;
    (*str)++;
  } else if (**str == '+')
    (*str)++;

  if (**str) {
    switch (specifier.intType) {
      case OCT:
        result = parse_oct(str, &num, specifier);
        break;
      case DEC:
        result = parse_dec(str, &num, specifier);
        break;
      case HEX:
        intTypeDefiner(str);
        result = parse_hex(str, &num, specifier);
        break;
      default:
        return false;
    }
  }

  if (result && !specifier.ignoreWriting) {
    num = num * (specifier.belowZero ? -1 : 1);

    switch (specifier.size) {
      case SHORT:
        *va_arg(args, unsigned short *) = (unsigned short)num;
        break;

      case NORMAL:
        *va_arg(args, unsigned int *) = (unsigned int)num;
        break;

      case LONG:
        *va_arg(args, unsigned long *) = (unsigned long)num;
        break;

      default:
    }
  }

  // Для %* возвращаем 0 (не увеличиваем счетчик), но парсинг был выполнен
  return (result && !specifier.ignoreWriting) ? 1 : 0;
}

int parse_int(const char **str, Specifier specifier, va_list args) {
  Bool result = false;
  long long num = 0;

  if (**str == '-') {
    specifier.belowZero = true;
    (*str)++;
  }

  if (!specifier.intType) specifier.intType = intTypeDefiner(str);

  if (**str) switch (specifier.intType) {
      case OCT:
        result = parse_oct(str, &num, specifier);
        break;
      case DEC:
        result = parse_dec(str, &num, specifier);
        break;
      case HEX:
        result = parse_hex(str, &num, specifier);
        break;
      default:
        return false;
    }

  if (result && !specifier.ignoreWriting) {
    num = num * (specifier.belowZero ? -1 : 1);

    switch (specifier.size) {
      case SHORT:
        *va_arg(args, short *) = (short)num;
        break;

      case NORMAL:
        *va_arg(args, int *) = (int)num;
        break;

      case LONG:
        *va_arg(args, long *) = (long)num;
        break;

      default:
    }
  }

  // Для %* возвращаем 0 (не увеличиваем счетчик), но парсинг был выполнен
  return (result && !specifier.ignoreWriting) ? 1 : 0;
}

IntType intTypeDefiner(const char **str) {
  if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    (*str) += 2;
    return HEX;
  } else if (**str == '0') {
    (*str)++;
    return OCT;
  } else if (**str > '0' && **str <= '9')
    return DEC;

  return 0;
}

Bool parse_oct(const char **str, void *value, Specifier specifier) {
  Bool result = false;

  unsigned long num = 0;

  if (**str >= '0' && **str <= '7') {
    result = true;

    while (**str >= '0' && **str <= '7') {
      if (specifier.isWidthSet && !specifier.width--) break;

      if (num > num * 8 + (**str - '0')) {
        (*str)++;
        num = ULONG_MAX;
        continue;
      }

      num = num * 8 + (**str - '0');
      (*str)++;
    }

    integerAssign(num, value, specifier);
  }

  return result;
}

Bool parse_hex(const char **str, void *value, Specifier specifier) {
  Bool result = false;

  unsigned long num = 0;

  if ((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'f') ||
      (**str >= 'A' && **str <= 'F')) {
    result = true;

    while ((**str >= '0' && **str <= '9') || (**str >= 'a' && **str <= 'f') ||
           (**str >= 'A' && **str <= 'F')) {
      unsigned short ch = 0;

      if (**str >= 'a' && **str <= 'f') {
        ch = (**str - 'a') + 10;
      } else if (**str >= 'A' && **str <= 'F') {
        ch = (**str - 'A') + 10;
      } else {
        ch = (**str - '0');
      }

      if (specifier.isWidthSet && !specifier.width--) break;

      if (num > num * 16 + ch) {
        (*str)++;
        num = ULONG_MAX;
        continue;
      }

      num = num * 16 + ch;

      (*str)++;
    }

    integerAssign(num, value, specifier);
  }

  return result;
}

Bool parse_dec(const char **str, void *value, Specifier specifier) {
  Bool result = false;

  unsigned long num = 0;

  if (**str >= '0' && **str <= '9') {
    result = true;

    while (**str >= '0' && **str <= '9') {
      if (specifier.isWidthSet && !specifier.width--) break;

      if (num > num * 10 + (**str - '0')) {
        (*str)++;
        num = ULONG_MAX;
        continue;
      }

      num = num * 10 + (**str - '0');
      (*str)++;
    }

    integerAssign(num, value, specifier);
  }

  return result;
}

void integerAssign(unsigned long num, void *value, Specifier specifier) {
  switch (specifier.type) {
    case INT:

      switch (specifier.size) {
        case SHORT:
          ASSIGN(short);
          break;
        case NORMAL:
          ASSIGN(int);
          break;
        case LONG:
          ASSIGN(long);
          break;
        default:
      }
      break;

    case UINT:

      switch (specifier.size) {
        case SHORT:
          ASSIGN(unsigned short);
          break;
        case NORMAL:
          ASSIGN(unsigned int);
          break;
        case LONG:
          ASSIGN(unsigned long);
          break;
        default:
      }
      break;

    case POINTER:
      ASSIGN(unsigned long);
      break;

    default:
      return;
  }
}

// Функция для чтения указателя из строки
int parse_pointer(const char **str, Specifier specifier, va_list args) {
  Bool result = true;

  unsigned long long num = 0;

  if (!nilPointerCheck(str)) {
    if (**str == '-') {
      (*str)++;
      specifier.belowZero = true;
    } else if (**str == '+')
      (*str)++;

    if (**str) {
      if (intTypeDefiner(str) == HEX) {
        if (specifier.isWidthSet) {
          if (specifier.width > 1)
            specifier.width -= 2;
          else
            specifier.width = 0;
        }
      }
      result = parse_hex(str, &num, specifier);
    }
  }

  if (result && !specifier.ignoreWriting) {
    num = num * (specifier.belowZero ? -1 : 1);
    *va_arg(args, void **) = (void *)num;
  }

  // Для %* возвращаем 0 (не увеличиваем счетчик), но парсинг был выполнен
  return (result && !specifier.ignoreWriting) ? 1 : 0;
}

int parse_string(const char **str, Specifier specifier, va_list args) {
  // Проверка на пустую входную строку
  if (!**str && specifier.type == STRING) {
    return 0;  // Если строка пуста для %s, возвращаем ошибку
  }

  // Получаем указатель на строку, если не требуется пропустить результат
  void *s = S21_NULL;
  if (!specifier.ignoreWriting) {
    if (specifier.size == LONG) {
      s = va_arg(args, s21_wchar_t *);
    } else {
      s = va_arg(args, char *);
    }
  }

  // Определяем максимальное количество символов для чтения
  int max_chars = specifier.isWidthSet ? specifier.width : INT_MAX;
  int read_chars = 0;

  // Для строк (%s) читаем до пробела или конца строки
  // Для символов (%c) читаем точно указанное количество
  Bool stop_at_space = (specifier.type == STRING);

  // Для широких символов
  if (specifier.size == LONG) {
    s21_wchar_t *ws = (s21_wchar_t *)s;
    // Считываем символы
    while (**str && read_chars < max_chars) {
      // Для %s останавливаемся на пробелах, для %c - нет
      if (stop_at_space && (**str == ' ' || **str == '\t' || **str == '\n' ||
                            **str == '\r' || **str == '\v')) {
        break;
      }

      if (ws && !specifier.ignoreWriting) {
        ws[read_chars] = (s21_wchar_t) * *str;  // Простое преобразование
      }
      (*str)++;
      read_chars++;
    }

    // Завершаем строку нулевым символом для строк (не для символов)
    if (ws && !specifier.ignoreWriting && specifier.type == STRING) {
      ws[read_chars] = L'\0';
    }
  } else {
    char *cs = (char *)s;
    // Считываем символы
    while (**str && read_chars < max_chars) {
      // Для %s останавливаемся на пробелах, для %c - нет
      if (stop_at_space && (**str == ' ' || **str == '\t' || **str == '\n' ||
                            **str == '\r' || **str == '\v')) {
        break;
      }

      if (cs && !specifier.ignoreWriting) {
        cs[read_chars] = **str;  // Сохраняем символ
      }
      (*str)++;
      read_chars++;
    }

    // Завершаем строку нулевым символом для строк (не для символов)
    if (cs && !specifier.ignoreWriting && specifier.type == STRING) {
      cs[read_chars] = '\0';
    }
  }

  // Если ничего не прочитали, это ошибка
  if (read_chars == 0) {
    return 0;
  }

  // Для %* возвращаем 0 (не увеличиваем счетчик), но парсинг был выполнен
  return specifier.ignoreWriting ? 0 : 1;
}

/**
 * Парсинг числа с плавающей точкой
 */
Bool parse_double(const char **str, void *value, Specifier specifier) {
  Bool result = false;
  long double num = 0.0;
  long double fraction = 0.0;
  int exponent = 0;
  Bool negative = false;
  Bool exp_negative = false;
  const char *start = *str;
  int width_left = specifier.isWidthSet ? specifier.width : INT_MAX;

  // Пропускаем пробелы (не учитываются в ширине)
  while (**str == ' ' || **str == '\t' || **str == '\n') (*str)++;

  // Проверяем знак
  if (**str == '-') {
    negative = true;
    (*str)++;
    width_left--;
  } else if (**str == '+') {
    (*str)++;
    width_left--;
  }

  if (width_left <= 0) return false;

  // Проверяем на inf/infinity
  if ((**str == 'i' || **str == 'I') && width_left >= 3) {
    if ((*(*str + 1) == 'n' || *(*str + 1) == 'N') &&
        (*(*str + 2) == 'f' || *(*str + 2) == 'F')) {
      (*str) += 3;
      width_left -= 3;

      // Проверяем полное слово "infinity" если есть место
      if (width_left >= 5 && (**str == 'i' || **str == 'I') &&
          (*(*str + 1) == 'n' || *(*str + 1) == 'N') &&
          (*(*str + 2) == 'i' || *(*str + 2) == 'I') &&
          (*(*str + 3) == 't' || *(*str + 3) == 'T') &&
          (*(*str + 4) == 'y' || *(*str + 4) == 'Y')) {
        (*str) += 5;
      }
      // Используем максимальное значение double как приближение бесконечности
      if (specifier.size == LONG_FLOAT) {
        num = negative ? -LDBL_MAX : LDBL_MAX;
      } else {
        num = negative ? -DBL_MAX : DBL_MAX;
      }
      result = true;
      // Переходим к присваиванию значения
      if (result && !specifier.ignoreWriting) {
        if (negative) num = -num;

        switch (specifier.size) {
          case LONG_FLOAT:
            *(long double *)value = num;
            break;
          case LONG:
            *(double *)value = (double)num;
            break;
          case NORMAL:
          default:
            *(float *)value = (float)num;
            break;
        }
      }
      return result;
    }
  }

  // Проверяем на nan
  if ((**str == 'n' || **str == 'N') && width_left >= 3) {
    if ((*(*str + 1) == 'a' || *(*str + 1) == 'A') &&
        (*(*str + 2) == 'n' || *(*str + 2) == 'N')) {
      (*str) += 3;
      num = 0.0 / 0.0;  // NaN
      result = true;
      // Переходим к присваиванию значения
      if (result && !specifier.ignoreWriting) {
        if (negative) num = -num;

        switch (specifier.size) {
          case LONG_FLOAT:
            *(long double *)value = num;
            break;
          case LONG:
            *(double *)value = (double)num;
            break;
          case NORMAL:
          default:
            *(float *)value = (float)num;
            break;
        }
      }
      return result;
    }
  }

  // Читаем целую часть
  Bool has_digits = false;
  while (**str >= '0' && **str <= '9' && width_left > 0) {
    num = num * 10 + (**str - '0');
    (*str)++;
    width_left--;
    has_digits = true;
    result = true;
  }

  // Читаем дробную часть
  if (**str == '.' && width_left > 0) {
    (*str)++;
    width_left--;
    long double divisor = 10.0;
    while (**str >= '0' && **str <= '9' && width_left > 0) {
      fraction += (**str - '0') / divisor;
      divisor *= 10;
      (*str)++;
      width_left--;
      has_digits = true;
      result = true;
    }
    num += fraction;
  }

  // Если не было цифр, возвращаем ошибку
  if (!has_digits) {
    *str = start;
    return false;
  }

  // Читаем экспоненту для e/E форматов
  if ((**str == 'e' || **str == 'E') && width_left > 0) {
    (*str)++;
    width_left--;

    // Знак экспоненты
    if (**str == '-' && width_left > 0) {
      exp_negative = true;
      (*str)++;
      width_left--;
    } else if (**str == '+' && width_left > 0) {
      (*str)++;
      width_left--;
    }

    // Читаем значение экспоненты
    Bool has_exp_digits = false;
    while (**str >= '0' && **str <= '9' && width_left > 0) {
      exponent = exponent * 10 + (**str - '0');
      (*str)++;
      width_left--;
      has_exp_digits = true;
    }

    if (has_exp_digits) {
      // Применяем экспоненту
      if (exp_negative) exponent = -exponent;
      long double multiplier = 1.0;
      if (exponent > 0) {
        for (int i = 0; i < exponent; i++) {
          multiplier *= 10.0;
        }
        num *= multiplier;
      } else if (exponent < 0) {
        for (int i = 0; i < -exponent; i++) {
          multiplier *= 10.0;
        }
        num /= multiplier;
      }
    }
  }

  // Присваивание значения
  if (result && !specifier.ignoreWriting) {
    if (negative) num = -num;

    switch (specifier.size) {
      case LONG_FLOAT:
        *(long double *)value = num;
        break;
      case LONG:
        *(double *)value = (double)num;
        break;
      case NORMAL:
      default:
        *(float *)value = (float)num;
        break;
    }
  }

  return result;
}

/**
 * Обработчик для спецификаторов f, e, E, g, G
 */
int parse_float(const char **str, Specifier specifier, va_list args) {
  void *ptr = S21_NULL;
  if (!specifier.ignoreWriting) {
    if (specifier.size == LONG_FLOAT) {
      ptr = va_arg(args, long double *);
    } else if (specifier.size == LONG) {
      ptr = va_arg(args, double *);
    } else {
      ptr = va_arg(args, float *);
    }
  }

  long double dummy;
  Bool result =
      parse_double(str, specifier.ignoreWriting ? &dummy : ptr, specifier);

  // Для %* возвращаем 0 (не увеличиваем счетчик), но парсинг был выполнен
  return (result && !specifier.ignoreWriting) ? 1 : 0;
}

Bool nilPointerCheck(const char **str) {
  if (**str == '(' && (*(*str + 1) == 'n' || *(*str + 1) == 'N') &&
      (*(*str + 2) == 'i' || *(*str + 2) == 'I') &&
      (*(*str + 3) == 'l' || *(*str + 3) == 'L') && *(*str + 4) == ')') {
    *str += 5;
    return true;
  }
  return false;
}

void scanf_setSpecifierWidth(Specifier *specifier, const char **ptr) {
  if (**ptr == '*') {
    specifier->ignoreWriting = true;
    (*ptr)++;
  }

  // Читаем ширину после '*' если есть
  while (**ptr >= '0' && **ptr <= '9') {
    specifier->isWidthSet = true;
    specifier->width = specifier->width * 10 + (**ptr - '0');
    (*ptr)++;
  }
}

void scanf_setSpecifierSize(Specifier *specifier, const char **ptr) {  // %i %d
  switch (**ptr) {
    case 'h':
      specifier->size = SHORT;
      break;
    case 'l':
      specifier->size = LONG;
      break;
    case 'L':
      specifier->size = LONG_FLOAT;
      break;
    default:
      return;
  }
  (*ptr)++;
}

void scanf_setSpecifierType(Specifier *specifier, const char **ptr) {
  switch (*(*ptr)++) {
    case 'c':
      specifier->type = CHAR;
      break;
    case 's':
      specifier->type = STRING;
      break;

    case 'd':
      specifier->type = INT;
      specifier->intType = DEC;
      break;
    case 'i':
      specifier->type = INT;
      break;

    case 'E':
      specifier->upperCaseValues = true;
      specifier->type = DOUBLE;
      specifier->scientificNotation = true;
      specifier->intType = DEC;
      break;

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
      specifier->type = DOUBLE;
      specifier->chooseNotation = true;
      specifier->intType = DEC;
      break;

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
      specifier->type = UINT;
      specifier->intType = HEX;
      break;
    case 'x':
      specifier->type = UINT;
      specifier->intType = HEX;
      break;

    case 'p':
      specifier->type = POINTER;
      specifier->intType = HEX;
      break;

    case 'n':
      specifier->type = COUNT;
      break;
    case '%':
      specifier->type = PERCENT;
      break;
    default:;
  }
}
