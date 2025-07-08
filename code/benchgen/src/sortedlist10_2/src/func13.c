#include "sortedlist10_2.h" 
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
           cell_t* cell14 = sortedlist11->root;
           if(sortedlist11->n == 0) {
               sortedlist11->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist11->root->val  = 40;
               sortedlist11->root->next = NULL;
               sortedlist11->n++;
           } else {
               while(cell14 != NULL)
               {
                   if(cell14->next == NULL && cell14->val < 40) {
                       cell14->next = (cell_t*)malloc(sizeof(cell_t));
                       cell14->next->next = NULL;
                       cell14->next->val  = 40;
                       sortedlist11->n++;
                       break;
                   } else if(40 < cell14->val) {
                       cell_t* tmp14 = cell14->next;
                       cell14->next = (cell_t*)malloc(sizeof(cell_t));
                       cell14->next->next = tmp14;
                       int tmp_val14 = cell14->val;
                       cell14->val = 40;
                       cell14->next->val = tmp_val14;
                       sortedlist11->n++;
                       break;
                   }
                   cell14 = cell14->next;
               }
           }
      }
      sortedlist12->refC--;
      if(sortedlist12->refC == 0){
           cell_t* cell15 = sortedlist12->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist12);
           DEBUG_FREE(sortedlist12->id);
      }
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell16 = sortedlist11->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
   }
   sortedlist_t* sortedlist32;
   if (pCounter > 0) {
      sortedlist32 = vars->data[--pCounter];
      sortedlist32->refC++;
      DEBUG_COPY(sortedlist32->id);
   } else {
      sortedlist32 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist32->refC = 1;
      sortedlist32->id = 32;
      sortedlist32->n = 0;
      sortedlist32->root = NULL;
      DEBUG_NEW(sortedlist32->id);
   }
   return sortedlist32;
}

