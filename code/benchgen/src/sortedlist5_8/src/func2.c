#include "sortedlist5_8.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist19 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist19->id);
      free(params0.data);
      sortedlist19->refC--;
      if(sortedlist19->refC == 0){
           cell_t* cell13 = sortedlist19->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist19);
           DEBUG_FREE(sortedlist19->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist30 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist30->id);
      free(params0.data);
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell14 = sortedlist30->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
      }
   }
   sortedlist_t* sortedlist32;
   if (pCounter > 0) {
      sortedlist32 = vars->data[--pCounter];
      sortedlist32->refC++;
      DEBUG_COPY(sortedlist32->id);
   } else {
      sortedlist32 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist32->refC = 1;
      sortedlist32->id = 32;
      sortedlist32->n = 0;
      sortedlist32->root = NULL;
      DEBUG_NEW(sortedlist32->id);
   }
   return sortedlist32;
}

