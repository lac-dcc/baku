#include "outs/5_9_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array59;
   if (pCounter > 0) {
      array59 = vars->data[--pCounter];
      array59->refC++;
      DEBUG_COPY(array59->id);
   } else {
      array59 = (array_t*)malloc(sizeof(array_t));
      array59->size = 917;
      array59->refC = 1;
      array59->id = 59;
      array59->data = (unsigned int*)malloc(array59->size*sizeof(unsigned int));
      memset(array59->data, 0, array59->size*sizeof(unsigned int));
      DEBUG_NEW(array59->id);
   }
   for (int i = 0; i < array59->size; i++) {
      array59->data[i]++;
   }
   for (int i = 0; i < array59->size; i++) {
      if (array59->data[i] == 43) { 
         return array59;
      }
   }
   for (int i = 0; i < array59->size; i++) {
      array59->data[i]--;
   }
   array_t* array60;
   if (pCounter > 0) {
      array60 = vars->data[--pCounter];
      array60->refC++;
      DEBUG_COPY(array60->id);
   } else {
      array60 = (array_t*)malloc(sizeof(array_t));
      array60->size = 183;
      array60->refC = 1;
      array60->id = 60;
      array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
      memset(array60->data, 0, array60->size*sizeof(unsigned int));
      DEBUG_NEW(array60->id);
   }
   if(PATH0 & 1) {
      unsigned int loop26 = 0;
      unsigned int loopLimit26 = (rand()%loopsFactor)/2 + 1;
      for(; loop26 < loopLimit26; loop26++) {
         array_t* array61;
         if (pCounter > 0) {
            array61 = vars->data[--pCounter];
            array61->refC++;
            DEBUG_COPY(array61->id);
         } else {
            array61 = (array_t*)malloc(sizeof(array_t));
            array61->size = 490;
            array61->refC = 1;
            array61->id = 61;
            array61->data = (unsigned int*)malloc(array61->size*sizeof(unsigned int));
            memset(array61->data, 0, array61->size*sizeof(unsigned int));
            DEBUG_NEW(array61->id);
         }
         for (int i = 0; i < array61->size; i++) {
            array61->data[i]--;
         }
         for (int i = 0; i < array60->size; i++) {
            if (array60->data[i] == 25) { 
               return array60;
            }
         }
         array61->refC--;
         if(array61->refC == 0) {
            free(array61->data);
            free(array61);
            DEBUG_FREE(array61->id);
         }
      }
   }
   else {
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array59;
      params0.data[1] = array60;
      array_t* array62 = func11(&params0, loopsFactor);
      DEBUG_RETURN(array62->id);
      free(params0.data);
      array62->refC--;
      if(array62->refC == 0) {
         free(array62->data);
         free(array62);
         DEBUG_FREE(array62->id);
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array59;
   params0.data[1] = array60;
   array_t* array63 = func8(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array63->id);
   free(params0.data);
   array60->refC--;
   if(array60->refC == 0) {
      free(array60->data);
      free(array60);
      DEBUG_FREE(array60->id);
   }
   array59->refC--;
   if(array59->refC == 0) {
      free(array59->data);
      free(array59);
      DEBUG_FREE(array59->id);
   }
   return array63;
}

