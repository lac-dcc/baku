#include "sortedlist10_4.h" 
sortedlist_t* func33(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist63;
   if (pCounter > 0) {
      sortedlist63 = vars->data[--pCounter];
      sortedlist63->refC++;
      DEBUG_COPY(sortedlist63->id);
   } else {
      sortedlist63 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist63->refC = 1;
      sortedlist63->id = 63;
      sortedlist63->n = 0;
      sortedlist63->root = NULL;
      DEBUG_NEW(sortedlist63->id);
   }
   return sortedlist63;
}

