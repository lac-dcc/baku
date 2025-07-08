#include "sortedlist8_7.h" 
sortedlist_t* func6(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist13;
   if (pCounter > 0) {
      sortedlist13 = vars->data[--pCounter];
      sortedlist13->refC++;
      DEBUG_COPY(sortedlist13->id);
   } else {
      sortedlist13 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist13->refC = 1;
      sortedlist13->id = 13;
      sortedlist13->n = 0;
      sortedlist13->root = NULL;
      DEBUG_NEW(sortedlist13->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      if(sortedlist13 != NULL && sortedlist13->n > 0)
      {
          cell_t* cell6 = sortedlist13->root;
          if(cell6->val == 59)
          {
              cell6 = cell6->next;
              sortedlist13->n--;
          }else{
              while(cell6->next != NULL && cell6->next->val != 59) cell6 = cell6->next;
              if(cell6->next != NULL)
              {
                  cell6 = cell6->next->next;
                  sortedlist13->n--;
              }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist13;
      sortedlist_t* sortedlist14 = func7(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist14->id);
      free(params0.data);
      sortedlist14->refC--;
      if(sortedlist14->refC == 0){
           cell_t* cell9 = sortedlist14->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist14);
           DEBUG_FREE(sortedlist14->id);
      }
   }
   return sortedlist13;
}

