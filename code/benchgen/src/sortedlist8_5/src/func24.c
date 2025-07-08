#include "sortedlist8_5.h" 
sortedlist_t* func24(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist33 = func25(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist33->id);
      free(params0.data);
      sortedlist33->refC--;
      if(sortedlist33->refC == 0){
           cell_t* cell18 = sortedlist33->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist33);
           DEBUG_FREE(sortedlist33->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist35 = func26(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell19 = sortedlist35->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
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

