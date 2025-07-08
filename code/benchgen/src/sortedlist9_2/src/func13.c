#include "sortedlist9_2.h" 
sortedlist_t* func13(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      sortedlist_t* sortedlist11;
      if (pCounter > 0) {
         sortedlist11 = vars->data[--pCounter];
         sortedlist11->refC++;
         DEBUG_COPY(sortedlist11->id);
      } else {
         sortedlist11 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist11->refC = 1;
         sortedlist11->id = 11;
         sortedlist11->n = 0;
         sortedlist11->root = NULL;
         DEBUG_NEW(sortedlist11->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist11;
      sortedlist_t* sortedlist12 = func17(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist12->id);
      free(params0.data);
      if(sortedlist11 != NULL && sortedlist11->n > 0) {
           cell_t* cell10 = sortedlist11->root;
           if(sortedlist11->n == 0) {
               sortedlist11->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist11->root->val  = 27;
               sortedlist11->root->next = NULL;
               sortedlist11->n++;
           } else {
               while(cell10 != NULL)
               {
                   if(cell10->next == NULL && cell10->val < 27) {
                       cell10->next = (cell_t*)malloc(sizeof(cell_t));
                       cell10->next->next = NULL;
                       cell10->next->val  = 27;
                       sortedlist11->n++;
                       break;
                   } else if(27 < cell10->val) {
                       cell_t* tmp10 = cell10->next;
                       cell10->next = (cell_t*)malloc(sizeof(cell_t));
                       cell10->next->next = tmp10;
                       int tmp_val10 = cell10->val;
                       cell10->val = 27;
                       cell10->next->val = tmp_val10;
                       sortedlist11->n++;
                       break;
                   }
                   cell10 = cell10->next;
               }
           }
      }
      sortedlist12->refC--;
      if(sortedlist12->refC == 0){
           cell_t* cell11 = sortedlist12->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist12);
           DEBUG_FREE(sortedlist12->id);
      }
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell12 = sortedlist11->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
   }
   sortedlist_t* sortedlist26;
   if (pCounter > 0) {
      sortedlist26 = vars->data[--pCounter];
      sortedlist26->refC++;
      DEBUG_COPY(sortedlist26->id);
   } else {
      sortedlist26 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist26->refC = 1;
      sortedlist26->id = 26;
      sortedlist26->n = 0;
      sortedlist26->root = NULL;
      DEBUG_NEW(sortedlist26->id);
   }
   return sortedlist26;
}

