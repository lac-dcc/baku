#include "outs/3_9_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 865;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   if(PATH0 & 1) {
      unsigned int loop14 = 0;
      unsigned int loopLimit14 = (rand()%loopsFactor)/2 + 1;
      for(; loop14 < loopLimit14; loop14++) {
         for (int i = 0; i < array29->size; i++) {
            array29->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array29;
      array_t* array30 = func8(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array30->id);
      free(params0.data);
      unsigned int loop15 = 0;
      unsigned int loopLimit15 = (rand()%loopsFactor)/2 + 1;
      for(; loop15 < loopLimit15; loop15++) {
         for (int i = 0; i < array29->size; i++) {
            array29->data[i]++;
         }
      }
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array29;
      params1.data[1] = array30;
      array_t* array31 = func5(&params1, loopsFactor);
      DEBUG_RETURN(array31->id);
      free(params1.data);
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
   else {
      array_t* array32;
      if (pCounter > 0) {
         array32 = vars->data[--pCounter];
         array32->refC++;
         DEBUG_COPY(array32->id);
      } else {
         array32 = (array_t*)malloc(sizeof(array_t));
         array32->size = 117;
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
         if (array32->data[i] == 81) { 
            return array32;
         }
      }
      for (int i = 0; i < array32->size; i++) {
         array32->data[i]--;
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array29;
      params0.data[1] = array32;
      array_t* array33 = func8(&params0, rng(), loopsFactor);
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
   unsigned int loop16 = 0;
   unsigned int loopLimit16 = (rand()%loopsFactor)/2 + 1;
   for(; loop16 < loopLimit16; loop16++) {
      for (int i = 0; i < array29->size; i++) {
         array29->data[i]++;
      }
      array_t* array34;
      if (pCounter > 0) {
         array34 = vars->data[--pCounter];
         array34->refC++;
         DEBUG_COPY(array34->id);
      } else {
         array34 = (array_t*)malloc(sizeof(array_t));
         array34->size = 856;
         array34->refC = 1;
         array34->id = 34;
         array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
         memset(array34->data, 0, array34->size*sizeof(unsigned int));
         DEBUG_NEW(array34->id);
      }
      for (int i = 0; i < array34->size; i++) {
         array34->data[i]++;
      }
      for (int i = 0; i < array34->size; i++) {
         if (array34->data[i] == 86) { 
            return array34;
         }
      }
      for (int i = 0; i < array34->size; i++) {
         array34->data[i]--;
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array29;
      params0.data[1] = array34;
      array_t* array35 = func8(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array35->id);
      free(params0.data);
      array35->refC--;
      if(array35->refC == 0) {
         free(array35->data);
         free(array35);
         DEBUG_FREE(array35->id);
      }
      array34->refC--;
      if(array34->refC == 0) {
         free(array34->data);
         free(array34);
         DEBUG_FREE(array34->id);
      }
   }
   return array29;
}

