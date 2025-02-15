#include "outs/5_8_array.h" 
array_t* func9(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array79;
   if (pCounter > 0) {
      array79 = vars->data[--pCounter];
      array79->refC++;
      DEBUG_COPY(array79->id);
   } else {
      array79 = (array_t*)malloc(sizeof(array_t));
      array79->size = 282;
      array79->refC = 1;
      array79->id = 79;
      array79->data = (unsigned int*)malloc(array79->size*sizeof(unsigned int));
      memset(array79->data, 0, array79->size*sizeof(unsigned int));
      DEBUG_NEW(array79->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array79;
   array_t* array80 = func15(&params0, loopsFactor);
   DEBUG_RETURN(array80->id);
   free(params0.data);
   if(PATH0 & 1) {
      array_t* array83;
      if (pCounter > 0) {
         array83 = vars->data[--pCounter];
         array83->refC++;
         DEBUG_COPY(array83->id);
      } else {
         array83 = (array_t*)malloc(sizeof(array_t));
         array83->size = 468;
         array83->refC = 1;
         array83->id = 83;
         array83->data = (unsigned int*)malloc(array83->size*sizeof(unsigned int));
         memset(array83->data, 0, array83->size*sizeof(unsigned int));
         DEBUG_NEW(array83->id);
      }
      unsigned int loop25 = 0;
      unsigned int loopLimit25 = (rand()%loopsFactor)/2 + 1;
      for(; loop25 < loopLimit25; loop25++) {
         for (int i = 0; i < array83->size; i++) {
            array83->data[i]--;
         }
         for (int i = 0; i < array79->size; i++) {
            if (array79->data[i] == 31) { 
               return array79;
            }
         }
      }
      array_t_param params1;
      params1.size = 3;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array79;
      params1.data[1] = array80;
      params1.data[2] = array83;
      array_t* array84 = func24(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array84->id);
      free(params1.data);
      array84->refC--;
      if(array84->refC == 0) {
         free(array84->data);
         free(array84);
         DEBUG_FREE(array84->id);
      }
      array83->refC--;
      if(array83->refC == 0) {
         free(array83->data);
         free(array83);
         DEBUG_FREE(array83->id);
      }
   }
   else {
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array79;
      params1.data[1] = array80;
      array_t* array85 = func16(&params1, loopsFactor);
      DEBUG_RETURN(array85->id);
      free(params1.data);
      array85->refC--;
      if(array85->refC == 0) {
         free(array85->data);
         free(array85);
         DEBUG_FREE(array85->id);
      }
   }
   array80->refC--;
   if(array80->refC == 0) {
      free(array80->data);
      free(array80);
      DEBUG_FREE(array80->id);
   }
   return array79;
}

