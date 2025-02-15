#include "outs/5_8_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array32;
   if (pCounter > 0) {
      array32 = vars->data[--pCounter];
      array32->refC++;
      DEBUG_COPY(array32->id);
   } else {
      array32 = (array_t*)malloc(sizeof(array_t));
      array32->size = 444;
      array32->refC = 1;
      array32->id = 32;
      array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
      memset(array32->data, 0, array32->size*sizeof(unsigned int));
      DEBUG_NEW(array32->id);
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/3 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      if(PATH0 & 1) {
         array_t* array33;
         if (pCounter > 0) {
            array33 = vars->data[--pCounter];
            array33->refC++;
            DEBUG_COPY(array33->id);
         } else {
            array33 = (array_t*)malloc(sizeof(array_t));
            array33->size = 619;
            array33->refC = 1;
            array33->id = 33;
            array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
            memset(array33->data, 0, array33->size*sizeof(unsigned int));
            DEBUG_NEW(array33->id);
         }
         unsigned int loop11 = 0;
         unsigned int loopLimit11 = (rand()%loopsFactor)/4 + 1;
         for(; loop11 < loopLimit11; loop11++) {
            for (int i = 0; i < array32->size; i++) {
               array32->data[i]--;
            }
            for (int i = 0; i < array33->size; i++) {
               if (array33->data[i] == 31) { 
                  return array33;
               }
            }
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array32;
         params0.data[1] = array33;
         array_t* array34 = func24(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array34->id);
         free(params0.data);
         array34->refC--;
         if(array34->refC == 0) {
            free(array34->data);
            free(array34);
            DEBUG_FREE(array34->id);
         }
         array33->refC--;
         if(array33->refC == 0) {
            free(array33->data);
            free(array33);
            DEBUG_FREE(array33->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array32;
         array_t* array35 = func16(&params0, loopsFactor);
         DEBUG_RETURN(array35->id);
         free(params0.data);
         array35->refC--;
         if(array35->refC == 0) {
            free(array35->data);
            free(array35);
            DEBUG_FREE(array35->id);
         }
      }
      array_t* array36;
      if (pCounter > 0) {
         array36 = vars->data[--pCounter];
         array36->refC++;
         DEBUG_COPY(array36->id);
      } else {
         array36 = (array_t*)malloc(sizeof(array_t));
         array36->size = 675;
         array36->refC = 1;
         array36->id = 36;
         array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
         memset(array36->data, 0, array36->size*sizeof(unsigned int));
         DEBUG_NEW(array36->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array32;
      params0.data[1] = array36;
      array_t* array37 = func17(&params0, loopsFactor);
      DEBUG_RETURN(array37->id);
      free(params0.data);
      if(PATH0 & 2) {
         array_t* array38;
         if (pCounter > 0) {
            array38 = vars->data[--pCounter];
            array38->refC++;
            DEBUG_COPY(array38->id);
         } else {
            array38 = (array_t*)malloc(sizeof(array_t));
            array38->size = 567;
            array38->refC = 1;
            array38->id = 38;
            array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
            memset(array38->data, 0, array38->size*sizeof(unsigned int));
            DEBUG_NEW(array38->id);
         }
         unsigned int loop12 = 0;
         unsigned int loopLimit12 = (rand()%loopsFactor)/4 + 1;
         for(; loop12 < loopLimit12; loop12++) {
            for (int i = 0; i < array32->size; i++) {
               array32->data[i]--;
            }
            for (int i = 0; i < array36->size; i++) {
               if (array36->data[i] == 53) { 
                  return array36;
               }
            }
         }
         array38->refC--;
         if(array38->refC == 0) {
            free(array38->data);
            free(array38);
            DEBUG_FREE(array38->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array32;
         params1.data[1] = array36;
         params1.data[2] = array37;
         array_t* array39 = func22(&params1, loopsFactor);
         DEBUG_RETURN(array39->id);
         free(params1.data);
         array39->refC--;
         if(array39->refC == 0) {
            free(array39->data);
            free(array39);
            DEBUG_FREE(array39->id);
         }
      }
      for (int i = 0; i < array36->size; i++) {
         if (array36->data[i] == 83) { 
            return array36;
         }
      }
      array37->refC--;
      if(array37->refC == 0) {
         free(array37->data);
         free(array37);
         DEBUG_FREE(array37->id);
      }
      array36->refC--;
      if(array36->refC == 0) {
         free(array36->data);
         free(array36);
         DEBUG_FREE(array36->id);
      }
   }
   for (int i = 0; i < array32->size; i++) {
      array32->data[i]--;
   }
   for (int i = 0; i < array32->size; i++) {
      if (array32->data[i] == 28) { 
         return array32;
      }
   }
   return array32;
}

