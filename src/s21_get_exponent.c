#include <stdio.h>

#include "s21_decimal.h"

unsigned int s21_get_exponent(unsigned int value) {
  value = (value << 1) >> 17;
  return value;
}