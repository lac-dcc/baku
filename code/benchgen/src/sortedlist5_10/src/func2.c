#include "sortedlist5_10.h" 
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
      }
   }
   return sortedlist7;
}

