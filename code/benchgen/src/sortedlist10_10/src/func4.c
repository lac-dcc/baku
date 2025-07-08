#include "sortedlist10_10.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
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
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/10 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      if(sortedlist13 != NULL && sortedlist13->n > 0) {
           cell_t* cell4 = sortedlist13->root;
           if(sortedlist13->n == 0) {
               sortedlist13->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist13->root->val  = 21;
               sortedlist13->root->next = NULL;
               sortedlist13->n++;
           } else {
               while(cell4 != NULL)
               {
                   if(cell4->next == NULL && cell4->val < 21) {
                       cell4->next = (cell_t*)malloc(sizeof(cell_t));
                       cell4->next->next = NULL;
                       cell4->next->val  = 21;
                       sortedlist13->n++;
                       break;
                   } else if(21 < cell4->val) {
                       cell_t* tmp4 = cell4->next;
                       cell4->next = (cell_t*)malloc(sizeof(cell_t));
                       cell4->next->next = tmp4;
                       int tmp_val4 = cell4->val;
                       cell4->val = 21;
                       cell4->next->val = tmp_val4;
                       sortedlist13->n++;
                       break;
                   }
                   cell4 = cell4->next;
               }
           }
      }
      unsigned int loop10 = 0;
      unsigned int loopLimit10 = (rand()%loopsFactor)/11 + 1;
      for(; loop10 < loopLimit10; loop10++) {
         sortedlist_t* sortedlist14;
         if (pCounter > 0) {
            sortedlist14 = vars->data[--pCounter];
            sortedlist14->refC++;
            DEBUG_COPY(sortedlist14->id);
         } else {
            sortedlist14 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
            sortedlist14->refC = 1;
            sortedlist14->id = 14;
            sortedlist14->n = 0;
            sortedlist14->root = NULL;
            DEBUG_NEW(sortedlist14->id);
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist13;
         params0.data[1] = sortedlist14;
         sortedlist_t* sortedlist15 = func5(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist15->id);
         free(params0.data);
         sortedlist15->refC--;
         if(sortedlist15->refC == 0){
              cell_t* cell5 = sortedlist15->root;
              cell_t* tmp5  = NULL;
              while(cell5 != NULL) {
                  tmp5 = cell5->next;
                  free(cell5);
                  cell5 = tmp5;
              }
              free(sortedlist15);
              DEBUG_FREE(sortedlist15->id);
         }
         sortedlist14->refC--;
         if(sortedlist14->refC == 0){
              cell_t* cell6 = sortedlist14->root;
              cell_t* tmp6  = NULL;
              while(cell6 != NULL) {
                  tmp6 = cell6->next;
                  free(cell6);
                  cell6 = tmp6;
              }
              free(sortedlist14);
              DEBUG_FREE(sortedlist14->id);
         }
      }
   }
   return sortedlist13;
}

