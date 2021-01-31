#include <gmp.h>

#include "interval_types.h"
#include "intervals.h"

int interval_list_halfstep_shift(interval_t *interval_list) {
   int shift = 0;
   for (int i=0; i<nintervals; i++) {
      shift += interval_list[i].ht_steps*interval_list[i].pow;
   }

   return shift;
}

void interval_list_freq_scale(interval_t *interval_list, mpq_t *scale) {
   mpq_set_si(*scale, 1, 1);
   for (int i=0; i<nintervals; i++) {
      if (interval_list[i].pow > 0) {
         for (int ipow=0; ipow<interval_list[i].pow; ipow++) {
            mpq_mul(*scale, *scale, interval_list[i].freqscale);
         }
      } else if (interval_list[i].pow < 0) {
         for (int ipow=0; ipow<-interval_list[i].pow; ipow++) {
            mpq_div(*scale, *scale, interval_list[i].freqscale);
         }
      }
   }
}
