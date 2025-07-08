#include "sortedlist7_4.h" 
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist30;
   if (pCounter > 0) {
      sortedlist30 = vars->data[--pCounter];
      sortedlist30->refC++;
      DEBUG_COPY(sortedlist30->id);
   } else {
      sortedlist30 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist30->refC = 1;
      sortedlist30->id = 30;
      sortedlist30->n = 0;
      sortedlist30->root = NULL;
      DEBUG_NEW(sortedlist30->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/2 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist30;
      sortedlist_t* sortedlist31 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist31->id);
      free(params0.data);
      sortedlist31->refC--;
      if(sortedlist31->refC == 0){
           cell_t* cell23 = sortedlist31->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist31);
           DEBUG_FREE(sortedlist31->id);
      }
   }
   return sortedlist30;
}

