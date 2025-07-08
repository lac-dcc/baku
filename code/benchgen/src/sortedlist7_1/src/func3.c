#include "sortedlist7_1.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist5;
      sortedlist_t* sortedlist6 = func4(&params0, loopsFactor);
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
   }
   return sortedlist5;
}

