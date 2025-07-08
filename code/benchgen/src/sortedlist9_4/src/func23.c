#include "sortedlist9_4.h" 
sortedlist_t* func23(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist53;
   if (pCounter > 0) {
      sortedlist53 = vars->data[--pCounter];
      sortedlist53->refC++;
      DEBUG_COPY(sortedlist53->id);
   } else {
      sortedlist53 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist53->refC = 1;
      sortedlist53->id = 53;
      sortedlist53->n = 0;
      sortedlist53->root = NULL;
      DEBUG_NEW(sortedlist53->id);
   }
   return sortedlist53;
}

