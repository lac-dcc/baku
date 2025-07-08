#include "sortedlist10_8.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t* sortedlist35;
      if (pCounter > 0) {
         sortedlist35 = vars->data[--pCounter];
         sortedlist35->refC++;
         DEBUG_COPY(sortedlist35->id);
      } else {
         sortedlist35 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist35->refC = 1;
         sortedlist35->id = 35;
         sortedlist35->n = 0;
         sortedlist35->root = NULL;
         DEBUG_NEW(sortedlist35->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist35;
      sortedlist_t* sortedlist36 = func18(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist36->id);
      free(params0.data);
      sortedlist36->refC--;
      if(sortedlist36->refC == 0){
           cell_t* cell20 = sortedlist36->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist36);
           DEBUG_FREE(sortedlist36->id);
      }
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell21 = sortedlist35->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
   sortedlist_t* sortedlist50;
   if (pCounter > 0) {
      sortedlist50 = vars->data[--pCounter];
      sortedlist50->refC++;
      DEBUG_COPY(sortedlist50->id);
   } else {
      sortedlist50 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist50->refC = 1;
      sortedlist50->id = 50;
      sortedlist50->n = 0;
      sortedlist50->root = NULL;
      DEBUG_NEW(sortedlist50->id);
   }
   return sortedlist50;
}

