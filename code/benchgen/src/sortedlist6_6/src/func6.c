#include "sortedlist6_6.h" 
sortedlist_t* func6(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist4;
   if (pCounter > 0) {
      sortedlist4 = vars->data[--pCounter];
      sortedlist4->refC++;
      DEBUG_COPY(sortedlist4->id);
   } else {
      sortedlist4 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist4->refC = 1;
      sortedlist4->id = 4;
      sortedlist4->n = 0;
      sortedlist4->root = NULL;
      DEBUG_NEW(sortedlist4->id);
   }
   return sortedlist4;
}

