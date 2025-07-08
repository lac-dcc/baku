#include "sortedlist9_4.h" 
sortedlist_t* func29(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist26;
   if (pCounter > 0) {
      sortedlist26 = vars->data[--pCounter];
      sortedlist26->refC++;
      DEBUG_COPY(sortedlist26->id);
   } else {
      sortedlist26 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist26->refC = 1;
      sortedlist26->id = 26;
      sortedlist26->n = 0;
      sortedlist26->root = NULL;
      DEBUG_NEW(sortedlist26->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist26;
      sortedlist_t* sortedlist27 = func31(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist27->id);
      free(params0.data);
      sortedlist27->refC--;
      if(sortedlist27->refC == 0){
           cell_t* cell6 = sortedlist27->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist27);
           DEBUG_FREE(sortedlist27->id);
      }
   }
   return sortedlist26;
}

