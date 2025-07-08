#include "sortedlist10_8.h" 
sortedlist_t* func12(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist52;
   if (pCounter > 0) {
      sortedlist52 = vars->data[--pCounter];
      sortedlist52->refC++;
      DEBUG_COPY(sortedlist52->id);
   } else {
      sortedlist52 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist52->refC = 1;
      sortedlist52->id = 52;
      sortedlist52->n = 0;
      sortedlist52->root = NULL;
      DEBUG_NEW(sortedlist52->id);
   }
   return sortedlist52;
}

