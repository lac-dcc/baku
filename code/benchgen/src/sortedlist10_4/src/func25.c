#include "sortedlist10_4.h" 
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist58;
   if (pCounter > 0) {
      sortedlist58 = vars->data[--pCounter];
      sortedlist58->refC++;
      DEBUG_COPY(sortedlist58->id);
   } else {
      sortedlist58 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist58->refC = 1;
      sortedlist58->id = 58;
      sortedlist58->n = 0;
      sortedlist58->root = NULL;
      DEBUG_NEW(sortedlist58->id);
   }
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/6 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist58;
      sortedlist_t* sortedlist59 = func30(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist59->id);
      free(params0.data);
      sortedlist59->refC--;
      if(sortedlist59->refC == 0){
           cell_t* cell27 = sortedlist59->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist59);
           DEBUG_FREE(sortedlist59->id);
      }
   }
   return sortedlist58;
}

