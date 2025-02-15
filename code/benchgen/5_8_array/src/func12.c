#include "outs/5_8_array.h" 
array_t* func12(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t* array13;
      if (pCounter > 0) {
         array13 = vars->data[--pCounter];
         array13->refC++;
         DEBUG_COPY(array13->id);
      } else {
         array13 = (array_t*)malloc(sizeof(array_t));
         array13->size = 413;
         array13->refC = 1;
         array13->id = 13;
         array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
         memset(array13->data, 0, array13->size*sizeof(unsigned int));
         DEBUG_NEW(array13->id);
      }
      unsigned int loop6 = 0;
      unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
      for(; loop6 < loopLimit6; loop6++) {
         for (int i = 0; i < array13->size; i++) {
            array13->data[i]--;
         }
         for (int i = 0; i < array13->size; i++) {
            if (array13->data[i] == 80) { 
               return array13;
            }
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array13;
      array_t* array14 = func24(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array14->id);
      free(params0.data);
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
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array21 = func16(&params0, loopsFactor);
      DEBUG_RETURN(array21->id);
      free(params0.data);
      array21->refC--;
      if(array21->refC == 0) {
         free(array21->data);
         free(array21);
         DEBUG_FREE(array21->id);
      }
   }
   array_t* array23;
   if (pCounter > 0) {
      array23 = vars->data[--pCounter];
      array23->refC++;
      DEBUG_COPY(array23->id);
   } else {
      array23 = (array_t*)malloc(sizeof(array_t));
      array23->size = 754;
      array23->refC = 1;
      array23->id = 23;
      array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
      memset(array23->data, 0, array23->size*sizeof(unsigned int));
      DEBUG_NEW(array23->id);
   }
   return array23;
}

