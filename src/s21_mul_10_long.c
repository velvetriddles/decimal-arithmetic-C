#include "s21_decimal.h"

int s21_mul_10_long(s21_decimal_long *value) {
  int error = 0;
  s21_decimal_long temp_1 = *value;
  error = s21_shift_left_by_1_long(&temp_1);
  s21_decimal_long temp_2 = temp_1;
  if (!error) {  // Если ошибки нет
    for (int i = 0; i < 2 && !error; i++) {
      error = s21_shift_left_by_1_long(&temp_2);
    }
    if (!error) s21_add_long(temp_1, temp_2, value);
  }
  return error;  // Возвращаем код ошибки
}