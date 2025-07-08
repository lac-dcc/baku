#include "sortedlist8_4.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
   for(; loop8 < loopLimit8; loop8++) {
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
      sortedlist_t* sortedlist40 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist40->id);
      free(params0.data);
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell25 = sortedlist40->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
      sortedlist39->refC--;
      if(sortedlist39->refC == 0){
           cell_t* cell26 = sortedlist39->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist39);
           DEBUG_FREE(sortedlist39->id);
      }
   }
   sortedlist_t* sortedlist59;
   if (pCounter > 0) {
      sortedlist59 = vars->data[--pCounter];
      sortedlist59->refC++;
      DEBUG_COPY(sortedlist59->id);
   } else {
      sortedlist59 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist59->refC = 1;
      sortedlist59->id = 59;
      sortedlist59->n = 0;
      sortedlist59->root = NULL;
      DEBUG_NEW(sortedlist59->id);
   }
   return sortedlist59;
}

