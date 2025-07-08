#include "sortedlist7_2.h" 
sortedlist_t* func20(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist41 = func21(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist41->id);
      free(params0.data);
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell20 = sortedlist41->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist43 = func22(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist43->id);
      free(params0.data);
      sortedlist43->refC--;
      if(sortedlist43->refC == 0){
           cell_t* cell21 = sortedlist43->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist43);
           DEBUG_FREE(sortedlist43->id);
      }
   }
   sortedlist_t* sortedlist45;
   if (pCounter > 0) {
      sortedlist45 = vars->data[--pCounter];
      sortedlist45->refC++;
      DEBUG_COPY(sortedlist45->id);
   } else {
      sortedlist45 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist45->refC = 1;
      sortedlist45->id = 45;
      sortedlist45->n = 0;
      sortedlist45->root = NULL;
      DEBUG_NEW(sortedlist45->id);
   }
   return sortedlist45;
}

