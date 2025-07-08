#include "sortedlist10_2.h" 
sortedlist_t* func28(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/5 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      sortedlist_t* sortedlist62;
      if (pCounter > 0) {
         sortedlist62 = vars->data[--pCounter];
         sortedlist62->refC++;
         DEBUG_COPY(sortedlist62->id);
      } else {
         sortedlist62 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist62->refC = 1;
         sortedlist62->id = 62;
         sortedlist62->n = 0;
         sortedlist62->root = NULL;
         DEBUG_NEW(sortedlist62->id);
      }
      sortedlist62->refC--;
      if(sortedlist62->refC == 0){
           cell_t* cell31 = sortedlist62->root;
           cell_t* tmp31  = NULL;
           while(cell31 != NULL) {
               tmp31 = cell31->next;
               free(cell31);
               cell31 = tmp31;
           }
           free(sortedlist62);
           DEBUG_FREE(sortedlist62->id);
      }
   }
   sortedlist_t* sortedlist63;
   if (pCounter > 0) {
      sortedlist63 = vars->data[--pCounter];
      sortedlist63->refC++;
      DEBUG_COPY(sortedlist63->id);
   } else {
      sortedlist63 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist63->refC = 1;
      sortedlist63->id = 63;
      sortedlist63->n = 0;
      sortedlist63->root = NULL;
      DEBUG_NEW(sortedlist63->id);
   }
   return sortedlist63;
}

