#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <stdbool.h>

#include "frac_types.h"

frac_t frac_new(long long num, long long denom);

frac_t frac_simplify(frac_t a);

// is a == b ?
bool frac_cmp_eq(frac_t a, frac_t b);

// is a < b ?
bool frac_cmp_lt(frac_t a, frac_t b);

// is a <= b ?
bool frac_cmp_le(frac_t a, frac_t b);

// is a > b ?
bool frac_cmp_gt(frac_t a, frac_t b);

// is a <= b ?
bool frac_cmp_ge(frac_t a, frac_t b);

// a + b
frac_t frac_add(frac_t a, frac_t b);

// a - b
frac_t frac_sub(frac_t a, frac_t b) ;

// a * b
frac_t frac_mul(frac_t a, frac_t b) ;

// a / b
frac_t frac_div(frac_t a, frac_t b) ;

// a ^ b
frac_t frac_pow(frac_t a, int b);

// converts to decimal double
double frac2decimal(frac_t a);

#endif
