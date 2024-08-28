#include "s21_decimal.h"

void s21_no_zero(s21_decimal_long *value) {
  int sign = s21_get_sign(value->bits[6]);
  int exp = (int)s21_get_exponent(value->bits[6]);
  s21_decimal_long ten = {{10, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long mod = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long zero = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long temp = *value;
  s21_set_exponent(&temp.bits[6], 0);
  while (exp > 0) {
    s21_mod_long(temp, ten, &mod);
    if (s21_is_equal_long(mod, zero)) {
      s21_div_long(temp, ten, &temp, &mod, 0);
      exp--;
    } else {
      break;
    }
  }
  *value = temp;
  s21_set_sign(&value->bits[6], sign);
  s21_set_exponent(&value->bits[6], exp);
}