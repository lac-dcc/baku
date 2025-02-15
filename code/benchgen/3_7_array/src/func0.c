#include "outs/3_7_array.h" 
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
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array2;
         array_t* array3 = func6(&params0, loopsFactor);
         DEBUG_RETURN(array3->id);
         free(params0.data);
         array_t* array5;
         if (pCounter > 0) {
            array5 = vars->data[--pCounter];
            array5->refC++;
            DEBUG_COPY(array5->id);
         } else {
            array5 = (array_t*)malloc(sizeof(array_t));
            array5->size = 763;
            array5->refC = 1;
            array5->id = 5;
            array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
            memset(array5->data, 0, array5->size*sizeof(unsigned int));
            DEBUG_NEW(array5->id);
         }
         if(PATH0 & 2) {
            unsigned int loop1 = 0;
            unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
            for(; loop1 < loopLimit1; loop1++) {
            }
         }
         else {
            array_t* array6;
            if (pCounter > 0) {
               array6 = vars->data[--pCounter];
               array6->refC++;
               DEBUG_COPY(array6->id);
            } else {
               array6 = (array_t*)malloc(sizeof(array_t));
               array6->size = 926;
               array6->refC = 1;
               array6->id = 6;
               array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
               memset(array6->data, 0, array6->size*sizeof(unsigned int));
               DEBUG_NEW(array6->id);
            }
            array_t_param params1;
            params1.size = 4;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array2;
            params1.data[1] = array3;
            params1.data[2] = array5;
            params1.data[3] = array6;
            array_t* array7 = func7(&params1, loopsFactor);
            DEBUG_RETURN(array7->id);
            free(params1.data);
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
         for (int i = 0; i < array2->size; i++) {
            if (array2->data[i] == 29) { 
               return array2;
            }
         }
         array_t* array9;
         if (pCounter > 0) {
            array9 = vars->data[--pCounter];
            array9->refC++;
            DEBUG_COPY(array9->id);
         } else {
            array9 = (array_t*)malloc(sizeof(array_t));
            array9->size = 782;
            array9->refC = 1;
            array9->id = 9;
            array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
            memset(array9->data, 0, array9->size*sizeof(unsigned int));
            DEBUG_NEW(array9->id);
         }
         array_t* array10;
         if (pCounter > 0) {
            array10 = vars->data[--pCounter];
            array10->refC++;
            DEBUG_COPY(array10->id);
         } else {
            array10 = (array_t*)malloc(sizeof(array_t));
            array10->size = 530;
            array10->refC = 1;
            array10->id = 10;
            array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
            memset(array10->data, 0, array10->size*sizeof(unsigned int));
            DEBUG_NEW(array10->id);
         }
         for (int i = 0; i < array5->size; i++) {
            array5->data[i]++;
         }
         unsigned int loop2 = 0;
         unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
         for(; loop2 < loopLimit2; loop2++) {
            for (int i = 0; i < array9->size; i++) {
               array9->data[i]--;
            }
         }
         array_t_param params1;
         params1.size = 5;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array2;
         params1.data[1] = array3;
         params1.data[2] = array5;
         params1.data[3] = array9;
         params1.data[4] = array10;
         array_t* array11 = func8(&params1, loopsFactor);
         DEBUG_RETURN(array11->id);
         free(params1.data);
         array11->refC--;
         if(array11->refC == 0) {
            free(array11->data);
            free(array11);
            DEBUG_FREE(array11->id);
         }
         array10->refC--;
         if(array10->refC == 0) {
            free(array10->data);
            free(array10);
            DEBUG_FREE(array10->id);
         }
         array9->refC--;
         if(array9->refC == 0) {
            free(array9->data);
            free(array9);
            DEBUG_FREE(array9->id);
         }
         array5->refC--;
         if(array5->refC == 0) {
            free(array5->data);
            free(array5);
            DEBUG_FREE(array5->id);
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
      array_t* array14;
      if (pCounter > 0) {
         array14 = vars->data[--pCounter];
         array14->refC++;
         DEBUG_COPY(array14->id);
      } else {
         array14 = (array_t*)malloc(sizeof(array_t));
         array14->size = 167;
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
         array15->size = 393;
         array15->refC = 1;
         array15->id = 15;
         array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
         memset(array15->data, 0, array15->size*sizeof(unsigned int));
         DEBUG_NEW(array15->id);
      }
      for (int i = 0; i < array14->size; i++) {
         array14->data[i]++;
      }
      unsigned int loop3 = 0;
      unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
      for(; loop3 < loopLimit3; loop3++) {
         for (int i = 0; i < array14->size; i++) {
            array14->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array13;
      params0.data[1] = array14;
      params0.data[2] = array15;
      array_t* array16 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array16->id);
      free(params0.data);
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array13;
      params1.data[1] = array14;
      params1.data[2] = array15;
      params1.data[3] = array16;
      array_t* array18 = func2(&params1, loopsFactor);
      DEBUG_RETURN(array18->id);
      free(params1.data);
      array18->refC--;
      if(array18->refC == 0) {
         free(array18->data);
         free(array18);
         DEBUG_FREE(array18->id);
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
      array13->refC--;
      if(array13->refC == 0) {
         free(array13->data);
         free(array13);
         DEBUG_FREE(array13->id);
      }
   }
   array_t* array27;
   if (pCounter > 0) {
      array27 = vars->data[--pCounter];
      array27->refC++;
      DEBUG_COPY(array27->id);
   } else {
      array27 = (array_t*)malloc(sizeof(array_t));
      array27->size = 582;
      array27->refC = 1;
      array27->id = 27;
      array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
      memset(array27->data, 0, array27->size*sizeof(unsigned int));
      DEBUG_NEW(array27->id);
   }
   return array27;
}

