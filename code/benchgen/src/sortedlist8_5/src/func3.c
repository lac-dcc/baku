#include "sortedlist8_5.h" 
sortedlist_t* func3(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist41 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist41->id);
      free(params0.data);
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell23 = sortedlist41->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist43 = func5(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist43->id);
      free(params0.data);
      sortedlist43->refC--;
      if(sortedlist43->refC == 0){
           cell_t* cell24 = sortedlist43->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist43);
           DEBUG_FREE(sortedlist43->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist45 = func6(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(sortedlist45->id);
   free(params0.data);
   return sortedlist45;
}

