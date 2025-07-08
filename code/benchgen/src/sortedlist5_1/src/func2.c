#include "sortedlist5_1.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist4 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist4->id);
      free(params0.data);
      sortedlist4->refC--;
      if(sortedlist4->refC == 0){
           cell_t* cell2 = sortedlist4->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
      }
   }
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
   return sortedlist10;
}

