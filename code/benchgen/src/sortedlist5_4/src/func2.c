#include "sortedlist5_4.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist22 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist22->id);
      free(params0.data);
      sortedlist22->refC--;
      if(sortedlist22->refC == 0){
           cell_t* cell10 = sortedlist22->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist22);
           DEBUG_FREE(sortedlist22->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist24 = func4(&params0, loopsFactor);
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
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist26 = func5(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist26->id);
   free(params0.data);
   return sortedlist26;
}

