#include "sortedlist10_2.h" 
sortedlist_t* func22(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/4 + 1;
   for(; loop8 < loopLimit8; loop8++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist57;
      sortedlist_t* sortedlist58 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist58->id);
      free(params0.data);
      if(sortedlist57 != NULL && sortedlist57->n > 0) {
           cell_t* cell33 = sortedlist57->root;
           if(sortedlist57->n == 0) {
               sortedlist57->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist57->root->val  = 69;
               sortedlist57->root->next = NULL;
               sortedlist57->n++;
           } else {
               while(cell33 != NULL)
               {
                   if(cell33->next == NULL && cell33->val < 69) {
                       cell33->next = (cell_t*)malloc(sizeof(cell_t));
                       cell33->next->next = NULL;
                       cell33->next->val  = 69;
                       sortedlist57->n++;
                       break;
                   } else if(69 < cell33->val) {
                       cell_t* tmp33 = cell33->next;
                       cell33->next = (cell_t*)malloc(sizeof(cell_t));
                       cell33->next->next = tmp33;
                       int tmp_val33 = cell33->val;
                       cell33->val = 69;
                       cell33->next->val = tmp_val33;
                       sortedlist57->n++;
                       break;
                   }
                   cell33 = cell33->next;
               }
           }
      }
      sortedlist58->refC--;
      if(sortedlist58->refC == 0){
           cell_t* cell34 = sortedlist58->root;
           cell_t* tmp34  = NULL;
           while(cell34 != NULL) {
               tmp34 = cell34->next;
               free(cell34);
               cell34 = tmp34;
           }
           free(sortedlist58);
           DEBUG_FREE(sortedlist58->id);
      }
      sortedlist57->refC--;
      if(sortedlist57->refC == 0){
           cell_t* cell35 = sortedlist57->root;
           cell_t* tmp35  = NULL;
           while(cell35 != NULL) {
               tmp35 = cell35->next;
               free(cell35);
               cell35 = tmp35;
           }
           free(sortedlist57);
           DEBUG_FREE(sortedlist57->id);
      }
   }
   sortedlist_t* sortedlist65;
   if (pCounter > 0) {
      sortedlist65 = vars->data[--pCounter];
      sortedlist65->refC++;
      DEBUG_COPY(sortedlist65->id);
   } else {
      sortedlist65 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist65->refC = 1;
      sortedlist65->id = 65;
      sortedlist65->n = 0;
      sortedlist65->root = NULL;
      DEBUG_NEW(sortedlist65->id);
   }
   return sortedlist65;
}

