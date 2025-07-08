#include "sortedlist6_1.h" 
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
           cell_t* cell5 = sortedlist1->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist13;
   if (pCounter > 0) {
      sortedlist13 = vars->data[--pCounter];
      sortedlist13->refC++;
      DEBUG_COPY(sortedlist13->id);
   } else {
      sortedlist13 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist13->refC = 1;
      sortedlist13->id = 13;
      sortedlist13->n = 0;
      sortedlist13->root = NULL;
      DEBUG_NEW(sortedlist13->id);
   }
   return sortedlist13;
}

