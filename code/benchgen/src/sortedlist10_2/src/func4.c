#include "sortedlist10_2.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/1 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      sortedlist_t* sortedlist42;
      if (pCounter > 0) {
         sortedlist42 = vars->data[--pCounter];
         sortedlist42->refC++;
         DEBUG_COPY(sortedlist42->id);
      } else {
         sortedlist42 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist42->refC = 1;
         sortedlist42->id = 42;
         sortedlist42->n = 0;
         sortedlist42->root = NULL;
         DEBUG_NEW(sortedlist42->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist42;
      sortedlist_t* sortedlist43 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist43->id);
      free(params0.data);
      if(sortedlist43 != NULL && sortedlist43->n > 0) {
           cell_t* cell45 = sortedlist43->root;
           if(sortedlist43->n == 0) {
               sortedlist43->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist43->root->val  = 98;
               sortedlist43->root->next = NULL;
               sortedlist43->n++;
           } else {
               while(cell45 != NULL)
               {
                   if(cell45->next == NULL && cell45->val < 98) {
                       cell45->next = (cell_t*)malloc(sizeof(cell_t));
                       cell45->next->next = NULL;
                       cell45->next->val  = 98;
                       sortedlist43->n++;
                       break;
                   } else if(98 < cell45->val) {
                       cell_t* tmp45 = cell45->next;
                       cell45->next = (cell_t*)malloc(sizeof(cell_t));
                       cell45->next->next = tmp45;
                       int tmp_val45 = cell45->val;
                       cell45->val = 98;
                       cell45->next->val = tmp_val45;
                       sortedlist43->n++;
                       break;
                   }
                   cell45 = cell45->next;
               }
           }
      }
      sortedlist43->refC--;
      if(sortedlist43->refC == 0){
           cell_t* cell46 = sortedlist43->root;
           cell_t* tmp46  = NULL;
           while(cell46 != NULL) {
               tmp46 = cell46->next;
               free(cell46);
               cell46 = tmp46;
           }
           free(sortedlist43);
           DEBUG_FREE(sortedlist43->id);
      }
      sortedlist42->refC--;
      if(sortedlist42->refC == 0){
           cell_t* cell47 = sortedlist42->root;
           cell_t* tmp47  = NULL;
           while(cell47 != NULL) {
               tmp47 = cell47->next;
               free(cell47);
               cell47 = tmp47;
           }
           free(sortedlist42);
           DEBUG_FREE(sortedlist42->id);
      }
   }
   sortedlist_t* sortedlist71;
   if (pCounter > 0) {
      sortedlist71 = vars->data[--pCounter];
      sortedlist71->refC++;
      DEBUG_COPY(sortedlist71->id);
   } else {
      sortedlist71 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist71->refC = 1;
      sortedlist71->id = 71;
      sortedlist71->n = 0;
      sortedlist71->root = NULL;
      DEBUG_NEW(sortedlist71->id);
   }
   return sortedlist71;
}

