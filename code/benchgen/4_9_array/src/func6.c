#include "outs/4_9_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array26;
   if (pCounter > 0) {
      array26 = vars->data[--pCounter];
      array26->refC++;
      DEBUG_COPY(array26->id);
   } else {
      array26 = (array_t*)malloc(sizeof(array_t));
      array26->size = 378;
      array26->refC = 1;
      array26->id = 26;
      array26->data = (unsigned int*)malloc(array26->size*sizeof(unsigned int));
      memset(array26->data, 0, array26->size*sizeof(unsigned int));
      DEBUG_NEW(array26->id);
   }
   if(PATH0 & 1) {
      unsigned int loop13 = 0;
      unsigned int loopLimit13 = (rand()%loopsFactor)/2 + 1;
      for(; loop13 < loopLimit13; loop13++) {
         for (int i = 0; i < array26->size; i++) {
            array26->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array26;
      array_t* array27 = func13(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array27->id);
      free(params0.data);
      unsigned int loop14 = 0;
      unsigned int loopLimit14 = (rand()%loopsFactor)/2 + 1;
      for(; loop14 < loopLimit14; loop14++) {
         for (int i = 0; i < array26->size; i++) {
            array26->data[i]++;
         }
      }
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array26;
      params1.data[1] = array27;
      array_t* array28 = func10(&params1, loopsFactor);
      DEBUG_RETURN(array28->id);
      free(params1.data);
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
      array27->refC--;
      if(array27->refC == 0) {
         free(array27->data);
         free(array27);
         DEBUG_FREE(array27->id);
      }
   }
   else {
      array_t* array30;
      if (pCounter > 0) {
         array30 = vars->data[--pCounter];
         array30->refC++;
         DEBUG_COPY(array30->id);
      } else {
         array30 = (array_t*)malloc(sizeof(array_t));
         array30->size = 444;
         array30->refC = 1;
         array30->id = 30;
         array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
         memset(array30->data, 0, array30->size*sizeof(unsigned int));
         DEBUG_NEW(array30->id);
      }
      for (int i = 0; i < array30->size; i++) {
         array30->data[i]++;
      }
      for (int i = 0; i < array26->size; i++) {
         if (array26->data[i] == 29) { 
            return array26;
         }
      }
      for (int i = 0; i < array30->size; i++) {
         array30->data[i]--;
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array26;
      params0.data[1] = array30;
      array_t* array31 = func13(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array31->id);
      free(params0.data);
      array31->refC--;
      if(array31->refC == 0) {
         free(array31->data);
         free(array31);
         DEBUG_FREE(array31->id);
      }
      array30->refC--;
      if(array30->refC == 0) {
         free(array30->data);
         free(array30);
         DEBUG_FREE(array30->id);
      }
   }
   unsigned int loop15 = 0;
   unsigned int loopLimit15 = (rand()%loopsFactor)/2 + 1;
   for(; loop15 < loopLimit15; loop15++) {
      for (int i = 0; i < array26->size; i++) {
         array26->data[i]++;
      }
      array_t* array32;
      if (pCounter > 0) {
         array32 = vars->data[--pCounter];
         array32->refC++;
         DEBUG_COPY(array32->id);
      } else {
         array32 = (array_t*)malloc(sizeof(array_t));
         array32->size = 481;
         array32->refC = 1;
         array32->id = 32;
         array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
         memset(array32->data, 0, array32->size*sizeof(unsigned int));
         DEBUG_NEW(array32->id);
      }
      for (int i = 0; i < array32->size; i++) {
         array32->data[i]++;
      }
      for (int i = 0; i < array32->size; i++) {
         if (array32->data[i] == 27) { 
            return array32;
         }
      }
      for (int i = 0; i < array32->size; i++) {
         array32->data[i]--;
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array26;
      params0.data[1] = array32;
      array_t* array33 = func13(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array33->id);
      free(params0.data);
      array33->refC--;
      if(array33->refC == 0) {
         free(array33->data);
         free(array33);
         DEBUG_FREE(array33->id);
      }
      array32->refC--;
      if(array32->refC == 0) {
         free(array32->data);
         free(array32);
         DEBUG_FREE(array32->id);
      }
   }
   return array26;
}

