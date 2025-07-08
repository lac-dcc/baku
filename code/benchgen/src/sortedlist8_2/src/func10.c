#include "sortedlist8_2.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t* sortedlist40;
      if (pCounter > 0) {
         sortedlist40 = vars->data[--pCounter];
         sortedlist40->refC++;
         DEBUG_COPY(sortedlist40->id);
      } else {
         sortedlist40 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist40->refC = 1;
         sortedlist40->id = 40;
         sortedlist40->n = 0;
         sortedlist40->root = NULL;
         DEBUG_NEW(sortedlist40->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist40;
      sortedlist_t* sortedlist41 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist41->id);
      free(params0.data);
      if(sortedlist40 != NULL && sortedlist40->n > 0) {
           cell_t* cell31 = sortedlist40->root;
           if(sortedlist40->n == 0) {
               sortedlist40->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist40->root->val  = 22;
               sortedlist40->root->next = NULL;
               sortedlist40->n++;
           } else {
               while(cell31 != NULL)
               {
                   if(cell31->next == NULL && cell31->val < 22) {
                       cell31->next = (cell_t*)malloc(sizeof(cell_t));
                       cell31->next->next = NULL;
                       cell31->next->val  = 22;
                       sortedlist40->n++;
                       break;
                   } else if(22 < cell31->val) {
                       cell_t* tmp31 = cell31->next;
                       cell31->next = (cell_t*)malloc(sizeof(cell_t));
                       cell31->next->next = tmp31;
                       int tmp_val31 = cell31->val;
                       cell31->val = 22;
                       cell31->next->val = tmp_val31;
                       sortedlist40->n++;
                       break;
                   }
                   cell31 = cell31->next;
               }
           }
      }
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell32 = sortedlist41->root;
           cell_t* tmp32  = NULL;
           while(cell32 != NULL) {
               tmp32 = cell32->next;
               free(cell32);
               cell32 = tmp32;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell33 = sortedlist40->root;
           cell_t* tmp33  = NULL;
           while(cell33 != NULL) {
               tmp33 = cell33->next;
               free(cell33);
               cell33 = tmp33;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
   }
   sortedlist_t* sortedlist55;
   if (pCounter > 0) {
      sortedlist55 = vars->data[--pCounter];
      sortedlist55->refC++;
      DEBUG_COPY(sortedlist55->id);
   } else {
      sortedlist55 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist55->refC = 1;
      sortedlist55->id = 55;
      sortedlist55->n = 0;
      sortedlist55->root = NULL;
      DEBUG_NEW(sortedlist55->id);
   }
   return sortedlist55;
}

