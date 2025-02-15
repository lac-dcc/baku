#include "outs/4_9_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array35;
   if (pCounter > 0) {
      array35 = vars->data[--pCounter];
      array35->refC++;
      DEBUG_COPY(array35->id);
   } else {
      array35 = (array_t*)malloc(sizeof(array_t));
      array35->size = 624;
      array35->refC = 1;
      array35->id = 35;
      array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
      memset(array35->data, 0, array35->size*sizeof(unsigned int));
      DEBUG_NEW(array35->id);
   }
   for (int i = 0; i < array35->size; i++) {
      array35->data[i]++;
   }
   for (int i = 0; i < array35->size; i++) {
      if (array35->data[i] == 32) { 
         return array35;
      }
   }
   for (int i = 0; i < array35->size; i++) {
      array35->data[i]--;
   }
   array_t* array36;
   if (pCounter > 0) {
      array36 = vars->data[--pCounter];
      array36->refC++;
      DEBUG_COPY(array36->id);
   } else {
      array36 = (array_t*)malloc(sizeof(array_t));
      array36->size = 503;
      array36->refC = 1;
      array36->id = 36;
      array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
      memset(array36->data, 0, array36->size*sizeof(unsigned int));
      DEBUG_NEW(array36->id);
   }
   if(PATH0 & 1) {
      unsigned int loop17 = 0;
      unsigned int loopLimit17 = (rand()%loopsFactor)/2 + 1;
      for(; loop17 < loopLimit17; loop17++) {
         array_t* array37;
         if (pCounter > 0) {
            array37 = vars->data[--pCounter];
            array37->refC++;
            DEBUG_COPY(array37->id);
         } else {
            array37 = (array_t*)malloc(sizeof(array_t));
            array37->size = 19;
            array37->refC = 1;
            array37->id = 37;
            array37->data = (unsigned int*)malloc(array37->size*sizeof(unsigned int));
            memset(array37->data, 0, array37->size*sizeof(unsigned int));
            DEBUG_NEW(array37->id);
         }
         for (int i = 0; i < array35->size; i++) {
            array35->data[i]--;
         }
         for (int i = 0; i < array35->size; i++) {
            if (array35->data[i] == 8) { 
               return array35;
            }
         }
         array37->refC--;
         if(array37->refC == 0) {
            free(array37->data);
            free(array37);
            DEBUG_FREE(array37->id);
         }
      }
   }
   else {
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array35;
      params0.data[1] = array36;
      array_t* array38 = func11(&params0, loopsFactor);
      DEBUG_RETURN(array38->id);
      free(params0.data);
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array35;
   params0.data[1] = array36;
   array_t* array39 = func8(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array39->id);
   free(params0.data);
   array36->refC--;
   if(array36->refC == 0) {
      free(array36->data);
      free(array36);
      DEBUG_FREE(array36->id);
   }
   array35->refC--;
   if(array35->refC == 0) {
      free(array35->data);
      free(array35);
      DEBUG_FREE(array35->id);
   }
   return array39;
}

