#include "sortedlist5_4.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist36;
   if (pCounter > 0) {
      sortedlist36 = vars->data[--pCounter];
      sortedlist36->refC++;
      DEBUG_COPY(sortedlist36->id);
   } else {
      sortedlist36 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist36->refC = 1;
      sortedlist36->id = 36;
      sortedlist36->n = 0;
      sortedlist36->root = NULL;
      DEBUG_NEW(sortedlist36->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/4 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist36;
      sortedlist_t* sortedlist37 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist37->id);
      free(params0.data);
      sortedlist37->refC--;
      if(sortedlist37->refC == 0){
           cell_t* cell14 = sortedlist37->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist37);
           DEBUG_FREE(sortedlist37->id);
      }
   }
   return sortedlist36;
}

