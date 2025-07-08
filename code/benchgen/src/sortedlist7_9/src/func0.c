#include "sortedlist7_9.h" 
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist1;
      sortedlist_t* sortedlist2 = func1(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist2->id);
      free(params0.data);
      sortedlist2->refC--;
      if(sortedlist2->refC == 0){
           cell_t* cell10 = sortedlist2->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
   }
   return sortedlist1;
}

