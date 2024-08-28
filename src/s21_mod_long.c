#include "s21_decimal.h"

int s21_mod_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result) {
  int error = 0;
  s21_decimal_long remainder = {{0, 0, 0, 0, 0, 0}};
  s21_reset_decimal_long(result);
  s21_decimal_long zero = {{0, 0, 0, 0, 0, 0, 0}};
  if (s21_is_equal_long(value_2, zero)) {
    error = 3;
  } else if (s21_is_equal_long(value_1, zero)) {
    *result = zero;
    remainder = zero;
  } else {
    int exp1 = (int)s21_get_exponent(value_1.bits[6]);
    int exp2 = (int)s21_get_exponent(value_2.bits[6]);
    int new_exp = 0;
    if (exp1 - exp2 > 0) {
      new_exp = exp1 - exp2;
      s21_set_exponent(&value_1.bits[6], 0);
      s21_set_exponent(&value_2.bits[6], 0);
      for (int i = 0; i < new_exp; i++) {
        s21_mul_10_long(&value_2);
      }
      s21_div_long(value_1, value_2, result, &remainder, 1);
      s21_set_exponent(&remainder.bits[6], exp1);
    } else if (exp1 - exp2 < 0) {
      new_exp = exp2 - exp1;
      s21_set_exponent(&value_1.bits[6], 0);
      s21_set_exponent(&value_2.bits[6], 0);
      for (int i = 0; i < new_exp; i++) {
        s21_mul_10_long(&value_1);
      }
      s21_div_long(value_1, value_2, result, &remainder, 1);
      s21_set_exponent(&remainder.bits[6], exp2);
    } else {
      s21_set_exponent(&value_1.bits[6], 0);
      s21_set_exponent(&value_2.bits[6], 0);
      s21_div_long(value_1, value_2, result, &remainder, 1);
      s21_set_exponent(&remainder.bits[6], exp1);
    }
  }
  *result = remainder;
  return error;
}