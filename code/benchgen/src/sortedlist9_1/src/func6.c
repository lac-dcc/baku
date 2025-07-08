#include "sortedlist9_1.h" 
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
           cell_t* cell2 = sortedlist10->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   sortedlist_t* sortedlist16;
   if (pCounter > 0) {
      sortedlist16 = vars->data[--pCounter];
      sortedlist16->refC++;
      DEBUG_COPY(sortedlist16->id);
   } else {
      sortedlist16 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist16->refC = 1;
      sortedlist16->id = 16;
      sortedlist16->n = 0;
      sortedlist16->root = NULL;
      DEBUG_NEW(sortedlist16->id);
   }
   return sortedlist16;
}

