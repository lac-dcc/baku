#include "sortedlist10_5.h" 
sortedlist_t* func2(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist57;
   if (pCounter > 0) {
      sortedlist57 = vars->data[--pCounter];
      sortedlist57->refC++;
      DEBUG_COPY(sortedlist57->id);
   } else {
      sortedlist57 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist57->refC = 1;
      sortedlist57->id = 57;
      sortedlist57->n = 0;
      sortedlist57->root = NULL;
      DEBUG_NEW(sortedlist57->id);
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/1 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      if(sortedlist57 != NULL && sortedlist57->n > 0)
      {
          cell_t* cell31 = sortedlist57->root;
          if(cell31->val == 26)
          {
              cell31 = cell31->next;
              sortedlist57->n--;
          }else{
              while(cell31->next != NULL && cell31->next->val != 26) cell31 = cell31->next;
              if(cell31->next != NULL)
              {
                  cell31 = cell31->next->next;
                  sortedlist57->n--;
              }
           }
      }
   }
   return sortedlist57;
}

