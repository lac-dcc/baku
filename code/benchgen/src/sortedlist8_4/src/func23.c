#include "sortedlist8_4.h" 
sortedlist_t* func23(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist51;
   if (pCounter > 0) {
      sortedlist51 = vars->data[--pCounter];
      sortedlist51->refC++;
      DEBUG_COPY(sortedlist51->id);
   } else {
      sortedlist51 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist51->refC = 1;
      sortedlist51->id = 51;
      sortedlist51->n = 0;
      sortedlist51->root = NULL;
      DEBUG_NEW(sortedlist51->id);
   }
   return sortedlist51;
}

