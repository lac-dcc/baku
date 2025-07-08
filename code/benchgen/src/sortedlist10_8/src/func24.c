#include "sortedlist10_8.h" 
sortedlist_t* func24(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist39;
      sortedlist_t* sortedlist40 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist40->id);
      free(params0.data);
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell16 = sortedlist40->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
      sortedlist39->refC--;
      if(sortedlist39->refC == 0){
           cell_t* cell17 = sortedlist39->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist39);
           DEBUG_FREE(sortedlist39->id);
      }
   }
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
   return sortedlist46;
}

