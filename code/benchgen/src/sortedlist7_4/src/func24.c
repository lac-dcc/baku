#include "sortedlist7_4.h" 
sortedlist_t* func24(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist46;
   if (pCounter > 0) {
      sortedlist46 = vars->data[--pCounter];
      sortedlist46->refC++;
      DEBUG_COPY(sortedlist46->id);
   } else {
      sortedlist46 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist46->refC = 1;
      sortedlist46->id = 46;
      sortedlist46->n = 0;
      sortedlist46->root = NULL;
      DEBUG_NEW(sortedlist46->id);
   }
   return sortedlist46;
}

