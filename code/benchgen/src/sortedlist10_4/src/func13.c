#include "sortedlist10_4.h" 
sortedlist_t* func13(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist45;
   if (pCounter > 0) {
      sortedlist45 = vars->data[--pCounter];
      sortedlist45->refC++;
      DEBUG_COPY(sortedlist45->id);
   } else {
      sortedlist45 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist45->refC = 1;
      sortedlist45->id = 45;
      sortedlist45->n = 0;
      sortedlist45->root = NULL;
      DEBUG_NEW(sortedlist45->id);
   }
   return sortedlist45;
}

