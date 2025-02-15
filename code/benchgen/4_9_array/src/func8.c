#include "outs/4_9_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array11;
   if (pCounter > 0) {
      array11 = vars->data[--pCounter];
      array11->refC++;
      DEBUG_COPY(array11->id);
   } else {
      array11 = (array_t*)malloc(sizeof(array_t));
      array11->size = 11;
      array11->refC = 1;
      array11->id = 11;
      array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
      memset(array11->data, 0, array11->size*sizeof(unsigned int));
      DEBUG_NEW(array11->id);
   }
   if(PATH0 & 1) {
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
      for(; loop4 < loopLimit4; loop4++) {
         for (int i = 0; i < array11->size; i++) {
            array11->data[i]--;
         }
      }
      unsigned int loop5 = 0;
      unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
      for(; loop5 < loopLimit5; loop5++) {
         for (int i = 0; i < array11->size; i++) {
            array11->data[i]++;
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array11;
      array_t* array12 = func12(&params0, loopsFactor);
      DEBUG_RETURN(array12->id);
      free(params0.data);
      array12->refC--;
      if(array12->refC == 0) {
         free(array12->data);
         free(array12);
         DEBUG_FREE(array12->id);
      }
   }
   else {
      array_t* array14;
      if (pCounter > 0) {
         array14 = vars->data[--pCounter];
         array14->refC++;
         DEBUG_COPY(array14->id);
      } else {
         array14 = (array_t*)malloc(sizeof(array_t));
         array14->size = 324;
         array14->refC = 1;
         array14->id = 14;
         array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
         memset(array14->data, 0, array14->size*sizeof(unsigned int));
         DEBUG_NEW(array14->id);
      }
      for (int i = 0; i < array14->size; i++) {
         array14->data[i]++;
      }
      for (int i = 0; i < array11->size; i++) {
         if (array11->data[i] == 13) { 
            return array11;
         }
      }
      for (int i = 0; i < array11->size; i++) {
         array11->data[i]--;
      }
      array14->refC--;
      if(array14->refC == 0) {
         free(array14->data);
         free(array14);
         DEBUG_FREE(array14->id);
      }
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      for (int i = 0; i < array11->size; i++) {
         array11->data[i]++;
      }
      array_t* array15;
      if (pCounter > 0) {
         array15 = vars->data[--pCounter];
         array15->refC++;
         DEBUG_COPY(array15->id);
      } else {
         array15 = (array_t*)malloc(sizeof(array_t));
         array15->size = 980;
         array15->refC = 1;
         array15->id = 15;
         array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
         memset(array15->data, 0, array15->size*sizeof(unsigned int));
         DEBUG_NEW(array15->id);
      }
      for (int i = 0; i < array11->size; i++) {
         array11->data[i]++;
      }
      for (int i = 0; i < array15->size; i++) {
         if (array15->data[i] == 62) { 
            return array15;
         }
      }
      for (int i = 0; i < array11->size; i++) {
         array11->data[i]--;
      }
      array15->refC--;
      if(array15->refC == 0) {
         free(array15->data);
         free(array15);
         DEBUG_FREE(array15->id);
      }
   }
   return array11;
}

