#include "s21_decimal.h"

void s21_set_for_shift_right_long(s21_decimal_long *value, int i, int flag,
                                  int error) {
  value->bits[i] = value->bits[i] >> 1;
  if (flag && !error && i != 5) {
    s21_setbit(&value->bits[i], 31, 1);
  }
}