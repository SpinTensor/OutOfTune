#include <stdbool.h>

bool in_list(int len, int *list, int n) {
   for (int i=0; i<len; i++ ) {
      if (list[i] == n) {
         return true;
      }
   }
   return false;
}
