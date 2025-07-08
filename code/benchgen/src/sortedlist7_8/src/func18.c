#include "sortedlist7_8.h" 
sortedlist_t* func18(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist29 = func19(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist29->id);
      free(params0.data);
      sortedlist29->refC--;
      if(sortedlist29->refC == 0){
           cell_t* cell10 = sortedlist29->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist29);
           DEBUG_FREE(sortedlist29->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist31 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist31->id);
      free(params0.data);
      sortedlist31->refC--;
      if(sortedlist31->refC == 0){
           cell_t* cell11 = sortedlist31->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist31);
           DEBUG_FREE(sortedlist31->id);
      }
   }
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
   return sortedlist33;
}

