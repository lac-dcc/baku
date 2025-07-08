#include "sortedlist10_1.h" 
sortedlist_t* func1(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist2;
   if (pCounter > 0) {
      sortedlist2 = vars->data[--pCounter];
      sortedlist2->refC++;
      DEBUG_COPY(sortedlist2->id);
   } else {
      sortedlist2 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist2->refC = 1;
      sortedlist2->id = 2;
      sortedlist2->n = 0;
      sortedlist2->root = NULL;
      DEBUG_NEW(sortedlist2->id);
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist2;
      sortedlist_t* sortedlist3 = func2(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist3->id);
      free(params0.data);
      sortedlist3->refC--;
      if(sortedlist3->refC == 0){
           cell_t* cell8 = sortedlist3->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist3);
           DEBUG_FREE(sortedlist3->id);
      }
   }
   return sortedlist2;
}

