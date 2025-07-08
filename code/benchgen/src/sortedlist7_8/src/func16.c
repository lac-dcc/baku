#include "sortedlist7_8.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist27;
      if (pCounter > 0) {
         sortedlist27 = vars->data[--pCounter];
         sortedlist27->refC++;
         DEBUG_COPY(sortedlist27->id);
      } else {
         sortedlist27 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist27->refC = 1;
         sortedlist27->id = 27;
         sortedlist27->n = 0;
         sortedlist27->root = NULL;
         DEBUG_NEW(sortedlist27->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist27;
      sortedlist_t* sortedlist28 = func18(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist28->id);
      free(params0.data);
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell12 = sortedlist28->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
      sortedlist27->refC--;
      if(sortedlist27->refC == 0){
           cell_t* cell13 = sortedlist27->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist27);
           DEBUG_FREE(sortedlist27->id);
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

