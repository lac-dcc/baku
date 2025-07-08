#include "sortedlist9_4.h" 
sortedlist_t* func12(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist43 = func13(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist43->id);
      free(params0.data);
      sortedlist43->refC--;
      if(sortedlist43->refC == 0){
           cell_t* cell18 = sortedlist43->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist43);
           DEBUG_FREE(sortedlist43->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist45 = func14(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist45->id);
      free(params0.data);
      sortedlist45->refC--;
      if(sortedlist45->refC == 0){
           cell_t* cell19 = sortedlist45->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist45);
           DEBUG_FREE(sortedlist45->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist47 = func15(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist47->id);
   free(params0.data);
   return sortedlist47;
}

