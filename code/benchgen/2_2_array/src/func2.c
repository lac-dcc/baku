#include "outs/2_2_array.h" 
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
      }
      else {
      }
      for (int i = 0; i < array3->size; i++) {
         if (array3->data[i] == 40) { 
            return array3;
         }
      }
      array_t* array4;
      if (pCounter > 0) {
         array4 = vars->data[--pCounter];
         array4->refC++;
         DEBUG_COPY(array4->id);
      } else {
         array4 = (array_t*)malloc(sizeof(array_t));
         array4->size = 426;
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
      array5->size = 172;
      array5->refC = 1;
      array5->id = 5;
      array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
      memset(array5->data, 0, array5->size*sizeof(unsigned int));
      DEBUG_NEW(array5->id);
   }
   return array5;
}

