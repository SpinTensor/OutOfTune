#ifndef INTERVALS_H
#define INTERVALS_H

#include "interval_types.h"
#include "cmd_opt_types.h"

extern const int nintervals;

interval_t *new_interval_list(cmd_options_t options);

long long total_interval_lists(interval_t *interval_list);

void next_interval_list(interval_t *interval_list);

void free_interval_list(interval_t **interval_list_ptr);

#endif
