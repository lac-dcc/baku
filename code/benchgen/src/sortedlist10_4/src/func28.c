#include "sortedlist10_4.h" 
sortedlist_t* func28(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist24;
   if (pCounter > 0) {
      sortedlist24 = vars->data[--pCounter];
      sortedlist24->refC++;
      DEBUG_COPY(sortedlist24->id);
   } else {
      sortedlist24 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist24->refC = 1;
      sortedlist24->id = 24;
      sortedlist24->n = 0;
      sortedlist24->root = NULL;
      DEBUG_NEW(sortedlist24->id);
   }
   return sortedlist24;
}

