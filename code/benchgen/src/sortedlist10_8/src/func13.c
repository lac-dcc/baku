#include "sortedlist10_8.h" 
sortedlist_t* func13(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist7 = func14(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist7->id);
      free(params0.data);
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell5 = sortedlist7->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist19 = func15(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist19->id);
      free(params0.data);
      sortedlist19->refC--;
      if(sortedlist19->refC == 0){
           cell_t* cell6 = sortedlist19->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist19);
           DEBUG_FREE(sortedlist19->id);
      }
   }
   sortedlist_t* sortedlist21;
   if (pCounter > 0) {
      sortedlist21 = vars->data[--pCounter];
      sortedlist21->refC++;
      DEBUG_COPY(sortedlist21->id);
   } else {
      sortedlist21 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist21->refC = 1;
      sortedlist21->id = 21;
      sortedlist21->n = 0;
      sortedlist21->root = NULL;
      DEBUG_NEW(sortedlist21->id);
   }
   return sortedlist21;
}

