#include "sortedlist9_2.h" 
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      sortedlist_t* sortedlist6;
      if (pCounter > 0) {
         sortedlist6 = vars->data[--pCounter];
         sortedlist6->refC++;
         DEBUG_COPY(sortedlist6->id);
      } else {
         sortedlist6 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist6->refC = 1;
         sortedlist6->id = 6;
         sortedlist6->n = 0;
         sortedlist6->root = NULL;
         DEBUG_NEW(sortedlist6->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist6;
      sortedlist_t* sortedlist7 = func11(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist7->id);
      free(params0.data);
      if(sortedlist7 != NULL && sortedlist7->n > 0) {
           cell_t* cell14 = sortedlist7->root;
           if(sortedlist7->n == 0) {
               sortedlist7->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist7->root->val  = 26;
               sortedlist7->root->next = NULL;
               sortedlist7->n++;
           } else {
               while(cell14 != NULL)
               {
                   if(cell14->next == NULL && cell14->val < 26) {
                       cell14->next = (cell_t*)malloc(sizeof(cell_t));
                       cell14->next->next = NULL;
                       cell14->next->val  = 26;
                       sortedlist7->n++;
                       break;
                   } else if(26 < cell14->val) {
                       cell_t* tmp14 = cell14->next;
                       cell14->next = (cell_t*)malloc(sizeof(cell_t));
                       cell14->next->next = tmp14;
                       int tmp_val14 = cell14->val;
                       cell14->val = 26;
                       cell14->next->val = tmp_val14;
                       sortedlist7->n++;
                       break;
                   }
                   cell14 = cell14->next;
               }
           }
      }
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell15 = sortedlist7->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
      sortedlist6->refC--;
      if(sortedlist6->refC == 0){
           cell_t* cell16 = sortedlist6->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
   }
   sortedlist_t* sortedlist28;
   if (pCounter > 0) {
      sortedlist28 = vars->data[--pCounter];
      sortedlist28->refC++;
      DEBUG_COPY(sortedlist28->id);
   } else {
      sortedlist28 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist28->refC = 1;
      sortedlist28->id = 28;
      sortedlist28->n = 0;
      sortedlist28->root = NULL;
      DEBUG_NEW(sortedlist28->id);
   }
   return sortedlist28;
}

