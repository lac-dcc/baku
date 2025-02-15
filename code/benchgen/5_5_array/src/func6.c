#include "outs/5_5_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
      for(; loop4 < loopLimit4; loop4++) {
         array_t* array4;
         if (pCounter > 0) {
            array4 = vars->data[--pCounter];
            array4->refC++;
            DEBUG_COPY(array4->id);
         } else {
            array4 = (array_t*)malloc(sizeof(array_t));
            array4->size = 926;
            array4->refC = 1;
            array4->id = 4;
            array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
            memset(array4->data, 0, array4->size*sizeof(unsigned int));
            DEBUG_NEW(array4->id);
         }
         unsigned int loop5 = 0;
         unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
         for(; loop5 < loopLimit5; loop5++) {
            array_t* array5;
            if (pCounter > 0) {
               array5 = vars->data[--pCounter];
               array5->refC++;
               DEBUG_COPY(array5->id);
            } else {
               array5 = (array_t*)malloc(sizeof(array_t));
               array5->size = 540;
               array5->refC = 1;
               array5->id = 5;
               array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
               memset(array5->data, 0, array5->size*sizeof(unsigned int));
               DEBUG_NEW(array5->id);
            }
            unsigned int loop6 = 0;
            unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
            for(; loop6 < loopLimit6; loop6++) {
               for (int i = 0; i < array4->size; i++) {
                  array4->data[i]++;
               }
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array4;
               params0.data[1] = array5;
               array_t* array6 = func7(&params0, loopsFactor);
               DEBUG_RETURN(array6->id);
               free(params0.data);
               for (int i = 0; i < array6->size; i++) {
                  if (array6->data[i] == 30) { 
                     return array6;
                  }
               }
               for (int i = 0; i < array6->size; i++) {
                  if (array6->data[i] == 23) { 
                     return array6;
                  }
               }
               array6->refC--;
               if(array6->refC == 0) {
                  free(array6->data);
                  free(array6);
                  DEBUG_FREE(array6->id);
               }
            }
            array5->refC--;
            if(array5->refC == 0) {
               free(array5->data);
               free(array5);
               DEBUG_FREE(array5->id);
            }
         }
         array4->refC--;
         if(array4->refC == 0) {
            free(array4->data);
            free(array4);
            DEBUG_FREE(array4->id);
         }
      }
   }
   else {
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/5 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         array_t* array8;
         if (pCounter > 0) {
            array8 = vars->data[--pCounter];
            array8->refC++;
            DEBUG_COPY(array8->id);
         } else {
            array8 = (array_t*)malloc(sizeof(array_t));
            array8->size = 67;
            array8->refC = 1;
            array8->id = 8;
            array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
            memset(array8->data, 0, array8->size*sizeof(unsigned int));
            DEBUG_NEW(array8->id);
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array8;
         array_t* array9 = func8(&params0, loopsFactor);
         DEBUG_RETURN(array9->id);
         free(params0.data);
         for (int i = 0; i < array9->size; i++) {
            if (array9->data[i] == 93) { 
               return array9;
            }
         }
         array_t* array11;
         if (pCounter > 0) {
            array11 = vars->data[--pCounter];
            array11->refC++;
            DEBUG_COPY(array11->id);
         } else {
            array11 = (array_t*)malloc(sizeof(array_t));
            array11->size = 456;
            array11->refC = 1;
            array11->id = 11;
            array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
            memset(array11->data, 0, array11->size*sizeof(unsigned int));
            DEBUG_NEW(array11->id);
         }
         unsigned int loop8 = 0;
         unsigned int loopLimit8 = (rand()%loopsFactor)/6 + 1;
         for(; loop8 < loopLimit8; loop8++) {
            for (int i = 0; i < array9->size; i++) {
               array9->data[i]++;
            }
            array_t* array12;
            if (pCounter > 0) {
               array12 = vars->data[--pCounter];
               array12->refC++;
               DEBUG_COPY(array12->id);
            } else {
               array12 = (array_t*)malloc(sizeof(array_t));
               array12->size = 42;
               array12->refC = 1;
               array12->id = 12;
               array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
               memset(array12->data, 0, array12->size*sizeof(unsigned int));
               DEBUG_NEW(array12->id);
            }
            for (int i = 0; i < array9->size; i++) {
               array9->data[i]--;
            }
            array12->refC--;
            if(array12->refC == 0) {
               free(array12->data);
               free(array12);
               DEBUG_FREE(array12->id);
            }
         }
         for (int i = 0; i < array8->size; i++) {
            if (array8->data[i] == 21) { 
               return array8;
            }
         }
         array11->refC--;
         if(array11->refC == 0) {
            free(array11->data);
            free(array11);
            DEBUG_FREE(array11->id);
         }
         array9->refC--;
         if(array9->refC == 0) {
            free(array9->data);
            free(array9);
            DEBUG_FREE(array9->id);
         }
         array8->refC--;
         if(array8->refC == 0) {
            free(array8->data);
            free(array8);
            DEBUG_FREE(array8->id);
         }
      }
   }
   array_t* array13;
   if (pCounter > 0) {
      array13 = vars->data[--pCounter];
      array13->refC++;
      DEBUG_COPY(array13->id);
   } else {
      array13 = (array_t*)malloc(sizeof(array_t));
      array13->size = 919;
      array13->refC = 1;
      array13->id = 13;
      array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
      memset(array13->data, 0, array13->size*sizeof(unsigned int));
      DEBUG_NEW(array13->id);
   }
   return array13;
}

