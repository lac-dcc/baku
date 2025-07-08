#include "sortedlist10_7.h" 
sortedlist_t* func9(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist19;
   if (pCounter > 0) {
      sortedlist19 = vars->data[--pCounter];
      sortedlist19->refC++;
      DEBUG_COPY(sortedlist19->id);
   } else {
      sortedlist19 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist19->refC = 1;
      sortedlist19->id = 19;
      sortedlist19->n = 0;
      sortedlist19->root = NULL;
      DEBUG_NEW(sortedlist19->id);
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/11 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      if(sortedlist19 != NULL && sortedlist19->n > 0) {
           cell_t* cell9 = sortedlist19->root;
           if(sortedlist19->n == 0) {
               sortedlist19->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist19->root->val  = 36;
               sortedlist19->root->next = NULL;
               sortedlist19->n++;
           } else {
               while(cell9 != NULL)
               {
                   if(cell9->next == NULL && cell9->val < 36) {
                       cell9->next = (cell_t*)malloc(sizeof(cell_t));
                       cell9->next->next = NULL;
                       cell9->next->val  = 36;
                       sortedlist19->n++;
                       break;
                   } else if(36 < cell9->val) {
                       cell_t* tmp9 = cell9->next;
                       cell9->next = (cell_t*)malloc(sizeof(cell_t));
                       cell9->next->next = tmp9;
                       int tmp_val9 = cell9->val;
                       cell9->val = 36;
                       cell9->next->val = tmp_val9;
                       sortedlist19->n++;
                       break;
                   }
                   cell9 = cell9->next;
               }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist19;
      sortedlist_t* sortedlist20 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist20->id);
      free(params0.data);
      sortedlist20->refC--;
      if(sortedlist20->refC == 0){
           cell_t* cell10 = sortedlist20->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
   }
   return sortedlist19;
}

