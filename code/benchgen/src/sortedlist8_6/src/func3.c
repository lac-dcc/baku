#include "sortedlist8_6.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist12;
   if (pCounter > 0) {
      sortedlist12 = vars->data[--pCounter];
      sortedlist12->refC++;
      DEBUG_COPY(sortedlist12->id);
   } else {
      sortedlist12 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist12->refC = 1;
      sortedlist12->id = 12;
      sortedlist12->n = 0;
      sortedlist12->root = NULL;
      DEBUG_NEW(sortedlist12->id);
   }
   return sortedlist12;
}

