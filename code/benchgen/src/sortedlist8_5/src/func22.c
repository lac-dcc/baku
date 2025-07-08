#include "sortedlist8_5.h" 
sortedlist_t* func22(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist29;
   if (pCounter > 0) {
      sortedlist29 = vars->data[--pCounter];
      sortedlist29->refC++;
      DEBUG_COPY(sortedlist29->id);
   } else {
      sortedlist29 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist29->refC = 1;
      sortedlist29->id = 29;
      sortedlist29->n = 0;
      sortedlist29->root = NULL;
      DEBUG_NEW(sortedlist29->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      if(sortedlist29 != NULL && sortedlist29->n > 0)
      {
          cell_t* cell15 = sortedlist29->root;
          if(cell15->val == 68)
          {
              cell15 = cell15->next;
              sortedlist29->n--;
          }else{
              while(cell15->next != NULL && cell15->next->val != 68) cell15 = cell15->next;
              if(cell15->next != NULL)
              {
                  cell15 = cell15->next->next;
                  sortedlist29->n--;
              }
           }
      }
   }
   return sortedlist29;
}

