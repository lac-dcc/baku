#include "sortedlist9_8.h" 
sortedlist_t* func18(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist36 = func19(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist36->id);
      free(params0.data);
      sortedlist36->refC--;
      if(sortedlist36->refC == 0){
           cell_t* cell14 = sortedlist36->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist36);
           DEBUG_FREE(sortedlist36->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist40 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist40->id);
      free(params0.data);
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell15 = sortedlist40->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
   }
   sortedlist_t* sortedlist42;
   if (pCounter > 0) {
      sortedlist42 = vars->data[--pCounter];
      sortedlist42->refC++;
      DEBUG_COPY(sortedlist42->id);
   } else {
      sortedlist42 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist42->refC = 1;
      sortedlist42->id = 42;
      sortedlist42->n = 0;
      sortedlist42->root = NULL;
      DEBUG_NEW(sortedlist42->id);
   }
   return sortedlist42;
}

