#include "sortedlist10_4.h" 
sortedlist_t* func14(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist47;
   if (pCounter > 0) {
      sortedlist47 = vars->data[--pCounter];
      sortedlist47->refC++;
      DEBUG_COPY(sortedlist47->id);
   } else {
      sortedlist47 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist47->refC = 1;
      sortedlist47->id = 47;
      sortedlist47->n = 0;
      sortedlist47->root = NULL;
      DEBUG_NEW(sortedlist47->id);
   }
   return sortedlist47;
}

