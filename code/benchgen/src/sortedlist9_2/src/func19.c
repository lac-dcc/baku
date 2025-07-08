#include "sortedlist9_2.h" 
sortedlist_t* func19(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist16;
      sortedlist_t* sortedlist17 = func23(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist17->id);
      free(params0.data);
      if(sortedlist16 != NULL && sortedlist16->n > 0) {
           cell_t* cell6 = sortedlist16->root;
           if(sortedlist16->n == 0) {
               sortedlist16->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist16->root->val  = 92;
               sortedlist16->root->next = NULL;
               sortedlist16->n++;
           } else {
               while(cell6 != NULL)
               {
                   if(cell6->next == NULL && cell6->val < 92) {
                       cell6->next = (cell_t*)malloc(sizeof(cell_t));
                       cell6->next->next = NULL;
                       cell6->next->val  = 92;
                       sortedlist16->n++;
                       break;
                   } else if(92 < cell6->val) {
                       cell_t* tmp6 = cell6->next;
                       cell6->next = (cell_t*)malloc(sizeof(cell_t));
                       cell6->next->next = tmp6;
                       int tmp_val6 = cell6->val;
                       cell6->val = 92;
                       cell6->next->val = tmp_val6;
                       sortedlist16->n++;
                       break;
                   }
                   cell6 = cell6->next;
               }
           }
      }
      sortedlist17->refC--;
      if(sortedlist17->refC == 0){
           cell_t* cell7 = sortedlist17->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist17);
           DEBUG_FREE(sortedlist17->id);
      }
      sortedlist16->refC--;
      if(sortedlist16->refC == 0){
           cell_t* cell8 = sortedlist16->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist16);
           DEBUG_FREE(sortedlist16->id);
      }
   }
   sortedlist_t* sortedlist24;
   if (pCounter > 0) {
      sortedlist24 = vars->data[--pCounter];
      sortedlist24->refC++;
      DEBUG_COPY(sortedlist24->id);
   } else {
      sortedlist24 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist24->refC = 1;
      sortedlist24->id = 24;
      sortedlist24->n = 0;
      sortedlist24->root = NULL;
      DEBUG_NEW(sortedlist24->id);
   }
   return sortedlist24;
}

