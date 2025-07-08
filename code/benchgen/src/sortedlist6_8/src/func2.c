#include "sortedlist6_8.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist20 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist20->id);
      free(params0.data);
      sortedlist20->refC--;
      if(sortedlist20->refC == 0){
           cell_t* cell14 = sortedlist20->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist32 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist32->id);
      free(params0.data);
      sortedlist32->refC--;
      if(sortedlist32->refC == 0){
           cell_t* cell15 = sortedlist32->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist32);
           DEBUG_FREE(sortedlist32->id);
      }
   }
   sortedlist_t* sortedlist34;
   if (pCounter > 0) {
      sortedlist34 = vars->data[--pCounter];
      sortedlist34->refC++;
      DEBUG_COPY(sortedlist34->id);
   } else {
      sortedlist34 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist34->refC = 1;
      sortedlist34->id = 34;
      sortedlist34->n = 0;
      sortedlist34->root = NULL;
      DEBUG_NEW(sortedlist34->id);
   }
   return sortedlist34;
}

