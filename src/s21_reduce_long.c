#include "s21_decimal.h"

int s21_reduce_long(s21_decimal_long *value_1, s21_decimal_long *value_2) {
  int ex_1 = (int)s21_get_exponent(value_1->bits[6]);
  int ex_2 = (int)s21_get_exponent(value_2->bits[6]);
  int error = 0;
  int flag = 0;
  int result = 0;
  if (ex_1 > ex_2) {
    result = ex_1 - ex_2;
    flag = 1;
  } else {
    result = ex_2 - ex_1;
  }
  for (int i = 0; i < result && !error; i++) {
    if (flag) {
      error = s21_mul_10_long(value_2);
    } else {
      error = s21_mul_10_long(value_1);
    }
  }
  if (!error) {
    if (flag)
      value_2->bits[6] = value_1->bits[6];
    else
      value_1->bits[6] = value_2->bits[6];
  }
  return error;
}