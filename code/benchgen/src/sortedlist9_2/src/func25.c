#include "sortedlist9_2.h" 
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist21;
      if (pCounter > 0) {
         sortedlist21 = vars->data[--pCounter];
         sortedlist21->refC++;
         DEBUG_COPY(sortedlist21->id);
      } else {
         sortedlist21 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist21->refC = 1;
         sortedlist21->id = 21;
         sortedlist21->n = 0;
         sortedlist21->root = NULL;
         DEBUG_NEW(sortedlist21->id);
      }
      sortedlist21->refC--;
      if(sortedlist21->refC == 0){
           cell_t* cell4 = sortedlist21->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist21);
           DEBUG_FREE(sortedlist21->id);
      }
   }
   sortedlist_t* sortedlist22;
   if (pCounter > 0) {
      sortedlist22 = vars->data[--pCounter];
      sortedlist22->refC++;
      DEBUG_COPY(sortedlist22->id);
   } else {
      sortedlist22 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist22->refC = 1;
      sortedlist22->id = 22;
      sortedlist22->n = 0;
      sortedlist22->root = NULL;
      DEBUG_NEW(sortedlist22->id);
   }
   return sortedlist22;
}

