#include <stdio.h>

#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_reset_decimal(dst);
  int error = 1;
  int sign = s21_get_float_sign(&src);
  int exponent = s21_get_float_exponent(&src);

  if (dst != NULL && isnan(src) == 0 && isinf(src) == 0 && src != 0) {
    s21_reset_decimal(dst);
    double temp = (double)fabs(src);
    int scale = 0;

    while (scale < 28 && (int)temp / (int)pow(2, 21) == 0) {
      temp *= 10;
      scale++;
    }
    temp = round(temp);

    if ((exponent > -94 && exponent < 96) && scale <= 28) {
      union float_to_dec mantissa;
      temp = (float)temp;

      while (fmod(temp, 10) == 0 && scale > 0) {
        scale--;
        temp /= 10;
      }

      mantissa.fl = temp;
      exponent = s21_get_float_exponent(&mantissa.fl);

      dst->bits[exponent / 32] |= 1 << exponent % 32;
      for (int i = exponent - 1, j = 22; j >= 0; i--, j--) {
        if ((mantissa.d & (1 << j)) != 0) {
          dst->bits[i / 32] |= 1 << i % 32;
        }
      }

      dst->bits[3] = (sign << 31) | (scale << 16);
      error = 0;
    }
  }
  return error;
}