#include "frac_types.h"
#include "fractions.h"
#include "interval_types.h"
#include "intervals.h"

int interval_list_halfstep_shift(interval_t *interval_list) {
   int shift = 0;
   for (int i=0; i<nintervals; i++) {
      shift += interval_list[i].ht_steps*interval_list[i].pow;
   }

   return shift;
}

frac_t interval_list_freq_scale(interval_t *interval_list) {
   frac_t scale = frac_new(1, 1);
   for (int i=0; i<nintervals; i++) {
      frac_t f = frac_pow(interval_list[i].freqscale,
                          interval_list[i].pow);
      scale = frac_mul(scale, f);
   }

   return scale;
}
