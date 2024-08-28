#include <stdio.h>

#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;

  s21_decimal_long value = {{0, 0, 0, 0, 0, 0}};
  s21_dec_to_longdec(src, &value);
  s21_decimal_long ipart_long = {{0, 0, 0, 0, 0, 0}};
  s21_decimal_long mod = {{0, 0, 0, 0, 0, 0}};
  s21_decimal_long temp_div = {{1, 0, 0, 0, 0, 0}};

  int exp = (int)s21_get_exponent(value.bits[6]);
  for (int i = 0; i < exp; i++) {
    s21_mul_10_long(&temp_div);
  }

  int sign_temp = s21_get_sign(value.bits[6]);
  s21_set_sign(&value.bits[6], 0);
  error = s21_div_long(value, temp_div, &ipart_long, &mod, 1);

  s21_set_sign(&ipart_long.bits[6], sign_temp);

  s21_decimal ipart = {{0, 0, 0}};

  if (!error) {
    s21_longdec_to_dec(ipart_long, &ipart);

    if (ipart.bits[1] || ipart.bits[2]) {
      error = 1;
    } else {
      unsigned int x = 2147483647;
      if (ipart.bits[0] > x) {
        error = 1;
      } else {
        int sign = s21_get_sign(ipart.bits[3]);
        int temp = (int)ipart.bits[0];
        if (sign) {
          temp *= -1;
        }
        *dst = temp;
      }
    }
  }

  if (error) error = 1;  // Если произошла ошибка, возвращаем 1
  return error;
}