#include "s21_decimal.h"

int s21_shift_left_by_1_long(s21_decimal_long *value) {
  int error = 0;
  int flag = 0;
  for (int i = 0; i < 6; i++) {
    if (s21_getbit(value->bits[i], 31)) {
      if (i == 5) error = 1;
      s21_set_for_shift_long(value, i, flag, error);
      flag = 1;
    } else {
      s21_set_for_shift_long(value, i, flag, error);
      flag = 0;
    }
  }
  return error;
}