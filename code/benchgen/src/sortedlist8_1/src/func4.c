#include "sortedlist8_1.h" 
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
           cell_t* cell3 = sortedlist7->root;
           cell_t* tmp3  = NULL;
           while(cell3 != NULL) {
               tmp3 = cell3->next;
               free(cell3);
               cell3 = tmp3;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
   }
   sortedlist_t* sortedlist15;
   if (pCounter > 0) {
      sortedlist15 = vars->data[--pCounter];
      sortedlist15->refC++;
      DEBUG_COPY(sortedlist15->id);
   } else {
      sortedlist15 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist15->refC = 1;
      sortedlist15->id = 15;
      sortedlist15->n = 0;
      sortedlist15->root = NULL;
      DEBUG_NEW(sortedlist15->id);
   }
   return sortedlist15;
}

