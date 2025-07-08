#include "sortedlist6_7.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
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
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      if(sortedlist5 != NULL && sortedlist5->n > 0)
      {
          cell_t* cell2 = sortedlist5->root;
          if(cell2->val == 35)
          {
              cell2 = cell2->next;
              sortedlist5->n--;
          }else{
              while(cell2->next != NULL && cell2->next->val != 35) cell2 = cell2->next;
              if(cell2->next != NULL)
              {
                  cell2 = cell2->next->next;
                  sortedlist5->n--;
              }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist5;
      sortedlist_t* sortedlist6 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist6->id);
      free(params0.data);
      sortedlist6->refC--;
      if(sortedlist6->refC == 0){
           cell_t* cell9 = sortedlist6->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
   }
   return sortedlist5;
}

