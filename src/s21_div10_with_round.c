#include "s21_decimal.h"

void s21_div10_with_round(s21_decimal_long *long_decimal) {
  int exp_long = (int)s21_get_exponent(long_decimal->bits[6]);
  s21_decimal_long ten = {{10, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long mod = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long zero_five = {{5, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long temp = {{0, 0, 0, 0, 0, 0, 0}};

  s21_decimal_long temp_long_dec = *long_decimal;
  int sign = s21_get_sign(long_decimal->bits[6]);
  s21_set_exponent(&temp_long_dec.bits[6], 0);
  s21_div_long(temp_long_dec, ten, &temp_long_dec, &mod, 1);
  if (!s21_is_less_long(mod, zero_five)) {
    s21_decimal_long temp3 = {{0, 0, 0, 0, 0, 0, 0}};
    s21_div_long(temp_long_dec, ten, &temp, &temp3, 1);
    int digit = (int)temp3.bits[0];
    if (digit % 2 != 0 ||
        (digit % 2 == 0 && !s21_is_equal_long(mod, zero_five))) {
      s21_decimal_long one = {{1, 0, 0, 0, 0, 0, 0}};
      s21_add_long(temp_long_dec, one, &temp_long_dec);
    }
    s21_set_exponent(&temp_long_dec.bits[6], --exp_long);
    *long_decimal = temp_long_dec;
  } else {
    s21_set_exponent(&temp_long_dec.bits[6], --exp_long);
    *long_decimal = temp_long_dec;
  }
  s21_set_sign(&long_decimal->bits[6], sign);
}
