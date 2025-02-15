#include "outs/2_2_array.h" 
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
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      for (int i = 0; i < array1->size; i++) {
         array1->data[i]++;
      }
      for (int i = 0; i < array1->size; i++) {
         if (array1->data[i] == 21) { 
            return array1;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array1;
         array_t* array2 = func2(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array2->id);
         free(params0.data);
         array_t* array6;
         if (pCounter > 0) {
            array6 = vars->data[--pCounter];
            array6->refC++;
            DEBUG_COPY(array6->id);
         } else {
            array6 = (array_t*)malloc(sizeof(array_t));
            array6->size = 211;
            array6->refC = 1;
            array6->id = 6;
            array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
            memset(array6->data, 0, array6->size*sizeof(unsigned int));
            DEBUG_NEW(array6->id);
         }
         array6->refC--;
         if(array6->refC == 0) {
            free(array6->data);
            free(array6);
            DEBUG_FREE(array6->id);
         }
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
      else {
         array_t* array7;
         if (pCounter > 0) {
            array7 = vars->data[--pCounter];
            array7->refC++;
            DEBUG_COPY(array7->id);
         } else {
            array7 = (array_t*)malloc(sizeof(array_t));
            array7->size = 368;
            array7->refC = 1;
            array7->id = 7;
            array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
            memset(array7->data, 0, array7->size*sizeof(unsigned int));
            DEBUG_NEW(array7->id);
         }
         unsigned int loop2 = 0;
         unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
         for(; loop2 < loopLimit2; loop2++) {
            for (int i = 0; i < array7->size; i++) {
               array7->data[i]++;
            }
            for (int i = 0; i < array7->size; i++) {
               if (array7->data[i] == 82) { 
                  return array7;
               }
            }
            if(PATH0 & 2) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array1;
               params0.data[1] = array7;
               array_t* array8 = func7(&params0, loopsFactor);
               DEBUG_RETURN(array8->id);
               free(params0.data);
               array_t* array10;
               if (pCounter > 0) {
                  array10 = vars->data[--pCounter];
                  array10->refC++;
                  DEBUG_COPY(array10->id);
               } else {
                  array10 = (array_t*)malloc(sizeof(array_t));
                  array10->size = 802;
                  array10->refC = 1;
                  array10->id = 10;
                  array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
                  memset(array10->data, 0, array10->size*sizeof(unsigned int));
                  DEBUG_NEW(array10->id);
               }
               array10->refC--;
               if(array10->refC == 0) {
                  free(array10->data);
                  free(array10);
                  DEBUG_FREE(array10->id);
               }
               array8->refC--;
               if(array8->refC == 0) {
                  free(array8->data);
                  free(array8);
                  DEBUG_FREE(array8->id);
               }
            }
            else {
            }
         }
         array_t* array11;
         if (pCounter > 0) {
            array11 = vars->data[--pCounter];
            array11->refC++;
            DEBUG_COPY(array11->id);
         } else {
            array11 = (array_t*)malloc(sizeof(array_t));
            array11->size = 22;
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
         array7->refC--;
         if(array7->refC == 0) {
            free(array7->data);
            free(array7);
            DEBUG_FREE(array7->id);
         }
      }
   }
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
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array1;
      params0.data[1] = array12;
      array_t* array13 = func3(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array13->id);
      free(params0.data);
      for (int i = 0; i < array13->size; i++) {
         if (array13->data[i] == 15) { 
            return array13;
         }
      }
      unsigned int loop5 = 0;
      unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
      for(; loop5 < loopLimit5; loop5++) {
         for (int i = 0; i < array1->size; i++) {
            array1->data[i]--;
         }
         for (int i = 0; i < array13->size; i++) {
            if (array13->data[i] == 26) { 
               return array13;
            }
         }
         if(PATH0 & 4) {
            array_t* array18;
            if (pCounter > 0) {
               array18 = vars->data[--pCounter];
               array18->refC++;
               DEBUG_COPY(array18->id);
            } else {
               array18 = (array_t*)malloc(sizeof(array_t));
               array18->size = 91;
               array18->refC = 1;
               array18->id = 18;
               array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
               memset(array18->data, 0, array18->size*sizeof(unsigned int));
               DEBUG_NEW(array18->id);
            }
            array_t_param params1;
            params1.size = 4;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array1;
            params1.data[1] = array12;
            params1.data[2] = array13;
            params1.data[3] = array18;
            array_t* array19 = func8(&params1, loopsFactor);
            DEBUG_RETURN(array19->id);
            free(params1.data);
            array_t* array21;
            if (pCounter > 0) {
               array21 = vars->data[--pCounter];
               array21->refC++;
               DEBUG_COPY(array21->id);
            } else {
               array21 = (array_t*)malloc(sizeof(array_t));
               array21->size = 281;
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
               array22->size = 305;
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
            array18->refC--;
            if(array18->refC == 0) {
               free(array18->data);
               free(array18);
               DEBUG_FREE(array18->id);
            }
         }
         else {
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array1;
            params1.data[1] = array12;
            params1.data[2] = array13;
            array_t* array23 = func9(&params1, loopsFactor);
            DEBUG_RETURN(array23->id);
            free(params1.data);
            array_t* array25;
            if (pCounter > 0) {
               array25 = vars->data[--pCounter];
               array25->refC++;
               DEBUG_COPY(array25->id);
            } else {
               array25 = (array_t*)malloc(sizeof(array_t));
               array25->size = 313;
               array25->refC = 1;
               array25->id = 25;
               array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
               memset(array25->data, 0, array25->size*sizeof(unsigned int));
               DEBUG_NEW(array25->id);
            }
            array25->refC--;
            if(array25->refC == 0) {
               free(array25->data);
               free(array25);
               DEBUG_FREE(array25->id);
            }
            array23->refC--;
            if(array23->refC == 0) {
               free(array23->data);
               free(array23);
               DEBUG_FREE(array23->id);
            }
         }
      }
      array_t_param params1;
      params1.size = 3;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array1;
      params1.data[1] = array12;
      params1.data[2] = array13;
      array_t* array26 = func4(&params1, loopsFactor);
      DEBUG_RETURN(array26->id);
      free(params1.data);
      array_t* array34;
      if (pCounter > 0) {
         array34 = vars->data[--pCounter];
         array34->refC++;
         DEBUG_COPY(array34->id);
      } else {
         array34 = (array_t*)malloc(sizeof(array_t));
         array34->size = 739;
         array34->refC = 1;
         array34->id = 34;
         array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
         memset(array34->data, 0, array34->size*sizeof(unsigned int));
         DEBUG_NEW(array34->id);
      }
      array_t* array35;
      if (pCounter > 0) {
         array35 = vars->data[--pCounter];
         array35->refC++;
         DEBUG_COPY(array35->id);
      } else {
         array35 = (array_t*)malloc(sizeof(array_t));
         array35->size = 12;
         array35->refC = 1;
         array35->id = 35;
         array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
         memset(array35->data, 0, array35->size*sizeof(unsigned int));
         DEBUG_NEW(array35->id);
      }
      array35->refC--;
      if(array35->refC == 0) {
         free(array35->data);
         free(array35);
         DEBUG_FREE(array35->id);
      }
      array34->refC--;
      if(array34->refC == 0) {
         free(array34->data);
         free(array34);
         DEBUG_FREE(array34->id);
      }
      array26->refC--;
      if(array26->refC == 0) {
         free(array26->data);
         free(array26);
         DEBUG_FREE(array26->id);
      }
      array13->refC--;
      if(array13->refC == 0) {
         free(array13->data);
         free(array13);
         DEBUG_FREE(array13->id);
      }
   }
   array12->refC--;
   if(array12->refC == 0) {
      free(array12->data);
      free(array12);
      DEBUG_FREE(array12->id);
   }
   return array1;
}

