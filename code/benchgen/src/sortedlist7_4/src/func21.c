#include "sortedlist7_4.h" 
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
      sortedlist19->refC--;
      if(sortedlist19->refC == 0){
           cell_t* cell4 = sortedlist19->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist19);
           DEBUG_FREE(sortedlist19->id);
      }
   }
   sortedlist_t* sortedlist20;
   if (pCounter > 0) {
      sortedlist20 = vars->data[--pCounter];
      sortedlist20->refC++;
      DEBUG_COPY(sortedlist20->id);
   } else {
      sortedlist20 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist20->refC = 1;
      sortedlist20->id = 20;
      sortedlist20->n = 0;
      sortedlist20->root = NULL;
      DEBUG_NEW(sortedlist20->id);
   }
   return sortedlist20;
}

