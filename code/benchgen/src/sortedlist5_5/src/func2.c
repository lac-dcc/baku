#include "sortedlist5_5.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist32;
   if (pCounter > 0) {
      sortedlist32 = vars->data[--pCounter];
      sortedlist32->refC++;
      DEBUG_COPY(sortedlist32->id);
   } else {
      sortedlist32 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist32->refC = 1;
      sortedlist32->id = 32;
      sortedlist32->n = 0;
      sortedlist32->root = NULL;
      DEBUG_NEW(sortedlist32->id);
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/1 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      if(sortedlist32 != NULL && sortedlist32->n > 0)
      {
          cell_t* cell16 = sortedlist32->root;
          if(cell16->val == 62)
          {
              cell16 = cell16->next;
              sortedlist32->n--;
          }else{
              while(cell16->next != NULL && cell16->next->val != 62) cell16 = cell16->next;
              if(cell16->next != NULL)
              {
                  cell16 = cell16->next->next;
                  sortedlist32->n--;
              }
           }
      }
   }
   return sortedlist32;
}

