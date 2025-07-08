#include "sortedlist5_1.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist7 = func5(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist7->id);
      free(params0.data);
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell0 = sortedlist7->root;
           cell_t* tmp0  = NULL;
           while(cell0 != NULL) {
               tmp0 = cell0->next;
               free(cell0);
               cell0 = tmp0;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
   }
   sortedlist_t* sortedlist9;
   if (pCounter > 0) {
      sortedlist9 = vars->data[--pCounter];
      sortedlist9->refC++;
      DEBUG_COPY(sortedlist9->id);
   } else {
      sortedlist9 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist9->refC = 1;
      sortedlist9->id = 9;
      sortedlist9->n = 0;
      sortedlist9->root = NULL;
      DEBUG_NEW(sortedlist9->id);
   }
   return sortedlist9;
}

