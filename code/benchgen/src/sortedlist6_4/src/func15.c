#include "sortedlist6_4.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/4 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist38;
      sortedlist_t* sortedlist39 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist39->id);
      free(params0.data);
      sortedlist39->refC--;
      if(sortedlist39->refC == 0){
           cell_t* cell16 = sortedlist39->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist39);
           DEBUG_FREE(sortedlist39->id);
      }
   }
   return sortedlist38;
}

