#include <stdio.h>

#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  s21_decimal_long value1_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long value2_long = {{0, 0, 0, 0, 0, 0, 0}};

  s21_preparing_long_dec(value_1, value_2, &value1_long, &value2_long);

  result = s21_is_less_long(value1_long, value2_long);
  return result;
}
