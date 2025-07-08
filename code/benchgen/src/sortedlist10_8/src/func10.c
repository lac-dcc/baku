#include "sortedlist10_8.h" 
sortedlist_t* func10(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist33 = func11(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist33->id);
      free(params0.data);
      sortedlist33->refC--;
      if(sortedlist33->refC == 0){
           cell_t* cell22 = sortedlist33->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist33);
           DEBUG_FREE(sortedlist33->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist51 = func12(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist51->id);
      free(params0.data);
      sortedlist51->refC--;
      if(sortedlist51->refC == 0){
           cell_t* cell23 = sortedlist51->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist51);
           DEBUG_FREE(sortedlist51->id);
      }
   }
   sortedlist_t* sortedlist53;
   if (pCounter > 0) {
      sortedlist53 = vars->data[--pCounter];
      sortedlist53->refC++;
      DEBUG_COPY(sortedlist53->id);
   } else {
      sortedlist53 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist53->refC = 1;
      sortedlist53->id = 53;
      sortedlist53->n = 0;
      sortedlist53->root = NULL;
      DEBUG_NEW(sortedlist53->id);
   }
   return sortedlist53;
}

