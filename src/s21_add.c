#include <stdio.h>

#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_reset_decimal(result);
  int error = 0;

  s21_decimal_long value1_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long value2_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long result_long = {{0, 0, 0, 0, 0, 0, 0}};

  s21_preparing_long_dec(value_1, value_2, &value1_long, &value2_long);

  error = s21_add_long(value1_long, value2_long, &result_long);

  if (!error) error = s21_longdec_to_dec(result_long, result);

  return error;
}