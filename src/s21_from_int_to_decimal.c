#include <stdio.h>

#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_reset_decimal(dst);
  int error = 1;
  int flag = 0;
  if (src < 0) {
    flag = 1;
    src *= -1;
  }
  dst->bits[0] = src;
  if (flag) {
    s21_set_sign(&dst->bits[3], 1);
  }
  error = 0;
  return error;
}