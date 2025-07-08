#include "sortedlist8_8.h" 
sortedlist_t* func18(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist35 = func19(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell13 = sortedlist35->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist38 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist38->id);
      free(params0.data);
      sortedlist38->refC--;
      if(sortedlist38->refC == 0){
           cell_t* cell14 = sortedlist38->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist38);
           DEBUG_FREE(sortedlist38->id);
      }
   }
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
   return sortedlist40;
}

