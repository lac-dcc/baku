#include "sortedlist9_2.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      sortedlist_t* sortedlist46;
      if (pCounter > 0) {
         sortedlist46 = vars->data[--pCounter];
         sortedlist46->refC++;
         DEBUG_COPY(sortedlist46->id);
      } else {
         sortedlist46 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist46->refC = 1;
         sortedlist46->id = 46;
         sortedlist46->n = 0;
         sortedlist46->root = NULL;
         DEBUG_NEW(sortedlist46->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist46;
      sortedlist_t* sortedlist47 = func20(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist47->id);
      free(params0.data);
      if(sortedlist46 != NULL && sortedlist46->n > 0) {
           cell_t* cell32 = sortedlist46->root;
           if(sortedlist46->n == 0) {
               sortedlist46->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist46->root->val  = 58;
               sortedlist46->root->next = NULL;
               sortedlist46->n++;
           } else {
               while(cell32 != NULL)
               {
                   if(cell32->next == NULL && cell32->val < 58) {
                       cell32->next = (cell_t*)malloc(sizeof(cell_t));
                       cell32->next->next = NULL;
                       cell32->next->val  = 58;
                       sortedlist46->n++;
                       break;
                   } else if(58 < cell32->val) {
                       cell_t* tmp32 = cell32->next;
                       cell32->next = (cell_t*)malloc(sizeof(cell_t));
                       cell32->next->next = tmp32;
                       int tmp_val32 = cell32->val;
                       cell32->val = 58;
                       cell32->next->val = tmp_val32;
                       sortedlist46->n++;
                       break;
                   }
                   cell32 = cell32->next;
               }
           }
      }
      sortedlist47->refC--;
      if(sortedlist47->refC == 0){
           cell_t* cell33 = sortedlist47->root;
           cell_t* tmp33  = NULL;
           while(cell33 != NULL) {
               tmp33 = cell33->next;
               free(cell33);
               cell33 = tmp33;
           }
           free(sortedlist47);
           DEBUG_FREE(sortedlist47->id);
      }
      sortedlist46->refC--;
      if(sortedlist46->refC == 0){
           cell_t* cell34 = sortedlist46->root;
           cell_t* tmp34  = NULL;
           while(cell34 != NULL) {
               tmp34 = cell34->next;
               free(cell34);
               cell34 = tmp34;
           }
           free(sortedlist46);
           DEBUG_FREE(sortedlist46->id);
      }
   }
   sortedlist_t* sortedlist60;
   if (pCounter > 0) {
      sortedlist60 = vars->data[--pCounter];
      sortedlist60->refC++;
      DEBUG_COPY(sortedlist60->id);
   } else {
      sortedlist60 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist60->refC = 1;
      sortedlist60->id = 60;
      sortedlist60->n = 0;
      sortedlist60->root = NULL;
      DEBUG_NEW(sortedlist60->id);
   }
   return sortedlist60;
}

