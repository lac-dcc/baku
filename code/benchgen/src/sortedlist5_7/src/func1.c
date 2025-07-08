#include "sortedlist5_7.h" 
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
      if(sortedlist3 != NULL && sortedlist3->n > 0) {
           cell_t* cell1 = sortedlist3->root;
           if(sortedlist3->n == 0) {
               sortedlist3->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist3->root->val  = 15;
               sortedlist3->root->next = NULL;
               sortedlist3->n++;
           } else {
               while(cell1 != NULL)
               {
                   if(cell1->next == NULL && cell1->val < 15) {
                       cell1->next = (cell_t*)malloc(sizeof(cell_t));
                       cell1->next->next = NULL;
                       cell1->next->val  = 15;
                       sortedlist3->n++;
                       break;
                   } else if(15 < cell1->val) {
                       cell_t* tmp1 = cell1->next;
                       cell1->next = (cell_t*)malloc(sizeof(cell_t));
                       cell1->next->next = tmp1;
                       int tmp_val1 = cell1->val;
                       cell1->val = 15;
                       cell1->next->val = tmp_val1;
                       sortedlist3->n++;
                       break;
                   }
                   cell1 = cell1->next;
               }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist3;
      sortedlist_t* sortedlist4 = func2(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist4->id);
      free(params0.data);
      sortedlist4->refC--;
      if(sortedlist4->refC == 0){
           cell_t* cell8 = sortedlist4->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist4);
           DEBUG_FREE(sortedlist4->id);
      }
   }
   return sortedlist3;
}

