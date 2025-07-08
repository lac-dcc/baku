#include "sortedlist8_1.h" 
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist1 = func1(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist1->id);
      free(params0.data);
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell7 = sortedlist1->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
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

