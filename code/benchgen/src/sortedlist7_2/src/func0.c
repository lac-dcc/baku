#include "sortedlist7_2.h" 
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      sortedlist_t* sortedlist1;
      if (pCounter > 0) {
         sortedlist1 = vars->data[--pCounter];
         sortedlist1->refC++;
         DEBUG_COPY(sortedlist1->id);
      } else {
         sortedlist1 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist1->refC = 1;
         sortedlist1->id = 1;
         sortedlist1->n = 0;
         sortedlist1->root = NULL;
         DEBUG_NEW(sortedlist1->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist1;
      sortedlist_t* sortedlist2 = func5(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist2->id);
      free(params0.data);
      if(sortedlist2 != NULL && sortedlist2->n > 0) {
           cell_t* cell13 = sortedlist2->root;
           if(sortedlist2->n == 0) {
               sortedlist2->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist2->root->val  = 63;
               sortedlist2->root->next = NULL;
               sortedlist2->n++;
           } else {
               while(cell13 != NULL)
               {
                   if(cell13->next == NULL && cell13->val < 63) {
                       cell13->next = (cell_t*)malloc(sizeof(cell_t));
                       cell13->next->next = NULL;
                       cell13->next->val  = 63;
                       sortedlist2->n++;
                       break;
                   } else if(63 < cell13->val) {
                       cell_t* tmp13 = cell13->next;
                       cell13->next = (cell_t*)malloc(sizeof(cell_t));
                       cell13->next->next = tmp13;
                       int tmp_val13 = cell13->val;
                       cell13->val = 63;
                       cell13->next->val = tmp_val13;
                       sortedlist2->n++;
                       break;
                   }
                   cell13 = cell13->next;
               }
           }
      }
      sortedlist2->refC--;
      if(sortedlist2->refC == 0){
           cell_t* cell14 = sortedlist2->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell15 = sortedlist1->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist23;
   if (pCounter > 0) {
      sortedlist23 = vars->data[--pCounter];
      sortedlist23->refC++;
      DEBUG_COPY(sortedlist23->id);
   } else {
      sortedlist23 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist23->refC = 1;
      sortedlist23->id = 23;
      sortedlist23->n = 0;
      sortedlist23->root = NULL;
      DEBUG_NEW(sortedlist23->id);
   }
   return sortedlist23;
}

