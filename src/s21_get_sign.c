#include <stdio.h>

#include "s21_decimal.h"

int s21_get_sign(unsigned int x) { return s21_getbit(x, 31); }