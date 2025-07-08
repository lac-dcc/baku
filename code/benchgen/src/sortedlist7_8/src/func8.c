#include "sortedlist7_8.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t* sortedlist23;
      if (pCounter > 0) {
         sortedlist23 = vars->data[--pCounter];
         sortedlist23->refC++;
         DEBUG_COPY(sortedlist23->id);
      } else {
         sortedlist23 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist23->refC = 1;
         sortedlist23->id = 23;
         sortedlist23->n = 0;
         sortedlist23->root = NULL;
         DEBUG_NEW(sortedlist23->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist23;
      sortedlist_t* sortedlist24 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist24->id);
      free(params0.data);
      sortedlist24->refC--;
      if(sortedlist24->refC == 0){
           cell_t* cell16 = sortedlist24->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist24);
           DEBUG_FREE(sortedlist24->id);
      }
      sortedlist23->refC--;
      if(sortedlist23->refC == 0){
           cell_t* cell17 = sortedlist23->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist23);
           DEBUG_FREE(sortedlist23->id);
      }
   }
   sortedlist_t* sortedlist38;
   if (pCounter > 0) {
      sortedlist38 = vars->data[--pCounter];
      sortedlist38->refC++;
      DEBUG_COPY(sortedlist38->id);
   } else {
      sortedlist38 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist38->refC = 1;
      sortedlist38->id = 38;
      sortedlist38->n = 0;
      sortedlist38->root = NULL;
      DEBUG_NEW(sortedlist38->id);
   }
   return sortedlist38;
}

