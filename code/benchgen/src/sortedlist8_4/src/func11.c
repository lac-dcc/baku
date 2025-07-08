#include "sortedlist8_4.h" 
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
           cell_t* cell9 = sortedlist11->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell10 = sortedlist10->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   sortedlist_t* sortedlist28;
   if (pCounter > 0) {
      sortedlist28 = vars->data[--pCounter];
      sortedlist28->refC++;
      DEBUG_COPY(sortedlist28->id);
   } else {
      sortedlist28 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist28->refC = 1;
      sortedlist28->id = 28;
      sortedlist28->n = 0;
      sortedlist28->root = NULL;
      DEBUG_NEW(sortedlist28->id);
   }
   return sortedlist28;
}

