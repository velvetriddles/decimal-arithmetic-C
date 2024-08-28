#include "s21_decimal.h"

void s21_reset_decimal_long(s21_decimal_long *result) {
  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;
  result->bits[4] = 0;
  result->bits[5] = 0;
  result->bits[6] = 0;
}