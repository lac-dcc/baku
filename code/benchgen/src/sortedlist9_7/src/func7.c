#include "sortedlist9_7.h" 
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist15;
   if (pCounter > 0) {
      sortedlist15 = vars->data[--pCounter];
      sortedlist15->refC++;
      DEBUG_COPY(sortedlist15->id);
   } else {
      sortedlist15 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist15->refC = 1;
      sortedlist15->id = 15;
      sortedlist15->n = 0;
      sortedlist15->root = NULL;
      DEBUG_NEW(sortedlist15->id);
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/9 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      if(sortedlist15 != NULL && sortedlist15->n > 0) {
           cell_t* cell7 = sortedlist15->root;
           if(sortedlist15->n == 0) {
               sortedlist15->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist15->root->val  = 26;
               sortedlist15->root->next = NULL;
               sortedlist15->n++;
           } else {
               while(cell7 != NULL)
               {
                   if(cell7->next == NULL && cell7->val < 26) {
                       cell7->next = (cell_t*)malloc(sizeof(cell_t));
                       cell7->next->next = NULL;
                       cell7->next->val  = 26;
                       sortedlist15->n++;
                       break;
                   } else if(26 < cell7->val) {
                       cell_t* tmp7 = cell7->next;
                       cell7->next = (cell_t*)malloc(sizeof(cell_t));
                       cell7->next->next = tmp7;
                       int tmp_val7 = cell7->val;
                       cell7->val = 26;
                       cell7->next->val = tmp_val7;
                       sortedlist15->n++;
                       break;
                   }
                   cell7 = cell7->next;
               }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist15;
      sortedlist_t* sortedlist16 = func8(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist16->id);
      free(params0.data);
      sortedlist16->refC--;
      if(sortedlist16->refC == 0){
           cell_t* cell10 = sortedlist16->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist16);
           DEBUG_FREE(sortedlist16->id);
      }
   }
   return sortedlist15;
}

