#include "sortedlist10_1.h" 
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
           cell_t* cell9 = sortedlist1->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist21;
   if (pCounter > 0) {
      sortedlist21 = vars->data[--pCounter];
      sortedlist21->refC++;
      DEBUG_COPY(sortedlist21->id);
   } else {
      sortedlist21 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist21->refC = 1;
      sortedlist21->id = 21;
      sortedlist21->n = 0;
      sortedlist21->root = NULL;
      DEBUG_NEW(sortedlist21->id);
   }
   return sortedlist21;
}

