#include "sortedlist9_1.h" 
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
   sortedlist_t* sortedlist15;
   if (pCounter > 0) {
      sortedlist15 = vars->data[--pCounter];
      sortedlist15->refC++;
      DEBUG_COPY(sortedlist15->id);
   } else {
      sortedlist15 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist15->refC = 1;
      sortedlist15->id = 15;
      sortedlist15->n = 0;
      sortedlist15->root = NULL;
      DEBUG_NEW(sortedlist15->id);
   }
   return sortedlist15;
}

