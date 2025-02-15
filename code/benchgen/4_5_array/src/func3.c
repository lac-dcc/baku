#include "outs/4_5_array.h" 
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
            array_t_param params0;
            params0.size = 1;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array2;
            array_t* array3 = func6(&params0, rng(), loopsFactor);
            DEBUG_RETURN(array3->id);
            free(params0.data);
            array_t* array7;
            if (pCounter > 0) {
               array7 = vars->data[--pCounter];
               array7->refC++;
               DEBUG_COPY(array7->id);
            } else {
               array7 = (array_t*)malloc(sizeof(array_t));
               array7->size = 736;
               array7->refC = 1;
               array7->id = 7;
               array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
               memset(array7->data, 0, array7->size*sizeof(unsigned int));
               DEBUG_NEW(array7->id);
            }
            unsigned int loop6 = 0;
            unsigned int loopLimit6 = (rand()%loopsFactor)/5 + 1;
            for(; loop6 < loopLimit6; loop6++) {
               for (int i = 0; i < array7->size; i++) {
                  array7->data[i]++;
               }
               array_t_param params1;
               params1.size = 3;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array2;
               params1.data[1] = array3;
               params1.data[2] = array7;
               array_t* array8 = func4(&params1, loopsFactor);
               DEBUG_RETURN(array8->id);
               free(params1.data);
               for (int i = 0; i < array8->size; i++) {
                  if (array8->data[i] == 29) { 
                     return array8;
                  }
               }
               for (int i = 0; i < array7->size; i++) {
                  if (array7->data[i] == 22) { 
                     return array7;
                  }
               }
               array8->refC--;
               if(array8->refC == 0) {
                  free(array8->data);
                  free(array8);
                  DEBUG_FREE(array8->id);
               }
            }
            array7->refC--;
            if(array7->refC == 0) {
               free(array7->data);
               free(array7);
               DEBUG_FREE(array7->id);
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
      unsigned int loop8 = 0;
      unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
      for(; loop8 < loopLimit8; loop8++) {
         array_t* array11;
         if (pCounter > 0) {
            array11 = vars->data[--pCounter];
            array11->refC++;
            DEBUG_COPY(array11->id);
         } else {
            array11 = (array_t*)malloc(sizeof(array_t));
            array11->size = 58;
            array11->refC = 1;
            array11->id = 11;
            array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
            memset(array11->data, 0, array11->size*sizeof(unsigned int));
            DEBUG_NEW(array11->id);
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array11;
         array_t* array12 = func5(&params0, loopsFactor);
         DEBUG_RETURN(array12->id);
         free(params0.data);
         for (int i = 0; i < array12->size; i++) {
            if (array12->data[i] == 21) { 
               return array12;
            }
         }
         array_t* array14;
         if (pCounter > 0) {
            array14 = vars->data[--pCounter];
            array14->refC++;
            DEBUG_COPY(array14->id);
         } else {
            array14 = (array_t*)malloc(sizeof(array_t));
            array14->size = 919;
            array14->refC = 1;
            array14->id = 14;
            array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
            memset(array14->data, 0, array14->size*sizeof(unsigned int));
            DEBUG_NEW(array14->id);
         }
         unsigned int loop9 = 0;
         unsigned int loopLimit9 = (rand()%loopsFactor)/4 + 1;
         for(; loop9 < loopLimit9; loop9++) {
            for (int i = 0; i < array14->size; i++) {
               array14->data[i]++;
            }
            array_t* array15;
            if (pCounter > 0) {
               array15 = vars->data[--pCounter];
               array15->refC++;
               DEBUG_COPY(array15->id);
            } else {
               array15 = (array_t*)malloc(sizeof(array_t));
               array15->size = 537;
               array15->refC = 1;
               array15->id = 15;
               array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
               memset(array15->data, 0, array15->size*sizeof(unsigned int));
               DEBUG_NEW(array15->id);
            }
            for (int i = 0; i < array14->size; i++) {
               array14->data[i]--;
            }
            array15->refC--;
            if(array15->refC == 0) {
               free(array15->data);
               free(array15);
               DEBUG_FREE(array15->id);
            }
         }
         array_t* array16;
         if (pCounter > 0) {
            array16 = vars->data[--pCounter];
            array16->refC++;
            DEBUG_COPY(array16->id);
         } else {
            array16 = (array_t*)malloc(sizeof(array_t));
            array16->size = 324;
            array16->refC = 1;
            array16->id = 16;
            array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
            memset(array16->data, 0, array16->size*sizeof(unsigned int));
            DEBUG_NEW(array16->id);
         }
         unsigned int loop10 = 0;
         unsigned int loopLimit10 = (rand()%loopsFactor)/4 + 1;
         for(; loop10 < loopLimit10; loop10++) {
            for (int i = 0; i < array16->size; i++) {
               array16->data[i]--;
            }
         }
         for (int i = 0; i < array14->size; i++) {
            if (array14->data[i] == 13) { 
               return array14;
            }
         }
         array16->refC--;
         if(array16->refC == 0) {
            free(array16->data);
            free(array16);
            DEBUG_FREE(array16->id);
         }
         array14->refC--;
         if(array14->refC == 0) {
            free(array14->data);
            free(array14);
            DEBUG_FREE(array14->id);
         }
         array12->refC--;
         if(array12->refC == 0) {
            free(array12->data);
            free(array12);
            DEBUG_FREE(array12->id);
         }
         array11->refC--;
         if(array11->refC == 0) {
            free(array11->data);
            free(array11);
            DEBUG_FREE(array11->id);
         }
      }
   }
   array_t* array17;
   if (pCounter > 0) {
      array17 = vars->data[--pCounter];
      array17->refC++;
      DEBUG_COPY(array17->id);
   } else {
      array17 = (array_t*)malloc(sizeof(array_t));
      array17->size = 526;
      array17->refC = 1;
      array17->id = 17;
      array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
      memset(array17->data, 0, array17->size*sizeof(unsigned int));
      DEBUG_NEW(array17->id);
   }
   return array17;
}

