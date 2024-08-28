#include "s21_decimal.h"

void s21_start_adding_long(s21_decimal_long *value_1, s21_decimal_long *value_2,
                           s21_decimal_long *result, int i, int *flag) {
  int bit1 = s21_getbit(value_1->bits[i / 32], i % 32);
  int bit2 = s21_getbit(value_2->bits[i / 32], i % 32);
  if (bit1 == 1 && bit2 == 1) {
    if (*flag)
      s21_setbit(&result->bits[i / 32], i % 32, 1);
    else
      s21_setbit(&result->bits[i / 32], i % 32, 0);
    *flag = 1;
  } else if (bit1 == 1 || bit2 == 1) {
    if (*flag) {
      s21_setbit(&result->bits[i / 32], i % 32, 0);
      *flag = 1;
    } else {
      s21_setbit(&result->bits[i / 32], i % 32, 1);
      *flag = 0;
    }
  } else {
    if (*flag)
      s21_setbit(&result->bits[i / 32], i % 32, 1);
    else
      s21_setbit(&result->bits[i / 32], i % 32, 0);
    *flag = 0;
  }
}