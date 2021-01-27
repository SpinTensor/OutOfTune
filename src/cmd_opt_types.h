#ifndef CMD_OPT_TYPES_H
#define CMD_OPT_TYPES_H

#include <argp.h>

typedef struct {
   int nP1; // number of unisons
   int nm2; // number of minor seconds
   int nM2; // number of major seconds
   int nm3; // number of minor thirds
   int nM3; // number of major thirds
   int nP4; // number of perfect fourths
   int nP5; // number of perfect fifths
   int nm6; // number of minor sixths
   int nM6; // number of major sixths
   int nm7; // number of minor sevenths
   int nM7; // number of major sevenths
   int nP8; // number of perfect octaves
   char *startingNote; // note on which to start the sequence
   int maxhstepsdown; // allowed number of halfsteps down from the starting note
   int maxhstepsup; // allowed number of halfsteps up from the starting note
   int navoidhsteps; // number of halfsteps to avoid in sequence generation
   int *avoidhsteps; // halfsteps to avoid in sequence generation
   double target_frequency_scale; // target frequency scale to be reached after sequence
   int target_halfstep_shift; // target half step shift to be reached after sequence
   long long nsequence_opt_steps; // number of steps to attempt to optimize sequence
} cmd_options_t;

enum cmd_opt_IDs {
   nP1_ID = 1024, // number of unisons
   nm2_ID, // number of minor seconds
   nM2_ID, // number of major seconds
   nm3_ID, // number of minor thirds
   nM3_ID, // number of major thirds
   nP4_ID, // number of perfect fourths
   nP5_ID, // number of perfect fifths
   nm6_ID, // number of minor sixths
   nM6_ID, // number of major sixths
   nm7_ID, // number of minor sevenths
   nM7_ID, // number of major sevenths
   nP8_ID, // number of perfect octaves
   startingNote_ID, // note on which to start the sequence
   maxhstepsdown_ID, // allowed number of halfsteps down from the starting note
   maxhstepsup_ID, // allowed number of halfsteps up from the starting note
   navoidhsteps_ID, // number of halfsteps to avoid in sequence generation
   avoidhsteps_ID, // halfsteps to avoid in sequence generation
   target_frequency_scale_ID, // target frequency scale to be reached after sequence
   target_halfstep_shift_ID, // target half step shift to be reached after sequence
   nsequence_opt_steps_ID // number of steps to attempt to optimize sequence
};

#endif
