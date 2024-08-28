#include "s21_decimal.h"

int s21_is_less_long(s21_decimal_long value_1, s21_decimal_long value_2) {
  int s1 = s21_getbit(value_1.bits[6], 31);
  int s2 = s21_getbit(value_2.bits[6], 31);
  int result = (s1 > s2) - (s1 == s2);
  if (result == -1) s21_reduce_long(&value_1, &value_2);
  for (int i = 6; i >= 0 && result == -1; i--)
    if (value_1.bits[i] != value_2.bits[i])
      result = (value_1.bits[i] < value_2.bits[i]) ^ s1;
  return result == -1 ? 0 : result;
}
