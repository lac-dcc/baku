#include "outs/3_7_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array32;
   if (pCounter > 0) {
      array32 = vars->data[--pCounter];
      array32->refC++;
      DEBUG_COPY(array32->id);
   } else {
      array32 = (array_t*)malloc(sizeof(array_t));
      array32->size = 403;
      array32->refC = 1;
      array32->id = 32;
      array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
      memset(array32->data, 0, array32->size*sizeof(unsigned int));
      DEBUG_NEW(array32->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array32;
   array_t* array33 = func6(&params0, loopsFactor);
   DEBUG_RETURN(array33->id);
   free(params0.data);
   array_t* array34;
   if (pCounter > 0) {
      array34 = vars->data[--pCounter];
      array34->refC++;
      DEBUG_COPY(array34->id);
   } else {
      array34 = (array_t*)malloc(sizeof(array_t));
      array34->size = 399;
      array34->refC = 1;
      array34->id = 34;
      array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
      memset(array34->data, 0, array34->size*sizeof(unsigned int));
      DEBUG_NEW(array34->id);
   }
   if(PATH0 & 1) {
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/1 + 1;
      for(; loop7 < loopLimit7; loop7++) {
      }
   }
   else {
      array_t* array35;
      if (pCounter > 0) {
         array35 = vars->data[--pCounter];
         array35->refC++;
         DEBUG_COPY(array35->id);
      } else {
         array35 = (array_t*)malloc(sizeof(array_t));
         array35->size = 932;
         array35->refC = 1;
         array35->id = 35;
         array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
         memset(array35->data, 0, array35->size*sizeof(unsigned int));
         DEBUG_NEW(array35->id);
      }
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array32;
      params1.data[1] = array33;
      params1.data[2] = array34;
      params1.data[3] = array35;
      array_t* array36 = func7(&params1, loopsFactor);
      DEBUG_RETURN(array36->id);
      free(params1.data);
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
   }
   for (int i = 0; i < array32->size; i++) {
      if (array32->data[i] == 39) { 
         return array32;
      }
   }
   array_t* array37;
   if (pCounter > 0) {
      array37 = vars->data[--pCounter];
      array37->refC++;
      DEBUG_COPY(array37->id);
   } else {
      array37 = (array_t*)malloc(sizeof(array_t));
      array37->size = 12;
      array37->refC = 1;
      array37->id = 37;
      array37->data = (unsigned int*)malloc(array37->size*sizeof(unsigned int));
      memset(array37->data, 0, array37->size*sizeof(unsigned int));
      DEBUG_NEW(array37->id);
   }
   array_t* array38;
   if (pCounter > 0) {
      array38 = vars->data[--pCounter];
      array38->refC++;
      DEBUG_COPY(array38->id);
   } else {
      array38 = (array_t*)malloc(sizeof(array_t));
      array38->size = 226;
      array38->refC = 1;
      array38->id = 38;
      array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
      memset(array38->data, 0, array38->size*sizeof(unsigned int));
      DEBUG_NEW(array38->id);
   }
   for (int i = 0; i < array33->size; i++) {
      array33->data[i]++;
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/1 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      for (int i = 0; i < array38->size; i++) {
         array38->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 5;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array32;
   params1.data[1] = array33;
   params1.data[2] = array34;
   params1.data[3] = array37;
   params1.data[4] = array38;
   array_t* array39 = func8(&params1, loopsFactor);
   DEBUG_RETURN(array39->id);
   free(params1.data);
   for (int i = 0; i < array38->size; i++) {
      if (array38->data[i] == 34) { 
         return array38;
      }
   }
   array39->refC--;
   if(array39->refC == 0) {
      free(array39->data);
      free(array39);
      DEBUG_FREE(array39->id);
   }
   array37->refC--;
   if(array37->refC == 0) {
      free(array37->data);
      free(array37);
      DEBUG_FREE(array37->id);
   }
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
   array32->refC--;
   if(array32->refC == 0) {
      free(array32->data);
      free(array32);
      DEBUG_FREE(array32->id);
   }
   return array38;
}

