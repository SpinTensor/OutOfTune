#include "random.h"

void swap_elements(int *list, int i, int j) {
   int tmp = list[i];
   list[i] = list[j];
   list[j] = tmp;
}

void shuffle_list(int n, int *list) {
   for (int i=n-1; i>0; i--) {
      int r = next_int_random(0, i);
      swap_elements(list, i, r);
   }
}
