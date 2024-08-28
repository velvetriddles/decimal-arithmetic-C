#include "s21_decimal.h"

int s21_div_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result, s21_decimal_long *remainder,
                 int flag_mod) {
  int error = 0;
  s21_reset_decimal_long(result);
  s21_decimal_long zero = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long one = {{1, 0, 0, 0, 0, 0, 0}};
  if (s21_is_equal_long(value_2, zero)) {
    error = 3;
  } else if (s21_is_equal_long(value_1, zero)) {
    *result = zero;
    *remainder = zero;
  } else {
    int exp1 = (int)s21_get_exponent(value_1.bits[6]);
    int exp2 = (int)s21_get_exponent(value_2.bits[6]);
    s21_set_exponent(&value_1.bits[6], 0);
    s21_set_exponent(&value_2.bits[6], 0);
    int new_exp = exp1 - exp2;
    s21_decimal_long temp = {{1, 0, 0, 0, 0, 0, 0}};
    int flag_while = 1;
    int flag_10 = 1;

    s21_make_div(&flag_while, &flag_10, flag_mod, &value_1, &value_2, &temp,
                 &one, result, remainder, &zero);

    while (new_exp < 0) {
      s21_mul_10_long(result);
      s21_no_zero(result);
      new_exp++;
    }
    if (new_exp > 0) {
      int exp = (int)s21_get_exponent(result->bits[6]);
      s21_set_exponent(&result->bits[6], new_exp + exp);
    }
  }
  return error;
}
