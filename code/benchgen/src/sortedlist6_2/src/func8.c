#include "sortedlist6_2.h" 
sortedlist_t* func8(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist30 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist30->id);
      free(params0.data);
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell17 = sortedlist30->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist32 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist32->id);
      free(params0.data);
      sortedlist32->refC--;
      if(sortedlist32->refC == 0){
           cell_t* cell24 = sortedlist32->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist32);
           DEBUG_FREE(sortedlist32->id);
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

