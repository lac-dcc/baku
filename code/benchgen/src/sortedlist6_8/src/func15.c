#include "sortedlist6_8.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist11;
   if (pCounter > 0) {
      sortedlist11 = vars->data[--pCounter];
      sortedlist11->refC++;
      DEBUG_COPY(sortedlist11->id);
   } else {
      sortedlist11 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist11->refC = 1;
      sortedlist11->id = 11;
      sortedlist11->n = 0;
      sortedlist11->root = NULL;
      DEBUG_NEW(sortedlist11->id);
   }
   return sortedlist11;
}

