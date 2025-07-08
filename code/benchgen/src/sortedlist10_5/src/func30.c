#include "sortedlist10_5.h" 
sortedlist_t* func30(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist43 = func31(&params0, loopsFactor);
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
      sortedlist_t* sortedlist45 = func32(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist45->id);
      free(params0.data);
      sortedlist45->refC--;
      if(sortedlist45->refC == 0){
           cell_t* cell25 = sortedlist45->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist45);
           DEBUG_FREE(sortedlist45->id);
      }
   }
   sortedlist_t* sortedlist47;
   if (pCounter > 0) {
      sortedlist47 = vars->data[--pCounter];
      sortedlist47->refC++;
      DEBUG_COPY(sortedlist47->id);
   } else {
      sortedlist47 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist47->refC = 1;
      sortedlist47->id = 47;
      sortedlist47->n = 0;
      sortedlist47->root = NULL;
      DEBUG_NEW(sortedlist47->id);
   }
   return sortedlist47;
}

