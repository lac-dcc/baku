#include "outs/2_9_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array17;
   if (pCounter > 0) {
      array17 = vars->data[--pCounter];
      array17->refC++;
      DEBUG_COPY(array17->id);
   } else {
      array17 = (array_t*)malloc(sizeof(array_t));
      array17->size = 313;
      array17->refC = 1;
      array17->id = 17;
      array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
      memset(array17->data, 0, array17->size*sizeof(unsigned int));
      DEBUG_NEW(array17->id);
   }
   if(PATH0 & 1) {
      unsigned int loop8 = 0;
      unsigned int loopLimit8 = (rand()%loopsFactor)/2 + 1;
      for(; loop8 < loopLimit8; loop8++) {
         for (int i = 0; i < array17->size; i++) {
            array17->data[i]--;
         }
      }
      unsigned int loop9 = 0;
      unsigned int loopLimit9 = (rand()%loopsFactor)/2 + 1;
      for(; loop9 < loopLimit9; loop9++) {
         for (int i = 0; i < array17->size; i++) {
            array17->data[i]++;
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array17;
      array_t* array18 = func5(&params0, loopsFactor);
      DEBUG_RETURN(array18->id);
      free(params0.data);
      array18->refC--;
      if(array18->refC == 0) {
         free(array18->data);
         free(array18);
         DEBUG_FREE(array18->id);
      }
   }
   else {
      array_t* array19;
      if (pCounter > 0) {
         array19 = vars->data[--pCounter];
         array19->refC++;
         DEBUG_COPY(array19->id);
      } else {
         array19 = (array_t*)malloc(sizeof(array_t));
         array19->size = 545;
         array19->refC = 1;
         array19->id = 19;
         array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
         memset(array19->data, 0, array19->size*sizeof(unsigned int));
         DEBUG_NEW(array19->id);
      }
      for (int i = 0; i < array17->size; i++) {
         array17->data[i]++;
      }
      for (int i = 0; i < array19->size; i++) {
         if (array19->data[i] == 34) { 
            return array19;
         }
      }
      for (int i = 0; i < array17->size; i++) {
         array17->data[i]--;
      }
      array19->refC--;
      if(array19->refC == 0) {
         free(array19->data);
         free(array19);
         DEBUG_FREE(array19->id);
      }
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/2 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      for (int i = 0; i < array17->size; i++) {
         array17->data[i]++;
      }
      array_t* array20;
      if (pCounter > 0) {
         array20 = vars->data[--pCounter];
         array20->refC++;
         DEBUG_COPY(array20->id);
      } else {
         array20 = (array_t*)malloc(sizeof(array_t));
         array20->size = 750;
         array20->refC = 1;
         array20->id = 20;
         array20->data = (unsigned int*)malloc(array20->size*sizeof(unsigned int));
         memset(array20->data, 0, array20->size*sizeof(unsigned int));
         DEBUG_NEW(array20->id);
      }
      for (int i = 0; i < array20->size; i++) {
         array20->data[i]++;
      }
      for (int i = 0; i < array17->size; i++) {
         if (array17->data[i] == 76) { 
            return array17;
         }
      }
      for (int i = 0; i < array17->size; i++) {
         array17->data[i]--;
      }
      array20->refC--;
      if(array20->refC == 0) {
         free(array20->data);
         free(array20);
         DEBUG_FREE(array20->id);
      }
   }
   return array17;
}

