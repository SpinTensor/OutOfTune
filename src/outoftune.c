#include <stdlib.h>
#include <stdio.h>

#include <limits.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

#include "cmd_options.h"
#include "intervals.h"
#include "interval_list_properties.h"
#include "sequences.h"
#include "opt_sequence.h"

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
   printf("   startingOctave = %d\n", options.startingOctave); // octave in which to start the sequence
   printf("   maxhstepsdown = %d\n", options.maxhstepsdown); // allowed number of halfsteps down from the starting note
   printf("   maxhstepsup = %d\n", options.maxhstepsup); // allowed number of halfsteps up from the starting note
   printf("   navoidhsteps = %d\n", options.navoidhsteps); // number of halfsteps to avoid in sequence generation
   for (int i=0; i<options.navoidhsteps; i++) {
      printf("      avoidhsteps[%d] = %d\n", i, options.avoidhsteps[i]); // halfsteps to avoid in sequence generation
   }
   printf("   target_frequency_scale = %lf\n", options.target_frequency_scale); // target frequency scale to be reached after sequence
   printf("   target_halfstep_shift = %d\n", options.target_halfstep_shift); // target half step shift to be reached after sequence
   printf("   nseq_opt_steps = %lld\n", options.nsequence_opt_steps); // number of optimization steps for sequence optimization
   interval_t *interval_list = new_interval_list(options);
   mpq_t freq_scale;

   printf("\n");
   printf("Checking %lld possible interval combinations\n", total_interval_lists(interval_list));

   sequence_t sequence = new_sequence(options);
   // store best metrics
   double best_freq_scale_diff = INT_MAX;
   best_freq_scale_diff = (best_freq_scale_diff < 0) ? -best_freq_scale_diff : best_freq_scale_diff;

   // go through all 
   for (long long i=0; i<total_interval_lists(interval_list); i++) {
      int halfstep_shift = interval_list_halfstep_shift(interval_list);
      if (halfstep_shift == options.target_halfstep_shift) {

         interval_list_freq_scale(interval_list, &freq_scale);
         double freq_scale_diff = options.target_frequency_scale - mpq_get_d(freq_scale);
         freq_scale_diff = (freq_scale_diff < 0) ? -freq_scale_diff : freq_scale_diff;

         if (freq_scale_diff <= best_freq_scale_diff) {
            best_freq_scale_diff = freq_scale_diff;

            store_sequence(freq_scale,
                           freq_scale_diff,
                           halfstep_shift,
                           interval_list,
                           &sequence);
            if (sequence.sequence_length > 1) {

               optimize_sequence(&sequence, options);

               generate_note_sequence(&sequence, options);

               if (sequence.score == 0) {

                  printf("%16lld:", i);
                  for (int iint=0; iint<nintervals; iint++) {
                     printf(" %4d", interval_list[iint].pow);
                  }

                  printf(" (shift = %d, scale = %le (%le cents)",
                         halfstep_shift,
                         mpq_get_d(freq_scale),
                         1200.0 * log(mpq_get_d(freq_scale))/ log(2.0));

                  for (int i=0; i<sequence.sequence_length; i++) {
                     if (i%12 == 0) {
                        printf("\n                 ");
                     }
                     printf(" %4d", sequence.interval_sequence[i]);
                  }

                  for (int i=0; i<sequence.sequence_length+1; i++) {
                     if (i%8 == 0) {
                        printf("\n                 ");
                     }
                     printf(" %s", sequence.note_sequence[i].name);
                     if (strlen(sequence.note_sequence[i].name) == 1) {
                        printf(" ");
                     }
                     printf("(%2d) ", sequence.note_sequence[i].octave);
                  }
                  printf("\n                  ");
                  printf("maxhstepsup = %d, maxhstepsdown = %d, avoidviolations = %d, score = %d\n\n",
                         sequence.maxhstepsup,
                         sequence.maxhstepsdown,
                         sequence.avoidviolations,
                         sequence.score);
               }
            }
         }
      }
      next_interval_list(interval_list);
   }

   mpq_clear(freq_scale);
   free_sequence(sequence);
   free_interval_list(&interval_list);
   free_cmd_options(&options);
   return 0;
}
