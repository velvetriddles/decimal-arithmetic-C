#include <stdio.h>

#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_reset_decimal(result);
  int error = 0;

  s21_decimal_long value1_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long value2_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long result_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long mod_long = {{0, 0, 0, 0, 0, 0, 0}};

  s21_dec_to_longdec(value_1, &value1_long);
  s21_dec_to_longdec(value_2, &value2_long);

  // Определяем знаки делимого и делителя
  int sign1 = s21_get_sign(value1_long.bits[6]);
  int sign2 = s21_get_sign(value2_long.bits[6]);
  s21_set_sign(&value1_long.bits[6], 0);
  s21_set_sign(&value2_long.bits[6], 0);
  int sign3 = (sign1 && sign2) || (sign1 == 0 && sign2 == 0) ? 0 : 1;

  error = s21_div_long(value1_long, value2_long, &result_long, &mod_long, 0);

  s21_set_sign(&result_long.bits[6], sign3);

  if (!error) error = s21_longdec_to_dec(result_long, result);

  if (error && (error != 3)) error = sign3 == 0 ? 1 : 2;

  return error;
}