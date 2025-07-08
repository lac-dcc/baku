#include "sortedlist10_9.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
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
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      sortedlist_t* sortedlist10;
      if (pCounter > 0) {
         sortedlist10 = vars->data[--pCounter];
         sortedlist10->refC++;
         DEBUG_COPY(sortedlist10->id);
      } else {
         sortedlist10 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist10->refC = 1;
         sortedlist10->id = 10;
         sortedlist10->n = 0;
         sortedlist10->root = NULL;
         DEBUG_NEW(sortedlist10->id);
      }
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         if(sortedlist9 != NULL && sortedlist9->n > 0)
         {
             cell_t* cell3 = sortedlist9->root;
             if(cell3->val == 92)
             {
                 cell3 = cell3->next;
                 sortedlist9->n--;
             }else{
                 while(cell3->next != NULL && cell3->next->val != 92) cell3 = cell3->next;
                 if(cell3->next != NULL)
                 {
                     cell3 = cell3->next->next;
                     sortedlist9->n--;
                 }
              }
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist9;
         params0.data[1] = sortedlist10;
         sortedlist_t* sortedlist11 = func4(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist11->id);
         free(params0.data);
         sortedlist11->refC--;
         if(sortedlist11->refC == 0){
              cell_t* cell7 = sortedlist11->root;
              cell_t* tmp7  = NULL;
              while(cell7 != NULL) {
                  tmp7 = cell7->next;
                  free(cell7);
                  cell7 = tmp7;
              }
              free(sortedlist11);
              DEBUG_FREE(sortedlist11->id);
         }
      }
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell8 = sortedlist10->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   return sortedlist9;
}

