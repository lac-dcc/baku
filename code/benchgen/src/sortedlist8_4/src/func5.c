#include "sortedlist8_4.h" 
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist37;
   if (pCounter > 0) {
      sortedlist37 = vars->data[--pCounter];
      sortedlist37->refC++;
      DEBUG_COPY(sortedlist37->id);
   } else {
      sortedlist37 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist37->refC = 1;
      sortedlist37->id = 37;
      sortedlist37->n = 0;
      sortedlist37->root = NULL;
      DEBUG_NEW(sortedlist37->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/2 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist37;
      sortedlist_t* sortedlist38 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist38->id);
      free(params0.data);
      sortedlist38->refC--;
      if(sortedlist38->refC == 0){
           cell_t* cell27 = sortedlist38->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist38);
           DEBUG_FREE(sortedlist38->id);
      }
   }
   return sortedlist37;
}

