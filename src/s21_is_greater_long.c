#include "s21_decimal.h"

int s21_is_greater_long(s21_decimal_long value_1, s21_decimal_long value_2) {
  return !(s21_is_less_long(value_1, value_2) |
           s21_is_equal_long(value_1, value_2));
}