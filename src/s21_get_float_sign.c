#include <stdio.h>

#include "s21_decimal.h"

int s21_get_float_sign(float *src) { return *(int *)src >> 31; }