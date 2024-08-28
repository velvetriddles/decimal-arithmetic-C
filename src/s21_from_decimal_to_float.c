#include <stdio.h>

#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 1;

  double temp = 0;
  int scale = 0;

  for (int i = 0; i < 96; i++) {
    if ((src.bits[i / 32] & (1 << i % 32)) != 0) {
      temp += pow(2, i);
    }
  }

  // Получаем масштаб числа из его битовой структуры.
  scale = (src.bits[3] & ~0x80000000) >> 16;

  if (scale > 0) {
    for (int i = scale; i > 0; i--) {
      temp /= 10.0;
    }
  }

  *dst = (float)temp;

  if (src.bits[3] >> 31) {
    *dst *= -1;
  } else {
    *dst *= 1;
  }

  error = 0;
  return error;
}