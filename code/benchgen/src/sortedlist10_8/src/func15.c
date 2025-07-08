#include "sortedlist10_8.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist20;
   if (pCounter > 0) {
      sortedlist20 = vars->data[--pCounter];
      sortedlist20->refC++;
      DEBUG_COPY(sortedlist20->id);
   } else {
      sortedlist20 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist20->refC = 1;
      sortedlist20->id = 20;
      sortedlist20->n = 0;
      sortedlist20->root = NULL;
      DEBUG_NEW(sortedlist20->id);
   }
   return sortedlist20;
}

