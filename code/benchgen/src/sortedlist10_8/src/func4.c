#include "sortedlist10_8.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist56;
   if (pCounter > 0) {
      sortedlist56 = vars->data[--pCounter];
      sortedlist56->refC++;
      DEBUG_COPY(sortedlist56->id);
   } else {
      sortedlist56 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist56->refC = 1;
      sortedlist56->id = 56;
      sortedlist56->n = 0;
      sortedlist56->root = NULL;
      DEBUG_NEW(sortedlist56->id);
   }
   return sortedlist56;
}

