#include "sortedlist10_2.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist40;
   if (pCounter > 0) {
      sortedlist40 = vars->data[--pCounter];
      sortedlist40->refC++;
      DEBUG_COPY(sortedlist40->id);
   } else {
      sortedlist40 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist40->refC = 1;
      sortedlist40->id = 40;
      sortedlist40->n = 0;
      sortedlist40->root = NULL;
      DEBUG_NEW(sortedlist40->id);
   }
   return sortedlist40;
}

