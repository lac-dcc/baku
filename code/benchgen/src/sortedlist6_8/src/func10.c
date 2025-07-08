#include "sortedlist6_8.h" 
sortedlist_t* func10(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist24 = func11(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist24->id);
      free(params0.data);
      sortedlist24->refC--;
      if(sortedlist24->refC == 0){
           cell_t* cell10 = sortedlist24->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist24);
           DEBUG_FREE(sortedlist24->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist28 = func12(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist28->id);
      free(params0.data);
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell11 = sortedlist28->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
   }
   sortedlist_t* sortedlist30;
   if (pCounter > 0) {
      sortedlist30 = vars->data[--pCounter];
      sortedlist30->refC++;
      DEBUG_COPY(sortedlist30->id);
   } else {
      sortedlist30 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist30->refC = 1;
      sortedlist30->id = 30;
      sortedlist30->n = 0;
      sortedlist30->root = NULL;
      DEBUG_NEW(sortedlist30->id);
   }
   return sortedlist30;
}

