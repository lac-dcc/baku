#include "sortedlist8_4.h" 
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist55;
   if (pCounter > 0) {
      sortedlist55 = vars->data[--pCounter];
      sortedlist55->refC++;
      DEBUG_COPY(sortedlist55->id);
   } else {
      sortedlist55 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist55->refC = 1;
      sortedlist55->id = 55;
      sortedlist55->n = 0;
      sortedlist55->root = NULL;
      DEBUG_NEW(sortedlist55->id);
   }
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/6 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist55;
      sortedlist_t* sortedlist56 = func30(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist56->id);
      free(params0.data);
      sortedlist56->refC--;
      if(sortedlist56->refC == 0){
           cell_t* cell21 = sortedlist56->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist56);
           DEBUG_FREE(sortedlist56->id);
      }
   }
   return sortedlist55;
}

