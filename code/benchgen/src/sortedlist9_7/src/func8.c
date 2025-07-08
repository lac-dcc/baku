#include "sortedlist9_7.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist17;
   if (pCounter > 0) {
      sortedlist17 = vars->data[--pCounter];
      sortedlist17->refC++;
      DEBUG_COPY(sortedlist17->id);
   } else {
      sortedlist17 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist17->refC = 1;
      sortedlist17->id = 17;
      sortedlist17->n = 0;
      sortedlist17->root = NULL;
      DEBUG_NEW(sortedlist17->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/10 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      if(sortedlist17 != NULL && sortedlist17->n > 0)
      {
          cell_t* cell8 = sortedlist17->root;
          if(cell8->val == 26)
          {
              cell8 = cell8->next;
              sortedlist17->n--;
          }else{
              while(cell8->next != NULL && cell8->next->val != 26) cell8 = cell8->next;
              if(cell8->next != NULL)
              {
                  cell8 = cell8->next->next;
                  sortedlist17->n--;
              }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist17;
      sortedlist_t* sortedlist18 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist18->id);
      free(params0.data);
      sortedlist18->refC--;
      if(sortedlist18->refC == 0){
           cell_t* cell9 = sortedlist18->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist18);
           DEBUG_FREE(sortedlist18->id);
      }
   }
   return sortedlist17;
}

