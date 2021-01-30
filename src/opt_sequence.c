#include "sequence_types.h"
#include "cmd_opt_types.h"
#include "sequence_properties.h"
#include "permutations.h"
#include "random.h"

int compute_score(int maxhstepsup, int maxhstepsdown, int avoidviolations, cmd_options_t options) {
   int score = avoidviolations;
   if (maxhstepsup > options.maxhstepsup) {
      score += maxhstepsup;
   }
   if (maxhstepsdown > options.maxhstepsdown) {
      score += maxhstepsdown;
   }
   return score;
}

void optimize_sequence(sequence_t *sequence_ptr, cmd_options_t options) {
   shuffle_list(sequence_ptr->sequence_length, sequence_ptr->interval_sequence);
   sequence_properties(sequence_ptr, options,
                       &(sequence_ptr->maxhstepsup),
                       &(sequence_ptr->maxhstepsdown),
                       &(sequence_ptr->avoidviolations));
   int oldscore = compute_score(sequence_ptr->maxhstepsup,
                                sequence_ptr->maxhstepsdown,
                                sequence_ptr->avoidviolations,
                                options);

   int length = sequence_ptr->sequence_length;
   int tmpmaxhstepsup = sequence_ptr->maxhstepsup;
   int tmpmaxhstepsdown = sequence_ptr->maxhstepsdown;
   int tmpavoidviolations = sequence_ptr->avoidviolations;

   for (int istep=0; istep<options.nsequence_opt_steps; istep++) {
      int i = next_int_random(0, length-1);
      int j = i;
      while (j == i) {
         j = next_int_random(0, length-1);
      }
      swap_elements(sequence_ptr->interval_sequence, i, j);

      sequence_properties(sequence_ptr, options,
                          &tmpmaxhstepsup,
                          &tmpmaxhstepsdown,
                          &tmpavoidviolations);

      int newscore = compute_score(tmpmaxhstepsup,
                                   tmpmaxhstepsdown,
                                   tmpavoidviolations,
                                   options);
      if (newscore < oldscore) {
         // adapt new sequence
         sequence_ptr->maxhstepsup = tmpmaxhstepsup;
         sequence_ptr->maxhstepsdown = tmpmaxhstepsdown;
         sequence_ptr->avoidviolations = tmpavoidviolations;
         oldscore = newscore;
         // sequence is already adapted
      } else {
         // reset sequence
         // swap back the elements
         swap_elements(sequence_ptr->interval_sequence, i, j);
      }
      if (oldscore == 0) {
         break;
      }
   }
   sequence_ptr->score = oldscore;

   sequence_properties(sequence_ptr, options,
                       &(sequence_ptr->maxhstepsup),
                       &(sequence_ptr->maxhstepsdown),
                       &(sequence_ptr->avoidviolations));
}
