#include "sortedlist8_2.h" 
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
           cell_t* cell9 = sortedlist11->root;
           if(sortedlist11->n == 0) {
               sortedlist11->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist11->root->val  = 27;
               sortedlist11->root->next = NULL;
               sortedlist11->n++;
           } else {
               while(cell9 != NULL)
               {
                   if(cell9->next == NULL && cell9->val < 27) {
                       cell9->next = (cell_t*)malloc(sizeof(cell_t));
                       cell9->next->next = NULL;
                       cell9->next->val  = 27;
                       sortedlist11->n++;
                       break;
                   } else if(27 < cell9->val) {
                       cell_t* tmp9 = cell9->next;
                       cell9->next = (cell_t*)malloc(sizeof(cell_t));
                       cell9->next->next = tmp9;
                       int tmp_val9 = cell9->val;
                       cell9->val = 27;
                       cell9->next->val = tmp_val9;
                       sortedlist11->n++;
                       break;
                   }
                   cell9 = cell9->next;
               }
           }
      }
      sortedlist12->refC--;
      if(sortedlist12->refC == 0){
           cell_t* cell10 = sortedlist12->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist12);
           DEBUG_FREE(sortedlist12->id);
      }
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell11 = sortedlist11->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
   }
   sortedlist_t* sortedlist25;
   if (pCounter > 0) {
      sortedlist25 = vars->data[--pCounter];
      sortedlist25->refC++;
      DEBUG_COPY(sortedlist25->id);
   } else {
      sortedlist25 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist25->refC = 1;
      sortedlist25->id = 25;
      sortedlist25->n = 0;
      sortedlist25->root = NULL;
      DEBUG_NEW(sortedlist25->id);
   }
   return sortedlist25;
}

