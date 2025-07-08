#include "sortedlist8_8.h" 
sortedlist_t* func12(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist43;
   if (pCounter > 0) {
      sortedlist43 = vars->data[--pCounter];
      sortedlist43->refC++;
      DEBUG_COPY(sortedlist43->id);
   } else {
      sortedlist43 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist43->refC = 1;
      sortedlist43->id = 43;
      sortedlist43->n = 0;
      sortedlist43->root = NULL;
      DEBUG_NEW(sortedlist43->id);
   }
   return sortedlist43;
}

