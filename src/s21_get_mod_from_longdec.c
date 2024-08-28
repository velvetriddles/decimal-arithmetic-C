#include "s21_decimal.h"

void s21_get_mod_from_longdec(int exp_long, s21_decimal_long *long_decimal) {
  s21_decimal_long temp = *long_decimal;
  int x = 0;
  while (temp.bits[3] || temp.bits[4] || temp.bits[5]) {
    s21_div10_with_round(&temp);
    x++;
    if (x == exp_long) {
      break;
    }
  }
  int temp_exp = (int)s21_get_exponent(temp.bits[6]);
  temp_exp = temp_exp == exp_long ? 28 : temp_exp;

  int mod_exp = 0;
  if (temp_exp < 28) {
    mod_exp = exp_long - temp_exp;
  } else {
    mod_exp = exp_long >= 28 ? exp_long - 28 : temp_exp;
  }
  int new_exp = temp_exp >= 28 ? 28 : temp_exp;

  s21_decimal_long temp_div = {{1, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long mod = {{0, 0, 0, 0, 0, 0, 0}};

  s21_decimal_long temp_long_dec = *long_decimal;
  for (int i = 0; i < mod_exp; i++) {
    s21_mul_10_long(&temp_div);
  }
  s21_set_exponent(&temp_long_dec.bits[6], 0);
  int sign3 = s21_get_sign(temp_long_dec.bits[6]);
  s21_div_long(temp_long_dec, temp_div, &temp_long_dec, &mod, 1);
  s21_set_sign(&temp_long_dec.bits[6], sign3);
  s21_set_exponent(&temp_long_dec.bits[6], new_exp);
  s21_set_exponent(&mod.bits[6], mod_exp);

  s21_bank_round(mod, &temp_long_dec, long_decimal);
}