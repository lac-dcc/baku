#include "sortedlist6_2.h" 
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
      if(sortedlist12 != NULL && sortedlist12->n > 0) {
           cell_t* cell4 = sortedlist12->root;
           if(sortedlist12->n == 0) {
               sortedlist12->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist12->root->val  = 86;
               sortedlist12->root->next = NULL;
               sortedlist12->n++;
           } else {
               while(cell4 != NULL)
               {
                   if(cell4->next == NULL && cell4->val < 86) {
                       cell4->next = (cell_t*)malloc(sizeof(cell_t));
                       cell4->next->next = NULL;
                       cell4->next->val  = 86;
                       sortedlist12->n++;
                       break;
                   } else if(86 < cell4->val) {
                       cell_t* tmp4 = cell4->next;
                       cell4->next = (cell_t*)malloc(sizeof(cell_t));
                       cell4->next->next = tmp4;
                       int tmp_val4 = cell4->val;
                       cell4->val = 86;
                       cell4->next->val = tmp_val4;
                       sortedlist12->n++;
                       break;
                   }
                   cell4 = cell4->next;
               }
           }
      }
      sortedlist12->refC--;
      if(sortedlist12->refC == 0){
           cell_t* cell5 = sortedlist12->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist12);
           DEBUG_FREE(sortedlist12->id);
      }
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell6 = sortedlist11->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
   }
   sortedlist_t* sortedlist18;
   if (pCounter > 0) {
      sortedlist18 = vars->data[--pCounter];
      sortedlist18->refC++;
      DEBUG_COPY(sortedlist18->id);
   } else {
      sortedlist18 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist18->refC = 1;
      sortedlist18->id = 18;
      sortedlist18->n = 0;
      sortedlist18->root = NULL;
      DEBUG_NEW(sortedlist18->id);
   }
   return sortedlist18;
}

