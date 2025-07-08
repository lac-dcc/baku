#include "sortedlist9_9.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist6;
   if (pCounter > 0) {
      sortedlist6 = vars->data[--pCounter];
      sortedlist6->refC++;
      DEBUG_COPY(sortedlist6->id);
   } else {
      sortedlist6 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist6->refC = 1;
      sortedlist6->id = 6;
      sortedlist6->n = 0;
      sortedlist6->root = NULL;
      DEBUG_NEW(sortedlist6->id);
   }
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist7;
      if (pCounter > 0) {
         sortedlist7 = vars->data[--pCounter];
         sortedlist7->refC++;
         DEBUG_COPY(sortedlist7->id);
      } else {
         sortedlist7 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist7->refC = 1;
         sortedlist7->id = 7;
         sortedlist7->n = 0;
         sortedlist7->root = NULL;
         DEBUG_NEW(sortedlist7->id);
      }
      unsigned int loop5 = 0;
      unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
      for(; loop5 < loopLimit5; loop5++) {
         if(sortedlist7 != NULL && sortedlist7->n > 0)
         {
             cell_t* cell2 = sortedlist7->root;
             if(cell2->val == 35)
             {
                 cell2 = cell2->next;
                 sortedlist7->n--;
             }else{
                 while(cell2->next != NULL && cell2->next->val != 35) cell2 = cell2->next;
                 if(cell2->next != NULL)
                 {
                     cell2 = cell2->next->next;
                     sortedlist7->n--;
                 }
              }
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist6;
         params0.data[1] = sortedlist7;
         sortedlist_t* sortedlist8 = func3(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist8->id);
         free(params0.data);
         sortedlist8->refC--;
         if(sortedlist8->refC == 0){
              cell_t* cell9 = sortedlist8->root;
              cell_t* tmp9  = NULL;
              while(cell9 != NULL) {
                  tmp9 = cell9->next;
                  free(cell9);
                  cell9 = tmp9;
              }
              free(sortedlist8);
              DEBUG_FREE(sortedlist8->id);
         }
      }
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell10 = sortedlist7->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
   }
   return sortedlist6;
}

