#include "sortedlist9_5.h" 
sortedlist_t* func3(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist46 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist46->id);
      free(params0.data);
      sortedlist46->refC--;
      if(sortedlist46->refC == 0){
           cell_t* cell26 = sortedlist46->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist46);
           DEBUG_FREE(sortedlist46->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist48 = func5(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist48->id);
      free(params0.data);
      sortedlist48->refC--;
      if(sortedlist48->refC == 0){
           cell_t* cell27 = sortedlist48->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist48);
           DEBUG_FREE(sortedlist48->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist50 = func6(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(sortedlist50->id);
   free(params0.data);
   return sortedlist50;
}

