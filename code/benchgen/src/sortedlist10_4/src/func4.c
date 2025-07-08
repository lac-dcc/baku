#include "sortedlist10_4.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist38;
   if (pCounter > 0) {
      sortedlist38 = vars->data[--pCounter];
      sortedlist38->refC++;
      DEBUG_COPY(sortedlist38->id);
   } else {
      sortedlist38 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist38->refC = 1;
      sortedlist38->id = 38;
      sortedlist38->n = 0;
      sortedlist38->root = NULL;
      DEBUG_NEW(sortedlist38->id);
   }
   return sortedlist38;
}

