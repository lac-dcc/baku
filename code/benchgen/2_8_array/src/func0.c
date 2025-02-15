#include "outs/2_8_array.h" 
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
         array_t* array3 = func4(&params0, loopsFactor);
         DEBUG_RETURN(array3->id);
         free(params0.data);
         array3->refC--;
         if(array3->refC == 0) {
            free(array3->data);
            free(array3);
            DEBUG_FREE(array3->id);
         }
      }
      array_t* array5;
      if (pCounter > 0) {
         array5 = vars->data[--pCounter];
         array5->refC++;
         DEBUG_COPY(array5->id);
      } else {
         array5 = (array_t*)malloc(sizeof(array_t));
         array5->size = 211;
         array5->refC = 1;
         array5->id = 5;
         array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
         memset(array5->data, 0, array5->size*sizeof(unsigned int));
         DEBUG_NEW(array5->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array1;
      params0.data[1] = array5;
      array_t* array6 = func5(&params0, loopsFactor);
      DEBUG_RETURN(array6->id);
      free(params0.data);
      for (int i = 0; i < array6->size; i++) {
         if (array6->data[i] == 2) { 
            return array6;
         }
      }
      array6->refC--;
      if(array6->refC == 0) {
         free(array6->data);
         free(array6);
         DEBUG_FREE(array6->id);
      }
      array5->refC--;
      if(array5->refC == 0) {
         free(array5->data);
         free(array5);
         DEBUG_FREE(array5->id);
      }
   }
   return array1;
}

