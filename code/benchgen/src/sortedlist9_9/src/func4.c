#include "sortedlist9_9.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist12;
   if (pCounter > 0) {
      sortedlist12 = vars->data[--pCounter];
      sortedlist12->refC++;
      DEBUG_COPY(sortedlist12->id);
   } else {
      sortedlist12 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist12->refC = 1;
      sortedlist12->id = 12;
      sortedlist12->n = 0;
      sortedlist12->root = NULL;
      DEBUG_NEW(sortedlist12->id);
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/9 + 1;
   for(; loop8 < loopLimit8; loop8++) {
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
      unsigned int loop9 = 0;
      unsigned int loopLimit9 = (rand()%loopsFactor)/10 + 1;
      for(; loop9 < loopLimit9; loop9++) {
         if(sortedlist13 != NULL && sortedlist13->n > 0)
         {
             cell_t* cell4 = sortedlist13->root;
             if(cell4->val == 21)
             {
                 cell4 = cell4->next;
                 sortedlist13->n--;
             }else{
                 while(cell4->next != NULL && cell4->next->val != 21) cell4 = cell4->next;
                 if(cell4->next != NULL)
                 {
                     cell4 = cell4->next->next;
                     sortedlist13->n--;
                 }
              }
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist12;
         params0.data[1] = sortedlist13;
         sortedlist_t* sortedlist14 = func5(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist14->id);
         free(params0.data);
         sortedlist14->refC--;
         if(sortedlist14->refC == 0){
              cell_t* cell5 = sortedlist14->root;
              cell_t* tmp5  = NULL;
              while(cell5 != NULL) {
                  tmp5 = cell5->next;
                  free(cell5);
                  cell5 = tmp5;
              }
              free(sortedlist14);
              DEBUG_FREE(sortedlist14->id);
         }
      }
      sortedlist13->refC--;
      if(sortedlist13->refC == 0){
           cell_t* cell6 = sortedlist13->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist13);
           DEBUG_FREE(sortedlist13->id);
      }
   }
   return sortedlist12;
}

