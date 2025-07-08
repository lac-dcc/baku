#include "sortedlist6_4.h" 
sortedlist_t* func12(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist33 = func13(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist33->id);
      free(params0.data);
      sortedlist33->refC--;
      if(sortedlist33->refC == 0){
           cell_t* cell13 = sortedlist33->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist33);
           DEBUG_FREE(sortedlist33->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist35 = func14(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell14 = sortedlist35->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist37 = func15(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist37->id);
   free(params0.data);
   return sortedlist37;
}

