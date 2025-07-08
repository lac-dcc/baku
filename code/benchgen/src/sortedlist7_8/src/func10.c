#include "sortedlist7_8.h" 
sortedlist_t* func10(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist25 = func11(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist25->id);
      free(params0.data);
      sortedlist25->refC--;
      if(sortedlist25->refC == 0){
           cell_t* cell14 = sortedlist25->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist25);
           DEBUG_FREE(sortedlist25->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist35 = func12(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell15 = sortedlist35->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
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
   return sortedlist37;
}

