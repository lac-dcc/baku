#include "sortedlist9_2.h" 
sortedlist_t* func14(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist43 = func15(&params0, loopsFactor);
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
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist45 = func16(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist45->id);
      free(params0.data);
      sortedlist45->refC--;
      if(sortedlist45->refC == 0){
           cell_t* cell35 = sortedlist45->root;
           cell_t* tmp35  = NULL;
           while(cell35 != NULL) {
               tmp35 = cell35->next;
               free(cell35);
               cell35 = tmp35;
           }
           free(sortedlist45);
           DEBUG_FREE(sortedlist45->id);
      }
   }
   sortedlist_t* sortedlist61;
   if (pCounter > 0) {
      sortedlist61 = vars->data[--pCounter];
      sortedlist61->refC++;
      DEBUG_COPY(sortedlist61->id);
   } else {
      sortedlist61 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist61->refC = 1;
      sortedlist61->id = 61;
      sortedlist61->n = 0;
      sortedlist61->root = NULL;
      DEBUG_NEW(sortedlist61->id);
   }
   return sortedlist61;
}

