#ifndef SEQUENCE_TYPES_H
#define SEQUENCE_TYPES_H

#include "frac_types.h"

typedef struct {
   int nintervalpows;
   int *intervalpows;
   frac_t freq_scale;
   double freq_scale_diff;
   int halfstep_shift;
   int sequence_length;
   int *sequence;
   int maxhstepsup;
   int maxhstepsdown;
   int avoidviolations;
} sequence_t;

#endif