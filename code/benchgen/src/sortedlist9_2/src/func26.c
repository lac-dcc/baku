#include "sortedlist9_2.h" 
sortedlist_t* func26(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist53 = func27(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist53->id);
      free(params0.data);
      sortedlist53->refC--;
      if(sortedlist53->refC == 0){
           cell_t* cell26 = sortedlist53->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist53);
           DEBUG_FREE(sortedlist53->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist55 = func28(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist55->id);
      free(params0.data);
      sortedlist55->refC--;
      if(sortedlist55->refC == 0){
           cell_t* cell27 = sortedlist55->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist55);
           DEBUG_FREE(sortedlist55->id);
      }
   }
   sortedlist_t* sortedlist57;
   if (pCounter > 0) {
      sortedlist57 = vars->data[--pCounter];
      sortedlist57->refC++;
      DEBUG_COPY(sortedlist57->id);
   } else {
      sortedlist57 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist57->refC = 1;
      sortedlist57->id = 57;
      sortedlist57->n = 0;
      sortedlist57->root = NULL;
      DEBUG_NEW(sortedlist57->id);
   }
   return sortedlist57;
}

