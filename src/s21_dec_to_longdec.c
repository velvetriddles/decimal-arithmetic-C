#include "s21_decimal.h"

void s21_dec_to_longdec(s21_decimal input_dec,
                        s21_decimal_long *output_longdec) {
  for (int i = 0; i < 3; i++) output_longdec->bits[i] = input_dec.bits[i];
  for (int i = 4; i < 7; i++) output_longdec->bits[i] = 0;
  output_longdec->bits[6] = input_dec.bits[3];
  int sing = s21_getbit(input_dec.bits[3], 31);
  s21_setbit(&output_longdec->bits[6], 31, sing);
}