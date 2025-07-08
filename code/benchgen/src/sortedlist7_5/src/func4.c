#include "sortedlist7_5.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist37;
   if (pCounter > 0) {
      sortedlist37 = vars->data[--pCounter];
      sortedlist37->refC++;
      DEBUG_COPY(sortedlist37->id);
   } else {
      sortedlist37 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist37->refC = 1;
      sortedlist37->id = 37;
      sortedlist37->n = 0;
      sortedlist37->root = NULL;
      DEBUG_NEW(sortedlist37->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/1 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      if(sortedlist37 != NULL && sortedlist37->n > 0)
      {
          cell_t* cell19 = sortedlist37->root;
          if(cell19->val == 29)
          {
              cell19 = cell19->next;
              sortedlist37->n--;
          }else{
              while(cell19->next != NULL && cell19->next->val != 29) cell19 = cell19->next;
              if(cell19->next != NULL)
              {
                  cell19 = cell19->next->next;
                  sortedlist37->n--;
              }
           }
      }
   }
   return sortedlist37;
}

