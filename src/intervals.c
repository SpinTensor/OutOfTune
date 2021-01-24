#include <stdlib.h>
#include <stdbool.h>

#include "interval_types.h"
#include "cmd_opt_types.h"
#include "frac_types.h"
#include "fractions.h"

const int nintervals = 12;

interval_t *new_interval_list(cmd_options_t options) {
   interval_t *interval_list = (interval_t*) malloc(nintervals*sizeof(interval_t));

   interval_list[0].name = "unison";
   interval_list[0].ID = P1;
   interval_list[0].ht_steps = 0;
   interval_list[0].freqscale = frac_new(1, 1);
   interval_list[0].maxpow = options.nP1;
   interval_list[0].pow = -interval_list[0].maxpow;

   interval_list[1].name = "minor second";
   interval_list[1].ID = m2;
   interval_list[1].ht_steps = 1;
   interval_list[1].freqscale = frac_new(16, 15);
   interval_list[1].maxpow = options.nm2;
   interval_list[1].pow = -interval_list[1].maxpow;

   interval_list[2].name = "major second";
   interval_list[2].ID = M2;
   interval_list[2].ht_steps = 2;
   interval_list[2].freqscale = frac_new(9, 8);
   interval_list[2].maxpow = options.nM2;
   interval_list[2].pow = -interval_list[2].maxpow;

   interval_list[3].name = "minor third";
   interval_list[3].ID = m3;
   interval_list[3].ht_steps = 3;
   interval_list[3].freqscale = frac_new(6, 5);
   interval_list[3].maxpow = options.nm3;
   interval_list[3].pow = -interval_list[3].maxpow;

   interval_list[4].name = "major third";
   interval_list[4].ID = M3;
   interval_list[4].ht_steps = 4;
   interval_list[4].freqscale = frac_new(5, 4);
   interval_list[4].maxpow = options.nM3;
   interval_list[4].pow = -interval_list[4].maxpow;

   interval_list[5].name = "perfect fourth";
   interval_list[5].ID = P4;
   interval_list[5].ht_steps = 5;
   interval_list[5].freqscale = frac_new(4, 3);
   interval_list[5].maxpow = options.nP4;
   interval_list[5].pow = -interval_list[5].maxpow;

   interval_list[6].name = "perfect fifth";
   interval_list[6].ID = P5;
   interval_list[6].ht_steps = 7;
   interval_list[6].freqscale = frac_new(3, 2);
   interval_list[6].maxpow = options.nP5;
   interval_list[6].pow = -interval_list[6].maxpow;

   interval_list[7].name = "minor sixth";
   interval_list[7].ID = m6;
   interval_list[7].ht_steps = 8;
   interval_list[7].freqscale = frac_new(8, 5);
   interval_list[7].maxpow = options.nm6;
   interval_list[7].pow = -interval_list[7].maxpow;

   interval_list[8].name = "major sixth";
   interval_list[8].ID = M6;
   interval_list[8].ht_steps = 9;
   interval_list[8].freqscale = frac_new(5, 3);
   interval_list[8].maxpow = options.nM6;
   interval_list[8].pow = -interval_list[8].maxpow;

   interval_list[9].name = "minor seventh";
   interval_list[9].ID = m7;
   interval_list[9].ht_steps = 10;
   interval_list[9].freqscale = frac_new(16, 9);
   interval_list[9].maxpow = options.nm7;
   interval_list[9].pow = -interval_list[9].maxpow;

   interval_list[10].name = "major seventh";
   interval_list[10].ID = M7;
   interval_list[10].ht_steps = 11;
   interval_list[10].freqscale = frac_new(15, 8);
   interval_list[10].maxpow = options.nM7;
   interval_list[10].pow = -interval_list[10].maxpow;

   interval_list[11].name = "perfect octave";
   interval_list[11].ID = P8;
   interval_list[11].ht_steps = 12;
   interval_list[11].freqscale = frac_new(2, 1);
   interval_list[11].maxpow = options.nP8;
   interval_list[11].pow = -interval_list[11].maxpow;

   return interval_list;
}

long long total_interval_lists(interval_t *interval_list) {
   long long product = 1;
   for (int iinterval=0; iinterval<nintervals; iinterval++) {
      product *= 2*interval_list[iinterval].maxpow + 1;
   }
   return product;
}

void next_interval_list(interval_t *interval_list) {
   // search for the first interval entry which is supposed to be varied
   int idx = 0;
   while (interval_list[idx].maxpow == 0 && idx < nintervals) {
      idx++;
   }

   // increment the interval counter and carry if required
   bool carry = false;
   if (interval_list[idx].pow == interval_list[idx].maxpow) {
      carry = true;
      interval_list[idx].pow = -interval_list[idx].maxpow;
   } else {
      interval_list[idx].pow += 1;
   }

   // carry
   idx++;
   while (carry && idx < nintervals) {
      if (interval_list[idx].maxpow != 0) {
         if (interval_list[idx].pow == interval_list[idx].maxpow) {
            interval_list[idx].pow = -interval_list[idx].maxpow;
         } else {
            interval_list[idx].pow += 1;
            carry = false;
         }
      }
      idx++;
   }
}

void free_interval_list(interval_t **interval_list_ptr) {
   interval_t *interval_list = *interval_list_ptr;
   free(interval_list);
   interval_list = NULL;
}
