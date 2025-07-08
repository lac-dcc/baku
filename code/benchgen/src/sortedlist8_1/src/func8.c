#include "sortedlist8_1.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist13;
   if (pCounter > 0) {
      sortedlist13 = vars->data[--pCounter];
      sortedlist13->refC++;
      DEBUG_COPY(sortedlist13->id);
   } else {
      sortedlist13 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist13->refC = 1;
      sortedlist13->id = 13;
      sortedlist13->n = 0;
      sortedlist13->root = NULL;
      DEBUG_NEW(sortedlist13->id);
   }
   return sortedlist13;
}

