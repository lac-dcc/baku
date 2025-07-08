#include "sortedlist6_10.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist10;
   if (pCounter > 0) {
      sortedlist10 = vars->data[--pCounter];
      sortedlist10->refC++;
      DEBUG_COPY(sortedlist10->id);
   } else {
      sortedlist10 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist10->refC = 1;
      sortedlist10->id = 10;
      sortedlist10->n = 0;
      sortedlist10->root = NULL;
      DEBUG_NEW(sortedlist10->id);
   }
   return sortedlist10;
}

