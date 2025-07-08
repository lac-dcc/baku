#include "sortedlist5_10.h" 
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
      if(sortedlist1 != NULL && sortedlist1->n > 0) {
           cell_t* cell0 = sortedlist1->root;
           if(sortedlist1->n == 0) {
               sortedlist1->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist1->root->val  = 86;
               sortedlist1->root->next = NULL;
               sortedlist1->n++;
           } else {
               while(cell0 != NULL)
               {
                   if(cell0->next == NULL && cell0->val < 86) {
                       cell0->next = (cell_t*)malloc(sizeof(cell_t));
                       cell0->next->next = NULL;
                       cell0->next->val  = 86;
                       sortedlist1->n++;
                       break;
                   } else if(86 < cell0->val) {
                       cell_t* tmp0 = cell0->next;
                       cell0->next = (cell_t*)malloc(sizeof(cell_t));
                       cell0->next->next = tmp0;
                       int tmp_val0 = cell0->val;
                       cell0->val = 86;
                       cell0->next->val = tmp_val0;
                       sortedlist1->n++;
                       break;
                   }
                   cell0 = cell0->next;
               }
           }
      }
      unsigned int loop2 = 0;
      unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
      for(; loop2 < loopLimit2; loop2++) {
         sortedlist_t* sortedlist2;
         if (pCounter > 0) {
            sortedlist2 = vars->data[--pCounter];
            sortedlist2->refC++;
            DEBUG_COPY(sortedlist2->id);
         } else {
            sortedlist2 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
            sortedlist2->refC = 1;
            sortedlist2->id = 2;
            sortedlist2->n = 0;
            sortedlist2->root = NULL;
            DEBUG_NEW(sortedlist2->id);
         }
         sortedlist_t_param params0;
         params0.size = 2;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         params0.data[0] = sortedlist1;
         params0.data[1] = sortedlist2;
         sortedlist_t* sortedlist3 = func1(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist3->id);
         free(params0.data);
         sortedlist3->refC--;
         if(sortedlist3->refC == 0){
              cell_t* cell5 = sortedlist3->root;
              cell_t* tmp5  = NULL;
              while(cell5 != NULL) {
                  tmp5 = cell5->next;
                  free(cell5);
                  cell5 = tmp5;
              }
              free(sortedlist3);
              DEBUG_FREE(sortedlist3->id);
         }
         sortedlist2->refC--;
         if(sortedlist2->refC == 0){
              cell_t* cell6 = sortedlist2->root;
              cell_t* tmp6  = NULL;
              while(cell6 != NULL) {
                  tmp6 = cell6->next;
                  free(cell6);
                  cell6 = tmp6;
              }
              free(sortedlist2);
              DEBUG_FREE(sortedlist2->id);
         }
      }
   }
   return sortedlist1;
}

