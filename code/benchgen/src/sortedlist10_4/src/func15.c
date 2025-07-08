#include "sortedlist10_4.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist49;
   if (pCounter > 0) {
      sortedlist49 = vars->data[--pCounter];
      sortedlist49->refC++;
      DEBUG_COPY(sortedlist49->id);
   } else {
      sortedlist49 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist49->refC = 1;
      sortedlist49->id = 49;
      sortedlist49->n = 0;
      sortedlist49->root = NULL;
      DEBUG_NEW(sortedlist49->id);
   }
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/4 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist49;
      sortedlist_t* sortedlist50 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist50->id);
      free(params0.data);
      sortedlist50->refC--;
      if(sortedlist50->refC == 0){
           cell_t* cell30 = sortedlist50->root;
           cell_t* tmp30  = NULL;
           while(cell30 != NULL) {
               tmp30 = cell30->next;
               free(cell30);
               cell30 = tmp30;
           }
           free(sortedlist50);
           DEBUG_FREE(sortedlist50->id);
      }
   }
   return sortedlist49;
}

