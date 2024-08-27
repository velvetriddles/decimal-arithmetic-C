#ifndef C5_S21_DECIMAL_0_SRC_S21_DECIMAL_H_
#define C5_S21_DECIMAL_0_SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} s21_decimal_long;

union float_to_dec {
  float fl;
  int d;
};

// arifmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// comparison
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// tranformation
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// other
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
void s21_bank_round(s21_decimal_long mod, s21_decimal_long *temp_long_dec,
                    s21_decimal_long *long_decimal);

// bit
int s21_get_float_sign(float *src);
int s21_get_float_exponent(float *src);
void s21_preparing_long_dec(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal_long *value1_long,
                            s21_decimal_long *value2_long);
int s21_getbit(unsigned int x, int i);
void s21_setbit(unsigned int *x, int i, int bit);
void s21_reset_decimal(s21_decimal *result);
unsigned int s21_get_exponent(unsigned int value);
void s21_set_exponent(unsigned int *value, int d);
int s21_get_sign(unsigned int x);
void s21_set_sign(unsigned int *x, int sign);

//------------------LONG--------------

// arifmetic
void s21_div10_with_round(s21_decimal_long *long_decimal);
void s21_make_div(int *flag_while, int *flag_10, int flag_mod,
                  s21_decimal_long *value_1, s21_decimal_long *value_2,
                  s21_decimal_long *temp, s21_decimal_long *one,
                  s21_decimal_long *result, s21_decimal_long *remainder,
                  s21_decimal_long *zero);
int s21_add_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result);
int s21_div_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result, s21_decimal_long *remainder,
                 int flag_mod);
void s21_get_mod_from_longdec(int exp_long, s21_decimal_long *long_decimal);
int s21_mod_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result);
int s21_mul_10_long(s21_decimal_long *value);
int s21_mul_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result);
void s21_start_adding_long(s21_decimal_long *value_1, s21_decimal_long *value_2,
                           s21_decimal_long *result, int i, int *flag);
void s21_start_subbing_long(s21_decimal_long *value_1,
                            s21_decimal_long *value_2, s21_decimal_long *result,
                            int i);
int s21_sub_long(s21_decimal_long value_1, s21_decimal_long value_2,
                 s21_decimal_long *result);

// comparison
int s21_is_equal_long(s21_decimal_long value_1, s21_decimal_long value_2);
int s21_is_greater_long(s21_decimal_long value_1, s21_decimal_long value_2);
int s21_is_less_long(s21_decimal_long value_1, s21_decimal_long value_2);

// tranformation
void s21_dec_to_longdec(s21_decimal input_dec,
                        s21_decimal_long *output_longdec);
int s21_longdec_to_dec(s21_decimal_long long_decimal, s21_decimal *decimal);

// other
int s21_floor_long(s21_decimal_long value, s21_decimal_long *result);
int s21_negate_long(s21_decimal_long value, s21_decimal_long *result);
int s21_round_long(s21_decimal_long value, s21_decimal_long *result);

// bit
void s21_no_zero(s21_decimal_long *value);
void s21_reset_decimal_long(s21_decimal_long *result);
void s21_dec_to_longdec(s21_decimal input_dec,
                        s21_decimal_long *output_longdec);
int s21_reduce_long(s21_decimal_long *value_1, s21_decimal_long *value_2);
void s21_set_for_shift_long(s21_decimal_long *value, int i, int flag,
                            int error);
void s21_set_for_shift_right_long(s21_decimal_long *value, int i, int flag,
                                  int error);
int s21_shift_left_by_1_long(s21_decimal_long *value);
int s21_shift_right_by_1_long(s21_decimal_long *value);

#endif
