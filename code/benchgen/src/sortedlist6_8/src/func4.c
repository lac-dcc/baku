#include "sortedlist6_8.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist33;
   if (pCounter > 0) {
      sortedlist33 = vars->data[--pCounter];
      sortedlist33->refC++;
      DEBUG_COPY(sortedlist33->id);
   } else {
      sortedlist33 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist33->refC = 1;
      sortedlist33->id = 33;
      sortedlist33->n = 0;
      sortedlist33->root = NULL;
      DEBUG_NEW(sortedlist33->id);
   }
   return sortedlist33;
}

