#include <stdio.h>

#include "s21_decimal.h"

void s21_set_sign(unsigned int *x, int sign) { s21_setbit(x, 31, sign); }