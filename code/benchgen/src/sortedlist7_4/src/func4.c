#include "sortedlist7_4.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist28;
   if (pCounter > 0) {
      sortedlist28 = vars->data[--pCounter];
      sortedlist28->refC++;
      DEBUG_COPY(sortedlist28->id);
   } else {
      sortedlist28 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist28->refC = 1;
      sortedlist28->id = 28;
      sortedlist28->n = 0;
      sortedlist28->root = NULL;
      DEBUG_NEW(sortedlist28->id);
   }
   return sortedlist28;
}

