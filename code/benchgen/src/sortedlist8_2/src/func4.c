#include "sortedlist8_2.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist35;
      if (pCounter > 0) {
         sortedlist35 = vars->data[--pCounter];
         sortedlist35->refC++;
         DEBUG_COPY(sortedlist35->id);
      } else {
         sortedlist35 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist35->refC = 1;
         sortedlist35->id = 35;
         sortedlist35->n = 0;
         sortedlist35->root = NULL;
         DEBUG_NEW(sortedlist35->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist35;
      sortedlist_t* sortedlist36 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist36->id);
      free(params0.data);
      if(sortedlist36 != NULL && sortedlist36->n > 0) {
           cell_t* cell35 = sortedlist36->root;
           if(sortedlist36->n == 0) {
               sortedlist36->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist36->root->val  = 93;
               sortedlist36->root->next = NULL;
               sortedlist36->n++;
           } else {
               while(cell35 != NULL)
               {
                   if(cell35->next == NULL && cell35->val < 93) {
                       cell35->next = (cell_t*)malloc(sizeof(cell_t));
                       cell35->next->next = NULL;
                       cell35->next->val  = 93;
                       sortedlist36->n++;
                       break;
                   } else if(93 < cell35->val) {
                       cell_t* tmp35 = cell35->next;
                       cell35->next = (cell_t*)malloc(sizeof(cell_t));
                       cell35->next->next = tmp35;
                       int tmp_val35 = cell35->val;
                       cell35->val = 93;
                       cell35->next->val = tmp_val35;
                       sortedlist36->n++;
                       break;
                   }
                   cell35 = cell35->next;
               }
           }
      }
      sortedlist36->refC--;
      if(sortedlist36->refC == 0){
           cell_t* cell36 = sortedlist36->root;
           cell_t* tmp36  = NULL;
           while(cell36 != NULL) {
               tmp36 = cell36->next;
               free(cell36);
               cell36 = tmp36;
           }
           free(sortedlist36);
           DEBUG_FREE(sortedlist36->id);
      }
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell37 = sortedlist35->root;
           cell_t* tmp37  = NULL;
           while(cell37 != NULL) {
               tmp37 = cell37->next;
               free(cell37);
               cell37 = tmp37;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
   }
   sortedlist_t* sortedlist57;
   if (pCounter > 0) {
      sortedlist57 = vars->data[--pCounter];
      sortedlist57->refC++;
      DEBUG_COPY(sortedlist57->id);
   } else {
      sortedlist57 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist57->refC = 1;
      sortedlist57->id = 57;
      sortedlist57->n = 0;
      sortedlist57->root = NULL;
      DEBUG_NEW(sortedlist57->id);
   }
   return sortedlist57;
}

