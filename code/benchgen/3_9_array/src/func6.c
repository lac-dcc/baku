#include "outs/3_9_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array15;
   if (pCounter > 0) {
      array15 = vars->data[--pCounter];
      array15->refC++;
      DEBUG_COPY(array15->id);
   } else {
      array15 = (array_t*)malloc(sizeof(array_t));
      array15->size = 925;
      array15->refC = 1;
      array15->id = 15;
      array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
      memset(array15->data, 0, array15->size*sizeof(unsigned int));
      DEBUG_NEW(array15->id);
   }
   if(PATH0 & 1) {
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/2 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         for (int i = 0; i < array15->size; i++) {
            array15->data[i]--;
         }
      }
      unsigned int loop8 = 0;
      unsigned int loopLimit8 = (rand()%loopsFactor)/2 + 1;
      for(; loop8 < loopLimit8; loop8++) {
         for (int i = 0; i < array15->size; i++) {
            array15->data[i]++;
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array15;
      array_t* array16 = func10(&params0, loopsFactor);
      DEBUG_RETURN(array16->id);
      free(params0.data);
      array16->refC--;
      if(array16->refC == 0) {
         free(array16->data);
         free(array16);
         DEBUG_FREE(array16->id);
      }
   }
   else {
      array_t* array18;
      if (pCounter > 0) {
         array18 = vars->data[--pCounter];
         array18->refC++;
         DEBUG_COPY(array18->id);
      } else {
         array18 = (array_t*)malloc(sizeof(array_t));
         array18->size = 124;
         array18->refC = 1;
         array18->id = 18;
         array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
         memset(array18->data, 0, array18->size*sizeof(unsigned int));
         DEBUG_NEW(array18->id);
      }
      for (int i = 0; i < array18->size; i++) {
         array18->data[i]++;
      }
      for (int i = 0; i < array15->size; i++) {
         if (array15->data[i] == 45) { 
            return array15;
         }
      }
      for (int i = 0; i < array15->size; i++) {
         array15->data[i]--;
      }
      array18->refC--;
      if(array18->refC == 0) {
         free(array18->data);
         free(array18);
         DEBUG_FREE(array18->id);
      }
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/2 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      for (int i = 0; i < array15->size; i++) {
         array15->data[i]++;
      }
      array_t* array19;
      if (pCounter > 0) {
         array19 = vars->data[--pCounter];
         array19->refC++;
         DEBUG_COPY(array19->id);
      } else {
         array19 = (array_t*)malloc(sizeof(array_t));
         array19->size = 434;
         array19->refC = 1;
         array19->id = 19;
         array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
         memset(array19->data, 0, array19->size*sizeof(unsigned int));
         DEBUG_NEW(array19->id);
      }
      for (int i = 0; i < array15->size; i++) {
         array15->data[i]++;
      }
      for (int i = 0; i < array19->size; i++) {
         if (array19->data[i] == 50) { 
            return array19;
         }
      }
      for (int i = 0; i < array19->size; i++) {
         array19->data[i]--;
      }
      array19->refC--;
      if(array19->refC == 0) {
         free(array19->data);
         free(array19);
         DEBUG_FREE(array19->id);
      }
   }
   return array15;
}

