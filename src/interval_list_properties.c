#include "interval_types.h"
#include "intervals.h"

int interval_list_halfstep_shift(interval_t *interval_list) {
   int shift = 0;
   for (int i=0; i<nintervals; i++) {
      shift += interval_list[i].ht_steps*interval_list[i].pow;
   }

   return shift;
}

