#include "outs/3_2_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array73;
   if (pCounter > 0) {
      array73 = vars->data[--pCounter];
      array73->refC++;
      DEBUG_COPY(array73->id);
   } else {
      array73 = (array_t*)malloc(sizeof(array_t));
      array73->size = 491;
      array73->refC = 1;
      array73->id = 73;
      array73->data = (unsigned int*)malloc(array73->size*sizeof(unsigned int));
      memset(array73->data, 0, array73->size*sizeof(unsigned int));
      DEBUG_NEW(array73->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array73;
   array_t* array74 = func10(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array74->id);
   free(params0.data);
   for (int i = 0; i < array74->size; i++) {
      if (array74->data[i] == 29) { 
         return array74;
      }
   }
   unsigned int loop18 = 0;
   unsigned int loopLimit18 = (rand()%loopsFactor)/2 + 1;
   for(; loop18 < loopLimit18; loop18++) {
      for (int i = 0; i < array74->size; i++) {
         array74->data[i]--;
      }
      for (int i = 0; i < array74->size; i++) {
         if (array74->data[i] == 93) { 
            return array74;
         }
      }
      if(PATH0 & 1) {
         array_t* array79;
         if (pCounter > 0) {
            array79 = vars->data[--pCounter];
            array79->refC++;
            DEBUG_COPY(array79->id);
         } else {
            array79 = (array_t*)malloc(sizeof(array_t));
            array79->size = 818;
            array79->refC = 1;
            array79->id = 79;
            array79->data = (unsigned int*)malloc(array79->size*sizeof(unsigned int));
            memset(array79->data, 0, array79->size*sizeof(unsigned int));
            DEBUG_NEW(array79->id);
         }
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array73;
         params1.data[1] = array74;
         params1.data[2] = array79;
         array_t* array80 = func12(&params1, loopsFactor);
         DEBUG_RETURN(array80->id);
         free(params1.data);
         array_t* array81;
         if (pCounter > 0) {
            array81 = vars->data[--pCounter];
            array81->refC++;
            DEBUG_COPY(array81->id);
         } else {
            array81 = (array_t*)malloc(sizeof(array_t));
            array81->size = 11;
            array81->refC = 1;
            array81->id = 81;
            array81->data = (unsigned int*)malloc(array81->size*sizeof(unsigned int));
            memset(array81->data, 0, array81->size*sizeof(unsigned int));
            DEBUG_NEW(array81->id);
         }
         array_t* array82;
         if (pCounter > 0) {
            array82 = vars->data[--pCounter];
            array82->refC++;
            DEBUG_COPY(array82->id);
         } else {
            array82 = (array_t*)malloc(sizeof(array_t));
            array82->size = 928;
            array82->refC = 1;
            array82->id = 82;
            array82->data = (unsigned int*)malloc(array82->size*sizeof(unsigned int));
            memset(array82->data, 0, array82->size*sizeof(unsigned int));
            DEBUG_NEW(array82->id);
         }
         array82->refC--;
         if(array82->refC == 0) {
            free(array82->data);
            free(array82);
            DEBUG_FREE(array82->id);
         }
         array81->refC--;
         if(array81->refC == 0) {
            free(array81->data);
            free(array81);
            DEBUG_FREE(array81->id);
         }
         array80->refC--;
         if(array80->refC == 0) {
            free(array80->data);
            free(array80);
            DEBUG_FREE(array80->id);
         }
         array79->refC--;
         if(array79->refC == 0) {
            free(array79->data);
            free(array79);
            DEBUG_FREE(array79->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array73;
         params1.data[1] = array74;
         array_t* array83 = func13(&params1, loopsFactor);
         DEBUG_RETURN(array83->id);
         free(params1.data);
         array_t* array84;
         if (pCounter > 0) {
            array84 = vars->data[--pCounter];
            array84->refC++;
            DEBUG_COPY(array84->id);
         } else {
            array84 = (array_t*)malloc(sizeof(array_t));
            array84->size = 404;
            array84->refC = 1;
            array84->id = 84;
            array84->data = (unsigned int*)malloc(array84->size*sizeof(unsigned int));
            memset(array84->data, 0, array84->size*sizeof(unsigned int));
            DEBUG_NEW(array84->id);
         }
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
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array73;
   params1.data[1] = array74;
   array_t* array85 = func11(&params1, loopsFactor);
   DEBUG_RETURN(array85->id);
   free(params1.data);
   array_t* array91;
   if (pCounter > 0) {
      array91 = vars->data[--pCounter];
      array91->refC++;
      DEBUG_COPY(array91->id);
   } else {
      array91 = (array_t*)malloc(sizeof(array_t));
      array91->size = 183;
      array91->refC = 1;
      array91->id = 91;
      array91->data = (unsigned int*)malloc(array91->size*sizeof(unsigned int));
      memset(array91->data, 0, array91->size*sizeof(unsigned int));
      DEBUG_NEW(array91->id);
   }
   array_t* array92;
   if (pCounter > 0) {
      array92 = vars->data[--pCounter];
      array92->refC++;
      DEBUG_COPY(array92->id);
   } else {
      array92 = (array_t*)malloc(sizeof(array_t));
      array92->size = 490;
      array92->refC = 1;
      array92->id = 92;
      array92->data = (unsigned int*)malloc(array92->size*sizeof(unsigned int));
      memset(array92->data, 0, array92->size*sizeof(unsigned int));
      DEBUG_NEW(array92->id);
   }
   array91->refC--;
   if(array91->refC == 0) {
      free(array91->data);
      free(array91);
      DEBUG_FREE(array91->id);
   }
   array85->refC--;
   if(array85->refC == 0) {
      free(array85->data);
      free(array85);
      DEBUG_FREE(array85->id);
   }
   array74->refC--;
   if(array74->refC == 0) {
      free(array74->data);
      free(array74);
      DEBUG_FREE(array74->id);
   }
   array73->refC--;
   if(array73->refC == 0) {
      free(array73->data);
      free(array73);
      DEBUG_FREE(array73->id);
   }
   return array92;
}

