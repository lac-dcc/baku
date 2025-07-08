#include "sortedlist9_1.h" 
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
           cell_t* cell6 = sortedlist4->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
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

