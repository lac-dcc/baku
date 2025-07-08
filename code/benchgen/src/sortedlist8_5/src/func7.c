#include "sortedlist8_5.h" 
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist4;
   if (pCounter > 0) {
      sortedlist4 = vars->data[--pCounter];
      sortedlist4->refC++;
      DEBUG_COPY(sortedlist4->id);
   } else {
      sortedlist4 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist4->refC = 1;
      sortedlist4->id = 4;
      sortedlist4->n = 0;
      sortedlist4->root = NULL;
      DEBUG_NEW(sortedlist4->id);
   }
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      if(sortedlist4 != NULL && sortedlist4->n > 0)
      {
          cell_t* cell0 = sortedlist4->root;
          if(cell0->val == 86)
          {
              cell0 = cell0->next;
              sortedlist4->n--;
          }else{
              while(cell0->next != NULL && cell0->next->val != 86) cell0 = cell0->next;
              if(cell0->next != NULL)
              {
                  cell0 = cell0->next->next;
                  sortedlist4->n--;
              }
           }
      }
   }
   return sortedlist4;
}

