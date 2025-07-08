#include "sortedlist7_2.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist27;
   if (pCounter > 0) {
      sortedlist27 = vars->data[--pCounter];
      sortedlist27->refC++;
      DEBUG_COPY(sortedlist27->id);
   } else {
      sortedlist27 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist27->refC = 1;
      sortedlist27->id = 27;
      sortedlist27->n = 0;
      sortedlist27->root = NULL;
      DEBUG_NEW(sortedlist27->id);
   }
   return sortedlist27;
}

