#include "sortedlist5_2.h" 
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
           cell_t* cell12 = sortedlist19->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist19);
           DEBUG_FREE(sortedlist19->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist21 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist21->id);
      free(params0.data);
      sortedlist21->refC--;
      if(sortedlist21->refC == 0){
           cell_t* cell23 = sortedlist21->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist21);
           DEBUG_FREE(sortedlist21->id);
      }
   }
   sortedlist_t* sortedlist37;
   if (pCounter > 0) {
      sortedlist37 = vars->data[--pCounter];
      sortedlist37->refC++;
      DEBUG_COPY(sortedlist37->id);
   } else {
      sortedlist37 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist37->refC = 1;
      sortedlist37->id = 37;
      sortedlist37->n = 0;
      sortedlist37->root = NULL;
      DEBUG_NEW(sortedlist37->id);
   }
   return sortedlist37;
}

