#include "sortedlist8_4.h" 
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/5 + 1;
   for(; loop10 < loopLimit10; loop10++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist48;
      sortedlist_t* sortedlist49 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist49->id);
      free(params0.data);
      sortedlist49->refC--;
      if(sortedlist49->refC == 0){
           cell_t* cell22 = sortedlist49->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist49);
           DEBUG_FREE(sortedlist49->id);
      }
      sortedlist48->refC--;
      if(sortedlist48->refC == 0){
           cell_t* cell23 = sortedlist48->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist48);
           DEBUG_FREE(sortedlist48->id);
      }
   }
   sortedlist_t* sortedlist58;
   if (pCounter > 0) {
      sortedlist58 = vars->data[--pCounter];
      sortedlist58->refC++;
      DEBUG_COPY(sortedlist58->id);
   } else {
      sortedlist58 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist58->refC = 1;
      sortedlist58->id = 58;
      sortedlist58->n = 0;
      sortedlist58->root = NULL;
      DEBUG_NEW(sortedlist58->id);
   }
   return sortedlist58;
}

