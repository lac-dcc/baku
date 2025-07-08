#include "sortedlist8_4.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist46;
   if (pCounter > 0) {
      sortedlist46 = vars->data[--pCounter];
      sortedlist46->refC++;
      DEBUG_COPY(sortedlist46->id);
   } else {
      sortedlist46 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist46->refC = 1;
      sortedlist46->id = 46;
      sortedlist46->n = 0;
      sortedlist46->root = NULL;
      DEBUG_NEW(sortedlist46->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/4 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist46;
      sortedlist_t* sortedlist47 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist47->id);
      free(params0.data);
      sortedlist47->refC--;
      if(sortedlist47->refC == 0){
           cell_t* cell24 = sortedlist47->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist47);
           DEBUG_FREE(sortedlist47->id);
      }
   }
   return sortedlist46;
}

