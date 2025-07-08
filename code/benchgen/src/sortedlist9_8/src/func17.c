#include "sortedlist9_8.h" 
sortedlist_t* func17(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      sortedlist_t* sortedlist9;
      if (pCounter > 0) {
         sortedlist9 = vars->data[--pCounter];
         sortedlist9->refC++;
         DEBUG_COPY(sortedlist9->id);
      } else {
         sortedlist9 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist9->refC = 1;
         sortedlist9->id = 9;
         sortedlist9->n = 0;
         sortedlist9->root = NULL;
         DEBUG_NEW(sortedlist9->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist9;
      sortedlist_t* sortedlist10 = func21(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist10->id);
      free(params0.data);
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell2 = sortedlist10->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
      sortedlist9->refC--;
      if(sortedlist9->refC == 0){
           cell_t* cell3 = sortedlist9->root;
           cell_t* tmp3  = NULL;
           while(cell3 != NULL) {
               tmp3 = cell3->next;
               free(cell3);
               cell3 = tmp3;
           }
           free(sortedlist9);
           DEBUG_FREE(sortedlist9->id);
      }
   }
   sortedlist_t* sortedlist17;
   if (pCounter > 0) {
      sortedlist17 = vars->data[--pCounter];
      sortedlist17->refC++;
      DEBUG_COPY(sortedlist17->id);
   } else {
      sortedlist17 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist17->refC = 1;
      sortedlist17->id = 17;
      sortedlist17->n = 0;
      sortedlist17->root = NULL;
      DEBUG_NEW(sortedlist17->id);
   }
   return sortedlist17;
}

