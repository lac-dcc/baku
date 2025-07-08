#include "sortedlist9_10.h" 
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
      }
   }
   return sortedlist13;
}

