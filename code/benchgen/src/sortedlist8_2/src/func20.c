#include "sortedlist8_2.h" 
sortedlist_t* func20(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist47 = func21(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist47->id);
      free(params0.data);
      sortedlist47->refC--;
      if(sortedlist47->refC == 0){
           cell_t* cell24 = sortedlist47->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist47);
           DEBUG_FREE(sortedlist47->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist49 = func22(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist49->id);
      free(params0.data);
      sortedlist49->refC--;
      if(sortedlist49->refC == 0){
           cell_t* cell26 = sortedlist49->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist49);
           DEBUG_FREE(sortedlist49->id);
      }
   }
   sortedlist_t* sortedlist52;
   if (pCounter > 0) {
      sortedlist52 = vars->data[--pCounter];
      sortedlist52->refC++;
      DEBUG_COPY(sortedlist52->id);
   } else {
      sortedlist52 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist52->refC = 1;
      sortedlist52->id = 52;
      sortedlist52->n = 0;
      sortedlist52->root = NULL;
      DEBUG_NEW(sortedlist52->id);
   }
   return sortedlist52;
}

