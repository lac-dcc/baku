#include "sortedlist7_8.h" 
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
           cell_t* cell3 = sortedlist6->root;
           cell_t* tmp3  = NULL;
           while(cell3 != NULL) {
               tmp3 = cell3->next;
               free(cell3);
               cell3 = tmp3;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
      sortedlist5->refC--;
      if(sortedlist5->refC == 0){
           cell_t* cell4 = sortedlist5->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist5);
           DEBUG_FREE(sortedlist5->id);
      }
   }
   sortedlist_t* sortedlist14;
   if (pCounter > 0) {
      sortedlist14 = vars->data[--pCounter];
      sortedlist14->refC++;
      DEBUG_COPY(sortedlist14->id);
   } else {
      sortedlist14 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist14->refC = 1;
      sortedlist14->id = 14;
      sortedlist14->n = 0;
      sortedlist14->root = NULL;
      DEBUG_NEW(sortedlist14->id);
   }
   return sortedlist14;
}

