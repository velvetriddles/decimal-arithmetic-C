#include <stdio.h>

#include "s21_decimal.h"

void s21_set_exponent(unsigned int *value, int d) {
  int sign = s21_get_sign(*value);
  *value = 0;
  *value = *value >> 16;
  *value = *value | d;
  *value = *value << 16;
  s21_setbit(value, 31, sign);
}