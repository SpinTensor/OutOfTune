#include "sequence_types.h"
#include "cmd_opt_types.h"

void sequence_properties(sequence_t *sequence, cmd_options_t options) {
   int sum = 0;
   sequence->maxhstepsup = 0;
   sequence->maxhstepsdown = 0;
   for (int i=0; i<sequence->sequence_length; i++) {
      sum += sequence->sequence[i];
      if (sum > sequence->maxhstepsup) {
         sequence->maxhstepsup = sum;
      } else if (sum < -sequence->maxhstepsdown) {
         sequence->maxhstepsdown = -sum;
      }

      for (int j=0; j<options.navoidhsteps; j++) {
         if (sum == options.avoidhsteps[j]) {
            sequence->avoidviolations += 1;
         }
      }
   }
}
