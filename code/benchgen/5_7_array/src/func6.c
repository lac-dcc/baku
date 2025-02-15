#include "outs/5_7_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop3 = 0;
      unsigned int loopLimit3 = (rand()%loopsFactor)/2 + 1;
      for(; loop3 < loopLimit3; loop3++) {
         array_t* array15;
         if (pCounter > 0) {
            array15 = vars->data[--pCounter];
            array15->refC++;
            DEBUG_COPY(array15->id);
         } else {
            array15 = (array_t*)malloc(sizeof(array_t));
            array15->size = 42;
            array15->refC = 1;
            array15->id = 15;
            array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
            memset(array15->data, 0, array15->size*sizeof(unsigned int));
            DEBUG_NEW(array15->id);
         }
         for (int i = 0; i < array15->size; i++) {
            if (array15->data[i] == 73) { 
               return array15;
            }
         }
         array15->refC--;
         if(array15->refC == 0) {
            free(array15->data);
            free(array15);
            DEBUG_FREE(array15->id);
         }
      }
   }
   else {
      array_t* array16;
      if (pCounter > 0) {
         array16 = vars->data[--pCounter];
         array16->refC++;
         DEBUG_COPY(array16->id);
      } else {
         array16 = (array_t*)malloc(sizeof(array_t));
         array16->size = 421;
         array16->refC = 1;
         array16->id = 16;
         array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
         memset(array16->data, 0, array16->size*sizeof(unsigned int));
         DEBUG_NEW(array16->id);
      }
      array_t* array17;
      if (pCounter > 0) {
         array17 = vars->data[--pCounter];
         array17->refC++;
         DEBUG_COPY(array17->id);
      } else {
         array17 = (array_t*)malloc(sizeof(array_t));
         array17->size = 919;
         array17->refC = 1;
         array17->id = 17;
         array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
         memset(array17->data, 0, array17->size*sizeof(unsigned int));
         DEBUG_NEW(array17->id);
      }
      array_t* array18;
      if (pCounter > 0) {
         array18 = vars->data[--pCounter];
         array18->refC++;
         DEBUG_COPY(array18->id);
      } else {
         array18 = (array_t*)malloc(sizeof(array_t));
         array18->size = 784;
         array18->refC = 1;
         array18->id = 18;
         array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
         memset(array18->data, 0, array18->size*sizeof(unsigned int));
         DEBUG_NEW(array18->id);
      }
      for (int i = 0; i < array17->size; i++) {
         array17->data[i]++;
      }
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
      for(; loop4 < loopLimit4; loop4++) {
         for (int i = 0; i < array18->size; i++) {
            array18->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array16;
      params0.data[1] = array17;
      params0.data[2] = array18;
      array_t* array19 = func14(&params0, loopsFactor);
      DEBUG_RETURN(array19->id);
      free(params0.data);
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array16;
      params1.data[1] = array17;
      params1.data[2] = array18;
      params1.data[3] = array19;
      array_t* array20 = func9(&params1, loopsFactor);
      DEBUG_RETURN(array20->id);
      free(params1.data);
      array20->refC--;
      if(array20->refC == 0) {
         free(array20->data);
         free(array20);
         DEBUG_FREE(array20->id);
      }
      array19->refC--;
      if(array19->refC == 0) {
         free(array19->data);
         free(array19);
         DEBUG_FREE(array19->id);
      }
      array18->refC--;
      if(array18->refC == 0) {
         free(array18->data);
         free(array18);
         DEBUG_FREE(array18->id);
      }
      array17->refC--;
      if(array17->refC == 0) {
         free(array17->data);
         free(array17);
         DEBUG_FREE(array17->id);
      }
      array16->refC--;
      if(array16->refC == 0) {
         free(array16->data);
         free(array16);
         DEBUG_FREE(array16->id);
      }
   }
   array_t* array23;
   if (pCounter > 0) {
      array23 = vars->data[--pCounter];
      array23->refC++;
      DEBUG_COPY(array23->id);
   } else {
      array23 = (array_t*)malloc(sizeof(array_t));
      array23->size = 170;
      array23->refC = 1;
      array23->id = 23;
      array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
      memset(array23->data, 0, array23->size*sizeof(unsigned int));
      DEBUG_NEW(array23->id);
   }
   array_t* array24;
   if (pCounter > 0) {
      array24 = vars->data[--pCounter];
      array24->refC++;
      DEBUG_COPY(array24->id);
   } else {
      array24 = (array_t*)malloc(sizeof(array_t));
      array24->size = 996;
      array24->refC = 1;
      array24->id = 24;
      array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
      memset(array24->data, 0, array24->size*sizeof(unsigned int));
      DEBUG_NEW(array24->id);
   }
   for (int i = 0; i < array24->size; i++) {
      array24->data[i]++;
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      for (int i = 0; i < array24->size; i++) {
         array24->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array23;
   params0.data[1] = array24;
   array_t* array25 = func10(&params0, loopsFactor);
   DEBUG_RETURN(array25->id);
   free(params0.data);
   array25->refC--;
   if(array25->refC == 0) {
      free(array25->data);
      free(array25);
      DEBUG_FREE(array25->id);
   }
   array24->refC--;
   if(array24->refC == 0) {
      free(array24->data);
      free(array24);
      DEBUG_FREE(array24->id);
   }
   return array23;
}

