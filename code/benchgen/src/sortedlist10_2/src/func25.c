#include "sortedlist10_2.h" 
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist21;
      if (pCounter > 0) {
         sortedlist21 = vars->data[--pCounter];
         sortedlist21->refC++;
         DEBUG_COPY(sortedlist21->id);
      } else {
         sortedlist21 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist21->refC = 1;
         sortedlist21->id = 21;
         sortedlist21->n = 0;
         sortedlist21->root = NULL;
         DEBUG_NEW(sortedlist21->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist21;
      sortedlist_t* sortedlist22 = func29(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist22->id);
      free(params0.data);
      if(sortedlist21 != NULL && sortedlist21->n > 0) {
           cell_t* cell6 = sortedlist21->root;
           if(sortedlist21->n == 0) {
               sortedlist21->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist21->root->val  = 49;
               sortedlist21->root->next = NULL;
               sortedlist21->n++;
           } else {
               while(cell6 != NULL)
               {
                   if(cell6->next == NULL && cell6->val < 49) {
                       cell6->next = (cell_t*)malloc(sizeof(cell_t));
                       cell6->next->next = NULL;
                       cell6->next->val  = 49;
                       sortedlist21->n++;
                       break;
                   } else if(49 < cell6->val) {
                       cell_t* tmp6 = cell6->next;
                       cell6->next = (cell_t*)malloc(sizeof(cell_t));
                       cell6->next->next = tmp6;
                       int tmp_val6 = cell6->val;
                       cell6->val = 49;
                       cell6->next->val = tmp_val6;
                       sortedlist21->n++;
                       break;
                   }
                   cell6 = cell6->next;
               }
           }
      }
      sortedlist22->refC--;
      if(sortedlist22->refC == 0){
           cell_t* cell7 = sortedlist22->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist22);
           DEBUG_FREE(sortedlist22->id);
      }
      sortedlist21->refC--;
      if(sortedlist21->refC == 0){
           cell_t* cell8 = sortedlist21->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist21);
           DEBUG_FREE(sortedlist21->id);
      }
   }
   sortedlist_t* sortedlist28;
   if (pCounter > 0) {
      sortedlist28 = vars->data[--pCounter];
      sortedlist28->refC++;
      DEBUG_COPY(sortedlist28->id);
   } else {
      sortedlist28 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist28->refC = 1;
      sortedlist28->id = 28;
      sortedlist28->n = 0;
      sortedlist28->root = NULL;
      DEBUG_NEW(sortedlist28->id);
   }
   return sortedlist28;
}

