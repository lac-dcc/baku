#include "sortedlist9_8.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist34;
      if (pCounter > 0) {
         sortedlist34 = vars->data[--pCounter];
         sortedlist34->refC++;
         DEBUG_COPY(sortedlist34->id);
      } else {
         sortedlist34 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist34->refC = 1;
         sortedlist34->id = 34;
         sortedlist34->n = 0;
         sortedlist34->root = NULL;
         DEBUG_NEW(sortedlist34->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist34;
      sortedlist_t* sortedlist35 = func18(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell16 = sortedlist35->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
      sortedlist34->refC--;
      if(sortedlist34->refC == 0){
           cell_t* cell17 = sortedlist34->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist34);
           DEBUG_FREE(sortedlist34->id);
      }
   }
   sortedlist_t* sortedlist43;
   if (pCounter > 0) {
      sortedlist43 = vars->data[--pCounter];
      sortedlist43->refC++;
      DEBUG_COPY(sortedlist43->id);
   } else {
      sortedlist43 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist43->refC = 1;
      sortedlist43->id = 43;
      sortedlist43->n = 0;
      sortedlist43->root = NULL;
      DEBUG_NEW(sortedlist43->id);
   }
   return sortedlist43;
}

