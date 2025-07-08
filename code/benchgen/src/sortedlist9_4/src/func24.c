#include "sortedlist9_4.h" 
sortedlist_t* func24(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist55;
   if (pCounter > 0) {
      sortedlist55 = vars->data[--pCounter];
      sortedlist55->refC++;
      DEBUG_COPY(sortedlist55->id);
   } else {
      sortedlist55 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist55->refC = 1;
      sortedlist55->id = 55;
      sortedlist55->n = 0;
      sortedlist55->root = NULL;
      DEBUG_NEW(sortedlist55->id);
   }
   return sortedlist55;
}

