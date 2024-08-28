#include "s21_decimal.h"

int s21_is_equal_long(s21_decimal_long value_1, s21_decimal_long value_2) {
  int result = 1;
  int sign1 = s21_get_sign(value_1.bits[6]);
  int sign2 = s21_get_sign(value_1.bits[6]);
  s21_reduce_long(&value_1, &value_2);
  s21_set_sign(&value_1.bits[6], sign1);
  s21_set_sign(&value_1.bits[6], sign2);
  for (int i = 0; i < 7 && result; i++)
    result = (value_1.bits[i] == value_2.bits[i]);
  return result;
}