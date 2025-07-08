#include "sortedlist6_2.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/3 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t* sortedlist38;
      if (pCounter > 0) {
         sortedlist38 = vars->data[--pCounter];
         sortedlist38->refC++;
         DEBUG_COPY(sortedlist38->id);
      } else {
         sortedlist38 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist38->refC = 1;
         sortedlist38->id = 38;
         sortedlist38->n = 0;
         sortedlist38->root = NULL;
         DEBUG_NEW(sortedlist38->id);
      }
      sortedlist38->refC--;
      if(sortedlist38->refC == 0){
           cell_t* cell19 = sortedlist38->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist38);
           DEBUG_FREE(sortedlist38->id);
      }
   }
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
   return sortedlist39;
}

