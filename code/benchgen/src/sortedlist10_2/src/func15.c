#include "sortedlist10_2.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist50;
   if (pCounter > 0) {
      sortedlist50 = vars->data[--pCounter];
      sortedlist50->refC++;
      DEBUG_COPY(sortedlist50->id);
   } else {
      sortedlist50 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist50->refC = 1;
      sortedlist50->id = 50;
      sortedlist50->n = 0;
      sortedlist50->root = NULL;
      DEBUG_NEW(sortedlist50->id);
   }
   return sortedlist50;
}

