#include "outs/3_2_array.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      array_t* array3;
      if (pCounter > 0) {
         array3 = vars->data[--pCounter];
         array3->refC++;
         DEBUG_COPY(array3->id);
      } else {
         array3 = (array_t*)malloc(sizeof(array_t));
         array3->size = 763;
         array3->refC = 1;
         array3->id = 3;
         array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
         memset(array3->data, 0, array3->size*sizeof(unsigned int));
         DEBUG_NEW(array3->id);
      }
      if(PATH0 & 1) {
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
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array3;
         params0.data[1] = array4;
         array_t* array5 = func12(&params0, loopsFactor);
         DEBUG_RETURN(array5->id);
         free(params0.data);
         array_t* array7;
         if (pCounter > 0) {
            array7 = vars->data[--pCounter];
            array7->refC++;
            DEBUG_COPY(array7->id);
         } else {
            array7 = (array_t*)malloc(sizeof(array_t));
            array7->size = 567;
            array7->refC = 1;
            array7->id = 7;
            array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
            memset(array7->data, 0, array7->size*sizeof(unsigned int));
            DEBUG_NEW(array7->id);
         }
         array_t* array8;
         if (pCounter > 0) {
            array8 = vars->data[--pCounter];
            array8->refC++;
            DEBUG_COPY(array8->id);
         } else {
            array8 = (array_t*)malloc(sizeof(array_t));
            array8->size = 429;
            array8->refC = 1;
            array8->id = 8;
            array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
            memset(array8->data, 0, array8->size*sizeof(unsigned int));
            DEBUG_NEW(array8->id);
         }
         array8->refC--;
         if(array8->refC == 0) {
            free(array8->data);
            free(array8);
            DEBUG_FREE(array8->id);
         }
         array7->refC--;
         if(array7->refC == 0) {
            free(array7->data);
            free(array7);
            DEBUG_FREE(array7->id);
         }
         array5->refC--;
         if(array5->refC == 0) {
            free(array5->data);
            free(array5);
            DEBUG_FREE(array5->id);
         }
         array4->refC--;
         if(array4->refC == 0) {
            free(array4->data);
            free(array4);
            DEBUG_FREE(array4->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array3;
         array_t* array9 = func13(&params0, loopsFactor);
         DEBUG_RETURN(array9->id);
         free(params0.data);
         array_t* array11;
         if (pCounter > 0) {
            array11 = vars->data[--pCounter];
            array11->refC++;
            DEBUG_COPY(array11->id);
         } else {
            array11 = (array_t*)malloc(sizeof(array_t));
            array11->size = 802;
            array11->refC = 1;
            array11->id = 11;
            array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
            memset(array11->data, 0, array11->size*sizeof(unsigned int));
            DEBUG_NEW(array11->id);
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
      }
      if(PATH0 & 2) {
         array_t* array12;
         if (pCounter > 0) {
            array12 = vars->data[--pCounter];
            array12->refC++;
            DEBUG_COPY(array12->id);
         } else {
            array12 = (array_t*)malloc(sizeof(array_t));
            array12->size = 22;
            array12->refC = 1;
            array12->id = 12;
            array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
            memset(array12->data, 0, array12->size*sizeof(unsigned int));
            DEBUG_NEW(array12->id);
         }
         unsigned int loop3 = 0;
         unsigned int loopLimit3 = (rand()%loopsFactor)/3 + 1;
         for(; loop3 < loopLimit3; loop3++) {
            for (int i = 0; i < array3->size; i++) {
               array3->data[i]++;
            }
            for (int i = 0; i < array12->size; i++) {
               if (array12->data[i] == 67) { 
                  return array12;
               }
            }
            if(PATH0 & 4) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array3;
               params0.data[1] = array12;
               array_t* array13 = func14(&params0, loopsFactor);
               DEBUG_RETURN(array13->id);
               free(params0.data);
               array_t* array15;
               if (pCounter > 0) {
                  array15 = vars->data[--pCounter];
                  array15->refC++;
                  DEBUG_COPY(array15->id);
               } else {
                  array15 = (array_t*)malloc(sizeof(array_t));
                  array15->size = 421;
                  array15->refC = 1;
                  array15->id = 15;
                  array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
                  memset(array15->data, 0, array15->size*sizeof(unsigned int));
                  DEBUG_NEW(array15->id);
               }
               array15->refC--;
               if(array15->refC == 0) {
                  free(array15->data);
                  free(array15);
                  DEBUG_FREE(array15->id);
               }
               array13->refC--;
               if(array13->refC == 0) {
                  free(array13->data);
                  free(array13);
                  DEBUG_FREE(array13->id);
               }
            }
            else {
            }
         }
         array_t* array16;
         if (pCounter > 0) {
            array16 = vars->data[--pCounter];
            array16->refC++;
            DEBUG_COPY(array16->id);
         } else {
            array16 = (array_t*)malloc(sizeof(array_t));
            array16->size = 919;
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
         array12->refC--;
         if(array12->refC == 0) {
            free(array12->data);
            free(array12);
            DEBUG_FREE(array12->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array3;
         array_t* array17 = func15(&params0, loopsFactor);
         DEBUG_RETURN(array17->id);
         free(params0.data);
         for (int i = 0; i < array17->size; i++) {
            if (array17->data[i] == 26) { 
               return array17;
            }
         }
         unsigned int loop4 = 0;
         unsigned int loopLimit4 = (rand()%loopsFactor)/3 + 1;
         for(; loop4 < loopLimit4; loop4++) {
            for (int i = 0; i < array17->size; i++) {
               array17->data[i]--;
            }
            for (int i = 0; i < array3->size; i++) {
               if (array3->data[i] == 56) { 
                  return array3;
               }
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array3;
         params1.data[1] = array17;
         array_t* array19 = func16(&params1, loopsFactor);
         DEBUG_RETURN(array19->id);
         free(params1.data);
         array_t* array21;
         if (pCounter > 0) {
            array21 = vars->data[--pCounter];
            array21->refC++;
            DEBUG_COPY(array21->id);
         } else {
            array21 = (array_t*)malloc(sizeof(array_t));
            array21->size = 925;
            array21->refC = 1;
            array21->id = 21;
            array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
            memset(array21->data, 0, array21->size*sizeof(unsigned int));
            DEBUG_NEW(array21->id);
         }
         array_t* array22;
         if (pCounter > 0) {
            array22 = vars->data[--pCounter];
            array22->refC++;
            DEBUG_COPY(array22->id);
         } else {
            array22 = (array_t*)malloc(sizeof(array_t));
            array22->size = 84;
            array22->refC = 1;
            array22->id = 22;
            array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
            memset(array22->data, 0, array22->size*sizeof(unsigned int));
            DEBUG_NEW(array22->id);
         }
         array22->refC--;
         if(array22->refC == 0) {
            free(array22->data);
            free(array22);
            DEBUG_FREE(array22->id);
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
         array17->refC--;
         if(array17->refC == 0) {
            free(array17->data);
            free(array17);
            DEBUG_FREE(array17->id);
         }
      }
      for (int i = 0; i < array3->size; i++) {
         if (array3->data[i] == 36) { 
            return array3;
         }
      }
      array_t* array23;
      if (pCounter > 0) {
         array23 = vars->data[--pCounter];
         array23->refC++;
         DEBUG_COPY(array23->id);
      } else {
         array23 = (array_t*)malloc(sizeof(array_t));
         array23->size = 505;
         array23->refC = 1;
         array23->id = 23;
         array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
         memset(array23->data, 0, array23->size*sizeof(unsigned int));
         DEBUG_NEW(array23->id);
      }
      array23->refC--;
      if(array23->refC == 0) {
         free(array23->data);
         free(array23);
         DEBUG_FREE(array23->id);
      }
      array3->refC--;
      if(array3->refC == 0) {
         free(array3->data);
         free(array3);
         DEBUG_FREE(array3->id);
      }
   }
   array_t* array24;
   if (pCounter > 0) {
      array24 = vars->data[--pCounter];
      array24->refC++;
      DEBUG_COPY(array24->id);
   } else {
      array24 = (array_t*)malloc(sizeof(array_t));
      array24->size = 846;
      array24->refC = 1;
      array24->id = 24;
      array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
      memset(array24->data, 0, array24->size*sizeof(unsigned int));
      DEBUG_NEW(array24->id);
   }
   return array24;
}

