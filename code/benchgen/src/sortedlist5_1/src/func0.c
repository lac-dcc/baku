#include "sortedlist5_1.h" 
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
           cell_t* cell4 = sortedlist1->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist11;
   if (pCounter > 0) {
      sortedlist11 = vars->data[--pCounter];
      sortedlist11->refC++;
      DEBUG_COPY(sortedlist11->id);
   } else {
      sortedlist11 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist11->refC = 1;
      sortedlist11->id = 11;
      sortedlist11->n = 0;
      sortedlist11->root = NULL;
      DEBUG_NEW(sortedlist11->id);
   }
   return sortedlist11;
}

