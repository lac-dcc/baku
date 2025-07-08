#include "sortedlist6_4.h" 
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/5 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      sortedlist_t* sortedlist40;
      if (pCounter > 0) {
         sortedlist40 = vars->data[--pCounter];
         sortedlist40->refC++;
         DEBUG_COPY(sortedlist40->id);
      } else {
         sortedlist40 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist40->refC = 1;
         sortedlist40->id = 40;
         sortedlist40->n = 0;
         sortedlist40->root = NULL;
         DEBUG_NEW(sortedlist40->id);
      }
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell15 = sortedlist40->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
   }
   sortedlist_t* sortedlist41;
   if (pCounter > 0) {
      sortedlist41 = vars->data[--pCounter];
      sortedlist41->refC++;
      DEBUG_COPY(sortedlist41->id);
   } else {
      sortedlist41 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist41->refC = 1;
      sortedlist41->id = 41;
      sortedlist41->n = 0;
      sortedlist41->root = NULL;
      DEBUG_NEW(sortedlist41->id);
   }
   return sortedlist41;
}

