#include "sortedlist9_10.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
      if(sortedlist7 != NULL && sortedlist7->n > 0) {
           cell_t* cell2 = sortedlist7->root;
           if(sortedlist7->n == 0) {
               sortedlist7->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist7->root->val  = 35;
               sortedlist7->root->next = NULL;
               sortedlist7->n++;
           } else {
               while(cell2 != NULL)
               {
                   if(cell2->next == NULL && cell2->val < 35) {
                       cell2->next = (cell_t*)malloc(sizeof(cell_t));
                       cell2->next->next = NULL;
                       cell2->next->val  = 35;
                       sortedlist7->n++;
                       break;
                   } else if(35 < cell2->val) {
                       cell_t* tmp2 = cell2->next;
                       cell2->next = (cell_t*)malloc(sizeof(cell_t));
                       cell2->next->next = tmp2;
                       int tmp_val2 = cell2->val;
                       cell2->val = 35;
                       cell2->next->val = tmp_val2;
                       sortedlist7->n++;
                       break;
                   }
                   cell2 = cell2->next;
               }
           }
      }
      unsigned int loop6 = 0;
      unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
      for(; loop6 < loopLimit6; loop6++) {
         sortedlist_t* sortedlist8;
         if (pCounter > 0) {
            sortedlist8 = vars->data[--pCounter];
            sortedlist8->refC++;
            DEBUG_COPY(sortedlist8->id);
         } else {
            sortedlist8 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
            sortedlist8->refC = 1;
            sortedlist8->id = 8;
            sortedlist8->n = 0;
            sortedlist8->root = NULL;
            DEBUG_NEW(sortedlist8->id);
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist7;
         params0.data[1] = sortedlist8;
         sortedlist_t* sortedlist9 = func3(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist9->id);
         free(params0.data);
         sortedlist9->refC--;
         if(sortedlist9->refC == 0){
              cell_t* cell7 = sortedlist9->root;
              cell_t* tmp7  = NULL;
              while(cell7 != NULL) {
                  tmp7 = cell7->next;
                  free(cell7);
                  cell7 = tmp7;
              }
              free(sortedlist9);
              DEBUG_FREE(sortedlist9->id);
         }
         sortedlist8->refC--;
         if(sortedlist8->refC == 0){
              cell_t* cell8 = sortedlist8->root;
              cell_t* tmp8  = NULL;
              while(cell8 != NULL) {
                  tmp8 = cell8->next;
                  free(cell8);
                  cell8 = tmp8;
              }
              free(sortedlist8);
              DEBUG_FREE(sortedlist8->id);
         }
      }
   }
   return sortedlist7;
}

