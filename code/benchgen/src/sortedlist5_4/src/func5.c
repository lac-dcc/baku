#include "sortedlist5_4.h" 
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist27;
      sortedlist_t* sortedlist28 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist28->id);
      free(params0.data);
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell17 = sortedlist28->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
   }
   return sortedlist27;
}

