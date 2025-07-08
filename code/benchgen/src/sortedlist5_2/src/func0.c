#include "sortedlist5_2.h" 
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist1;
      sortedlist_t* sortedlist2 = func5(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist2->id);
      free(params0.data);
      if(sortedlist2 != NULL && sortedlist2->n > 0) {
           cell_t* cell8 = sortedlist2->root;
           if(sortedlist2->n == 0) {
               sortedlist2->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist2->root->val  = 21;
               sortedlist2->root->next = NULL;
               sortedlist2->n++;
           } else {
               while(cell8 != NULL)
               {
                   if(cell8->next == NULL && cell8->val < 21) {
                       cell8->next = (cell_t*)malloc(sizeof(cell_t));
                       cell8->next->next = NULL;
                       cell8->next->val  = 21;
                       sortedlist2->n++;
                       break;
                   } else if(21 < cell8->val) {
                       cell_t* tmp8 = cell8->next;
                       cell8->next = (cell_t*)malloc(sizeof(cell_t));
                       cell8->next->next = tmp8;
                       int tmp_val8 = cell8->val;
                       cell8->val = 21;
                       cell8->next->val = tmp_val8;
                       sortedlist2->n++;
                       break;
                   }
                   cell8 = cell8->next;
               }
           }
      }
      sortedlist2->refC--;
      if(sortedlist2->refC == 0){
           cell_t* cell9 = sortedlist2->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell10 = sortedlist1->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist16;
   if (pCounter > 0) {
      sortedlist16 = vars->data[--pCounter];
      sortedlist16->refC++;
      DEBUG_COPY(sortedlist16->id);
   } else {
      sortedlist16 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist16->refC = 1;
      sortedlist16->id = 16;
      sortedlist16->n = 0;
      sortedlist16->root = NULL;
      DEBUG_NEW(sortedlist16->id);
   }
   return sortedlist16;
}

