#include "sortedlist10_5.h" 
sortedlist_t* func26(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist36;
   if (pCounter > 0) {
      sortedlist36 = vars->data[--pCounter];
      sortedlist36->refC++;
      DEBUG_COPY(sortedlist36->id);
   } else {
      sortedlist36 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist36->refC = 1;
      sortedlist36->id = 36;
      sortedlist36->n = 0;
      sortedlist36->root = NULL;
      DEBUG_NEW(sortedlist36->id);
   }
   return sortedlist36;
}

