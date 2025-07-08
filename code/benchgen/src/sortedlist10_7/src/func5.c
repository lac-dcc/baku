#include "sortedlist10_7.h" 
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      if(sortedlist11 != NULL && sortedlist11->n > 0) {
           cell_t* cell5 = sortedlist11->root;
           if(sortedlist11->n == 0) {
               sortedlist11->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist11->root->val  = 27;
               sortedlist11->root->next = NULL;
               sortedlist11->n++;
           } else {
               while(cell5 != NULL)
               {
                   if(cell5->next == NULL && cell5->val < 27) {
                       cell5->next = (cell_t*)malloc(sizeof(cell_t));
                       cell5->next->next = NULL;
                       cell5->next->val  = 27;
                       sortedlist11->n++;
                       break;
                   } else if(27 < cell5->val) {
                       cell_t* tmp5 = cell5->next;
                       cell5->next = (cell_t*)malloc(sizeof(cell_t));
                       cell5->next->next = tmp5;
                       int tmp_val5 = cell5->val;
                       cell5->val = 27;
                       cell5->next->val = tmp_val5;
                       sortedlist11->n++;
                       break;
                   }
                   cell5 = cell5->next;
               }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist11;
      sortedlist_t* sortedlist12 = func6(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist12->id);
      free(params0.data);
      sortedlist12->refC--;
      if(sortedlist12->refC == 0){
           cell_t* cell14 = sortedlist12->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist12);
           DEBUG_FREE(sortedlist12->id);
      }
   }
   return sortedlist11;
}

