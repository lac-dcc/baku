#include "sortedlist10_8.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist29 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist29->id);
      free(params0.data);
      sortedlist29->refC--;
      if(sortedlist29->refC == 0){
           cell_t* cell26 = sortedlist29->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist29);
           DEBUG_FREE(sortedlist29->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist55 = func4(&params0, loopsFactor);
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

