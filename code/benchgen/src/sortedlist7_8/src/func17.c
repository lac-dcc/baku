#include "sortedlist7_8.h" 
sortedlist_t* func17(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      sortedlist_t* sortedlist9;
      if (pCounter > 0) {
         sortedlist9 = vars->data[--pCounter];
         sortedlist9->refC++;
         DEBUG_COPY(sortedlist9->id);
      } else {
         sortedlist9 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist9->refC = 1;
         sortedlist9->id = 9;
         sortedlist9->n = 0;
         sortedlist9->root = NULL;
         DEBUG_NEW(sortedlist9->id);
      }
      sortedlist9->refC--;
      if(sortedlist9->refC == 0){
           cell_t* cell0 = sortedlist9->root;
           cell_t* tmp0  = NULL;
           while(cell0 != NULL) {
               tmp0 = cell0->next;
               free(cell0);
               cell0 = tmp0;
           }
           free(sortedlist9);
           DEBUG_FREE(sortedlist9->id);
      }
   }
   sortedlist_t* sortedlist10;
   if (pCounter > 0) {
      sortedlist10 = vars->data[--pCounter];
      sortedlist10->refC++;
      DEBUG_COPY(sortedlist10->id);
   } else {
      sortedlist10 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist10->refC = 1;
      sortedlist10->id = 10;
      sortedlist10->n = 0;
      sortedlist10->root = NULL;
      DEBUG_NEW(sortedlist10->id);
   }
   return sortedlist10;
}

