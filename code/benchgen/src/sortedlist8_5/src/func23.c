#include "sortedlist8_5.h" 
sortedlist_t* func23(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist31;
   if (pCounter > 0) {
      sortedlist31 = vars->data[--pCounter];
      sortedlist31->refC++;
      DEBUG_COPY(sortedlist31->id);
   } else {
      sortedlist31 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist31->refC = 1;
      sortedlist31->id = 31;
      sortedlist31->n = 0;
      sortedlist31->root = NULL;
      DEBUG_NEW(sortedlist31->id);
   }
   return sortedlist31;
}

