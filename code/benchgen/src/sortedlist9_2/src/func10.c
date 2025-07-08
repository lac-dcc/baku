#include "sortedlist9_2.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      sortedlist_t* sortedlist41;
      if (pCounter > 0) {
         sortedlist41 = vars->data[--pCounter];
         sortedlist41->refC++;
         DEBUG_COPY(sortedlist41->id);
      } else {
         sortedlist41 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist41->refC = 1;
         sortedlist41->id = 41;
         sortedlist41->n = 0;
         sortedlist41->root = NULL;
         DEBUG_NEW(sortedlist41->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist41;
      sortedlist_t* sortedlist42 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist42->id);
      free(params0.data);
      if(sortedlist42 != NULL && sortedlist42->n > 0) {
           cell_t* cell36 = sortedlist42->root;
           if(sortedlist42->n == 0) {
               sortedlist42->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist42->root->val  = 56;
               sortedlist42->root->next = NULL;
               sortedlist42->n++;
           } else {
               while(cell36 != NULL)
               {
                   if(cell36->next == NULL && cell36->val < 56) {
                       cell36->next = (cell_t*)malloc(sizeof(cell_t));
                       cell36->next->next = NULL;
                       cell36->next->val  = 56;
                       sortedlist42->n++;
                       break;
                   } else if(56 < cell36->val) {
                       cell_t* tmp36 = cell36->next;
                       cell36->next = (cell_t*)malloc(sizeof(cell_t));
                       cell36->next->next = tmp36;
                       int tmp_val36 = cell36->val;
                       cell36->val = 56;
                       cell36->next->val = tmp_val36;
                       sortedlist42->n++;
                       break;
                   }
                   cell36 = cell36->next;
               }
           }
      }
      sortedlist42->refC--;
      if(sortedlist42->refC == 0){
           cell_t* cell37 = sortedlist42->root;
           cell_t* tmp37  = NULL;
           while(cell37 != NULL) {
               tmp37 = cell37->next;
               free(cell37);
               cell37 = tmp37;
           }
           free(sortedlist42);
           DEBUG_FREE(sortedlist42->id);
      }
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell38 = sortedlist41->root;
           cell_t* tmp38  = NULL;
           while(cell38 != NULL) {
               tmp38 = cell38->next;
               free(cell38);
               cell38 = tmp38;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
   }
   sortedlist_t* sortedlist62;
   if (pCounter > 0) {
      sortedlist62 = vars->data[--pCounter];
      sortedlist62->refC++;
      DEBUG_COPY(sortedlist62->id);
   } else {
      sortedlist62 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist62->refC = 1;
      sortedlist62->id = 62;
      sortedlist62->n = 0;
      sortedlist62->root = NULL;
      DEBUG_NEW(sortedlist62->id);
   }
   return sortedlist62;
}

