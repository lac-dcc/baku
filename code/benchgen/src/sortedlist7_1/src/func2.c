#include "sortedlist7_1.h" 
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
           cell_t* cell4 = sortedlist4->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
      }
   }
   sortedlist_t* sortedlist14;
   if (pCounter > 0) {
      sortedlist14 = vars->data[--pCounter];
      sortedlist14->refC++;
      DEBUG_COPY(sortedlist14->id);
   } else {
      sortedlist14 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist14->refC = 1;
      sortedlist14->id = 14;
      sortedlist14->n = 0;
      sortedlist14->root = NULL;
      DEBUG_NEW(sortedlist14->id);
   }
   return sortedlist14;
}

