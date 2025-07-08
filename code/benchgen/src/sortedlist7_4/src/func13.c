#include "sortedlist7_4.h" 
sortedlist_t* func13(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist35;
   if (pCounter > 0) {
      sortedlist35 = vars->data[--pCounter];
      sortedlist35->refC++;
      DEBUG_COPY(sortedlist35->id);
   } else {
      sortedlist35 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist35->refC = 1;
      sortedlist35->id = 35;
      sortedlist35->n = 0;
      sortedlist35->root = NULL;
      DEBUG_NEW(sortedlist35->id);
   }
   return sortedlist35;
}

