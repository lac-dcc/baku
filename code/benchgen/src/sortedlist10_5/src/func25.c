#include "sortedlist10_5.h" 
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist34;
   if (pCounter > 0) {
      sortedlist34 = vars->data[--pCounter];
      sortedlist34->refC++;
      DEBUG_COPY(sortedlist34->id);
   } else {
      sortedlist34 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist34->refC = 1;
      sortedlist34->id = 34;
      sortedlist34->n = 0;
      sortedlist34->root = NULL;
      DEBUG_NEW(sortedlist34->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/2 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      if(sortedlist34 != NULL && sortedlist34->n > 0)
      {
          cell_t* cell18 = sortedlist34->root;
          if(cell18->val == 30)
          {
              cell18 = cell18->next;
              sortedlist34->n--;
          }else{
              while(cell18->next != NULL && cell18->next->val != 30) cell18 = cell18->next;
              if(cell18->next != NULL)
              {
                  cell18 = cell18->next->next;
                  sortedlist34->n--;
              }
           }
      }
   }
   return sortedlist34;
}

