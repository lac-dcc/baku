#include "sortedlist6_2.h" 
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
           cell_t* cell8 = sortedlist7->root;
           if(sortedlist7->n == 0) {
               sortedlist7->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist7->root->val  = 62;
               sortedlist7->root->next = NULL;
               sortedlist7->n++;
           } else {
               while(cell8 != NULL)
               {
                   if(cell8->next == NULL && cell8->val < 62) {
                       cell8->next = (cell_t*)malloc(sizeof(cell_t));
                       cell8->next->next = NULL;
                       cell8->next->val  = 62;
                       sortedlist7->n++;
                       break;
                   } else if(62 < cell8->val) {
                       cell_t* tmp8 = cell8->next;
                       cell8->next = (cell_t*)malloc(sizeof(cell_t));
                       cell8->next->next = tmp8;
                       int tmp_val8 = cell8->val;
                       cell8->val = 62;
                       cell8->next->val = tmp_val8;
                       sortedlist7->n++;
                       break;
                   }
                   cell8 = cell8->next;
               }
           }
      }
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell9 = sortedlist7->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
      sortedlist6->refC--;
      if(sortedlist6->refC == 0){
           cell_t* cell10 = sortedlist6->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
   }
   sortedlist_t* sortedlist20;
   if (pCounter > 0) {
      sortedlist20 = vars->data[--pCounter];
      sortedlist20->refC++;
      DEBUG_COPY(sortedlist20->id);
   } else {
      sortedlist20 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist20->refC = 1;
      sortedlist20->id = 20;
      sortedlist20->n = 0;
      sortedlist20->root = NULL;
      DEBUG_NEW(sortedlist20->id);
   }
   return sortedlist20;
}

