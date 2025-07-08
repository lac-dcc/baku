#include "sortedlist10_1.h" 
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/9 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist11;
      sortedlist_t* sortedlist12 = func8(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist12->id);
      free(params0.data);
      sortedlist12->refC--;
      if(sortedlist12->refC == 0){
           cell_t* cell2 = sortedlist12->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist12);
           DEBUG_FREE(sortedlist12->id);
      }
   }
   return sortedlist11;
}

