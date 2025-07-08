#include "sortedlist10_5.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
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
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      if(sortedlist9 != NULL && sortedlist9->n > 0)
      {
          cell_t* cell3 = sortedlist9->root;
          if(cell3->val == 35)
          {
              cell3 = cell3->next;
              sortedlist9->n--;
          }else{
              while(cell3->next != NULL && cell3->next->val != 35) cell3 = cell3->next;
              if(cell3->next != NULL)
              {
                  cell3 = cell3->next->next;
                  sortedlist9->n--;
              }
           }
      }
   }
   return sortedlist9;
}

