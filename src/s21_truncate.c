#include <stdio.h>

#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  s21_reset_decimal(result);
  int error = 0;
  s21_decimal_long value1_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long result_long = {{0, 0, 0, 0, 0, 0, 0}};

  s21_dec_to_longdec(value, &value1_long);

  int sign = s21_get_sign(value1_long.bits[6]);
  s21_set_sign(&value1_long.bits[6], 0);
  int exp = (int)s21_get_exponent(value1_long.bits[6]);
  if (exp > 0) {
    s21_decimal_long temp_div = {{1, 0, 0, 0, 0, 0, 0}};
    s21_decimal_long mod = {{0, 0, 0, 0, 0, 0, 0}};
    s21_decimal_long temp_long_dec = value1_long;
    s21_set_exponent(&temp_long_dec.bits[6], 0);
    for (int i = 0; i < exp; i++) {
      error = s21_mul_10_long(&temp_div);
    }
    error = s21_div_long(temp_long_dec, temp_div, &temp_long_dec, &mod, 1);
    result_long = temp_long_dec;
  } else {
    result_long = value1_long;
  }
  s21_set_sign(&result_long.bits[6], sign);
  if (!error) error = s21_longdec_to_dec(result_long, result);

  return error;
}