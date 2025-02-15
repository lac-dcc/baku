#include "outs/4_5_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
      for(; loop4 < loopLimit4; loop4++) {
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
         array4->refC--;
         if(array4->refC == 0) {
            free(array4->data);
            free(array4);
            DEBUG_FREE(array4->id);
         }
      }
   }
   else {
      unsigned int loop5 = 0;
      unsigned int loopLimit5 = (rand()%loopsFactor)/5 + 1;
      for(; loop5 < loopLimit5; loop5++) {
         array_t* array5;
         if (pCounter > 0) {
            array5 = vars->data[--pCounter];
            array5->refC++;
            DEBUG_COPY(array5->id);
         } else {
            array5 = (array_t*)malloc(sizeof(array_t));
            array5->size = 540;
            array5->refC = 1;
            array5->id = 5;
            array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
            memset(array5->data, 0, array5->size*sizeof(unsigned int));
            DEBUG_NEW(array5->id);
         }
         array5->refC--;
         if(array5->refC == 0) {
            free(array5->data);
            free(array5);
            DEBUG_FREE(array5->id);
         }
      }
   }
   array_t* array6;
   if (pCounter > 0) {
      array6 = vars->data[--pCounter];
      array6->refC++;
      DEBUG_COPY(array6->id);
   } else {
      array6 = (array_t*)malloc(sizeof(array_t));
      array6->size = 426;
      array6->refC = 1;
      array6->id = 6;
      array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
      memset(array6->data, 0, array6->size*sizeof(unsigned int));
      DEBUG_NEW(array6->id);
   }
   return array6;
}

