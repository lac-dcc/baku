#include "sortedlist9_5.h" 
sortedlist_t* func19(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist24;
   if (pCounter > 0) {
      sortedlist24 = vars->data[--pCounter];
      sortedlist24->refC++;
      DEBUG_COPY(sortedlist24->id);
   } else {
      sortedlist24 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist24->refC = 1;
      sortedlist24->id = 24;
      sortedlist24->n = 0;
      sortedlist24->root = NULL;
      DEBUG_NEW(sortedlist24->id);
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      if(sortedlist24 != NULL && sortedlist24->n > 0)
      {
          cell_t* cell12 = sortedlist24->root;
          if(cell12->val == 26)
          {
              cell12 = cell12->next;
              sortedlist24->n--;
          }else{
              while(cell12->next != NULL && cell12->next->val != 26) cell12 = cell12->next;
              if(cell12->next != NULL)
              {
                  cell12 = cell12->next->next;
                  sortedlist24->n--;
              }
           }
      }
   }
   return sortedlist24;
}

