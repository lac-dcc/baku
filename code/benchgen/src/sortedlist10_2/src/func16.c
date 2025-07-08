#include "sortedlist10_2.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      sortedlist_t* sortedlist52;
      if (pCounter > 0) {
         sortedlist52 = vars->data[--pCounter];
         sortedlist52->refC++;
         DEBUG_COPY(sortedlist52->id);
      } else {
         sortedlist52 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist52->refC = 1;
         sortedlist52->id = 52;
         sortedlist52->n = 0;
         sortedlist52->root = NULL;
         DEBUG_NEW(sortedlist52->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist52;
      sortedlist_t* sortedlist53 = func20(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist53->id);
      free(params0.data);
      if(sortedlist52 != NULL && sortedlist52->n > 0) {
           cell_t* cell37 = sortedlist52->root;
           if(sortedlist52->n == 0) {
               sortedlist52->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist52->root->val  = 11;
               sortedlist52->root->next = NULL;
               sortedlist52->n++;
           } else {
               while(cell37 != NULL)
               {
                   if(cell37->next == NULL && cell37->val < 11) {
                       cell37->next = (cell_t*)malloc(sizeof(cell_t));
                       cell37->next->next = NULL;
                       cell37->next->val  = 11;
                       sortedlist52->n++;
                       break;
                   } else if(11 < cell37->val) {
                       cell_t* tmp37 = cell37->next;
                       cell37->next = (cell_t*)malloc(sizeof(cell_t));
                       cell37->next->next = tmp37;
                       int tmp_val37 = cell37->val;
                       cell37->val = 11;
                       cell37->next->val = tmp_val37;
                       sortedlist52->n++;
                       break;
                   }
                   cell37 = cell37->next;
               }
           }
      }
      sortedlist53->refC--;
      if(sortedlist53->refC == 0){
           cell_t* cell38 = sortedlist53->root;
           cell_t* tmp38  = NULL;
           while(cell38 != NULL) {
               tmp38 = cell38->next;
               free(cell38);
               cell38 = tmp38;
           }
           free(sortedlist53);
           DEBUG_FREE(sortedlist53->id);
      }
      sortedlist52->refC--;
      if(sortedlist52->refC == 0){
           cell_t* cell39 = sortedlist52->root;
           cell_t* tmp39  = NULL;
           while(cell39 != NULL) {
               tmp39 = cell39->next;
               free(cell39);
               cell39 = tmp39;
           }
           free(sortedlist52);
           DEBUG_FREE(sortedlist52->id);
      }
   }
   sortedlist_t* sortedlist67;
   if (pCounter > 0) {
      sortedlist67 = vars->data[--pCounter];
      sortedlist67->refC++;
      DEBUG_COPY(sortedlist67->id);
   } else {
      sortedlist67 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist67->refC = 1;
      sortedlist67->id = 67;
      sortedlist67->n = 0;
      sortedlist67->root = NULL;
      DEBUG_NEW(sortedlist67->id);
   }
   return sortedlist67;
}

