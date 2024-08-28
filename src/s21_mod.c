#include <stdio.h>

#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_reset_decimal(result);
  int error = 0;

  s21_decimal_long value1_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long value2_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long mod_long = {{0, 0, 0, 0, 0, 0, 0}};

  s21_dec_to_longdec(value_1, &value1_long);
  s21_dec_to_longdec(value_2, &value2_long);

  int sign = s21_get_sign(value1_long.bits[6]);
  s21_set_sign(&value1_long.bits[6], 0);
  s21_set_sign(&value2_long.bits[6], 0);

  error = s21_mod_long(value1_long, value2_long, &mod_long);

  s21_set_sign(&mod_long.bits[6], sign);

  if (!error) error = s21_longdec_to_dec(mod_long, result);

  return error;
}