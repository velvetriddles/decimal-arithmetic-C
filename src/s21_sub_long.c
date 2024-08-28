#include "s21_decimal.h"

int s21_sub_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result) {
  s21_reset_decimal_long(result);
  int error = 0;
  if (s21_get_sign(value_1.bits[6]) == 0 &&
      s21_get_sign(value_2.bits[6]) == 0) {
    if (s21_is_less_long(value_2, value_1)) {
      for (int i = 0; i < 192; i++) {
        s21_start_subbing_long(&value_1, &value_2, result, i);
      }
    } else if (s21_is_equal_long(value_1, value_2)) {
      s21_reset_decimal_long(result);
    } else {
      for (int i = 0; i < 192; i++)
        s21_start_subbing_long(&value_2, &value_1, result, i);
      s21_negate_long(*result, result);
    }
  } else if ((s21_get_sign(value_1.bits[6]) == 1 &&
              s21_get_sign(value_2.bits[6]) == 1)) {
    s21_negate_long(value_1, &value_1);
    s21_negate_long(value_2, &value_2);
    s21_sub_long(value_2, value_1, result);
  } else if (s21_get_sign(value_1.bits[6]) == 1 &&
             s21_get_sign(value_2.bits[6]) == 0) {
    s21_negate_long(value_1, &value_1);
    error = s21_add_long(value_1, value_2, result);
    s21_negate_long(*result, result);
  } else if ((s21_get_sign(value_1.bits[6]) == 0 &&
              s21_get_sign(value_2.bits[6]) == 1)) {
    s21_negate_long(value_2, &value_2);
    error = s21_add_long(value_1, value_2, result);
  }
  if (error) error = 2;
  int exp = (int)s21_get_exponent(value_1.bits[6]);
  s21_set_exponent(&result->bits[6], exp);
  return error;
}