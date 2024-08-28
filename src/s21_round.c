#include <stdio.h>

#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  s21_reset_decimal(result);
  int error = 0;

  s21_decimal_long value1_long = {{0, 0, 0, 0, 0, 0, 0}};
  s21_decimal_long result_long = {{0, 0, 0, 0, 0, 0, 0}};

  s21_dec_to_longdec(value, &value1_long);
  error = s21_round_long(value1_long, &result_long);
  if (!error) error = s21_longdec_to_dec(result_long, result);

  return error;
}