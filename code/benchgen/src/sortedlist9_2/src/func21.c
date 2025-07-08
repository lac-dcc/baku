#include "sortedlist9_2.h" 
sortedlist_t* func21(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist49;
   if (pCounter > 0) {
      sortedlist49 = vars->data[--pCounter];
      sortedlist49->refC++;
      DEBUG_COPY(sortedlist49->id);
   } else {
      sortedlist49 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist49->refC = 1;
      sortedlist49->id = 49;
      sortedlist49->n = 0;
      sortedlist49->root = NULL;
      DEBUG_NEW(sortedlist49->id);
   }
   return sortedlist49;
}

