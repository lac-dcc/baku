#include "sortedlist5_2.h" 
sortedlist_t* func8(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist24 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist24->id);
      free(params0.data);
      sortedlist24->refC--;
      if(sortedlist24->refC == 0){
           cell_t* cell13 = sortedlist24->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist24);
           DEBUG_FREE(sortedlist24->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist26 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist26->id);
      free(params0.data);
      sortedlist26->refC--;
      if(sortedlist26->refC == 0){
           cell_t* cell19 = sortedlist26->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist26);
           DEBUG_FREE(sortedlist26->id);
      }
   }
   sortedlist_t* sortedlist35;
   if (pCounter > 0) {
      sortedlist35 = vars->data[--pCounter];
      sortedlist35->refC++;
      DEBUG_COPY(sortedlist35->id);
   } else {
      sortedlist35 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist35->refC = 1;
      sortedlist35->id = 35;
      sortedlist35->n = 0;
      sortedlist35->root = NULL;
      DEBUG_NEW(sortedlist35->id);
   }
   return sortedlist35;
}

