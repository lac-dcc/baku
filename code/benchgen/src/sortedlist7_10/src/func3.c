#include "sortedlist7_10.h" 
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
      }
   }
   return sortedlist10;
}

