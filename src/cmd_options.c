#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <limits.h>
#include <argp.h>

#include <config.h>

#include "cmd_opt_types.h"

const char *argp_program_version = PACKAGE_VERSION;

const char *argp_program_bug_address = PACKAGE_BUGREPORT;

/* Program documentation. */
static char doc[] = "Generate tone shifting sequences of notes";

// A description of the arguments we accept.
// static char args_doc[] = "";

// the possible program options
static struct argp_option possible_options[] = {
   {
      "1p",
      nP1_ID,
      "n",
      0,
      "number of unisons in sequence",
      0
   }, {
      "2m",
      nm2_ID,
      "n",
      0,
      "number of minor seconds in sequence",
      0
   }, {
      "2M",
      nM2_ID,
      "n",
      0,
      "number of major seconds in sequence",
      0
   }, {
      "3m",
      nm3_ID,
      "n",
      0,
      "number of minor thirds in sequence",
      0
   }, {
      "3M",
      nM3_ID,
      "n",
      0,
      "number of major thirds in sequence",
      0
   }, {
      "4p",
      nP4_ID,
      "n",
      0,
      "number of perfect fourths in sequence",
      0
   }, {
      "5p",
      nP5_ID,
      "n",
      0,
      "number of perfect fifths in sequence",
      0
   }, {
      "6m",
      nm6_ID,
      "n",
      0,
      "number of minor sixths in sequence",
      0
   }, {
      "6M",
      nM6_ID,
      "n",
      0,
      "number of major sixths in sequence",
      0
   }, {
      "7m",
      nm7_ID,
      "n",
      0,
      "number of minor sevenths in sequence",
      0
   },{
      "7M",
      nM7_ID,
      "n",
      0,
      "number of major sevenths in sequence",
      0
   }, {"8p",
      nP8_ID,
      "n",
      0,
      "number of perfect octaves in sequence",
      0
   }, {"starting-note",
      startingNote_ID,
      "note",
      0,
      "Note to start the sequence on .e.g. \"cis\"",
      0
   }, {
      "max-hstep-up",
      maxhstepsup_ID,
      "n",
      0,
      "limit the number of halfsteps the sequence can go up from the starting note",
      0
   }, {
      "max-hstep-down",
      maxhstepsdown_ID,
      "n",
      0,
      "limit the number of halfsteps the sequence can go down from the starting note",
      0
   }, {
      "avoid-hsteps",
      avoidhsteps_ID,
      "n,m",
      0,
      "komma separated list of halfsteps to avoid in the sequence generation",
      0
   }, {
      "target-freq-scale",
      target_frequency_scale_ID,
      "c",
      0,
      "frequency scale parameter to aim at with sequence",
      0
   }, {
      "target-hstep-shift",
      target_halfstep_shift_ID,
      "i",
      0,
      "number of halfsteps to be off relative to starting note after sequence",
      0
   }, {
      0, 0, 0, 0, 0, 0}
};

// Option parsing function
static error_t parse_cmd_options(int key, char *arg, struct argp_state *state) {
   // Get the input argument from argp_parse, which we
   // know is a pointer to our arguments structure. */
   cmd_options_t *options = state->input;

   switch (key) {
      // Intervall amounts
      case nP1_ID:
         options->nP1 = atoi(arg);
         break;
      case nm2_ID:
         options->nm2 = atoi(arg);
         break;
      case nM2_ID:
         options->nM2 = atoi(arg);
         break;
      case nm3_ID:
         options->nm3 = atoi(arg);
         break;
      case nM3_ID:
         options->nM3 = atoi(arg);
         break;
      case nP4_ID:
         options->nP4 = atoi(arg);
         break;
      case nP5_ID:
         options->nP5 = atoi(arg);
         break;
      case nm6_ID:
         options->nm6 = atoi(arg);
         break;
      case nM6_ID:
         options->nM6 = atoi(arg);
         break;
      case nm7_ID:
         options->nm7 = atoi(arg);
         break;
      case nM7_ID:
         options->nM7 = atoi(arg);
         break;
      case nP8_ID:
         options->nP8 = atoi(arg);
         break;
      // other options
      case avoidhsteps_ID:
         // TODO
         break;
      case maxhstepsdown_ID:
         options->maxhstepsdown = atoi(arg);
         break;
      case maxhstepsup_ID:
         options->maxhstepsup = atoi(arg);
         break;
      case target_halfstep_shift_ID:
         options->target_halfstep_shift = atoi(arg);
         break;
      case target_frequency_scale_ID:
         options->target_frequency_scale = atof(arg);
         break;
      case startingNote_ID:
         options->startingNote = strdup(arg);
         break;
      case ARGP_KEY_ARG:
         if (state->arg_num > 0) {
            argp_usage(state);
         }
         break;
      default:
         return ARGP_ERR_UNKNOWN;
         break;
   }

   return 0;
}

// Our argp parser.
static struct argp argp = {possible_options,
                           parse_cmd_options,
                           NULL,
                           doc,
                           NULL, NULL, NULL};

// easy interface to command line option parsing
cmd_options_t parse_command_line_options(int argc, char **argv) {
   cmd_options_t options;
   // set default values
   options.nP1 = 0; // number of unisons
   options.nm2 = 0; // number of minor seconds
   options.nM2 = 0; // number of major seconds
   options.nm3 = 0; // number of minor thirds
   options.nM3 = 0; // number of major thirds
   options.nP4 = 0; // number of perfect fourths
   options.nP5 = 0; // number of perfect fifths
   options.nm6 = 0; // number of minor sixths
   options.nM6 = 0; // number of major sixths
   options.nm7 = 0; // number of minor sevenths
   options.nM7 = 0; // number of major sevenths
   options.nP8 = 0; // number of perfect octaves
   options.startingNote = NULL; // note on which to start the sequence
   options.maxhstepsdown = INT_MAX; // allowed number of halfsteps down from the starting note
   options.maxhstepsup = INT_MAX; // allowed number of halfsteps up from the starting note
   options.navoidhsteps = 0; // number of halfsteps to avoid in sequence generation
   options.avoidhsteps = NULL; // halfsteps to avoid in sequence generation
   options.target_frequency_scale = 1.0; // target frequency scale to be reached after sequence
   options.target_halfstep_shift = 0; // target half step shift to be reached after sequence

   // actually parse the arguments
   argp_parse(&argp, argc, argv, 0, 0, &options);

   return options;

}
