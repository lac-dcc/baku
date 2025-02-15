#include "outs/4_7_array.h" 
array_t* func0(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop0 = 0;
      unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
      for(; loop0 < loopLimit0; loop0++) {
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
         for (int i = 0; i < array2->size; i++) {
            if (array2->data[i] == 21) { 
               return array2;
            }
         }
         array_t* array3;
         if (pCounter > 0) {
            array3 = vars->data[--pCounter];
            array3->refC++;
            DEBUG_COPY(array3->id);
         } else {
            array3 = (array_t*)malloc(sizeof(array_t));
            array3->size = 362;
            array3->refC = 1;
            array3->id = 3;
            array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
            memset(array3->data, 0, array3->size*sizeof(unsigned int));
            DEBUG_NEW(array3->id);
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array2;
         params0.data[1] = array3;
         array_t* array4 = func6(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array4->id);
         free(params0.data);
         array_t* array12;
         if (pCounter > 0) {
            array12 = vars->data[--pCounter];
            array12->refC++;
            DEBUG_COPY(array12->id);
         } else {
            array12 = (array_t*)malloc(sizeof(array_t));
            array12->size = 58;
            array12->refC = 1;
            array12->id = 12;
            array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
            memset(array12->data, 0, array12->size*sizeof(unsigned int));
            DEBUG_NEW(array12->id);
         }
         if(PATH0 & 2) {
            unsigned int loop3 = 0;
            unsigned int loopLimit3 = (rand()%loopsFactor)/2 + 1;
            for(; loop3 < loopLimit3; loop3++) {
               array_t* array13;
               if (pCounter > 0) {
                  array13 = vars->data[--pCounter];
                  array13->refC++;
                  DEBUG_COPY(array13->id);
               } else {
                  array13 = (array_t*)malloc(sizeof(array_t));
                  array13->size = 69;
                  array13->refC = 1;
                  array13->id = 13;
                  array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
                  memset(array13->data, 0, array13->size*sizeof(unsigned int));
                  DEBUG_NEW(array13->id);
               }
               for (int i = 0; i < array4->size; i++) {
                  if (array4->data[i] == 93) { 
                     return array4;
                  }
               }
               array13->refC--;
               if(array13->refC == 0) {
                  free(array13->data);
                  free(array13);
                  DEBUG_FREE(array13->id);
               }
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
               array14->size = 456;
               array14->refC = 1;
               array14->id = 14;
               array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
               memset(array14->data, 0, array14->size*sizeof(unsigned int));
               DEBUG_NEW(array14->id);
            }
            array_t* array15;
            if (pCounter > 0) {
               array15 = vars->data[--pCounter];
               array15->refC++;
               DEBUG_COPY(array15->id);
            } else {
               array15 = (array_t*)malloc(sizeof(array_t));
               array15->size = 11;
               array15->refC = 1;
               array15->id = 15;
               array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
               memset(array15->data, 0, array15->size*sizeof(unsigned int));
               DEBUG_NEW(array15->id);
            }
            array_t* array16;
            if (pCounter > 0) {
               array16 = vars->data[--pCounter];
               array16->refC++;
               DEBUG_COPY(array16->id);
            } else {
               array16 = (array_t*)malloc(sizeof(array_t));
               array16->size = 42;
               array16->refC = 1;
               array16->id = 16;
               array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
               memset(array16->data, 0, array16->size*sizeof(unsigned int));
               DEBUG_NEW(array16->id);
            }
            for (int i = 0; i < array3->size; i++) {
               array3->data[i]++;
            }
            unsigned int loop4 = 0;
            unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
            for(; loop4 < loopLimit4; loop4++) {
               for (int i = 0; i < array14->size; i++) {
                  array14->data[i]--;
               }
            }
            array_t_param params1;
            params1.size = 7;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array2;
            params1.data[1] = array3;
            params1.data[2] = array4;
            params1.data[3] = array12;
            params1.data[4] = array14;
            params1.data[5] = array15;
            params1.data[6] = array16;
            array_t* array17 = func10(&params1, loopsFactor);
            DEBUG_RETURN(array17->id);
            free(params1.data);
            array_t_param params2;
            params2.size = 8;
            params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
            params2.data[0] = array2;
            params2.data[1] = array3;
            params2.data[2] = array4;
            params2.data[3] = array12;
            params2.data[4] = array14;
            params2.data[5] = array15;
            params2.data[6] = array16;
            params2.data[7] = array17;
            array_t* array18 = func7(&params2, loopsFactor);
            DEBUG_RETURN(array18->id);
            free(params2.data);
            array18->refC--;
            if(array18->refC == 0) {
               free(array18->data);
               free(array18);
               DEBUG_FREE(array18->id);
            }
            array17->refC--;
            if(array17->refC == 0) {
               free(array17->data);
               free(array17);
               DEBUG_FREE(array17->id);
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
            array14->refC--;
            if(array14->refC == 0) {
               free(array14->data);
               free(array14);
               DEBUG_FREE(array14->id);
            }
         }
         for (int i = 0; i < array4->size; i++) {
            if (array4->data[i] == 70) { 
               return array4;
            }
         }
         array_t* array22;
         if (pCounter > 0) {
            array22 = vars->data[--pCounter];
            array22->refC++;
            DEBUG_COPY(array22->id);
         } else {
            array22 = (array_t*)malloc(sizeof(array_t));
            array22->size = 996;
            array22->refC = 1;
            array22->id = 22;
            array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
            memset(array22->data, 0, array22->size*sizeof(unsigned int));
            DEBUG_NEW(array22->id);
         }
         array_t* array23;
         if (pCounter > 0) {
            array23 = vars->data[--pCounter];
            array23->refC++;
            DEBUG_COPY(array23->id);
         } else {
            array23 = (array_t*)malloc(sizeof(array_t));
            array23->size = 281;
            array23->refC = 1;
            array23->id = 23;
            array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
            memset(array23->data, 0, array23->size*sizeof(unsigned int));
            DEBUG_NEW(array23->id);
         }
         for (int i = 0; i < array12->size; i++) {
            array12->data[i]++;
         }
         unsigned int loop5 = 0;
         unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
         for(; loop5 < loopLimit5; loop5++) {
            for (int i = 0; i < array12->size; i++) {
               array12->data[i]--;
            }
         }
         array_t_param params1;
         params1.size = 6;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array2;
         params1.data[1] = array3;
         params1.data[2] = array4;
         params1.data[3] = array12;
         params1.data[4] = array22;
         params1.data[5] = array23;
         array_t* array24 = func8(&params1, loopsFactor);
         DEBUG_RETURN(array24->id);
         free(params1.data);
         array24->refC--;
         if(array24->refC == 0) {
            free(array24->data);
            free(array24);
            DEBUG_FREE(array24->id);
         }
         array23->refC--;
         if(array23->refC == 0) {
            free(array23->data);
            free(array23);
            DEBUG_FREE(array23->id);
         }
         array22->refC--;
         if(array22->refC == 0) {
            free(array22->data);
            free(array22);
            DEBUG_FREE(array22->id);
         }
         array12->refC--;
         if(array12->refC == 0) {
            free(array12->data);
            free(array12);
            DEBUG_FREE(array12->id);
         }
         array4->refC--;
         if(array4->refC == 0) {
            free(array4->data);
            free(array4);
            DEBUG_FREE(array4->id);
         }
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
   }
   else {
      array_t* array26;
      if (pCounter > 0) {
         array26 = vars->data[--pCounter];
         array26->refC++;
         DEBUG_COPY(array26->id);
      } else {
         array26 = (array_t*)malloc(sizeof(array_t));
         array26->size = 582;
         array26->refC = 1;
         array26->id = 26;
         array26->data = (unsigned int*)malloc(array26->size*sizeof(unsigned int));
         memset(array26->data, 0, array26->size*sizeof(unsigned int));
         DEBUG_NEW(array26->id);
      }
      array_t* array27;
      if (pCounter > 0) {
         array27 = vars->data[--pCounter];
         array27->refC++;
         DEBUG_COPY(array27->id);
      } else {
         array27 = (array_t*)malloc(sizeof(array_t));
         array27->size = 545;
         array27->refC = 1;
         array27->id = 27;
         array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
         memset(array27->data, 0, array27->size*sizeof(unsigned int));
         DEBUG_NEW(array27->id);
      }
      array_t* array28;
      if (pCounter > 0) {
         array28 = vars->data[--pCounter];
         array28->refC++;
         DEBUG_COPY(array28->id);
      } else {
         array28 = (array_t*)malloc(sizeof(array_t));
         array28->size = 814;
         array28->refC = 1;
         array28->id = 28;
         array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
         memset(array28->data, 0, array28->size*sizeof(unsigned int));
         DEBUG_NEW(array28->id);
      }
      for (int i = 0; i < array26->size; i++) {
         array26->data[i]++;
      }
      unsigned int loop6 = 0;
      unsigned int loopLimit6 = (rand()%loopsFactor)/1 + 1;
      for(; loop6 < loopLimit6; loop6++) {
         for (int i = 0; i < array28->size; i++) {
            array28->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array26;
      params0.data[1] = array27;
      params0.data[2] = array28;
      array_t* array29 = func4(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array29->id);
      free(params0.data);
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array26;
      params1.data[1] = array27;
      params1.data[2] = array28;
      params1.data[3] = array29;
      array_t* array38 = func2(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array38->id);
      free(params1.data);
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
      array29->refC--;
      if(array29->refC == 0) {
         free(array29->data);
         free(array29);
         DEBUG_FREE(array29->id);
      }
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
      array27->refC--;
      if(array27->refC == 0) {
         free(array27->data);
         free(array27);
         DEBUG_FREE(array27->id);
      }
      array26->refC--;
      if(array26->refC == 0) {
         free(array26->data);
         free(array26);
         DEBUG_FREE(array26->id);
      }
   }
   array_t* array58;
   if (pCounter > 0) {
      array58 = vars->data[--pCounter];
      array58->refC++;
      DEBUG_COPY(array58->id);
   } else {
      array58 = (array_t*)malloc(sizeof(array_t));
      array58->size = 829;
      array58->refC = 1;
      array58->id = 58;
      array58->data = (unsigned int*)malloc(array58->size*sizeof(unsigned int));
      memset(array58->data, 0, array58->size*sizeof(unsigned int));
      DEBUG_NEW(array58->id);
   }
   return array58;
}

