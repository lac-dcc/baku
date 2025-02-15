#include "outs/4_8_array.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array57;
   if (pCounter > 0) {
      array57 = vars->data[--pCounter];
      array57->refC++;
      DEBUG_COPY(array57->id);
   } else {
      array57 = (array_t*)malloc(sizeof(array_t));
      array57->size = 11;
      array57->refC = 1;
      array57->id = 57;
      array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
      memset(array57->data, 0, array57->size*sizeof(unsigned int));
      DEBUG_NEW(array57->id);
   }
   unsigned int loop17 = 0;
   unsigned int loopLimit17 = (rand()%loopsFactor)/2 + 1;
   for(; loop17 < loopLimit17; loop17++) {
      if(PATH0 & 1) {
         array_t* array58;
         if (pCounter > 0) {
            array58 = vars->data[--pCounter];
            array58->refC++;
            DEBUG_COPY(array58->id);
         } else {
            array58 = (array_t*)malloc(sizeof(array_t));
            array58->size = 928;
            array58->refC = 1;
            array58->id = 58;
            array58->data = (unsigned int*)malloc(array58->size*sizeof(unsigned int));
            memset(array58->data, 0, array58->size*sizeof(unsigned int));
            DEBUG_NEW(array58->id);
         }
         unsigned int loop18 = 0;
         unsigned int loopLimit18 = (rand()%loopsFactor)/3 + 1;
         for(; loop18 < loopLimit18; loop18++) {
            for (int i = 0; i < array58->size; i++) {
               array58->data[i]--;
            }
            for (int i = 0; i < array57->size; i++) {
               if (array57->data[i] == 4) { 
                  return array57;
               }
            }
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array57;
         params0.data[1] = array58;
         array_t* array59 = func18(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array59->id);
         free(params0.data);
         array59->refC--;
         if(array59->refC == 0) {
            free(array59->data);
            free(array59);
            DEBUG_FREE(array59->id);
         }
         array58->refC--;
         if(array58->refC == 0) {
            free(array58->data);
            free(array58);
            DEBUG_FREE(array58->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array57;
         array_t* array60 = func14(&params0, loopsFactor);
         DEBUG_RETURN(array60->id);
         free(params0.data);
         array60->refC--;
         if(array60->refC == 0) {
            free(array60->data);
            free(array60);
            DEBUG_FREE(array60->id);
         }
      }
      array_t* array61;
      if (pCounter > 0) {
         array61 = vars->data[--pCounter];
         array61->refC++;
         DEBUG_COPY(array61->id);
      } else {
         array61 = (array_t*)malloc(sizeof(array_t));
         array61->size = 606;
         array61->refC = 1;
         array61->id = 61;
         array61->data = (unsigned int*)malloc(array61->size*sizeof(unsigned int));
         memset(array61->data, 0, array61->size*sizeof(unsigned int));
         DEBUG_NEW(array61->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array57;
      params0.data[1] = array61;
      array_t* array62 = func15(&params0, loopsFactor);
      DEBUG_RETURN(array62->id);
      free(params0.data);
      if(PATH0 & 2) {
         array_t* array63;
         if (pCounter > 0) {
            array63 = vars->data[--pCounter];
            array63->refC++;
            DEBUG_COPY(array63->id);
         } else {
            array63 = (array_t*)malloc(sizeof(array_t));
            array63->size = 818;
            array63->refC = 1;
            array63->id = 63;
            array63->data = (unsigned int*)malloc(array63->size*sizeof(unsigned int));
            memset(array63->data, 0, array63->size*sizeof(unsigned int));
            DEBUG_NEW(array63->id);
         }
         unsigned int loop19 = 0;
         unsigned int loopLimit19 = (rand()%loopsFactor)/3 + 1;
         for(; loop19 < loopLimit19; loop19++) {
            for (int i = 0; i < array57->size; i++) {
               array57->data[i]--;
            }
            for (int i = 0; i < array57->size; i++) {
               if (array57->data[i] == 69) { 
                  return array57;
               }
            }
         }
         array63->refC--;
         if(array63->refC == 0) {
            free(array63->data);
            free(array63);
            DEBUG_FREE(array63->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array57;
         params1.data[1] = array61;
         params1.data[2] = array62;
         array_t* array64 = func16(&params1, loopsFactor);
         DEBUG_RETURN(array64->id);
         free(params1.data);
         array64->refC--;
         if(array64->refC == 0) {
            free(array64->data);
            free(array64);
            DEBUG_FREE(array64->id);
         }
      }
      for (int i = 0; i < array57->size; i++) {
         if (array57->data[i] == 24) { 
            return array57;
         }
      }
      array62->refC--;
      if(array62->refC == 0) {
         free(array62->data);
         free(array62);
         DEBUG_FREE(array62->id);
      }
      array61->refC--;
      if(array61->refC == 0) {
         free(array61->data);
         free(array61);
         DEBUG_FREE(array61->id);
      }
   }
   for (int i = 0; i < array57->size; i++) {
      array57->data[i]--;
   }
   for (int i = 0; i < array57->size; i++) {
      if (array57->data[i] == 83) { 
         return array57;
      }
   }
   return array57;
}

