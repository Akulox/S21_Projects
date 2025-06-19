#include "headers/s21_stringCS.h"

// Вставляет строку str в строку src на позицию start_index
// @param src Исходная строка, в которую происходит вставка
// @param str Строка, которую нужно вставить
// @param start_index Позиция для вставки (от 0 до длины src)
// @return Указатель на новую строку с результатом или NULL при ошибке

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *result = S21_NULL;  // Инициализация результата как NULL

  // Проверка валидности входных указателей
  if (src && str) {
    // Получаем длины обеих строк
    s21_size_t srcSize = s21_strlen(src);
    s21_size_t strSize = s21_strlen(str);

    // Проверяем:
    // 1. Что start_index не превышает длину src
    // 2. Что malloc успешно выделил память (srcSize + strSize + 1 для '\0')

    if (srcSize >= start_index &&
        (result = (char *)malloc(srcSize + strSize + 1))) {
      unsigned char *res =
          (unsigned char *)result;  // Рабочий указатель на результат

      // Копируем часть src ДО позиции вставки
      while (start_index--) {
        *res++ = *src++;  // Копируем посимвольно
        srcSize--;  // Уменьшаем счетчик оставшихся символов
      }

      // Вставляем строку str
      while (strSize--) {
        *res++ = *str++;  // Копируем str целиком
      }

      // Копируем оставшуюся часть src ПОСЛЕ позиции вставки
      while (srcSize--) {
        *res++ = *src++;  // Копируем остаток src
      }

      *res = '\0';  // Добавляем терминатор строки
    }
  }

  return result;  // Возвращаем новую строку или NULL при ошибке
}
