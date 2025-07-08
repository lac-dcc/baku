#include "sortedlist9_8.h" 
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist41;
   if (pCounter > 0) {
      sortedlist41 = vars->data[--pCounter];
      sortedlist41->refC++;
      DEBUG_COPY(sortedlist41->id);
   } else {
      sortedlist41 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist41->refC = 1;
      sortedlist41->id = 41;
      sortedlist41->n = 0;
      sortedlist41->root = NULL;
      DEBUG_NEW(sortedlist41->id);
   }
   return sortedlist41;
}

