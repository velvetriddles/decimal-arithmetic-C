#include "s21_decimal.h"

void s21_make_div(int *flag_while, int *flag_10, int flag_mod,
                  s21_decimal_long *value_1, s21_decimal_long *value_2,
                  s21_decimal_long *temp, s21_decimal_long *one,
                  s21_decimal_long *result, s21_decimal_long *remainder,
                  s21_decimal_long *zero) {
  while (*flag_while == 1) {
    while (!s21_is_less_long(*value_1, *value_2)) {
      s21_shift_left_by_1_long(value_2);
      s21_shift_left_by_1_long(temp);
      if (s21_getbit(value_2->bits[5], 31)) {
        *flag_10 = 0;
        s21_shift_left_by_1_long(temp);
        break;
      }
    }
    while (s21_is_greater_long(*temp, *one)) {
      if (*flag_10) {
        s21_shift_right_by_1_long(value_2);
      }
      s21_shift_right_by_1_long(temp);
      *flag_10 = 1;
      if (!s21_is_less_long(*value_1, *value_2)) {
        s21_sub_long(*value_1, *value_2, value_1);
        s21_add_long(*result, *temp, result);
      }
    }
    *remainder = *value_1;
    if (!flag_mod) {
      if (s21_is_equal_long(*remainder, *zero)) {
        *flag_while = 0;
      } else {  // Иначе
        int exp_result = (int)s21_get_exponent(result->bits[6]);
        if (exp_result == 56) {
          *flag_while = 0;
        } else {
          s21_mul_10_long(value_1);
          s21_mul_10_long(result);
          s21_set_exponent(&result->bits[6], exp_result + 1);
        }
      }
    } else {
      *flag_while = 0;
    }
  }
}