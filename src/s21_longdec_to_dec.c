#include "s21_decimal.h"

int s21_longdec_to_dec(s21_decimal_long long_decimal, s21_decimal *decimal) {
  int error = 0;
  int sign = s21_get_sign(long_decimal.bits[6]);
  s21_set_sign(&long_decimal.bits[6], 0);
  int exp_long = (int)s21_get_exponent(long_decimal.bits[6]);

  if (exp_long > 28 ||
      ((long_decimal.bits[3] || long_decimal.bits[4] || long_decimal.bits[5]) &&
       exp_long != 0)) {
    s21_get_mod_from_longdec(exp_long, &long_decimal);
  }
  if (!long_decimal.bits[3] && !long_decimal.bits[4] && !long_decimal.bits[5]) {
    decimal->bits[0] = long_decimal.bits[0];
    decimal->bits[1] = long_decimal.bits[1];
    decimal->bits[2] = long_decimal.bits[2];
    decimal->bits[3] = long_decimal.bits[6];
    s21_set_sign(&decimal->bits[3], sign);
  } else {
    if (s21_get_sign(long_decimal.bits[6])) {
      error = 2;
    } else {
      error = 1;
    }
  }
  return error;
}