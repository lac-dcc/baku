#include "sortedlist10_8.h" 
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist48;
   if (pCounter > 0) {
      sortedlist48 = vars->data[--pCounter];
      sortedlist48->refC++;
      DEBUG_COPY(sortedlist48->id);
   } else {
      sortedlist48 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist48->refC = 1;
      sortedlist48->id = 48;
      sortedlist48->n = 0;
      sortedlist48->root = NULL;
      DEBUG_NEW(sortedlist48->id);
   }
   return sortedlist48;
}

