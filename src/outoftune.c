#include <stdlib.h>
#include <stdio.h>

#include "cmd_options.h"
#include "fractions.h"
#include "intervals.h"
#include "interval_list_properties.h"
#include "sequences.h"
#include "sequence_properties.h"

int main(int argc, char **argv) {
   (void) argc;
   (void) argv;

   cmd_options_t options = parse_command_line_options(argc, argv);

   printf("Settings:\n");
   printf("   nP1 = %d\n", options.nP1); // number of unisons
   printf("   nm2 = %d\n", options.nm2); // number of minor seconds
   printf("   nM2 = %d\n", options.nM2); // number of major seconds
   printf("   nm3 = %d\n", options.nm3); // number of minor thirds
   printf("   nM3 = %d\n", options.nM3); // number of major thirds
   printf("   nP4 = %d\n", options.nP4); // number of perfect fourths
   printf("   nP5 = %d\n", options.nP5); // number of perfect fifths
   printf("   nm6 = %d\n", options.nm6); // number of minor sixths
   printf("   nM6 = %d\n", options.nM6); // number of major sixths
   printf("   nm7 = %d\n", options.nm7); // number of minor sevenths
   printf("   nM7 = %d\n", options.nM7); // number of major sevenths
   printf("   nP8 = %d\n", options.nP8); // number of perfect octaves
   printf("   startingNote = %s\n", options.startingNote); // note on which to start the sequence
   printf("   maxhstepsdown = %d\n", options.maxhstepsdown); // allowed number of halfsteps down from the starting note
   printf("   maxhstepsup = %d\n", options.maxhstepsup); // allowed number of halfsteps up from the starting note
   printf("   navoidhsteps = %d\n", options.navoidhsteps); // number of halfsteps to avoid in sequence generation
   for (int i=0; i<options.navoidhsteps; i++) {
      printf("      avoidhsteps[%d] = %d\n", i, options.avoidhsteps[i]); // halfsteps to avoid in sequence generation
   }
   printf("   target_frequency_scale = %lf\n", options.target_frequency_scale); // target frequency scale to be reached after sequence
   printf("   target_halfstep_shift = %d\n", options.target_halfstep_shift); // target half step shift to be reached after sequence
   interval_t *interval_list = new_interval_list(options);

   printf("\n");
   printf("Checking %lld possible interval combinations\n", total_interval_lists(interval_list));

   sequence_t sequence = new_sequence(options);


   // store best metrics
   frac_t best_freq_scale = interval_list_freq_scale(interval_list);
   double best_freq_scale_diff = 1.0 - frac2decimal(best_freq_scale);
   best_freq_scale_diff = (best_freq_scale_diff < 0) ? -best_freq_scale_diff : best_freq_scale_diff;

   // go through all 
   for (long long i=0; i<total_interval_lists(interval_list); i++) {
      int halfstep_shift = interval_list_halfstep_shift(interval_list);
      if (halfstep_shift == options.target_halfstep_shift) {

         frac_t freq_scale = interval_list_freq_scale(interval_list);
         double freq_scale_diff = 1.0 - frac2decimal(freq_scale);
         freq_scale_diff = (freq_scale_diff < 0) ? -freq_scale_diff : freq_scale_diff;

         if (freq_scale_diff <= best_freq_scale_diff) {
            best_freq_scale_diff = freq_scale_diff;
            best_freq_scale = freq_scale;

            printf("%16lld:", i);
            for (int iint=0; iint<nintervals; iint++) {
               printf(" %4d", interval_list[iint].pow);
            }

            printf(" (shift = %d, scale = %lf (%le))",
                   halfstep_shift,
                   frac2decimal(freq_scale),
                   freq_scale_diff);

            store_sequence(freq_scale,
                           freq_scale_diff,
                           halfstep_shift,
                           interval_list,
                           &sequence);

            sequence_properties(&sequence, options);

            for (int i=0; i<sequence.sequence_length; i++) {
               if (i%12 == 0) {
                  printf("\n                 ");
               }
               printf(" %4d", sequence.sequence[i]);
            }
            printf("\n");
            printf("                  ");
            printf("maxhstepsup = %d, maxhstepsdown = %d, avoidviolations = %d\n",
                   sequence.maxhstepsup,
                   sequence.maxhstepsdown,
                   sequence.avoidviolations);

         }
      }
      next_interval_list(interval_list);
   }

   free_sequence(sequence);
   free_interval_list(&interval_list);
   free_cmd_options(&options);
   return 0;
}
