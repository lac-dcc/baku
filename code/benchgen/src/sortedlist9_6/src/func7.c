#include "sortedlist9_6.h" 
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist6;
   if (pCounter > 0) {
      sortedlist6 = vars->data[--pCounter];
      sortedlist6->refC++;
      DEBUG_COPY(sortedlist6->id);
   } else {
      sortedlist6 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist6->refC = 1;
      sortedlist6->id = 6;
      sortedlist6->n = 0;
      sortedlist6->root = NULL;
      DEBUG_NEW(sortedlist6->id);
   }
   return sortedlist6;
}

