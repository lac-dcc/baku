#include "outs/5_2_array.h" 
array_t* func18(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array39;
   if (pCounter > 0) {
      array39 = vars->data[--pCounter];
      array39->refC++;
      DEBUG_COPY(array39->id);
   } else {
      array39 = (array_t*)malloc(sizeof(array_t));
      array39->size = 434;
      array39->refC = 1;
      array39->id = 39;
      array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
      memset(array39->data, 0, array39->size*sizeof(unsigned int));
      DEBUG_NEW(array39->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array39;
   array_t* array40 = func25(&params0, loopsFactor);
   DEBUG_RETURN(array40->id);
   free(params0.data);
   for (int i = 0; i < array40->size; i++) {
      if (array40->data[i] == 97) { 
         return array40;
      }
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      for (int i = 0; i < array39->size; i++) {
         array39->data[i]--;
      }
      for (int i = 0; i < array40->size; i++) {
         if (array40->data[i] == 92) { 
            return array40;
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array39;
   params1.data[1] = array40;
   array_t* array41 = func26(&params1, loopsFactor);
   DEBUG_RETURN(array41->id);
   free(params1.data);
   array_t* array42;
   if (pCounter > 0) {
      array42 = vars->data[--pCounter];
      array42->refC++;
      DEBUG_COPY(array42->id);
   } else {
      array42 = (array_t*)malloc(sizeof(array_t));
      array42->size = 301;
      array42->refC = 1;
      array42->id = 42;
      array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
      memset(array42->data, 0, array42->size*sizeof(unsigned int));
      DEBUG_NEW(array42->id);
   }
   array_t* array43;
   if (pCounter > 0) {
      array43 = vars->data[--pCounter];
      array43->refC++;
      DEBUG_COPY(array43->id);
   } else {
      array43 = (array_t*)malloc(sizeof(array_t));
      array43->size = 280;
      array43->refC = 1;
      array43->id = 43;
      array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
      memset(array43->data, 0, array43->size*sizeof(unsigned int));
      DEBUG_NEW(array43->id);
   }
   array43->refC--;
   if(array43->refC == 0) {
      free(array43->data);
      free(array43);
      DEBUG_FREE(array43->id);
   }
   array42->refC--;
   if(array42->refC == 0) {
      free(array42->data);
      free(array42);
      DEBUG_FREE(array42->id);
   }
   array41->refC--;
   if(array41->refC == 0) {
      free(array41->data);
      free(array41);
      DEBUG_FREE(array41->id);
   }
   array39->refC--;
   if(array39->refC == 0) {
      free(array39->data);
      free(array39);
      DEBUG_FREE(array39->id);
   }
   return array40;
}

