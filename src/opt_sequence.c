#include "sequence_types.h"
#include "cmd_opt_types.h"
#include "permutations.h"

void optimize_sequence(sequence_t *sequence_ptr, cmd_options_t options) {
   sequence_t sequence = *sequence_ptr;
   shuffle_list(sequence.sequence_length, sequence.sequence);
}
