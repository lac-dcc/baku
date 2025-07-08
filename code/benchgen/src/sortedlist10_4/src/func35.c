#include "sortedlist10_4.h" 
sortedlist_t* func35(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist67;
   if (pCounter > 0) {
      sortedlist67 = vars->data[--pCounter];
      sortedlist67->refC++;
      DEBUG_COPY(sortedlist67->id);
   } else {
      sortedlist67 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist67->refC = 1;
      sortedlist67->id = 67;
      sortedlist67->n = 0;
      sortedlist67->root = NULL;
      DEBUG_NEW(sortedlist67->id);
   }
   return sortedlist67;
}

