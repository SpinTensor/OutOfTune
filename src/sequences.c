#include <stdlib.h>

#include "cmd_opt_types.h"
#include "sequence_types.h"
#include "interval_types.h"

sequence_t new_sequence(cmd_options_t options) {
   sequence_t sequence;
   sequence.intervalpows = (int*) malloc(nintervals * sizeof(int));
   sequence.sequence_length =  options.nP1;
   sequence.sequence_length += options.nm2;
   sequence.sequence_length += options.nM2;
   sequence.sequence_length += options.nm3;
   sequence.sequence_length += options.nM3;
   sequence.sequence_length += options.nP4;
   sequence.sequence_length += options.nP5;
   sequence.sequence_length += options.nm6;
   sequence.sequence_length += options.nM6;
   sequence.sequence_length += options.nm7;
   sequence.sequence_length += options.nM7;
   sequence.sequence_length += options.nP8;

   sequence.interval_sequence = (int*) malloc(sequence.sequence_length * sizeof(int));

   return sequence;
}

void store_sequence(frac_t freq_scale, double freq_scale_diff, int halfstep_shift,
                    interval_t *interval_list, sequence_t *sequence) {
   sequence->freq_scale = freq_scale;
   sequence->freq_scale_diff = freq_scale_diff;
   sequence->halfstep_shift = halfstep_shift;
   sequence->sequence_length = 0;
   for (int i=0; i<nintervals; i++ ){
      sequence->intervalpows[i] = interval_list[i].pow;
      for (int j=0; j<sequence->intervalpows[i]; j++) {
         sequence->interval_sequence[sequence->sequence_length] = interval_list[i].ht_steps;
         sequence->sequence_length += 1;
      }
      for (int j=0; j>sequence->intervalpows[i]; j--) {
         sequence->interval_sequence[sequence->sequence_length] = -interval_list[i].ht_steps;
         sequence->sequence_length += 1;
      }
   }
}

void free_sequence(sequence_t sequence) {
   free(sequence.intervalpows);
   free(sequence.interval_sequence);
}
