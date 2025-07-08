#include "sortedlist6_2.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist33;
      if (pCounter > 0) {
         sortedlist33 = vars->data[--pCounter];
         sortedlist33->refC++;
         DEBUG_COPY(sortedlist33->id);
      } else {
         sortedlist33 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist33->refC = 1;
         sortedlist33->id = 33;
         sortedlist33->n = 0;
         sortedlist33->root = NULL;
         DEBUG_NEW(sortedlist33->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist33;
      sortedlist_t* sortedlist34 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist34->id);
      free(params0.data);
      if(sortedlist33 != NULL && sortedlist33->n > 0) {
           cell_t* cell21 = sortedlist33->root;
           if(sortedlist33->n == 0) {
               sortedlist33->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist33->root->val  = 67;
               sortedlist33->root->next = NULL;
               sortedlist33->n++;
           } else {
               while(cell21 != NULL)
               {
                   if(cell21->next == NULL && cell21->val < 67) {
                       cell21->next = (cell_t*)malloc(sizeof(cell_t));
                       cell21->next->next = NULL;
                       cell21->next->val  = 67;
                       sortedlist33->n++;
                       break;
                   } else if(67 < cell21->val) {
                       cell_t* tmp21 = cell21->next;
                       cell21->next = (cell_t*)malloc(sizeof(cell_t));
                       cell21->next->next = tmp21;
                       int tmp_val21 = cell21->val;
                       cell21->val = 67;
                       cell21->next->val = tmp_val21;
                       sortedlist33->n++;
                       break;
                   }
                   cell21 = cell21->next;
               }
           }
      }
      sortedlist34->refC--;
      if(sortedlist34->refC == 0){
           cell_t* cell22 = sortedlist34->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist34);
           DEBUG_FREE(sortedlist34->id);
      }
      sortedlist33->refC--;
      if(sortedlist33->refC == 0){
           cell_t* cell23 = sortedlist33->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist33);
           DEBUG_FREE(sortedlist33->id);
      }
   }
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
   return sortedlist41;
}

