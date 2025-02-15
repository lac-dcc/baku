#include "outs/3_2_array.h" 
array_t* func10(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array75;
   if (pCounter > 0) {
      array75 = vars->data[--pCounter];
      array75->refC++;
      DEBUG_COPY(array75->id);
   } else {
      array75 = (array_t*)malloc(sizeof(array_t));
      array75->size = 432;
      array75->refC = 1;
      array75->id = 75;
      array75->data = (unsigned int*)malloc(array75->size*sizeof(unsigned int));
      memset(array75->data, 0, array75->size*sizeof(unsigned int));
      DEBUG_NEW(array75->id);
   }
   unsigned int loop17 = 0;
   unsigned int loopLimit17 = (rand()%loopsFactor)/2 + 1;
   for(; loop17 < loopLimit17; loop17++) {
      for (int i = 0; i < array75->size; i++) {
         array75->data[i]++;
      }
      for (int i = 0; i < array75->size; i++) {
         if (array75->data[i] == 28) { 
            return array75;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array75;
         array_t* array76 = func14(&params0, loopsFactor);
         DEBUG_RETURN(array76->id);
         free(params0.data);
         array_t* array77;
         if (pCounter > 0) {
            array77 = vars->data[--pCounter];
            array77->refC++;
            DEBUG_COPY(array77->id);
         } else {
            array77 = (array_t*)malloc(sizeof(array_t));
            array77->size = 474;
            array77->refC = 1;
            array77->id = 77;
            array77->data = (unsigned int*)malloc(array77->size*sizeof(unsigned int));
            memset(array77->data, 0, array77->size*sizeof(unsigned int));
            DEBUG_NEW(array77->id);
         }
         array77->refC--;
         if(array77->refC == 0) {
            free(array77->data);
            free(array77);
            DEBUG_FREE(array77->id);
         }
         array76->refC--;
         if(array76->refC == 0) {
            free(array76->data);
            free(array76);
            DEBUG_FREE(array76->id);
         }
      }
      else {
      }
   }
   array_t* array78;
   if (pCounter > 0) {
      array78 = vars->data[--pCounter];
      array78->refC++;
      DEBUG_COPY(array78->id);
   } else {
      array78 = (array_t*)malloc(sizeof(array_t));
      array78->size = 121;
      array78->refC = 1;
      array78->id = 78;
      array78->data = (unsigned int*)malloc(array78->size*sizeof(unsigned int));
      memset(array78->data, 0, array78->size*sizeof(unsigned int));
      DEBUG_NEW(array78->id);
   }
   array78->refC--;
   if(array78->refC == 0) {
      free(array78->data);
      free(array78);
      DEBUG_FREE(array78->id);
   }
   return array75;
}

