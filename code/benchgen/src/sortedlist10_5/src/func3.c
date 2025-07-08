#include "sortedlist10_5.h" 
sortedlist_t* func3(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist51 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist51->id);
      free(params0.data);
      sortedlist51->refC--;
      if(sortedlist51->refC == 0){
           cell_t* cell29 = sortedlist51->root;
           cell_t* tmp29  = NULL;
           while(cell29 != NULL) {
               tmp29 = cell29->next;
               free(cell29);
               cell29 = tmp29;
           }
           free(sortedlist51);
           DEBUG_FREE(sortedlist51->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist53 = func5(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist53->id);
      free(params0.data);
      sortedlist53->refC--;
      if(sortedlist53->refC == 0){
           cell_t* cell30 = sortedlist53->root;
           cell_t* tmp30  = NULL;
           while(cell30 != NULL) {
               tmp30 = cell30->next;
               free(cell30);
               cell30 = tmp30;
           }
           free(sortedlist53);
           DEBUG_FREE(sortedlist53->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist55 = func6(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(sortedlist55->id);
   free(params0.data);
   return sortedlist55;
}

