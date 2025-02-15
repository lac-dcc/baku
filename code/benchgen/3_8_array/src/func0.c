#include "outs/3_8_array.h" 
array_t* func0(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array1;
   if (pCounter > 0) {
      array1 = vars->data[--pCounter];
      array1->refC++;
      DEBUG_COPY(array1->id);
   } else {
      array1 = (array_t*)malloc(sizeof(array_t));
      array1->size = 386;
      array1->refC = 1;
      array1->id = 1;
      array1->data = (unsigned int*)malloc(array1->size*sizeof(unsigned int));
      memset(array1->data, 0, array1->size*sizeof(unsigned int));
      DEBUG_NEW(array1->id);
   }
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      if(PATH0 & 1) {
         array_t* array2;
         if (pCounter > 0) {
            array2 = vars->data[--pCounter];
            array2->refC++;
            DEBUG_COPY(array2->id);
         } else {
            array2 = (array_t*)malloc(sizeof(array_t));
            array2->size = 492;
            array2->refC = 1;
            array2->id = 2;
            array2->data = (unsigned int*)malloc(array2->size*sizeof(unsigned int));
            memset(array2->data, 0, array2->size*sizeof(unsigned int));
            DEBUG_NEW(array2->id);
         }
         unsigned int loop2 = 0;
         unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
         for(; loop2 < loopLimit2; loop2++) {
            for (int i = 0; i < array2->size; i++) {
               array2->data[i]--;
            }
            for (int i = 0; i < array2->size; i++) {
               if (array2->data[i] == 62) { 
                  return array2;
               }
            }
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array1;
         params0.data[1] = array2;
         array_t* array3 = func10(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array3->id);
         free(params0.data);
         array3->refC--;
         if(array3->refC == 0) {
            free(array3->data);
            free(array3);
            DEBUG_FREE(array3->id);
         }
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array1;
         array_t* array10 = func4(&params0, loopsFactor);
         DEBUG_RETURN(array10->id);
         free(params0.data);
         array10->refC--;
         if(array10->refC == 0) {
            free(array10->data);
            free(array10);
            DEBUG_FREE(array10->id);
         }
      }
      array_t* array12;
      if (pCounter > 0) {
         array12 = vars->data[--pCounter];
         array12->refC++;
         DEBUG_COPY(array12->id);
      } else {
         array12 = (array_t*)malloc(sizeof(array_t));
         array12->size = 537;
         array12->refC = 1;
         array12->id = 12;
         array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
         memset(array12->data, 0, array12->size*sizeof(unsigned int));
         DEBUG_NEW(array12->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array1;
      params0.data[1] = array12;
      array_t* array13 = func5(&params0, loopsFactor);
      DEBUG_RETURN(array13->id);
      free(params0.data);
      if(PATH0 & 2) {
         array_t* array16;
         if (pCounter > 0) {
            array16 = vars->data[--pCounter];
            array16->refC++;
            DEBUG_COPY(array16->id);
         } else {
            array16 = (array_t*)malloc(sizeof(array_t));
            array16->size = 170;
            array16->refC = 1;
            array16->id = 16;
            array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
            memset(array16->data, 0, array16->size*sizeof(unsigned int));
            DEBUG_NEW(array16->id);
         }
         unsigned int loop5 = 0;
         unsigned int loopLimit5 = (rand()%loopsFactor)/3 + 1;
         for(; loop5 < loopLimit5; loop5++) {
            for (int i = 0; i < array1->size; i++) {
               array1->data[i]--;
            }
            for (int i = 0; i < array12->size; i++) {
               if (array12->data[i] == 5) { 
                  return array12;
               }
            }
         }
         array16->refC--;
         if(array16->refC == 0) {
            free(array16->data);
            free(array16);
            DEBUG_FREE(array16->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array12;
         params1.data[2] = array13;
         array_t* array17 = func14(&params1, loopsFactor);
         DEBUG_RETURN(array17->id);
         free(params1.data);
         array17->refC--;
         if(array17->refC == 0) {
            free(array17->data);
            free(array17);
            DEBUG_FREE(array17->id);
         }
      }
      for (int i = 0; i < array1->size; i++) {
         if (array1->data[i] == 95) { 
            return array1;
         }
      }
      array13->refC--;
      if(array13->refC == 0) {
         free(array13->data);
         free(array13);
         DEBUG_FREE(array13->id);
      }
      array12->refC--;
      if(array12->refC == 0) {
         free(array12->data);
         free(array12);
         DEBUG_FREE(array12->id);
      }
   }
   return array1;
}

