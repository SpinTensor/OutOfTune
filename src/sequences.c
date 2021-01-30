#include <stdlib.h>

#include <string.h>

#include "cmd_opt_types.h"
#include "sequence_types.h"
#include "interval_types.h"

sequence_t new_sequence(cmd_options_t options) {
   sequence_t sequence;
   sequence.intervalpows = (int*) malloc(nintervals * sizeof(int));
   sequence.sequence_length =  options.nP1;
   sequence.sequence_length += options.nm2;
   sequence.sequence_length += options.nM2;
   sequence.sequence_length += options.nm3;
   sequence.sequence_length += options.nM3;
   sequence.sequence_length += options.nP4;
   sequence.sequence_length += options.nP5;
   sequence.sequence_length += options.nm6;
   sequence.sequence_length += options.nM6;
   sequence.sequence_length += options.nm7;
   sequence.sequence_length += options.nM7;
   sequence.sequence_length += options.nP8;

   sequence.interval_sequence = (int*) malloc(sequence.sequence_length * sizeof(int));
   sequence.note_sequence = (note_t*) malloc((sequence.sequence_length+1)*sizeof(note_t));

   return sequence;
}

void store_sequence(frac_t freq_scale, double freq_scale_diff, int halfstep_shift,
                    interval_t *interval_list, sequence_t *sequence) {
   sequence->freq_scale = freq_scale;
   sequence->freq_scale_diff = freq_scale_diff;
   sequence->halfstep_shift = halfstep_shift;
   sequence->sequence_length = 0;
   for (int i=0; i<nintervals; i++ ){
      sequence->intervalpows[i] = interval_list[i].pow;
      for (int j=0; j<sequence->intervalpows[i]; j++) {
         sequence->interval_sequence[sequence->sequence_length] = interval_list[i].ht_steps;
         sequence->sequence_length += 1;
      }
      for (int j=0; j>sequence->intervalpows[i]; j--) {
         sequence->interval_sequence[sequence->sequence_length] = -interval_list[i].ht_steps;
         sequence->sequence_length += 1;
      }
   }
}

void generate_note_sequence(sequence_t *sequence_ptr, cmd_options_t options) {
#define NNOTES 12
   char *note_name_list[NNOTES] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

   int octave = options.startingOctave;
   int cur_note_idx = -1;
   for (int inote=0; inote<NNOTES; inote++) {
      if (strcmp(options.startingNote, note_name_list[inote]) == 0) {
         cur_note_idx = inote;
         break;
      }
   }

   sequence_ptr->note_sequence[0].name = note_name_list[cur_note_idx];
   sequence_ptr->note_sequence[0].octave = octave;

   for (int i=0; i<sequence_ptr->sequence_length; i++) {
      cur_note_idx += sequence_ptr->interval_sequence[i];
      while (cur_note_idx >= NNOTES) {
         cur_note_idx -= NNOTES;
         octave ++;
      }
      while (cur_note_idx < 0) {
         cur_note_idx += NNOTES;
         octave --;
      }
      sequence_ptr->note_sequence[i+1].name = note_name_list[cur_note_idx];
      sequence_ptr->note_sequence[i+1].octave = octave;
   }
#undef NNOTES
}

void free_sequence(sequence_t sequence) {
   free(sequence.intervalpows);
   free(sequence.interval_sequence);
   free(sequence.note_sequence);
}
