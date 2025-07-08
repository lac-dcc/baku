#include "sortedlist5_2.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t* sortedlist22;
      if (pCounter > 0) {
         sortedlist22 = vars->data[--pCounter];
         sortedlist22->refC++;
         DEBUG_COPY(sortedlist22->id);
      } else {
         sortedlist22 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist22->refC = 1;
         sortedlist22->id = 22;
         sortedlist22->n = 0;
         sortedlist22->root = NULL;
         DEBUG_NEW(sortedlist22->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist22;
      sortedlist_t* sortedlist23 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist23->id);
      free(params0.data);
      if(sortedlist23 != NULL && sortedlist23->n > 0) {
           cell_t* cell20 = sortedlist23->root;
           if(sortedlist23->n == 0) {
               sortedlist23->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist23->root->val  = 68;
               sortedlist23->root->next = NULL;
               sortedlist23->n++;
           } else {
               while(cell20 != NULL)
               {
                   if(cell20->next == NULL && cell20->val < 68) {
                       cell20->next = (cell_t*)malloc(sizeof(cell_t));
                       cell20->next->next = NULL;
                       cell20->next->val  = 68;
                       sortedlist23->n++;
                       break;
                   } else if(68 < cell20->val) {
                       cell_t* tmp20 = cell20->next;
                       cell20->next = (cell_t*)malloc(sizeof(cell_t));
                       cell20->next->next = tmp20;
                       int tmp_val20 = cell20->val;
                       cell20->val = 68;
                       cell20->next->val = tmp_val20;
                       sortedlist23->n++;
                       break;
                   }
                   cell20 = cell20->next;
               }
           }
      }
      sortedlist23->refC--;
      if(sortedlist23->refC == 0){
           cell_t* cell21 = sortedlist23->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist23);
           DEBUG_FREE(sortedlist23->id);
      }
      sortedlist22->refC--;
      if(sortedlist22->refC == 0){
           cell_t* cell22 = sortedlist22->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist22);
           DEBUG_FREE(sortedlist22->id);
      }
   }
   sortedlist_t* sortedlist36;
   if (pCounter > 0) {
      sortedlist36 = vars->data[--pCounter];
      sortedlist36->refC++;
      DEBUG_COPY(sortedlist36->id);
   } else {
      sortedlist36 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist36->refC = 1;
      sortedlist36->id = 36;
      sortedlist36->n = 0;
      sortedlist36->root = NULL;
      DEBUG_NEW(sortedlist36->id);
   }
   return sortedlist36;
}

