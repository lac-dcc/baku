#include "sortedlist5_1.h" 
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist8;
   if (pCounter > 0) {
      sortedlist8 = vars->data[--pCounter];
      sortedlist8->refC++;
      DEBUG_COPY(sortedlist8->id);
   } else {
      sortedlist8 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist8->refC = 1;
      sortedlist8->id = 8;
      sortedlist8->n = 0;
      sortedlist8->root = NULL;
      DEBUG_NEW(sortedlist8->id);
   }
   return sortedlist8;
}

