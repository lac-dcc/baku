#include "sortedlist10_4.h" 
sortedlist_t* func9(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist8;
   if (pCounter > 0) {
      sortedlist8 = vars->data[--pCounter];
      sortedlist8->refC++;
      DEBUG_COPY(sortedlist8->id);
   } else {
      sortedlist8 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist8->refC = 1;
      sortedlist8->id = 8;
      sortedlist8->n = 0;
      sortedlist8->root = NULL;
      DEBUG_NEW(sortedlist8->id);
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist8;
      sortedlist_t* sortedlist9 = func11(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist9->id);
      free(params0.data);
      sortedlist9->refC--;
      if(sortedlist9->refC == 0){
           cell_t* cell13 = sortedlist9->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist9);
           DEBUG_FREE(sortedlist9->id);
      }
   }
   return sortedlist8;
}

