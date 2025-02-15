#include "outs/4_7_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array30;
   if (pCounter > 0) {
      array30 = vars->data[--pCounter];
      array30->refC++;
      DEBUG_COPY(array30->id);
   } else {
      array30 = (array_t*)malloc(sizeof(array_t));
      array30->size = 808;
      array30->refC = 1;
      array30->id = 30;
      array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
      memset(array30->data, 0, array30->size*sizeof(unsigned int));
      DEBUG_NEW(array30->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array30;
   array_t* array31 = func11(&params0, loopsFactor);
   DEBUG_RETURN(array31->id);
   free(params0.data);
   array_t* array32;
   if (pCounter > 0) {
      array32 = vars->data[--pCounter];
      array32->refC++;
      DEBUG_COPY(array32->id);
   } else {
      array32 = (array_t*)malloc(sizeof(array_t));
      array32->size = 788;
      array32->refC = 1;
      array32->id = 32;
      array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
      memset(array32->data, 0, array32->size*sizeof(unsigned int));
      DEBUG_NEW(array32->id);
   }
   if(PATH0 & 1) {
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/1 + 1;
      for(; loop7 < loopLimit7; loop7++) {
      }
   }
   else {
      array_t* array33;
      if (pCounter > 0) {
         array33 = vars->data[--pCounter];
         array33->refC++;
         DEBUG_COPY(array33->id);
      } else {
         array33 = (array_t*)malloc(sizeof(array_t));
         array33->size = 584;
         array33->refC = 1;
         array33->id = 33;
         array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
         memset(array33->data, 0, array33->size*sizeof(unsigned int));
         DEBUG_NEW(array33->id);
      }
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array30;
      params1.data[1] = array31;
      params1.data[2] = array32;
      params1.data[3] = array33;
      array_t* array34 = func9(&params1, loopsFactor);
      DEBUG_RETURN(array34->id);
      free(params1.data);
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
   for (int i = 0; i < array32->size; i++) {
      if (array32->data[i] == 99) { 
         return array32;
      }
   }
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
   array_t* array36;
   if (pCounter > 0) {
      array36 = vars->data[--pCounter];
      array36->refC++;
      DEBUG_COPY(array36->id);
   } else {
      array36 = (array_t*)malloc(sizeof(array_t));
      array36->size = 60;
      array36->refC = 1;
      array36->id = 36;
      array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
      memset(array36->data, 0, array36->size*sizeof(unsigned int));
      DEBUG_NEW(array36->id);
   }
   for (int i = 0; i < array31->size; i++) {
      array31->data[i]++;
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/1 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      for (int i = 0; i < array35->size; i++) {
         array35->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 5;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array30;
   params1.data[1] = array31;
   params1.data[2] = array32;
   params1.data[3] = array35;
   params1.data[4] = array36;
   array_t* array37 = func10(&params1, loopsFactor);
   DEBUG_RETURN(array37->id);
   free(params1.data);
   for (int i = 0; i < array36->size; i++) {
      if (array36->data[i] == 86) { 
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
   array35->refC--;
   if(array35->refC == 0) {
      free(array35->data);
      free(array35);
      DEBUG_FREE(array35->id);
   }
   array32->refC--;
   if(array32->refC == 0) {
      free(array32->data);
      free(array32);
      DEBUG_FREE(array32->id);
   }
   array31->refC--;
   if(array31->refC == 0) {
      free(array31->data);
      free(array31);
      DEBUG_FREE(array31->id);
   }
   return array30;
}

