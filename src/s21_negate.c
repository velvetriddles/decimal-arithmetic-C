#include <stdio.h>

#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  *result = value;
  result->bits[3] = value.bits[3] ^ 2147483648;
  return 0;
}