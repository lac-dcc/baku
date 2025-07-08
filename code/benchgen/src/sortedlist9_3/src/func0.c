#include "sortedlist9_3.h" 
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist1;
   if (pCounter > 0) {
      sortedlist1 = vars->data[--pCounter];
      sortedlist1->refC++;
      DEBUG_COPY(sortedlist1->id);
   } else {
      sortedlist1 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist1->refC = 1;
      sortedlist1->id = 1;
      sortedlist1->n = 0;
      sortedlist1->root = NULL;
      DEBUG_NEW(sortedlist1->id);
   }
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      if(sortedlist1 != NULL && sortedlist1->n > 0)
      {
          cell_t* cell0 = sortedlist1->root;
          if(cell0->val == 86)
          {
              cell0 = cell0->next;
              sortedlist1->n--;
          }else{
              while(cell0->next != NULL && cell0->next->val != 86) cell0 = cell0->next;
              if(cell0->next != NULL)
              {
                  cell0 = cell0->next->next;
                  sortedlist1->n--;
              }
           }
      }
   }
   return sortedlist1;
}

