#include "sortedlist10_2.h" 
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
      if(sortedlist17 != NULL && sortedlist17->n > 0) {
           cell_t* cell10 = sortedlist17->root;
           if(sortedlist17->n == 0) {
               sortedlist17->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist17->root->val  = 90;
               sortedlist17->root->next = NULL;
               sortedlist17->n++;
           } else {
               while(cell10 != NULL)
               {
                   if(cell10->next == NULL && cell10->val < 90) {
                       cell10->next = (cell_t*)malloc(sizeof(cell_t));
                       cell10->next->next = NULL;
                       cell10->next->val  = 90;
                       sortedlist17->n++;
                       break;
                   } else if(90 < cell10->val) {
                       cell_t* tmp10 = cell10->next;
                       cell10->next = (cell_t*)malloc(sizeof(cell_t));
                       cell10->next->next = tmp10;
                       int tmp_val10 = cell10->val;
                       cell10->val = 90;
                       cell10->next->val = tmp_val10;
                       sortedlist17->n++;
                       break;
                   }
                   cell10 = cell10->next;
               }
           }
      }
      sortedlist17->refC--;
      if(sortedlist17->refC == 0){
           cell_t* cell11 = sortedlist17->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist17);
           DEBUG_FREE(sortedlist17->id);
      }
      sortedlist16->refC--;
      if(sortedlist16->refC == 0){
           cell_t* cell12 = sortedlist16->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist16);
           DEBUG_FREE(sortedlist16->id);
      }
   }
   sortedlist_t* sortedlist30;
   if (pCounter > 0) {
      sortedlist30 = vars->data[--pCounter];
      sortedlist30->refC++;
      DEBUG_COPY(sortedlist30->id);
   } else {
      sortedlist30 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist30->refC = 1;
      sortedlist30->id = 30;
      sortedlist30->n = 0;
      sortedlist30->root = NULL;
      DEBUG_NEW(sortedlist30->id);
   }
   return sortedlist30;
}

