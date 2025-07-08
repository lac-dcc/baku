#include "sortedlist9_4.h" 
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
           cell_t* cell7 = sortedlist20->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
      sortedlist19->refC--;
      if(sortedlist19->refC == 0){
           cell_t* cell8 = sortedlist19->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist19);
           DEBUG_FREE(sortedlist19->id);
      }
   }
   sortedlist_t* sortedlist29;
   if (pCounter > 0) {
      sortedlist29 = vars->data[--pCounter];
      sortedlist29->refC++;
      DEBUG_COPY(sortedlist29->id);
   } else {
      sortedlist29 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist29->refC = 1;
      sortedlist29->id = 29;
      sortedlist29->n = 0;
      sortedlist29->root = NULL;
      DEBUG_NEW(sortedlist29->id);
   }
   return sortedlist29;
}

