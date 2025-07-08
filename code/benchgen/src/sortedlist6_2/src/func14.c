#include "sortedlist6_2.h" 
sortedlist_t* func14(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist35 = func15(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell18 = sortedlist35->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist37 = func16(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist37->id);
      free(params0.data);
      sortedlist37->refC--;
      if(sortedlist37->refC == 0){
           cell_t* cell20 = sortedlist37->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist37);
           DEBUG_FREE(sortedlist37->id);
      }
   }
   sortedlist_t* sortedlist40;
   if (pCounter > 0) {
      sortedlist40 = vars->data[--pCounter];
      sortedlist40->refC++;
      DEBUG_COPY(sortedlist40->id);
   } else {
      sortedlist40 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist40->refC = 1;
      sortedlist40->id = 40;
      sortedlist40->n = 0;
      sortedlist40->root = NULL;
      DEBUG_NEW(sortedlist40->id);
   }
   return sortedlist40;
}

