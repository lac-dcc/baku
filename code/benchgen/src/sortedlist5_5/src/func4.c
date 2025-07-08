#include "sortedlist5_5.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist27;
   if (pCounter > 0) {
      sortedlist27 = vars->data[--pCounter];
      sortedlist27->refC++;
      DEBUG_COPY(sortedlist27->id);
   } else {
      sortedlist27 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist27->refC = 1;
      sortedlist27->id = 27;
      sortedlist27->n = 0;
      sortedlist27->root = NULL;
      DEBUG_NEW(sortedlist27->id);
   }
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      if(sortedlist27 != NULL && sortedlist27->n > 0)
      {
          cell_t* cell13 = sortedlist27->root;
          if(cell13->val == 11)
          {
              cell13 = cell13->next;
              sortedlist27->n--;
          }else{
              while(cell13->next != NULL && cell13->next->val != 11) cell13 = cell13->next;
              if(cell13->next != NULL)
              {
                  cell13 = cell13->next->next;
                  sortedlist27->n--;
              }
           }
      }
   }
   return sortedlist27;
}

