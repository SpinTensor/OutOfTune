#ifndef SEQUENCES_H
#define SEQUENCES_H

#include "cmd_opt_types.h"
#include "sequence_types.h"
#include "interval_types.h"

sequence_t new_sequence(cmd_options_t options);

void store_sequence(frac_t freq_scale, double freq_scale_diff, int halfstep_shift,
                    interval_t *interval_list, sequence_t *sequence);

void generate_note_sequence(sequence_t *sequence_ptr, cmd_options_t options);

void free_sequence(sequence_t sequence);

#endif
