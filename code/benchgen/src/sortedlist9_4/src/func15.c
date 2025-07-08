#include "sortedlist9_4.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist48;
   if (pCounter > 0) {
      sortedlist48 = vars->data[--pCounter];
      sortedlist48->refC++;
      DEBUG_COPY(sortedlist48->id);
   } else {
      sortedlist48 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist48->refC = 1;
      sortedlist48->id = 48;
      sortedlist48->n = 0;
      sortedlist48->root = NULL;
      DEBUG_NEW(sortedlist48->id);
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/4 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist48;
      sortedlist_t* sortedlist49 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist49->id);
      free(params0.data);
      sortedlist49->refC--;
      if(sortedlist49->refC == 0){
           cell_t* cell26 = sortedlist49->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist49);
           DEBUG_FREE(sortedlist49->id);
      }
   }
   return sortedlist48;
}

