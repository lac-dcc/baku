#include "outs/4_8_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array16;
   if (pCounter > 0) {
      array16 = vars->data[--pCounter];
      array16->refC++;
      DEBUG_COPY(array16->id);
   } else {
      array16 = (array_t*)malloc(sizeof(array_t));
      array16->size = 305;
      array16->refC = 1;
      array16->id = 16;
      array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
      memset(array16->data, 0, array16->size*sizeof(unsigned int));
      DEBUG_NEW(array16->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      if(PATH0 & 1) {
         array_t* array17;
         if (pCounter > 0) {
            array17 = vars->data[--pCounter];
            array17->refC++;
            DEBUG_COPY(array17->id);
         } else {
            array17 = (array_t*)malloc(sizeof(array_t));
            array17->size = 925;
            array17->refC = 1;
            array17->id = 17;
            array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
            memset(array17->data, 0, array17->size*sizeof(unsigned int));
            DEBUG_NEW(array17->id);
         }
         unsigned int loop7 = 0;
         unsigned int loopLimit7 = (rand()%loopsFactor)/4 + 1;
         for(; loop7 < loopLimit7; loop7++) {
            for (int i = 0; i < array16->size; i++) {
               array16->data[i]--;
            }
            for (int i = 0; i < array17->size; i++) {
               if (array17->data[i] == 36) { 
                  return array17;
               }
            }
         }
         array17->refC--;
         if(array17->refC == 0) {
            free(array17->data);
            free(array17);
            DEBUG_FREE(array17->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array16;
         array_t* array18 = func16(&params0, loopsFactor);
         DEBUG_RETURN(array18->id);
         free(params0.data);
         array18->refC--;
         if(array18->refC == 0) {
            free(array18->data);
            free(array18);
            DEBUG_FREE(array18->id);
         }
      }
      array_t* array19;
      if (pCounter > 0) {
         array19 = vars->data[--pCounter];
         array19->refC++;
         DEBUG_COPY(array19->id);
      } else {
         array19 = (array_t*)malloc(sizeof(array_t));
         array19->size = 729;
         array19->refC = 1;
         array19->id = 19;
         array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
         memset(array19->data, 0, array19->size*sizeof(unsigned int));
         DEBUG_NEW(array19->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array16;
      params0.data[1] = array19;
      array_t* array20 = func17(&params0, loopsFactor);
      DEBUG_RETURN(array20->id);
      free(params0.data);
      for (int i = 0; i < array16->size; i++) {
         if (array16->data[i] == 95) { 
            return array16;
         }
      }
      array20->refC--;
      if(array20->refC == 0) {
         free(array20->data);
         free(array20);
         DEBUG_FREE(array20->id);
      }
      array19->refC--;
      if(array19->refC == 0) {
         free(array19->data);
         free(array19);
         DEBUG_FREE(array19->id);
      }
   }
   for (int i = 0; i < array16->size; i++) {
      array16->data[i]--;
   }
   for (int i = 0; i < array16->size; i++) {
      if (array16->data[i] == 14) { 
         return array16;
      }
   }
   return array16;
}

