#include "s21_decimal.h"

int s21_add_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result) {
  s21_reset_decimal_long(result);
  int error = 0;
  int flag = 0;
  int sign1 = s21_get_sign(value_1.bits[6]);
  int sign2 = s21_get_sign(value_2.bits[6]);

  if ((sign1 == 0 && sign2 == 0) || (sign1 == 1 && sign2 == 1)) {
    for (int i = 0; i < 192; i++) {
      s21_start_adding_long(&value_1, &value_2, result, i, &flag);
    }
    if (flag == 1) {
      error = 1;
      s21_reset_decimal_long(result);
    }
    result->bits[6] = value_1.bits[6];
  } else if (sign1 == 0 && sign2 == 1) {
    s21_negate_long(value_2, &value_2);
    s21_sub_long(value_1, value_2, result);
  } else if (sign1 == 1 && sign2 == 0) {
    s21_negate_long(value_1, &value_1);
    s21_sub_long(value_2, value_1, result);
  }
  return error;
}
