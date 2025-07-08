#include "sortedlist6_1.h" 
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
           cell_t* cell3 = sortedlist4->root;
           cell_t* tmp3  = NULL;
           while(cell3 != NULL) {
               tmp3 = cell3->next;
               free(cell3);
               cell3 = tmp3;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
      }
   }
   sortedlist_t* sortedlist12;
   if (pCounter > 0) {
      sortedlist12 = vars->data[--pCounter];
      sortedlist12->refC++;
      DEBUG_COPY(sortedlist12->id);
   } else {
      sortedlist12 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist12->refC = 1;
      sortedlist12->id = 12;
      sortedlist12->n = 0;
      sortedlist12->root = NULL;
      DEBUG_NEW(sortedlist12->id);
   }
   return sortedlist12;
}

