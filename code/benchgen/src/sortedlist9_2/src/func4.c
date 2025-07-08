#include "sortedlist9_2.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/1 + 1;
   for(; loop5 < loopLimit5; loop5++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist36;
      sortedlist_t* sortedlist37 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist37->id);
      free(params0.data);
      if(sortedlist37 != NULL && sortedlist37->n > 0) {
           cell_t* cell40 = sortedlist37->root;
           if(sortedlist37->n == 0) {
               sortedlist37->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist37->root->val  = 73;
               sortedlist37->root->next = NULL;
               sortedlist37->n++;
           } else {
               while(cell40 != NULL)
               {
                   if(cell40->next == NULL && cell40->val < 73) {
                       cell40->next = (cell_t*)malloc(sizeof(cell_t));
                       cell40->next->next = NULL;
                       cell40->next->val  = 73;
                       sortedlist37->n++;
                       break;
                   } else if(73 < cell40->val) {
                       cell_t* tmp40 = cell40->next;
                       cell40->next = (cell_t*)malloc(sizeof(cell_t));
                       cell40->next->next = tmp40;
                       int tmp_val40 = cell40->val;
                       cell40->val = 73;
                       cell40->next->val = tmp_val40;
                       sortedlist37->n++;
                       break;
                   }
                   cell40 = cell40->next;
               }
           }
      }
      sortedlist37->refC--;
      if(sortedlist37->refC == 0){
           cell_t* cell41 = sortedlist37->root;
           cell_t* tmp41  = NULL;
           while(cell41 != NULL) {
               tmp41 = cell41->next;
               free(cell41);
               cell41 = tmp41;
           }
           free(sortedlist37);
           DEBUG_FREE(sortedlist37->id);
      }
      sortedlist36->refC--;
      if(sortedlist36->refC == 0){
           cell_t* cell42 = sortedlist36->root;
           cell_t* tmp42  = NULL;
           while(cell42 != NULL) {
               tmp42 = cell42->next;
               free(cell42);
               cell42 = tmp42;
           }
           free(sortedlist36);
           DEBUG_FREE(sortedlist36->id);
      }
   }
   sortedlist_t* sortedlist64;
   if (pCounter > 0) {
      sortedlist64 = vars->data[--pCounter];
      sortedlist64->refC++;
      DEBUG_COPY(sortedlist64->id);
   } else {
      sortedlist64 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist64->refC = 1;
      sortedlist64->id = 64;
      sortedlist64->n = 0;
      sortedlist64->root = NULL;
      DEBUG_NEW(sortedlist64->id);
   }
   return sortedlist64;
}

