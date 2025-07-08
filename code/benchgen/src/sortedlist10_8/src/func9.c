#include "sortedlist10_8.h" 
sortedlist_t* func9(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      sortedlist_t* sortedlist5;
      if (pCounter > 0) {
         sortedlist5 = vars->data[--pCounter];
         sortedlist5->refC++;
         DEBUG_COPY(sortedlist5->id);
      } else {
         sortedlist5 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist5->refC = 1;
         sortedlist5->id = 5;
         sortedlist5->n = 0;
         sortedlist5->root = NULL;
         DEBUG_NEW(sortedlist5->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist5;
      sortedlist_t* sortedlist6 = func13(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist6->id);
      free(params0.data);
      sortedlist6->refC--;
      if(sortedlist6->refC == 0){
           cell_t* cell7 = sortedlist6->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
      sortedlist5->refC--;
      if(sortedlist5->refC == 0){
           cell_t* cell8 = sortedlist5->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist5);
           DEBUG_FREE(sortedlist5->id);
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

