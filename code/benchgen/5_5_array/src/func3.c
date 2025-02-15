#include "outs/5_5_array.h" 
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
            array_t* array14;
            if (pCounter > 0) {
               array14 = vars->data[--pCounter];
               array14->refC++;
               DEBUG_COPY(array14->id);
            } else {
               array14 = (array_t*)malloc(sizeof(array_t));
               array14->size = 537;
               array14->refC = 1;
               array14->id = 14;
               array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
               memset(array14->data, 0, array14->size*sizeof(unsigned int));
               DEBUG_NEW(array14->id);
            }
            unsigned int loop9 = 0;
            unsigned int loopLimit9 = (rand()%loopsFactor)/5 + 1;
            for(; loop9 < loopLimit9; loop9++) {
               for (int i = 0; i < array14->size; i++) {
                  array14->data[i]++;
               }
               array_t_param params1;
               params1.size = 3;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array2;
               params1.data[1] = array3;
               params1.data[2] = array14;
               array_t* array15 = func4(&params1, loopsFactor);
               DEBUG_RETURN(array15->id);
               free(params1.data);
               for (int i = 0; i < array3->size; i++) {
                  if (array3->data[i] == 62) { 
                     return array3;
                  }
               }
               for (int i = 0; i < array14->size; i++) {
                  if (array14->data[i] == 96) { 
                     return array14;
                  }
               }
               array15->refC--;
               if(array15->refC == 0) {
                  free(array15->data);
                  free(array15);
                  DEBUG_FREE(array15->id);
               }
            }
            array14->refC--;
            if(array14->refC == 0) {
               free(array14->data);
               free(array14);
               DEBUG_FREE(array14->id);
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
      unsigned int loop11 = 0;
      unsigned int loopLimit11 = (rand()%loopsFactor)/3 + 1;
      for(; loop11 < loopLimit11; loop11++) {
         array_t* array18;
         if (pCounter > 0) {
            array18 = vars->data[--pCounter];
            array18->refC++;
            DEBUG_COPY(array18->id);
         } else {
            array18 = (array_t*)malloc(sizeof(array_t));
            array18->size = 281;
            array18->refC = 1;
            array18->id = 18;
            array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
            memset(array18->data, 0, array18->size*sizeof(unsigned int));
            DEBUG_NEW(array18->id);
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array18;
         array_t* array19 = func5(&params0, loopsFactor);
         DEBUG_RETURN(array19->id);
         free(params0.data);
         for (int i = 0; i < array19->size; i++) {
            if (array19->data[i] == 13) { 
               return array19;
            }
         }
         array_t* array21;
         if (pCounter > 0) {
            array21 = vars->data[--pCounter];
            array21->refC++;
            DEBUG_COPY(array21->id);
         } else {
            array21 = (array_t*)malloc(sizeof(array_t));
            array21->size = 857;
            array21->refC = 1;
            array21->id = 21;
            array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
            memset(array21->data, 0, array21->size*sizeof(unsigned int));
            DEBUG_NEW(array21->id);
         }
         unsigned int loop12 = 0;
         unsigned int loopLimit12 = (rand()%loopsFactor)/4 + 1;
         for(; loop12 < loopLimit12; loop12++) {
            for (int i = 0; i < array18->size; i++) {
               array18->data[i]++;
            }
            array_t* array22;
            if (pCounter > 0) {
               array22 = vars->data[--pCounter];
               array22->refC++;
               DEBUG_COPY(array22->id);
            } else {
               array22 = (array_t*)malloc(sizeof(array_t));
               array22->size = 895;
               array22->refC = 1;
               array22->id = 22;
               array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
               memset(array22->data, 0, array22->size*sizeof(unsigned int));
               DEBUG_NEW(array22->id);
            }
            for (int i = 0; i < array21->size; i++) {
               array21->data[i]--;
            }
            array22->refC--;
            if(array22->refC == 0) {
               free(array22->data);
               free(array22);
               DEBUG_FREE(array22->id);
            }
         }
         array_t* array23;
         if (pCounter > 0) {
            array23 = vars->data[--pCounter];
            array23->refC++;
            DEBUG_COPY(array23->id);
         } else {
            array23 = (array_t*)malloc(sizeof(array_t));
            array23->size = 545;
            array23->refC = 1;
            array23->id = 23;
            array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
            memset(array23->data, 0, array23->size*sizeof(unsigned int));
            DEBUG_NEW(array23->id);
         }
         unsigned int loop13 = 0;
         unsigned int loopLimit13 = (rand()%loopsFactor)/4 + 1;
         for(; loop13 < loopLimit13; loop13++) {
            for (int i = 0; i < array21->size; i++) {
               array21->data[i]--;
            }
         }
         for (int i = 0; i < array23->size; i++) {
            if (array23->data[i] == 34) { 
               return array23;
            }
         }
         array23->refC--;
         if(array23->refC == 0) {
            free(array23->data);
            free(array23);
            DEBUG_FREE(array23->id);
         }
         array21->refC--;
         if(array21->refC == 0) {
            free(array21->data);
            free(array21);
            DEBUG_FREE(array21->id);
         }
         array19->refC--;
         if(array19->refC == 0) {
            free(array19->data);
            free(array19);
            DEBUG_FREE(array19->id);
         }
         array18->refC--;
         if(array18->refC == 0) {
            free(array18->data);
            free(array18);
            DEBUG_FREE(array18->id);
         }
      }
   }
   array_t* array24;
   if (pCounter > 0) {
      array24 = vars->data[--pCounter];
      array24->refC++;
      DEBUG_COPY(array24->id);
   } else {
      array24 = (array_t*)malloc(sizeof(array_t));
      array24->size = 364;
      array24->refC = 1;
      array24->id = 24;
      array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
      memset(array24->data, 0, array24->size*sizeof(unsigned int));
      DEBUG_NEW(array24->id);
   }
   return array24;
}

