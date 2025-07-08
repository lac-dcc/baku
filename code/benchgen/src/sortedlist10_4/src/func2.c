#include "sortedlist10_4.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist35 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell17 = sortedlist35->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist37 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist37->id);
      free(params0.data);
      sortedlist37->refC--;
      if(sortedlist37->refC == 0){
           cell_t* cell18 = sortedlist37->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist37);
           DEBUG_FREE(sortedlist37->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist39 = func5(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist39->id);
   free(params0.data);
   return sortedlist39;
}

