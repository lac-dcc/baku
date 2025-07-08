#include "sortedlist8_2.h" 
sortedlist_t* func8(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist37 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist37->id);
      free(params0.data);
      sortedlist37->refC--;
      if(sortedlist37->refC == 0){
           cell_t* cell22 = sortedlist37->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist37);
           DEBUG_FREE(sortedlist37->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist39 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist39->id);
      free(params0.data);
      sortedlist39->refC--;
      if(sortedlist39->refC == 0){
           cell_t* cell34 = sortedlist39->root;
           cell_t* tmp34  = NULL;
           while(cell34 != NULL) {
               tmp34 = cell34->next;
               free(cell34);
               cell34 = tmp34;
           }
           free(sortedlist39);
           DEBUG_FREE(sortedlist39->id);
      }
   }
   sortedlist_t* sortedlist56;
   if (pCounter > 0) {
      sortedlist56 = vars->data[--pCounter];
      sortedlist56->refC++;
      DEBUG_COPY(sortedlist56->id);
   } else {
      sortedlist56 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist56->refC = 1;
      sortedlist56->id = 56;
      sortedlist56->n = 0;
      sortedlist56->root = NULL;
      DEBUG_NEW(sortedlist56->id);
   }
   return sortedlist56;
}

