#include "sortedlist9_5.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist47;
   if (pCounter > 0) {
      sortedlist47 = vars->data[--pCounter];
      sortedlist47->refC++;
      DEBUG_COPY(sortedlist47->id);
   } else {
      sortedlist47 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist47->refC = 1;
      sortedlist47->id = 47;
      sortedlist47->n = 0;
      sortedlist47->root = NULL;
      DEBUG_NEW(sortedlist47->id);
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/1 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      if(sortedlist47 != NULL && sortedlist47->n > 0)
      {
          cell_t* cell25 = sortedlist47->root;
          if(cell25->val == 29)
          {
              cell25 = cell25->next;
              sortedlist47->n--;
          }else{
              while(cell25->next != NULL && cell25->next->val != 29) cell25 = cell25->next;
              if(cell25->next != NULL)
              {
                  cell25 = cell25->next->next;
                  sortedlist47->n--;
              }
           }
      }
   }
   return sortedlist47;
}

