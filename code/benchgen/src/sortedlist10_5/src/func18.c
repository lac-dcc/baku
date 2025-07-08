#include "sortedlist10_5.h" 
sortedlist_t* func18(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist23 = func19(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist23->id);
      free(params0.data);
      sortedlist23->refC--;
      if(sortedlist23->refC == 0){
           cell_t* cell13 = sortedlist23->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist23);
           DEBUG_FREE(sortedlist23->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist25 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist25->id);
      free(params0.data);
      sortedlist25->refC--;
      if(sortedlist25->refC == 0){
           cell_t* cell14 = sortedlist25->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist25);
           DEBUG_FREE(sortedlist25->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist27 = func21(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(sortedlist27->id);
   free(params0.data);
   return sortedlist27;
}

