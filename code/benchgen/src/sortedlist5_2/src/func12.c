#include "sortedlist5_2.h" 
sortedlist_t* func12(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist9;
   if (pCounter > 0) {
      sortedlist9 = vars->data[--pCounter];
      sortedlist9->refC++;
      DEBUG_COPY(sortedlist9->id);
   } else {
      sortedlist9 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist9->refC = 1;
      sortedlist9->id = 9;
      sortedlist9->n = 0;
      sortedlist9->root = NULL;
      DEBUG_NEW(sortedlist9->id);
   }
   return sortedlist9;
}

