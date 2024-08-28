#include "s21_decimal.h"

void s21_start_subbing_long(s21_decimal_long *value_1,
                            s21_decimal_long *value_2, s21_decimal_long *result,
                            int i) {
  int bit1 = s21_getbit(value_1->bits[i / 32], i % 32);
  int bit2 = s21_getbit(value_2->bits[i / 32], i % 32);
  if ((bit1 == 1 && bit2 == 1) || (bit1 == 0 && bit2 == 0)) {
    s21_setbit(&result->bits[i / 32], i % 32, 0);
  } else if (bit1 == 1 && bit2 == 0) {
    s21_setbit(&result->bits[i / 32], i % 32, 1);
  } else if (bit1 == 0 && bit2 == 1) {
    int k = 1;
    int n = 0;
    if ((i + k) % 32 == 0) {
      n += 32;
    }
    while (s21_getbit(value_1->bits[(i + n) / 32], (i + k) % 32) != 1) {
      s21_setbit(&value_1->bits[(i + n) / 32], (i + k) % 32, 1);
      k++;
      if ((i + k) % 32 == 0) n += 32;
    }
    s21_setbit(&value_1->bits[(i + n) / 32], (i + k) % 32, 0);
    s21_setbit(&result->bits[i / 32], i % 32, 1);
  }
}