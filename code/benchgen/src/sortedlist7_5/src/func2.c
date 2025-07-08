#include "sortedlist7_5.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist42;
   if (pCounter > 0) {
      sortedlist42 = vars->data[--pCounter];
      sortedlist42->refC++;
      DEBUG_COPY(sortedlist42->id);
   } else {
      sortedlist42 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist42->refC = 1;
      sortedlist42->id = 42;
      sortedlist42->n = 0;
      sortedlist42->root = NULL;
      DEBUG_NEW(sortedlist42->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/1 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      if(sortedlist42 != NULL && sortedlist42->n > 0)
      {
          cell_t* cell22 = sortedlist42->root;
          if(cell22->val == 93)
          {
              cell22 = cell22->next;
              sortedlist42->n--;
          }else{
              while(cell22->next != NULL && cell22->next->val != 93) cell22 = cell22->next;
              if(cell22->next != NULL)
              {
                  cell22 = cell22->next->next;
                  sortedlist42->n--;
              }
           }
      }
   }
   return sortedlist42;
}

