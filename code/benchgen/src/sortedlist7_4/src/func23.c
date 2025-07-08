#include "sortedlist7_4.h" 
sortedlist_t* func23(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist44;
   if (pCounter > 0) {
      sortedlist44 = vars->data[--pCounter];
      sortedlist44->refC++;
      DEBUG_COPY(sortedlist44->id);
   } else {
      sortedlist44 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist44->refC = 1;
      sortedlist44->id = 44;
      sortedlist44->n = 0;
      sortedlist44->root = NULL;
      DEBUG_NEW(sortedlist44->id);
   }
   return sortedlist44;
}

