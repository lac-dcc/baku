#include "sortedlist6_8.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/2 + 1;
   for(; loop3 < loopLimit3; loop3++) {
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
      sortedlist26->refC--;
      if(sortedlist26->refC == 0){
           cell_t* cell9 = sortedlist26->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist26);
           DEBUG_FREE(sortedlist26->id);
      }
   }
   sortedlist_t* sortedlist27;
   if (pCounter > 0) {
      sortedlist27 = vars->data[--pCounter];
      sortedlist27->refC++;
      DEBUG_COPY(sortedlist27->id);
   } else {
      sortedlist27 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist27->refC = 1;
      sortedlist27->id = 27;
      sortedlist27->n = 0;
      sortedlist27->root = NULL;
      DEBUG_NEW(sortedlist27->id);
   }
   return sortedlist27;
}

