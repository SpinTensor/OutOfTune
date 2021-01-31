#ifndef INTERVAL_TYPES_H
#define INTERVAL_TYPES_H

#include <gmp.h>

enum interval_ID_e {
   P1,
   m2, M2,
   m3, M3,
   P4,
   P5,
   m6, M6,
   m7, M7,
   P8
};

typedef struct {
   char *name;
   enum interval_ID_e ID;
   int ht_steps;
   mpq_t freqscale;
   int minpow;
   int maxpow;
   int pow;
} interval_t;

extern const int nintervals;

#endif
