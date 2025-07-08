#include "sortedlist9_2.h" 
sortedlist_t* func22(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/4 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      sortedlist_t* sortedlist51;
      if (pCounter > 0) {
         sortedlist51 = vars->data[--pCounter];
         sortedlist51->refC++;
         DEBUG_COPY(sortedlist51->id);
      } else {
         sortedlist51 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist51->refC = 1;
         sortedlist51->id = 51;
         sortedlist51->n = 0;
         sortedlist51->root = NULL;
         DEBUG_NEW(sortedlist51->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist51;
      sortedlist_t* sortedlist52 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist52->id);
      free(params0.data);
      if(sortedlist52 != NULL && sortedlist52->n > 0) {
           cell_t* cell28 = sortedlist52->root;
           if(sortedlist52->n == 0) {
               sortedlist52->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist52->root->val  = 35;
               sortedlist52->root->next = NULL;
               sortedlist52->n++;
           } else {
               while(cell28 != NULL)
               {
                   if(cell28->next == NULL && cell28->val < 35) {
                       cell28->next = (cell_t*)malloc(sizeof(cell_t));
                       cell28->next->next = NULL;
                       cell28->next->val  = 35;
                       sortedlist52->n++;
                       break;
                   } else if(35 < cell28->val) {
                       cell_t* tmp28 = cell28->next;
                       cell28->next = (cell_t*)malloc(sizeof(cell_t));
                       cell28->next->next = tmp28;
                       int tmp_val28 = cell28->val;
                       cell28->val = 35;
                       cell28->next->val = tmp_val28;
                       sortedlist52->n++;
                       break;
                   }
                   cell28 = cell28->next;
               }
           }
      }
      sortedlist52->refC--;
      if(sortedlist52->refC == 0){
           cell_t* cell29 = sortedlist52->root;
           cell_t* tmp29  = NULL;
           while(cell29 != NULL) {
               tmp29 = cell29->next;
               free(cell29);
               cell29 = tmp29;
           }
           free(sortedlist52);
           DEBUG_FREE(sortedlist52->id);
      }
      sortedlist51->refC--;
      if(sortedlist51->refC == 0){
           cell_t* cell30 = sortedlist51->root;
           cell_t* tmp30  = NULL;
           while(cell30 != NULL) {
               tmp30 = cell30->next;
               free(cell30);
               cell30 = tmp30;
           }
           free(sortedlist51);
           DEBUG_FREE(sortedlist51->id);
      }
   }
   sortedlist_t* sortedlist58;
   if (pCounter > 0) {
      sortedlist58 = vars->data[--pCounter];
      sortedlist58->refC++;
      DEBUG_COPY(sortedlist58->id);
   } else {
      sortedlist58 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist58->refC = 1;
      sortedlist58->id = 58;
      sortedlist58->n = 0;
      sortedlist58->root = NULL;
      DEBUG_NEW(sortedlist58->id);
   }
   return sortedlist58;
}

