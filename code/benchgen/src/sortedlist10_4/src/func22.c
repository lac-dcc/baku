#include "sortedlist10_4.h" 
sortedlist_t* func22(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist53 = func23(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist53->id);
      free(params0.data);
      sortedlist53->refC--;
      if(sortedlist53->refC == 0){
           cell_t* cell21 = sortedlist53->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist53);
           DEBUG_FREE(sortedlist53->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist55 = func24(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist55->id);
      free(params0.data);
      sortedlist55->refC--;
      if(sortedlist55->refC == 0){
           cell_t* cell22 = sortedlist55->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist55);
           DEBUG_FREE(sortedlist55->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist57 = func25(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist57->id);
   free(params0.data);
   return sortedlist57;
}

