#include <stdio.h>

#include "s21_decimal.h"

void s21_preparing_long_dec(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal_long *value1_long,
                            s21_decimal_long *value2_long) {
  s21_dec_to_longdec(value_1, value1_long);
  s21_dec_to_longdec(value_2, value2_long);

  int sign1 = s21_get_sign(value1_long->bits[6]);
  int sign2 = s21_get_sign(value2_long->bits[6]);
  s21_reduce_long(value1_long, value2_long);
  s21_set_sign(&value1_long->bits[6], sign1);
  s21_set_sign(&value2_long->bits[6], sign2);
}
