#include "outs/2_2_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array14;
   if (pCounter > 0) {
      array14 = vars->data[--pCounter];
      array14->refC++;
      DEBUG_COPY(array14->id);
   } else {
      array14 = (array_t*)malloc(sizeof(array_t));
      array14->size = 11;
      array14->refC = 1;
      array14->id = 14;
      array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
      memset(array14->data, 0, array14->size*sizeof(unsigned int));
      DEBUG_NEW(array14->id);
   }
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      for (int i = 0; i < array14->size; i++) {
         array14->data[i]++;
      }
      for (int i = 0; i < array14->size; i++) {
         if (array14->data[i] == 73) { 
            return array14;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array14;
         array_t* array15 = func7(&params0, loopsFactor);
         DEBUG_RETURN(array15->id);
         free(params0.data);
         array_t* array16;
         if (pCounter > 0) {
            array16 = vars->data[--pCounter];
            array16->refC++;
            DEBUG_COPY(array16->id);
         } else {
            array16 = (array_t*)malloc(sizeof(array_t));
            array16->size = 784;
            array16->refC = 1;
            array16->id = 16;
            array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
            memset(array16->data, 0, array16->size*sizeof(unsigned int));
            DEBUG_NEW(array16->id);
         }
         array16->refC--;
         if(array16->refC == 0) {
            free(array16->data);
            free(array16);
            DEBUG_FREE(array16->id);
         }
         array15->refC--;
         if(array15->refC == 0) {
            free(array15->data);
            free(array15);
            DEBUG_FREE(array15->id);
         }
      }
      else {
      }
   }
   array_t* array17;
   if (pCounter > 0) {
      array17 = vars->data[--pCounter];
      array17->refC++;
      DEBUG_COPY(array17->id);
   } else {
      array17 = (array_t*)malloc(sizeof(array_t));
      array17->size = 537;
      array17->refC = 1;
      array17->id = 17;
      array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
      memset(array17->data, 0, array17->size*sizeof(unsigned int));
      DEBUG_NEW(array17->id);
   }
   array17->refC--;
   if(array17->refC == 0) {
      free(array17->data);
      free(array17);
      DEBUG_FREE(array17->id);
   }
   return array14;
}

