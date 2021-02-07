#include "sequence_types.h"
#include "cmd_opt_types.h"
#include "sequence_properties.h"
#include "permutations.h"
#include "in_list.c"
#include "random.h"

void optimize_sequence(sequence_t *sequence_ptr, cmd_options_t options) {
   int length = sequence_ptr->sequence_length;
   shuffle_list(sequence_ptr->sequence_length, sequence_ptr->interval_sequence);
   int sum = 0;
   for (int ielem=0; ielem<length-1; ielem++) {
      int i = next_int_random(ielem+1, length-1);
      while (sum + sequence_ptr->interval_sequence[i] > options.maxhstepsup ||
             sum + sequence_ptr->interval_sequence[i] < -options.maxhstepsdown) {
         i = next_int_random(ielem+1, length-1);
      }
      sum += sequence_ptr->interval_sequence[i];
      swap_elements(sequence_ptr->interval_sequence, ielem, i);
   }
   sequence_properties(sequence_ptr,
                       &(sequence_ptr->maxhstepsup),
                       &(sequence_ptr->maxhstepsdown));
}
