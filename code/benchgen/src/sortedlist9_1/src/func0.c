#include "sortedlist9_1.h" 
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
           cell_t* cell8 = sortedlist1->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist19;
   if (pCounter > 0) {
      sortedlist19 = vars->data[--pCounter];
      sortedlist19->refC++;
      DEBUG_COPY(sortedlist19->id);
   } else {
      sortedlist19 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist19->refC = 1;
      sortedlist19->id = 19;
      sortedlist19->n = 0;
      sortedlist19->root = NULL;
      DEBUG_NEW(sortedlist19->id);
   }
   return sortedlist19;
}

