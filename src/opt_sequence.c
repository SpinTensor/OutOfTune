#include <stdbool.h>

#include "sequence_types.h"
#include "cmd_opt_types.h"
#include "sequence_properties.h"
#include "permutations.h"
#include "in_list.c"
#include "random.h"

void optimize_sequence(sequence_t *sequence_ptr, cmd_options_t options) {
   int length = sequence_ptr->sequence_length;
   bool success = false;
   while (!success) {
      success = true;
      shuffle_list(sequence_ptr->sequence_length, sequence_ptr->interval_sequence);
      int sum = 0;
      for (int ielem=0; ielem<length-1; ielem++) {
         int i = next_int_random(ielem+1, length-1);
         int itrials = 0;
         while (sum + sequence_ptr->interval_sequence[i] > options.maxhstepsup ||
                sum + sequence_ptr->interval_sequence[i] < -options.maxhstepsdown) {
            i = next_int_random(ielem+1, length-1);
            itrials++;
            if (itrials> 100*length) {
               success = false;
               break;
            }
         }
         if (success) {
            sum += sequence_ptr->interval_sequence[i];
            swap_elements(sequence_ptr->interval_sequence, ielem, i);
         } else {
            break;
         }
      }
   }
   sequence_properties(sequence_ptr,
                       &(sequence_ptr->maxhstepsup),
                       &(sequence_ptr->maxhstepsdown));
}
