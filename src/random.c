#include <stdlib.h>
#include <stdbool.h>

int next_int_random(int lower, int upper) {
   int n = upper - lower + 1;
   int remainder = RAND_MAX % n;
   int x;
   do {
      x = rand();
   } while (x >= RAND_MAX - remainder);
   return lower + x % n;
}
