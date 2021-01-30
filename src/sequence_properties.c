#include "sequence_types.h"
#include "cmd_opt_types.h"

void sequence_properties(sequence_t *sequence, cmd_options_t options,
                         int *maxhstepsup, int *maxhstepsdown, int *avoidviolations) {
   int sum = 0;
   *maxhstepsup = 0;
   *maxhstepsdown = 0;
   *avoidviolations = 0;
   for (int i=0; i<sequence->sequence_length; i++) {
      sum += sequence->interval_sequence[i];
      if (sum > *maxhstepsup) {
         *maxhstepsup = sum;
      } else if (sum < -(*maxhstepsdown)) {
         *maxhstepsdown = -sum;
      }

      for (int j=0; j<options.navoidhsteps; j++) {
         if (sum == options.avoidhsteps[j]) {
            *avoidviolations += 1;
         }
      }
   }
}
