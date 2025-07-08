#include "sortedlist8_4.h" 
sortedlist_t* func21(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t* sortedlist19;
      if (pCounter > 0) {
         sortedlist19 = vars->data[--pCounter];
         sortedlist19->refC++;
         DEBUG_COPY(sortedlist19->id);
      } else {
         sortedlist19 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist19->refC = 1;
         sortedlist19->id = 19;
         sortedlist19->n = 0;
         sortedlist19->root = NULL;
         DEBUG_NEW(sortedlist19->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist19;
      sortedlist_t* sortedlist20 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist20->id);
      free(params0.data);
      sortedlist20->refC--;
      if(sortedlist20->refC == 0){
           cell_t* cell6 = sortedlist20->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
      sortedlist19->refC--;
      if(sortedlist19->refC == 0){
           cell_t* cell7 = sortedlist19->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist19);
           DEBUG_FREE(sortedlist19->id);
      }
   }
   sortedlist_t* sortedlist27;
   if (pCounter > 0) {
      sortedlist27 = vars->data[--pCounter];
      sortedlist27->refC++;
      DEBUG_COPY(sortedlist27->id);
   } else {
      sortedlist27 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist27->refC = 1;
      sortedlist27->id = 27;
      sortedlist27->n = 0;
      sortedlist27->root = NULL;
      DEBUG_NEW(sortedlist27->id);
   }
   return sortedlist27;
}

