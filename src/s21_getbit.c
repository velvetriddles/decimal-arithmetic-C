#include <stdio.h>

#include "s21_decimal.h"

int s21_getbit(unsigned int x, int i) {
  unsigned int y = 1 << i;
  return (x & y) ? 1 : 0;
}