#include "sortedlist9_4.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist34 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist34->id);
      free(params0.data);
      sortedlist34->refC--;
      if(sortedlist34->refC == 0){
           cell_t* cell16 = sortedlist34->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist34);
           DEBUG_FREE(sortedlist34->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist36 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist36->id);
      free(params0.data);
      sortedlist36->refC--;
      if(sortedlist36->refC == 0){
           cell_t* cell17 = sortedlist36->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist36);
           DEBUG_FREE(sortedlist36->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist38 = func5(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist38->id);
   free(params0.data);
   return sortedlist38;
}

