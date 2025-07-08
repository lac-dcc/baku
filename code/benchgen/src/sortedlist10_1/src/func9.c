#include "sortedlist10_1.h" 
sortedlist_t* func9(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/11 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist14;
      sortedlist_t* sortedlist15 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist15->id);
      free(params0.data);
      sortedlist15->refC--;
      if(sortedlist15->refC == 0){
           cell_t* cell0 = sortedlist15->root;
           cell_t* tmp0  = NULL;
           while(cell0 != NULL) {
               tmp0 = cell0->next;
               free(cell0);
               cell0 = tmp0;
           }
           free(sortedlist15);
           DEBUG_FREE(sortedlist15->id);
      }
   }
   return sortedlist14;
}

