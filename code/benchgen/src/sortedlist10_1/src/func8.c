#include "sortedlist10_1.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/10 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist13 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist13->id);
      free(params0.data);
      sortedlist13->refC--;
      if(sortedlist13->refC == 0){
           cell_t* cell1 = sortedlist13->root;
           cell_t* tmp1  = NULL;
           while(cell1 != NULL) {
               tmp1 = cell1->next;
               free(cell1);
               cell1 = tmp1;
           }
           free(sortedlist13);
           DEBUG_FREE(sortedlist13->id);
      }
   }
   sortedlist_t* sortedlist17;
   if (pCounter > 0) {
      sortedlist17 = vars->data[--pCounter];
      sortedlist17->refC++;
      DEBUG_COPY(sortedlist17->id);
   } else {
      sortedlist17 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist17->refC = 1;
      sortedlist17->id = 17;
      sortedlist17->n = 0;
      sortedlist17->root = NULL;
      DEBUG_NEW(sortedlist17->id);
   }
   return sortedlist17;
}

