#include "sortedlist9_8.h" 
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
           cell_t* cell6 = sortedlist6->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
      sortedlist5->refC--;
      if(sortedlist5->refC == 0){
           cell_t* cell7 = sortedlist5->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist5);
           DEBUG_FREE(sortedlist5->id);
      }
   }
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
   return sortedlist21;
}

