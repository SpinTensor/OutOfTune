#include <stdlib.h>
#include <stdio.h>

#include "cmd_options.h"
#include "intervals.h"

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

   interval_t *intervallist = new_interval_list(options);




   free_interval_list(&intervallist);
   free_cmd_options(&options);
   return 0;
}
