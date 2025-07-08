#include "sortedlist7_4.h" 
sortedlist_t* func22(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist43 = func23(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist43->id);
      free(params0.data);
      sortedlist43->refC--;
      if(sortedlist43->refC == 0){
           cell_t* cell16 = sortedlist43->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist43);
           DEBUG_FREE(sortedlist43->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist45 = func24(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist45->id);
      free(params0.data);
      sortedlist45->refC--;
      if(sortedlist45->refC == 0){
           cell_t* cell17 = sortedlist45->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist45);
           DEBUG_FREE(sortedlist45->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist47 = func25(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist47->id);
   free(params0.data);
   return sortedlist47;
}

