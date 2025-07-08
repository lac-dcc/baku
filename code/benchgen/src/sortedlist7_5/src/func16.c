#include "sortedlist7_5.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist19;
   if (pCounter > 0) {
      sortedlist19 = vars->data[--pCounter];
      sortedlist19->refC++;
      DEBUG_COPY(sortedlist19->id);
   } else {
      sortedlist19 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist19->refC = 1;
      sortedlist19->id = 19;
      sortedlist19->n = 0;
      sortedlist19->root = NULL;
      DEBUG_NEW(sortedlist19->id);
   }
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      if(sortedlist19 != NULL && sortedlist19->n > 0)
      {
          cell_t* cell9 = sortedlist19->root;
          if(cell9->val == 59)
          {
              cell9 = cell9->next;
              sortedlist19->n--;
          }else{
              while(cell9->next != NULL && cell9->next->val != 59) cell9 = cell9->next;
              if(cell9->next != NULL)
              {
                  cell9 = cell9->next->next;
                  sortedlist19->n--;
              }
           }
      }
   }
   return sortedlist19;
}

