#include "s21_decimal.h"

int s21_negate_long(s21_decimal_long value, s21_decimal_long *result) {
  *result = value;
  result->bits[6] = value.bits[6] ^ 2147483648;
  return 0;
}