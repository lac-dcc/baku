#include "sortedlist10_2.h" 
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
           cell_t* cell22 = sortedlist2->root;
           if(sortedlist2->n == 0) {
               sortedlist2->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist2->root->val  = 82;
               sortedlist2->root->next = NULL;
               sortedlist2->n++;
           } else {
               while(cell22 != NULL)
               {
                   if(cell22->next == NULL && cell22->val < 82) {
                       cell22->next = (cell_t*)malloc(sizeof(cell_t));
                       cell22->next->next = NULL;
                       cell22->next->val  = 82;
                       sortedlist2->n++;
                       break;
                   } else if(82 < cell22->val) {
                       cell_t* tmp22 = cell22->next;
                       cell22->next = (cell_t*)malloc(sizeof(cell_t));
                       cell22->next->next = tmp22;
                       int tmp_val22 = cell22->val;
                       cell22->val = 82;
                       cell22->next->val = tmp_val22;
                       sortedlist2->n++;
                       break;
                   }
                   cell22 = cell22->next;
               }
           }
      }
      sortedlist2->refC--;
      if(sortedlist2->refC == 0){
           cell_t* cell23 = sortedlist2->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell24 = sortedlist1->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist36;
   if (pCounter > 0) {
      sortedlist36 = vars->data[--pCounter];
      sortedlist36->refC++;
      DEBUG_COPY(sortedlist36->id);
   } else {
      sortedlist36 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist36->refC = 1;
      sortedlist36->id = 36;
      sortedlist36->n = 0;
      sortedlist36->root = NULL;
      DEBUG_NEW(sortedlist36->id);
   }
   return sortedlist36;
}

