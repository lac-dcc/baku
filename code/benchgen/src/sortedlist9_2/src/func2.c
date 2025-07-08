#include "sortedlist9_2.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist33 = func3(&params0, loopsFactor);
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
      sortedlist_t* sortedlist35 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell43 = sortedlist35->root;
           cell_t* tmp43  = NULL;
           while(cell43 != NULL) {
               tmp43 = cell43->next;
               free(cell43);
               cell43 = tmp43;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
   sortedlist_t* sortedlist65;
   if (pCounter > 0) {
      sortedlist65 = vars->data[--pCounter];
      sortedlist65->refC++;
      DEBUG_COPY(sortedlist65->id);
   } else {
      sortedlist65 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist65->refC = 1;
      sortedlist65->id = 65;
      sortedlist65->n = 0;
      sortedlist65->root = NULL;
      DEBUG_NEW(sortedlist65->id);
   }
   return sortedlist65;
}

