#include "outs/3_5_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop2 = 0;
      unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
      for(; loop2 < loopLimit2; loop2++) {
         array_t* array2;
         if (pCounter > 0) {
            array2 = vars->data[--pCounter];
            array2->refC++;
            DEBUG_COPY(array2->id);
         } else {
            array2 = (array_t*)malloc(sizeof(array_t));
            array2->size = 362;
            array2->refC = 1;
            array2->id = 2;
            array2->data = (unsigned int*)malloc(array2->size*sizeof(unsigned int));
            memset(array2->data, 0, array2->size*sizeof(unsigned int));
            DEBUG_NEW(array2->id);
         }
         unsigned int loop3 = 0;
         unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
         for(; loop3 < loopLimit3; loop3++) {
            array_t* array3;
            if (pCounter > 0) {
               array3 = vars->data[--pCounter];
               array3->refC++;
               DEBUG_COPY(array3->id);
            } else {
               array3 = (array_t*)malloc(sizeof(array_t));
               array3->size = 27;
               array3->refC = 1;
               array3->id = 3;
               array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
               memset(array3->data, 0, array3->size*sizeof(unsigned int));
               DEBUG_NEW(array3->id);
            }
            unsigned int loop4 = 0;
            unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
            for(; loop4 < loopLimit4; loop4++) {
               for (int i = 0; i < array2->size; i++) {
                  array2->data[i]++;
               }
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array2;
               params0.data[1] = array3;
               array_t* array4 = func4(&params0, loopsFactor);
               DEBUG_RETURN(array4->id);
               free(params0.data);
               for (int i = 0; i < array3->size; i++) {
                  if (array3->data[i] == 11) { 
                     return array3;
                  }
               }
               for (int i = 0; i < array4->size; i++) {
                  if (array4->data[i] == 67) { 
                     return array4;
                  }
               }
               array4->refC--;
               if(array4->refC == 0) {
                  free(array4->data);
                  free(array4);
                  DEBUG_FREE(array4->id);
               }
            }
            array3->refC--;
            if(array3->refC == 0) {
               free(array3->data);
               free(array3);
               DEBUG_FREE(array3->id);
            }
         }
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
   }
   else {
      unsigned int loop5 = 0;
      unsigned int loopLimit5 = (rand()%loopsFactor)/3 + 1;
      for(; loop5 < loopLimit5; loop5++) {
         array_t* array6;
         if (pCounter > 0) {
            array6 = vars->data[--pCounter];
            array6->refC++;
            DEBUG_COPY(array6->id);
         } else {
            array6 = (array_t*)malloc(sizeof(array_t));
            array6->size = 429;
            array6->refC = 1;
            array6->id = 6;
            array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
            memset(array6->data, 0, array6->size*sizeof(unsigned int));
            DEBUG_NEW(array6->id);
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array6;
         array_t* array7 = func5(&params0, loopsFactor);
         DEBUG_RETURN(array7->id);
         free(params0.data);
         for (int i = 0; i < array7->size; i++) {
            if (array7->data[i] == 2) { 
               return array7;
            }
         }
         array_t* array9;
         if (pCounter > 0) {
            array9 = vars->data[--pCounter];
            array9->refC++;
            DEBUG_COPY(array9->id);
         } else {
            array9 = (array_t*)malloc(sizeof(array_t));
            array9->size = 22;
            array9->refC = 1;
            array9->id = 9;
            array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
            memset(array9->data, 0, array9->size*sizeof(unsigned int));
            DEBUG_NEW(array9->id);
         }
         unsigned int loop6 = 0;
         unsigned int loopLimit6 = (rand()%loopsFactor)/4 + 1;
         for(; loop6 < loopLimit6; loop6++) {
            for (int i = 0; i < array6->size; i++) {
               array6->data[i]++;
            }
            array_t* array10;
            if (pCounter > 0) {
               array10 = vars->data[--pCounter];
               array10->refC++;
               DEBUG_COPY(array10->id);
            } else {
               array10 = (array_t*)malloc(sizeof(array_t));
               array10->size = 69;
               array10->refC = 1;
               array10->id = 10;
               array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
               memset(array10->data, 0, array10->size*sizeof(unsigned int));
               DEBUG_NEW(array10->id);
            }
            for (int i = 0; i < array10->size; i++) {
               array10->data[i]--;
            }
            array10->refC--;
            if(array10->refC == 0) {
               free(array10->data);
               free(array10);
               DEBUG_FREE(array10->id);
            }
         }
         for (int i = 0; i < array7->size; i++) {
            if (array7->data[i] == 56) { 
               return array7;
            }
         }
         array9->refC--;
         if(array9->refC == 0) {
            free(array9->data);
            free(array9);
            DEBUG_FREE(array9->id);
         }
         array7->refC--;
         if(array7->refC == 0) {
            free(array7->data);
            free(array7);
            DEBUG_FREE(array7->id);
         }
         array6->refC--;
         if(array6->refC == 0) {
            free(array6->data);
            free(array6);
            DEBUG_FREE(array6->id);
         }
      }
   }
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
   return array11;
}

