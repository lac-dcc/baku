#include "sortedlist5_7.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist9;
   if (pCounter > 0) {
      sortedlist9 = vars->data[--pCounter];
      sortedlist9->refC++;
      DEBUG_COPY(sortedlist9->id);
   } else {
      sortedlist9 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist9->refC = 1;
      sortedlist9->id = 9;
      sortedlist9->n = 0;
      sortedlist9->root = NULL;
      DEBUG_NEW(sortedlist9->id);
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      if(sortedlist9 != NULL && sortedlist9->n > 0)
      {
          cell_t* cell4 = sortedlist9->root;
          if(cell4->val == 21)
          {
              cell4 = cell4->next;
              sortedlist9->n--;
          }else{
              while(cell4->next != NULL && cell4->next->val != 21) cell4 = cell4->next;
              if(cell4->next != NULL)
              {
                  cell4 = cell4->next->next;
                  sortedlist9->n--;
              }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist9;
      sortedlist_t* sortedlist10 = func5(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist10->id);
      free(params0.data);
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell5 = sortedlist10->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   return sortedlist9;
}

