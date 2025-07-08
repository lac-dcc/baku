#include "sortedlist7_4.h" 
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist39;
   if (pCounter > 0) {
      sortedlist39 = vars->data[--pCounter];
      sortedlist39->refC++;
      DEBUG_COPY(sortedlist39->id);
   } else {
      sortedlist39 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist39->refC = 1;
      sortedlist39->id = 39;
      sortedlist39->n = 0;
      sortedlist39->root = NULL;
      DEBUG_NEW(sortedlist39->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/4 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist39;
      sortedlist_t* sortedlist40 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist40->id);
      free(params0.data);
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell20 = sortedlist40->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
   }
   return sortedlist39;
}

