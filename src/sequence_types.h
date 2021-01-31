#ifndef SEQUENCE_TYPES_H
#define SEQUENCE_TYPES_H

#include <gmp.h>

typedef struct {
   char *name;
   int octave;
} note_t;

typedef struct {
   int nintervalpows;
   int *intervalpows;
   mpq_t freq_scale;
   double freq_scale_diff;
   int halfstep_shift;
   int sequence_length;
   int *interval_sequence;
   note_t *note_sequence;
   int maxhstepsup;
   int maxhstepsdown;
   int avoidviolations;
   int score;
} sequence_t;

#endif
