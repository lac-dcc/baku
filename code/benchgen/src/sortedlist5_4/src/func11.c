#include "sortedlist5_4.h" 
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
           cell_t* cell4 = sortedlist11->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell5 = sortedlist10->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   sortedlist_t* sortedlist18;
   if (pCounter > 0) {
      sortedlist18 = vars->data[--pCounter];
      sortedlist18->refC++;
      DEBUG_COPY(sortedlist18->id);
   } else {
      sortedlist18 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist18->refC = 1;
      sortedlist18->id = 18;
      sortedlist18->n = 0;
      sortedlist18->root = NULL;
      DEBUG_NEW(sortedlist18->id);
   }
   return sortedlist18;
}

