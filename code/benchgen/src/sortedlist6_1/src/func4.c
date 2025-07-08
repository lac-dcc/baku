#include "sortedlist6_1.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist7 = func5(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist7->id);
      free(params0.data);
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell1 = sortedlist7->root;
           cell_t* tmp1  = NULL;
           while(cell1 != NULL) {
               tmp1 = cell1->next;
               free(cell1);
               cell1 = tmp1;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
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

