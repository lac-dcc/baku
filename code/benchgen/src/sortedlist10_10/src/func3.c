#include "sortedlist10_10.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
      if(sortedlist10 != NULL && sortedlist10->n > 0) {
           cell_t* cell3 = sortedlist10->root;
           if(sortedlist10->n == 0) {
               sortedlist10->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist10->root->val  = 92;
               sortedlist10->root->next = NULL;
               sortedlist10->n++;
           } else {
               while(cell3 != NULL)
               {
                   if(cell3->next == NULL && cell3->val < 92) {
                       cell3->next = (cell_t*)malloc(sizeof(cell_t));
                       cell3->next->next = NULL;
                       cell3->next->val  = 92;
                       sortedlist10->n++;
                       break;
                   } else if(92 < cell3->val) {
                       cell_t* tmp3 = cell3->next;
                       cell3->next = (cell_t*)malloc(sizeof(cell_t));
                       cell3->next->next = tmp3;
                       int tmp_val3 = cell3->val;
                       cell3->val = 92;
                       cell3->next->val = tmp_val3;
                       sortedlist10->n++;
                       break;
                   }
                   cell3 = cell3->next;
               }
           }
      }
      unsigned int loop8 = 0;
      unsigned int loopLimit8 = (rand()%loopsFactor)/9 + 1;
      for(; loop8 < loopLimit8; loop8++) {
         sortedlist_t* sortedlist11;
         if (pCounter > 0) {
            sortedlist11 = vars->data[--pCounter];
            sortedlist11->refC++;
            DEBUG_COPY(sortedlist11->id);
         } else {
            sortedlist11 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
            sortedlist11->refC = 1;
            sortedlist11->id = 11;
            sortedlist11->n = 0;
            sortedlist11->root = NULL;
            DEBUG_NEW(sortedlist11->id);
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist10;
         params0.data[1] = sortedlist11;
         sortedlist_t* sortedlist12 = func4(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist12->id);
         free(params0.data);
         sortedlist12->refC--;
         if(sortedlist12->refC == 0){
              cell_t* cell7 = sortedlist12->root;
              cell_t* tmp7  = NULL;
              while(cell7 != NULL) {
                  tmp7 = cell7->next;
                  free(cell7);
                  cell7 = tmp7;
              }
              free(sortedlist12);
              DEBUG_FREE(sortedlist12->id);
         }
         sortedlist11->refC--;
         if(sortedlist11->refC == 0){
              cell_t* cell8 = sortedlist11->root;
              cell_t* tmp8  = NULL;
              while(cell8 != NULL) {
                  tmp8 = cell8->next;
                  free(cell8);
                  cell8 = tmp8;
              }
              free(sortedlist11);
              DEBUG_FREE(sortedlist11->id);
         }
      }
   }
   return sortedlist10;
}

