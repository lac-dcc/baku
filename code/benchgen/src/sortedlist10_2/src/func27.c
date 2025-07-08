#include "sortedlist10_2.h" 
sortedlist_t* func27(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist60;
   if (pCounter > 0) {
      sortedlist60 = vars->data[--pCounter];
      sortedlist60->refC++;
      DEBUG_COPY(sortedlist60->id);
   } else {
      sortedlist60 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist60->refC = 1;
      sortedlist60->id = 60;
      sortedlist60->n = 0;
      sortedlist60->root = NULL;
      DEBUG_NEW(sortedlist60->id);
   }
   return sortedlist60;
}

