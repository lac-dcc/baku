#include "sortedlist10_5.h" 
sortedlist_t* func28(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist39;
   if (pCounter > 0) {
      sortedlist39 = vars->data[--pCounter];
      sortedlist39->refC++;
      DEBUG_COPY(sortedlist39->id);
   } else {
      sortedlist39 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist39->refC = 1;
      sortedlist39->id = 39;
      sortedlist39->n = 0;
      sortedlist39->root = NULL;
      DEBUG_NEW(sortedlist39->id);
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/2 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      if(sortedlist39 != NULL && sortedlist39->n > 0)
      {
          cell_t* cell21 = sortedlist39->root;
          if(cell21->val == 35)
          {
              cell21 = cell21->next;
              sortedlist39->n--;
          }else{
              while(cell21->next != NULL && cell21->next->val != 35) cell21 = cell21->next;
              if(cell21->next != NULL)
              {
                  cell21 = cell21->next->next;
                  sortedlist39->n--;
              }
           }
      }
   }
   return sortedlist39;
}

