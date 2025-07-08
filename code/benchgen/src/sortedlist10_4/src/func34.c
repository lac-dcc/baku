#include "sortedlist10_4.h" 
sortedlist_t* func34(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist65;
   if (pCounter > 0) {
      sortedlist65 = vars->data[--pCounter];
      sortedlist65->refC++;
      DEBUG_COPY(sortedlist65->id);
   } else {
      sortedlist65 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist65->refC = 1;
      sortedlist65->id = 65;
      sortedlist65->n = 0;
      sortedlist65->root = NULL;
      DEBUG_NEW(sortedlist65->id);
   }
   return sortedlist65;
}

