#include "sortedlist10_10.h" 
sortedlist_t* func1(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist4;
   if (pCounter > 0) {
      sortedlist4 = vars->data[--pCounter];
      sortedlist4->refC++;
      DEBUG_COPY(sortedlist4->id);
   } else {
      sortedlist4 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist4->refC = 1;
      sortedlist4->id = 4;
      sortedlist4->n = 0;
      sortedlist4->root = NULL;
      DEBUG_NEW(sortedlist4->id);
   }
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      if(sortedlist4 != NULL && sortedlist4->n > 0) {
           cell_t* cell1 = sortedlist4->root;
           if(sortedlist4->n == 0) {
               sortedlist4->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist4->root->val  = 15;
               sortedlist4->root->next = NULL;
               sortedlist4->n++;
           } else {
               while(cell1 != NULL)
               {
                   if(cell1->next == NULL && cell1->val < 15) {
                       cell1->next = (cell_t*)malloc(sizeof(cell_t));
                       cell1->next->next = NULL;
                       cell1->next->val  = 15;
                       sortedlist4->n++;
                       break;
                   } else if(15 < cell1->val) {
                       cell_t* tmp1 = cell1->next;
                       cell1->next = (cell_t*)malloc(sizeof(cell_t));
                       cell1->next->next = tmp1;
                       int tmp_val1 = cell1->val;
                       cell1->val = 15;
                       cell1->next->val = tmp_val1;
                       sortedlist4->n++;
                       break;
                   }
                   cell1 = cell1->next;
               }
           }
      }
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
      for(; loop4 < loopLimit4; loop4++) {
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
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist4;
         params0.data[1] = sortedlist5;
         sortedlist_t* sortedlist6 = func2(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist6->id);
         free(params0.data);
         sortedlist6->refC--;
         if(sortedlist6->refC == 0){
              cell_t* cell11 = sortedlist6->root;
              cell_t* tmp11  = NULL;
              while(cell11 != NULL) {
                  tmp11 = cell11->next;
                  free(cell11);
                  cell11 = tmp11;
              }
              free(sortedlist6);
              DEBUG_FREE(sortedlist6->id);
         }
         sortedlist5->refC--;
         if(sortedlist5->refC == 0){
              cell_t* cell12 = sortedlist5->root;
              cell_t* tmp12  = NULL;
              while(cell12 != NULL) {
                  tmp12 = cell12->next;
                  free(cell12);
                  cell12 = tmp12;
              }
              free(sortedlist5);
              DEBUG_FREE(sortedlist5->id);
         }
      }
   }
   return sortedlist4;
}

