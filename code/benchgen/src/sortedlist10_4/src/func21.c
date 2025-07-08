#include "sortedlist10_4.h" 
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
           cell_t* cell8 = sortedlist20->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
      sortedlist19->refC--;
      if(sortedlist19->refC == 0){
           cell_t* cell9 = sortedlist19->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist19);
           DEBUG_FREE(sortedlist19->id);
      }
   }
   sortedlist_t* sortedlist30;
   if (pCounter > 0) {
      sortedlist30 = vars->data[--pCounter];
      sortedlist30->refC++;
      DEBUG_COPY(sortedlist30->id);
   } else {
      sortedlist30 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist30->refC = 1;
      sortedlist30->id = 30;
      sortedlist30->n = 0;
      sortedlist30->root = NULL;
      DEBUG_NEW(sortedlist30->id);
   }
   return sortedlist30;
}

