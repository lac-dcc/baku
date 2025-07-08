#include "sortedlist9_5.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist52;
   if (pCounter > 0) {
      sortedlist52 = vars->data[--pCounter];
      sortedlist52->refC++;
      DEBUG_COPY(sortedlist52->id);
   } else {
      sortedlist52 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist52->refC = 1;
      sortedlist52->id = 52;
      sortedlist52->n = 0;
      sortedlist52->root = NULL;
      DEBUG_NEW(sortedlist52->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/1 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      if(sortedlist52 != NULL && sortedlist52->n > 0)
      {
          cell_t* cell28 = sortedlist52->root;
          if(cell28->val == 98)
          {
              cell28 = cell28->next;
              sortedlist52->n--;
          }else{
              while(cell28->next != NULL && cell28->next->val != 98) cell28 = cell28->next;
              if(cell28->next != NULL)
              {
                  cell28 = cell28->next->next;
                  sortedlist52->n--;
              }
           }
      }
   }
   return sortedlist52;
}

