#include "sortedlist5_2.h" 
sortedlist_t* func13(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      sortedlist_t* sortedlist11;
      if (pCounter > 0) {
         sortedlist11 = vars->data[--pCounter];
         sortedlist11->refC++;
         DEBUG_COPY(sortedlist11->id);
      } else {
         sortedlist11 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist11->refC = 1;
         sortedlist11->id = 11;
         sortedlist11->n = 0;
         sortedlist11->root = NULL;
         DEBUG_NEW(sortedlist11->id);
      }
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell2 = sortedlist11->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
   }
   sortedlist_t* sortedlist12;
   if (pCounter > 0) {
      sortedlist12 = vars->data[--pCounter];
      sortedlist12->refC++;
      DEBUG_COPY(sortedlist12->id);
   } else {
      sortedlist12 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist12->refC = 1;
      sortedlist12->id = 12;
      sortedlist12->n = 0;
      sortedlist12->root = NULL;
      DEBUG_NEW(sortedlist12->id);
   }
   return sortedlist12;
}

