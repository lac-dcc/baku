#include "sortedlist6_4.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist25;
   if (pCounter > 0) {
      sortedlist25 = vars->data[--pCounter];
      sortedlist25->refC++;
      DEBUG_COPY(sortedlist25->id);
   } else {
      sortedlist25 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist25->refC = 1;
      sortedlist25->id = 25;
      sortedlist25->n = 0;
      sortedlist25->root = NULL;
      DEBUG_NEW(sortedlist25->id);
   }
   return sortedlist25;
}

