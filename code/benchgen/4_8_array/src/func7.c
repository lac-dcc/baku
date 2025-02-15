#include "outs/4_8_array.h" 
array_t* func7(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop12 = 0;
   unsigned int loopLimit12 = (rand()%loopsFactor)/2 + 1;
   for(; loop12 < loopLimit12; loop12++) {
      if(PATH0 & 1) {
         array_t* array39;
         if (pCounter > 0) {
            array39 = vars->data[--pCounter];
            array39->refC++;
            DEBUG_COPY(array39->id);
         } else {
            array39 = (array_t*)malloc(sizeof(array_t));
            array39->size = 732;
            array39->refC = 1;
            array39->id = 39;
            array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
            memset(array39->data, 0, array39->size*sizeof(unsigned int));
            DEBUG_NEW(array39->id);
         }
         unsigned int loop13 = 0;
         unsigned int loopLimit13 = (rand()%loopsFactor)/3 + 1;
         for(; loop13 < loopLimit13; loop13++) {
            for (int i = 0; i < array39->size; i++) {
               array39->data[i]--;
            }
            for (int i = 0; i < array39->size; i++) {
               if (array39->data[i] == 19) { 
                  return array39;
               }
            }
         }
         array39->refC--;
         if(array39->refC == 0) {
            free(array39->data);
            free(array39);
            DEBUG_FREE(array39->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 0;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         array_t* array40 = func16(&params0, loopsFactor);
         DEBUG_RETURN(array40->id);
         free(params0.data);
         array40->refC--;
         if(array40->refC == 0) {
            free(array40->data);
            free(array40);
            DEBUG_FREE(array40->id);
         }
      }
      array_t* array41;
      if (pCounter > 0) {
         array41 = vars->data[--pCounter];
         array41->refC++;
         DEBUG_COPY(array41->id);
      } else {
         array41 = (array_t*)malloc(sizeof(array_t));
         array41->size = 708;
         array41->refC = 1;
         array41->id = 41;
         array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
         memset(array41->data, 0, array41->size*sizeof(unsigned int));
         DEBUG_NEW(array41->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array41;
      array_t* array42 = func17(&params0, loopsFactor);
      DEBUG_RETURN(array42->id);
      free(params0.data);
      for (int i = 0; i < array42->size; i++) {
         if (array42->data[i] == 96) { 
            return array42;
         }
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
   }
   array_t* array43;
   if (pCounter > 0) {
      array43 = vars->data[--pCounter];
      array43->refC++;
      DEBUG_COPY(array43->id);
   } else {
      array43 = (array_t*)malloc(sizeof(array_t));
      array43->size = 723;
      array43->refC = 1;
      array43->id = 43;
      array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
      memset(array43->data, 0, array43->size*sizeof(unsigned int));
      DEBUG_NEW(array43->id);
   }
   return array43;
}

