#include "sortedlist10_4.h" 
sortedlist_t* func11(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t* sortedlist10;
      if (pCounter > 0) {
         sortedlist10 = vars->data[--pCounter];
         sortedlist10->refC++;
         DEBUG_COPY(sortedlist10->id);
      } else {
         sortedlist10 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist10->refC = 1;
         sortedlist10->id = 10;
         sortedlist10->n = 0;
         sortedlist10->root = NULL;
         DEBUG_NEW(sortedlist10->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist10;
      sortedlist_t* sortedlist11 = func16(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist11->id);
      free(params0.data);
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell11 = sortedlist11->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell12 = sortedlist10->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   sortedlist_t* sortedlist31;
   if (pCounter > 0) {
      sortedlist31 = vars->data[--pCounter];
      sortedlist31->refC++;
      DEBUG_COPY(sortedlist31->id);
   } else {
      sortedlist31 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist31->refC = 1;
      sortedlist31->id = 31;
      sortedlist31->n = 0;
      sortedlist31->root = NULL;
      DEBUG_NEW(sortedlist31->id);
   }
   return sortedlist31;
}

