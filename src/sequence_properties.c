#include "sequence_types.h"
#include "cmd_opt_types.h"

void sequence_properties(sequence_t *sequence, int *maxhstepsup, int *maxhstepsdown) {
   int sum = 0;
   *maxhstepsup = 0;
   *maxhstepsdown = 0;
   for (int i=0; i<sequence->sequence_length; i++) {
      sum += sequence->interval_sequence[i];
      if (sum > *maxhstepsup) {
         *maxhstepsup = sum;
      } else if (sum < -(*maxhstepsdown)) {
         *maxhstepsdown = -sum;
      }
   }
}
