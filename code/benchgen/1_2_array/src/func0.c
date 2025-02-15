#include "outs/1_2_array.h" 
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
         array_t* array2 = func2(&params0, loopsFactor);
         DEBUG_RETURN(array2->id);
         free(params0.data);
         array_t* array4;
         if (pCounter > 0) {
            array4 = vars->data[--pCounter];
            array4->refC++;
            DEBUG_COPY(array4->id);
         } else {
            array4 = (array_t*)malloc(sizeof(array_t));
            array4->size = 540;
            array4->refC = 1;
            array4->id = 4;
            array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
            memset(array4->data, 0, array4->size*sizeof(unsigned int));
            DEBUG_NEW(array4->id);
         }
         array4->refC--;
         if(array4->refC == 0) {
            free(array4->data);
            free(array4);
            DEBUG_FREE(array4->id);
         }
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
      else {
      }
   }
   array_t* array5;
   if (pCounter > 0) {
      array5 = vars->data[--pCounter];
      array5->refC++;
      DEBUG_COPY(array5->id);
   } else {
      array5 = (array_t*)malloc(sizeof(array_t));
      array5->size = 426;
      array5->refC = 1;
      array5->id = 5;
      array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
      memset(array5->data, 0, array5->size*sizeof(unsigned int));
      DEBUG_NEW(array5->id);
   }
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/1 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array1;
      params0.data[1] = array5;
      array_t* array6 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array6->id);
      free(params0.data);
      for (int i = 0; i < array6->size; i++) {
         if (array6->data[i] == 30) { 
            return array6;
         }
      }
      unsigned int loop2 = 0;
      unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
      for(; loop2 < loopLimit2; loop2++) {
         for (int i = 0; i < array6->size; i++) {
            array6->data[i]--;
         }
         for (int i = 0; i < array5->size; i++) {
            if (array5->data[i] == 67) { 
               return array5;
            }
         }
      }
      array_t_param params1;
      params1.size = 3;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array1;
      params1.data[1] = array5;
      params1.data[2] = array6;
      array_t* array8 = func4(&params1, loopsFactor);
      DEBUG_RETURN(array8->id);
      free(params1.data);
      array_t* array10;
      if (pCounter > 0) {
         array10 = vars->data[--pCounter];
         array10->refC++;
         DEBUG_COPY(array10->id);
      } else {
         array10 = (array_t*)malloc(sizeof(array_t));
         array10->size = 167;
         array10->refC = 1;
         array10->id = 10;
         array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
         memset(array10->data, 0, array10->size*sizeof(unsigned int));
         DEBUG_NEW(array10->id);
      }
      array_t* array11;
      if (pCounter > 0) {
         array11 = vars->data[--pCounter];
         array11->refC++;
         DEBUG_COPY(array11->id);
      } else {
         array11 = (array_t*)malloc(sizeof(array_t));
         array11->size = 393;
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
   return array1;
}

