#include "outs/1_6_array.h" 
array_t* func0(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      if(PATH0 & 1) {
      }
      else {
         array_t* array3;
         if (pCounter > 0) {
            array3 = vars->data[--pCounter];
            array3->refC++;
            DEBUG_COPY(array3->id);
         } else {
            array3 = (array_t*)malloc(sizeof(array_t));
            array3->size = 649;
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
            array4->size = 421;
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
            array5->size = 362;
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
   }
   array_t* array6;
   if (pCounter > 0) {
      array6 = vars->data[--pCounter];
      array6->refC++;
      DEBUG_COPY(array6->id);
   } else {
      array6 = (array_t*)malloc(sizeof(array_t));
      array6->size = 27;
      array6->refC = 1;
      array6->id = 6;
      array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
      memset(array6->data, 0, array6->size*sizeof(unsigned int));
      DEBUG_NEW(array6->id);
   }
   array_t* array7;
   if (pCounter > 0) {
      array7 = vars->data[--pCounter];
      array7->refC++;
      DEBUG_COPY(array7->id);
   } else {
      array7 = (array_t*)malloc(sizeof(array_t));
      array7->size = 690;
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
      array8->size = 59;
      array8->refC = 1;
      array8->id = 8;
      array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
      memset(array8->data, 0, array8->size*sizeof(unsigned int));
      DEBUG_NEW(array8->id);
   }
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
   array2->refC--;
   if(array2->refC == 0) {
      free(array2->data);
      free(array2);
      DEBUG_FREE(array2->id);
   }
   return array8;
}

