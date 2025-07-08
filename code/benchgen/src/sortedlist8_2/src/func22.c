#include "sortedlist8_2.h" 
sortedlist_t* func22(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/4 + 1;
   for(; loop7 < loopLimit7; loop7++) {
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
      sortedlist50->refC--;
      if(sortedlist50->refC == 0){
           cell_t* cell25 = sortedlist50->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist50);
           DEBUG_FREE(sortedlist50->id);
      }
   }
   sortedlist_t* sortedlist51;
   if (pCounter > 0) {
      sortedlist51 = vars->data[--pCounter];
      sortedlist51->refC++;
      DEBUG_COPY(sortedlist51->id);
   } else {
      sortedlist51 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist51->refC = 1;
      sortedlist51->id = 51;
      sortedlist51->n = 0;
      sortedlist51->root = NULL;
      DEBUG_NEW(sortedlist51->id);
   }
   return sortedlist51;
}

