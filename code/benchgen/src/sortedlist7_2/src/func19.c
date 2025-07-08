#include "sortedlist7_2.h" 
sortedlist_t* func19(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t* sortedlist16;
      if (pCounter > 0) {
         sortedlist16 = vars->data[--pCounter];
         sortedlist16->refC++;
         DEBUG_COPY(sortedlist16->id);
      } else {
         sortedlist16 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist16->refC = 1;
         sortedlist16->id = 16;
         sortedlist16->n = 0;
         sortedlist16->root = NULL;
         DEBUG_NEW(sortedlist16->id);
      }
      sortedlist16->refC--;
      if(sortedlist16->refC == 0){
           cell_t* cell3 = sortedlist16->root;
           cell_t* tmp3  = NULL;
           while(cell3 != NULL) {
               tmp3 = cell3->next;
               free(cell3);
               cell3 = tmp3;
           }
           free(sortedlist16);
           DEBUG_FREE(sortedlist16->id);
      }
   }
   sortedlist_t* sortedlist17;
   if (pCounter > 0) {
      sortedlist17 = vars->data[--pCounter];
      sortedlist17->refC++;
      DEBUG_COPY(sortedlist17->id);
   } else {
      sortedlist17 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist17->refC = 1;
      sortedlist17->id = 17;
      sortedlist17->n = 0;
      sortedlist17->root = NULL;
      DEBUG_NEW(sortedlist17->id);
   }
   return sortedlist17;
}

