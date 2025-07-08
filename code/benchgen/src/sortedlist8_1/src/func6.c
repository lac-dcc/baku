#include "sortedlist8_1.h" 
sortedlist_t* func6(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist10 = func7(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist10->id);
      free(params0.data);
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell1 = sortedlist10->root;
           cell_t* tmp1  = NULL;
           while(cell1 != NULL) {
               tmp1 = cell1->next;
               free(cell1);
               cell1 = tmp1;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
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

