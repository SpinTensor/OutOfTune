#ifndef SEQUENCE_PROPERTIES_H
#define SEQUENCE_PROPERTIES_H

#include "sequence_types.h"
#include "cmd_opt_types.h"

void sequence_properties(sequence_t *sequence, cmd_options_t options,
                         int *maxhstepsup, int *maxhstepsdown, int *avoidviolations);
#endif
