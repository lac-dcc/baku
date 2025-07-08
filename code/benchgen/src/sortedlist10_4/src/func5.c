#include "sortedlist10_4.h" 
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist40;
   if (pCounter > 0) {
      sortedlist40 = vars->data[--pCounter];
      sortedlist40->refC++;
      DEBUG_COPY(sortedlist40->id);
   } else {
      sortedlist40 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist40->refC = 1;
      sortedlist40->id = 40;
      sortedlist40->n = 0;
      sortedlist40->root = NULL;
      DEBUG_NEW(sortedlist40->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/2 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist40;
      sortedlist_t* sortedlist41 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist41->id);
      free(params0.data);
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell33 = sortedlist41->root;
           cell_t* tmp33  = NULL;
           while(cell33 != NULL) {
               tmp33 = cell33->next;
               free(cell33);
               cell33 = tmp33;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
   }
   return sortedlist40;
}

