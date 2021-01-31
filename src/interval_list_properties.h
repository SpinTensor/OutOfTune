#ifndef INTERVAL_LIST_PROPERTIES
#define INTERVAL_LIST_PROPERTIES

#include <gmp.h>

#include "interval_types.h"

int interval_list_halfstep_shift(interval_t *interval_list);

void interval_list_freq_scale(interval_t *interval_list, mpq_t *scale);

#endif
