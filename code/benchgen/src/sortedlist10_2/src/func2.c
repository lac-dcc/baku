#include "sortedlist10_2.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist39 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist39->id);
      free(params0.data);
      sortedlist39->refC--;
      if(sortedlist39->refC == 0){
           cell_t* cell26 = sortedlist39->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist39);
           DEBUG_FREE(sortedlist39->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist41 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist41->id);
      free(params0.data);
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell48 = sortedlist41->root;
           cell_t* tmp48  = NULL;
           while(cell48 != NULL) {
               tmp48 = cell48->next;
               free(cell48);
               cell48 = tmp48;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
   }
   sortedlist_t* sortedlist72;
   if (pCounter > 0) {
      sortedlist72 = vars->data[--pCounter];
      sortedlist72->refC++;
      DEBUG_COPY(sortedlist72->id);
   } else {
      sortedlist72 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist72->refC = 1;
      sortedlist72->id = 72;
      sortedlist72->n = 0;
      sortedlist72->root = NULL;
      DEBUG_NEW(sortedlist72->id);
   }
   return sortedlist72;
}

