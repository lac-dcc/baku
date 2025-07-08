#include "sortedlist6_4.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist24 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist24->id);
      free(params0.data);
      sortedlist24->refC--;
      if(sortedlist24->refC == 0){
           cell_t* cell11 = sortedlist24->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist24);
           DEBUG_FREE(sortedlist24->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist26 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist26->id);
      free(params0.data);
      sortedlist26->refC--;
      if(sortedlist26->refC == 0){
           cell_t* cell12 = sortedlist26->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist26);
           DEBUG_FREE(sortedlist26->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist28 = func5(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist28->id);
   free(params0.data);
   return sortedlist28;
}

