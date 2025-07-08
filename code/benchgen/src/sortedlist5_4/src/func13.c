#include "sortedlist5_4.h" 
sortedlist_t* func13(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist32;
   if (pCounter > 0) {
      sortedlist32 = vars->data[--pCounter];
      sortedlist32->refC++;
      DEBUG_COPY(sortedlist32->id);
   } else {
      sortedlist32 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist32->refC = 1;
      sortedlist32->id = 32;
      sortedlist32->n = 0;
      sortedlist32->root = NULL;
      DEBUG_NEW(sortedlist32->id);
   }
   return sortedlist32;
}

