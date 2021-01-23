#include <stdbool.h>

#include "frac_types.h"

#include "gcd.h"
#include "lcm.h"
#include "int_pow.h"

frac_t frac_new(long long num, long long denom) {
   frac_t n;
   n.num = num;
   n.denom = denom;
   return n;
}

frac_t frac_simplify(frac_t a) {
   if (a.denom != 0) {
      long long d = gcd(a.num, a.denom);
      a.num /= d;
      a.denom /= d;
   }
   if (a.denom < 0) {
      a.num *= -1;
      a.denom *= -1;
   }
   return a;
}

// is a == b ?
bool frac_cmp_eq(frac_t a, frac_t b) {
   return ((a.num * b.denom) == (a.denom * b.num));
}

// is a < b ?
bool frac_cmp_lt(frac_t a, frac_t b) {
   return ((a.num*b.denom) < (a.denom*b.num));
}

// is a <= b ?
bool frac_cmp_le(frac_t a, frac_t b) {
   return ((a.num*b.denom) <= (a.denom*b.num));
}

// is a > b ?
bool frac_cmp_gt(frac_t a, frac_t b) {
   return ((a.num*b.denom) > (a.denom*b.num));
}

// is a >= b ?
bool frac_cmp_ge(frac_t a, frac_t b) {
   return ((a.num*b.denom) >= (a.denom*b.num));
}

// a + b
frac_t frac_add(frac_t a, frac_t b) {
   frac_t s;
   s.num = a.num*b.denom + a.denom*b.num;
   s.denom = a.denom * b.denom;
   return frac_simplify(s);
}

// a - b
frac_t frac_sub(frac_t a, frac_t b) {
   b.num *= -1;
   return frac_add(a, b);
}

// a * b
frac_t frac_mul(frac_t a, frac_t b) {
   a.num *= b.num;
   a.denom *= b.denom;
   return frac_simplify(a);
}

// a / b
frac_t frac_div(frac_t a, frac_t b) {
   a.num *= b.denom;
   a.denom *= b.num;
   return frac_simplify(a);
}

// a ^ b
frac_t frac_pow(frac_t a, int b) {
   a = frac_simplify(a);
   a.num = ll_pow(a.num, b);
   a.denom = ll_pow(a.denom, b);
   return a;
}
