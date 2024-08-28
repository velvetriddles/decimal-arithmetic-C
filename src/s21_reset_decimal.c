#include <stdio.h>

#include "s21_decimal.h"

void s21_reset_decimal(s21_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
}