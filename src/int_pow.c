#include <stdbool.h>

long long ll_pow(long long base, int exp) {
   long long res = 1;
   while (true) {
      if (exp &1) {
         res *= base;
      }
      exp >>= 1;
      if (exp == 0) {
         break;
      }
      base *= base;
   }
   return res;
}
