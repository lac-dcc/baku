#include "sortedlist9_8.h" 
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist23;
   if (pCounter > 0) {
      sortedlist23 = vars->data[--pCounter];
      sortedlist23->refC++;
      DEBUG_COPY(sortedlist23->id);
   } else {
      sortedlist23 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist23->refC = 1;
      sortedlist23->id = 23;
      sortedlist23->n = 0;
      sortedlist23->root = NULL;
      DEBUG_NEW(sortedlist23->id);
   }
   return sortedlist23;
}

