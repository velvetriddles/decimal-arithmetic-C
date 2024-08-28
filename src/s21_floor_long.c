#include "s21_decimal.h"

int s21_floor_long(s21_decimal_long value, s21_decimal_long *result) {
  int sign = s21_get_sign(value.bits[6]);
  s21_set_sign(&value.bits[6], 0);
  int exp = (int)s21_get_exponent(value.bits[6]);
  int error = 0;
  if (exp > 0) {
    s21_decimal_long temp_div = {{1, 0, 0, 0, 0, 0, 0}};
    s21_decimal_long mod = {{0, 0, 0, 0, 0, 0, 0}};
    s21_decimal_long zero = {{0, 0, 0, 0, 0, 0, 0}};
    s21_decimal_long one = {{1, 0, 0, 0, 0, 0, 0}};
    s21_decimal_long temp_long_dec = value;
    s21_set_exponent(&temp_long_dec.bits[6], 0);
    for (int i = 0; i < exp; i++) {
      error = s21_mul_10_long(&temp_div);
    }
    error = s21_div_long(temp_long_dec, temp_div, &temp_long_dec, &mod, 1);
    if (sign && !s21_is_equal_long(mod, zero)) {
      s21_add_long(temp_long_dec, one, &temp_long_dec);
    }
    *result = temp_long_dec;
  } else {
    *result = value;
  }
  s21_set_sign(&result->bits[6], sign);
  return error;
}