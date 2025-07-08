#include "sortedlist8_5.h" 
sortedlist_t* func13(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/2 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      if(sortedlist14 != NULL && sortedlist14->n > 0)
      {
          cell_t* cell6 = sortedlist14->root;
          if(cell6->val == 21)
          {
              cell6 = cell6->next;
              sortedlist14->n--;
          }else{
              while(cell6->next != NULL && cell6->next->val != 21) cell6 = cell6->next;
              if(cell6->next != NULL)
              {
                  cell6 = cell6->next->next;
                  sortedlist14->n--;
              }
           }
      }
   }
   return sortedlist14;
}

