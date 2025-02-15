#include "outs/2_7_array.h" 
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
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
   }
   else {
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
      array_t* array4;
      if (pCounter > 0) {
         array4 = vars->data[--pCounter];
         array4->refC++;
         DEBUG_COPY(array4->id);
      } else {
         array4 = (array_t*)malloc(sizeof(array_t));
         array4->size = 27;
         array4->refC = 1;
         array4->id = 4;
         array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
         memset(array4->data, 0, array4->size*sizeof(unsigned int));
         DEBUG_NEW(array4->id);
      }
      array_t* array5;
      if (pCounter > 0) {
         array5 = vars->data[--pCounter];
         array5->refC++;
         DEBUG_COPY(array5->id);
      } else {
         array5 = (array_t*)malloc(sizeof(array_t));
         array5->size = 690;
         array5->refC = 1;
         array5->id = 5;
         array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
         memset(array5->data, 0, array5->size*sizeof(unsigned int));
         DEBUG_NEW(array5->id);
      }
      for (int i = 0; i < array4->size; i++) {
         array4->data[i]++;
      }
      unsigned int loop1 = 0;
      unsigned int loopLimit1 = (rand()%loopsFactor)/1 + 1;
      for(; loop1 < loopLimit1; loop1++) {
         for (int i = 0; i < array5->size; i++) {
            array5->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array3;
      params0.data[1] = array4;
      params0.data[2] = array5;
      array_t* array6 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array6->id);
      free(params0.data);
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array3;
      params1.data[1] = array4;
      params1.data[2] = array5;
      params1.data[3] = array6;
      array_t* array8 = func2(&params1, loopsFactor);
      DEBUG_RETURN(array8->id);
      free(params1.data);
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
      array3->refC--;
      if(array3->refC == 0) {
         free(array3->data);
         free(array3);
         DEBUG_FREE(array3->id);
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
   return array12;
}

