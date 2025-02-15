#include "outs/2_5_array.h" 
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
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
   }
   else {
      unsigned int loop3 = 0;
      unsigned int loopLimit3 = (rand()%loopsFactor)/3 + 1;
      for(; loop3 < loopLimit3; loop3++) {
         array_t* array3;
         if (pCounter > 0) {
            array3 = vars->data[--pCounter];
            array3->refC++;
            DEBUG_COPY(array3->id);
         } else {
            array3 = (array_t*)malloc(sizeof(array_t));
            array3->size = 27;
            array3->refC = 1;
            array3->id = 3;
            array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
            memset(array3->data, 0, array3->size*sizeof(unsigned int));
            DEBUG_NEW(array3->id);
         }
         array3->refC--;
         if(array3->refC == 0) {
            free(array3->data);
            free(array3);
            DEBUG_FREE(array3->id);
         }
      }
   }
   array_t* array4;
   if (pCounter > 0) {
      array4 = vars->data[--pCounter];
      array4->refC++;
      DEBUG_COPY(array4->id);
   } else {
      array4 = (array_t*)malloc(sizeof(array_t));
      array4->size = 690;
      array4->refC = 1;
      array4->id = 4;
      array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
      memset(array4->data, 0, array4->size*sizeof(unsigned int));
      DEBUG_NEW(array4->id);
   }
   return array4;
}

