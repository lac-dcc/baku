#include "sortedlist9_4.h" 
sortedlist_t* func30(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/7 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      sortedlist_t* sortedlist59;
      if (pCounter > 0) {
         sortedlist59 = vars->data[--pCounter];
         sortedlist59->refC++;
         DEBUG_COPY(sortedlist59->id);
      } else {
         sortedlist59 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist59->refC = 1;
         sortedlist59->id = 59;
         sortedlist59->n = 0;
         sortedlist59->root = NULL;
         DEBUG_NEW(sortedlist59->id);
      }
      sortedlist59->refC--;
      if(sortedlist59->refC == 0){
           cell_t* cell22 = sortedlist59->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist59);
           DEBUG_FREE(sortedlist59->id);
      }
   }
   sortedlist_t* sortedlist60;
   if (pCounter > 0) {
      sortedlist60 = vars->data[--pCounter];
      sortedlist60->refC++;
      DEBUG_COPY(sortedlist60->id);
   } else {
      sortedlist60 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist60->refC = 1;
      sortedlist60->id = 60;
      sortedlist60->n = 0;
      sortedlist60->root = NULL;
      DEBUG_NEW(sortedlist60->id);
   }
   return sortedlist60;
}

