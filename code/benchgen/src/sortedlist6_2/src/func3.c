#include "sortedlist6_2.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist26;
   if (pCounter > 0) {
      sortedlist26 = vars->data[--pCounter];
      sortedlist26->refC++;
      DEBUG_COPY(sortedlist26->id);
   } else {
      sortedlist26 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist26->refC = 1;
      sortedlist26->id = 26;
      sortedlist26->n = 0;
      sortedlist26->root = NULL;
      DEBUG_NEW(sortedlist26->id);
   }
   return sortedlist26;
}

