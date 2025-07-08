#include "sortedlist10_4.h" 
sortedlist_t* func31(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      sortedlist_t* sortedlist28;
      if (pCounter > 0) {
         sortedlist28 = vars->data[--pCounter];
         sortedlist28->refC++;
         DEBUG_COPY(sortedlist28->id);
      } else {
         sortedlist28 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist28->refC = 1;
         sortedlist28->id = 28;
         sortedlist28->n = 0;
         sortedlist28->root = NULL;
         DEBUG_NEW(sortedlist28->id);
      }
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell6 = sortedlist28->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
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

