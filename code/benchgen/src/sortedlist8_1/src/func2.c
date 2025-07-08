#include "sortedlist8_1.h" 
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
           cell_t* cell5 = sortedlist4->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
      }
   }
   sortedlist_t* sortedlist16;
   if (pCounter > 0) {
      sortedlist16 = vars->data[--pCounter];
      sortedlist16->refC++;
      DEBUG_COPY(sortedlist16->id);
   } else {
      sortedlist16 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist16->refC = 1;
      sortedlist16->id = 16;
      sortedlist16->n = 0;
      sortedlist16->root = NULL;
      DEBUG_NEW(sortedlist16->id);
   }
   return sortedlist16;
}

