#include "sortedlist10_8.h" 
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t* sortedlist13;
      if (pCounter > 0) {
         sortedlist13 = vars->data[--pCounter];
         sortedlist13->refC++;
         DEBUG_COPY(sortedlist13->id);
      } else {
         sortedlist13 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist13->refC = 1;
         sortedlist13->id = 13;
         sortedlist13->n = 0;
         sortedlist13->root = NULL;
         DEBUG_NEW(sortedlist13->id);
      }
      sortedlist13->refC--;
      if(sortedlist13->refC == 0){
           cell_t* cell0 = sortedlist13->root;
           cell_t* tmp0  = NULL;
           while(cell0 != NULL) {
               tmp0 = cell0->next;
               free(cell0);
               cell0 = tmp0;
           }
           free(sortedlist13);
           DEBUG_FREE(sortedlist13->id);
      }
   }
   sortedlist_t* sortedlist14;
   if (pCounter > 0) {
      sortedlist14 = vars->data[--pCounter];
      sortedlist14->refC++;
      DEBUG_COPY(sortedlist14->id);
   } else {
      sortedlist14 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist14->refC = 1;
      sortedlist14->id = 14;
      sortedlist14->n = 0;
      sortedlist14->root = NULL;
      DEBUG_NEW(sortedlist14->id);
   }
   return sortedlist14;
}

