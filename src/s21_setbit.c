#include <stdio.h>

#include "s21_decimal.h"

void s21_setbit(unsigned int *x, int i, int bit) {
  int y = 1 << i;
  *x = bit ? *x | y : *x & (~y);
}