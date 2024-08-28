#include "s21_decimal.h"

int s21_mul_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result) {
  int error = 0;
  s21_decimal_long temp = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long temp_result = {{0, 0, 0, 0, 0, 0, 0}};

  for (int i = 0; i < 192; i++) {
    for (int j = 0; j < 192; j++) {
      int bit1 = s21_getbit(value_1.bits[i / 32], i % 32);
      int bit2 = s21_getbit(value_2.bits[j / 32], j % 32);
      s21_setbit(&temp.bits[j / 32], j % 32, bit1 * bit2);
    }
    for (int n = 0; n < i && !error; n++)
      error = s21_shift_left_by_1_long(&temp);
    if (!error) error = s21_add_long(temp, temp_result, &temp_result);
  }
  if (error)
    s21_reset_decimal_long(result);
  else {
    s21_reset_decimal_long(result);
    s21_add_long(temp, temp_result, result);
    s21_set_exponent(&result->bits[6],
                     (int)(s21_get_exponent(value_1.bits[6]) +
                           s21_get_exponent(value_2.bits[6])));
  }
  return error;
}