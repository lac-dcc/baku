#include "sortedlist10_9.h" 
sortedlist_t* func1(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist3;
   if (pCounter > 0) {
      sortedlist3 = vars->data[--pCounter];
      sortedlist3->refC++;
      DEBUG_COPY(sortedlist3->id);
   } else {
      sortedlist3 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist3->refC = 1;
      sortedlist3->id = 3;
      sortedlist3->n = 0;
      sortedlist3->root = NULL;
      DEBUG_NEW(sortedlist3->id);
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
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
      unsigned int loop3 = 0;
      unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
      for(; loop3 < loopLimit3; loop3++) {
         if(sortedlist4 != NULL && sortedlist4->n > 0)
         {
             cell_t* cell1 = sortedlist4->root;
             if(cell1->val == 15)
             {
                 cell1 = cell1->next;
                 sortedlist4->n--;
             }else{
                 while(cell1->next != NULL && cell1->next->val != 15) cell1 = cell1->next;
                 if(cell1->next != NULL)
                 {
                     cell1 = cell1->next->next;
                     sortedlist4->n--;
                 }
              }
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist3;
         params0.data[1] = sortedlist4;
         sortedlist_t* sortedlist5 = func2(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist5->id);
         free(params0.data);
         sortedlist5->refC--;
         if(sortedlist5->refC == 0){
              cell_t* cell11 = sortedlist5->root;
              cell_t* tmp11  = NULL;
              while(cell11 != NULL) {
                  tmp11 = cell11->next;
                  free(cell11);
                  cell11 = tmp11;
              }
              free(sortedlist5);
              DEBUG_FREE(sortedlist5->id);
         }
      }
      sortedlist4->refC--;
      if(sortedlist4->refC == 0){
           cell_t* cell12 = sortedlist4->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
      }
   }
   return sortedlist3;
}

