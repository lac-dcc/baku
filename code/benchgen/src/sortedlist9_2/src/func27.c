#include "sortedlist9_2.h" 
sortedlist_t* func27(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist54;
   if (pCounter > 0) {
      sortedlist54 = vars->data[--pCounter];
      sortedlist54->refC++;
      DEBUG_COPY(sortedlist54->id);
   } else {
      sortedlist54 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist54->refC = 1;
      sortedlist54->id = 54;
      sortedlist54->n = 0;
      sortedlist54->root = NULL;
      DEBUG_NEW(sortedlist54->id);
   }
   return sortedlist54;
}

