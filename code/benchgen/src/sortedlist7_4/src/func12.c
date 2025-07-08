#include "sortedlist7_4.h" 
sortedlist_t* func12(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist34 = func13(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist34->id);
      free(params0.data);
      sortedlist34->refC--;
      if(sortedlist34->refC == 0){
           cell_t* cell14 = sortedlist34->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist34);
           DEBUG_FREE(sortedlist34->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist36 = func14(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist36->id);
      free(params0.data);
      sortedlist36->refC--;
      if(sortedlist36->refC == 0){
           cell_t* cell15 = sortedlist36->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist36);
           DEBUG_FREE(sortedlist36->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist38 = func15(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist38->id);
   free(params0.data);
   return sortedlist38;
}

