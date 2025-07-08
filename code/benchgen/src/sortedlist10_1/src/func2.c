#include "sortedlist10_1.h" 
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
           cell_t* cell7 = sortedlist4->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
      }
   }
   sortedlist_t* sortedlist20;
   if (pCounter > 0) {
      sortedlist20 = vars->data[--pCounter];
      sortedlist20->refC++;
      DEBUG_COPY(sortedlist20->id);
   } else {
      sortedlist20 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist20->refC = 1;
      sortedlist20->id = 20;
      sortedlist20->n = 0;
      sortedlist20->root = NULL;
      DEBUG_NEW(sortedlist20->id);
   }
   return sortedlist20;
}

