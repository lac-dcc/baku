#include "outs/4_7_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array63;
   if (pCounter > 0) {
      array63 = vars->data[--pCounter];
      array63->refC++;
      DEBUG_COPY(array63->id);
   } else {
      array63 = (array_t*)malloc(sizeof(array_t));
      array63->size = 451;
      array63->refC = 1;
      array63->id = 63;
      array63->data = (unsigned int*)malloc(array63->size*sizeof(unsigned int));
      memset(array63->data, 0, array63->size*sizeof(unsigned int));
      DEBUG_NEW(array63->id);
   }
   for (int i = 0; i < array63->size; i++) {
      if (array63->data[i] == 55) { 
         return array63;
      }
   }
   array_t* array64;
   if (pCounter > 0) {
      array64 = vars->data[--pCounter];
      array64->refC++;
      DEBUG_COPY(array64->id);
   } else {
      array64 = (array_t*)malloc(sizeof(array_t));
      array64->size = 379;
      array64->refC = 1;
      array64->id = 64;
      array64->data = (unsigned int*)malloc(array64->size*sizeof(unsigned int));
      memset(array64->data, 0, array64->size*sizeof(unsigned int));
      DEBUG_NEW(array64->id);
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array63;
   params0.data[1] = array64;
   array_t* array65 = func6(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array65->id);
   free(params0.data);
   array_t* array66;
   if (pCounter > 0) {
      array66 = vars->data[--pCounter];
      array66->refC++;
      DEBUG_COPY(array66->id);
   } else {
      array66 = (array_t*)malloc(sizeof(array_t));
      array66->size = 228;
      array66->refC = 1;
      array66->id = 66;
      array66->data = (unsigned int*)malloc(array66->size*sizeof(unsigned int));
      memset(array66->data, 0, array66->size*sizeof(unsigned int));
      DEBUG_NEW(array66->id);
   }
   if(PATH0 & 1) {
      unsigned int loop15 = 0;
      unsigned int loopLimit15 = (rand()%loopsFactor)/1 + 1;
      for(; loop15 < loopLimit15; loop15++) {
         array_t* array67;
         if (pCounter > 0) {
            array67 = vars->data[--pCounter];
            array67->refC++;
            DEBUG_COPY(array67->id);
         } else {
            array67 = (array_t*)malloc(sizeof(array_t));
            array67->size = 841;
            array67->refC = 1;
            array67->id = 67;
            array67->data = (unsigned int*)malloc(array67->size*sizeof(unsigned int));
            memset(array67->data, 0, array67->size*sizeof(unsigned int));
            DEBUG_NEW(array67->id);
         }
         for (int i = 0; i < array63->size; i++) {
            if (array63->data[i] == 93) { 
               return array63;
            }
         }
         array67->refC--;
         if(array67->refC == 0) {
            free(array67->data);
            free(array67);
            DEBUG_FREE(array67->id);
         }
      }
   }
   else {
      array_t* array68;
      if (pCounter > 0) {
         array68 = vars->data[--pCounter];
         array68->refC++;
         DEBUG_COPY(array68->id);
      } else {
         array68 = (array_t*)malloc(sizeof(array_t));
         array68->size = 500;
         array68->refC = 1;
         array68->id = 68;
         array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
         memset(array68->data, 0, array68->size*sizeof(unsigned int));
         DEBUG_NEW(array68->id);
      }
      array_t* array69;
      if (pCounter > 0) {
         array69 = vars->data[--pCounter];
         array69->refC++;
         DEBUG_COPY(array69->id);
      } else {
         array69 = (array_t*)malloc(sizeof(array_t));
         array69->size = 34;
         array69->refC = 1;
         array69->id = 69;
         array69->data = (unsigned int*)malloc(array69->size*sizeof(unsigned int));
         memset(array69->data, 0, array69->size*sizeof(unsigned int));
         DEBUG_NEW(array69->id);
      }
      array_t* array70;
      if (pCounter > 0) {
         array70 = vars->data[--pCounter];
         array70->refC++;
         DEBUG_COPY(array70->id);
      } else {
         array70 = (array_t*)malloc(sizeof(array_t));
         array70->size = 764;
         array70->refC = 1;
         array70->id = 70;
         array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
         memset(array70->data, 0, array70->size*sizeof(unsigned int));
         DEBUG_NEW(array70->id);
      }
      for (int i = 0; i < array68->size; i++) {
         array68->data[i]++;
      }
      unsigned int loop16 = 0;
      unsigned int loopLimit16 = (rand()%loopsFactor)/1 + 1;
      for(; loop16 < loopLimit16; loop16++) {
         for (int i = 0; i < array66->size; i++) {
            array66->data[i]--;
         }
      }
      array_t_param params1;
      params1.size = 7;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array63;
      params1.data[1] = array64;
      params1.data[2] = array65;
      params1.data[3] = array66;
      params1.data[4] = array68;
      params1.data[5] = array69;
      params1.data[6] = array70;
      array_t* array71 = func10(&params1, loopsFactor);
      DEBUG_RETURN(array71->id);
      free(params1.data);
      array_t_param params2;
      params2.size = 8;
      params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
      params2.data[0] = array63;
      params2.data[1] = array64;
      params2.data[2] = array65;
      params2.data[3] = array66;
      params2.data[4] = array68;
      params2.data[5] = array69;
      params2.data[6] = array70;
      params2.data[7] = array71;
      array_t* array72 = func7(&params2, loopsFactor);
      DEBUG_RETURN(array72->id);
      free(params2.data);
      array72->refC--;
      if(array72->refC == 0) {
         free(array72->data);
         free(array72);
         DEBUG_FREE(array72->id);
      }
      array71->refC--;
      if(array71->refC == 0) {
         free(array71->data);
         free(array71);
         DEBUG_FREE(array71->id);
      }
      array70->refC--;
      if(array70->refC == 0) {
         free(array70->data);
         free(array70);
         DEBUG_FREE(array70->id);
      }
      array69->refC--;
      if(array69->refC == 0) {
         free(array69->data);
         free(array69);
         DEBUG_FREE(array69->id);
      }
      array68->refC--;
      if(array68->refC == 0) {
         free(array68->data);
         free(array68);
         DEBUG_FREE(array68->id);
      }
   }
   for (int i = 0; i < array66->size; i++) {
      if (array66->data[i] == 65) { 
         return array66;
      }
   }
   array_t* array73;
   if (pCounter > 0) {
      array73 = vars->data[--pCounter];
      array73->refC++;
      DEBUG_COPY(array73->id);
   } else {
      array73 = (array_t*)malloc(sizeof(array_t));
      array73->size = 859;
      array73->refC = 1;
      array73->id = 73;
      array73->data = (unsigned int*)malloc(array73->size*sizeof(unsigned int));
      memset(array73->data, 0, array73->size*sizeof(unsigned int));
      DEBUG_NEW(array73->id);
   }
   array_t* array74;
   if (pCounter > 0) {
      array74 = vars->data[--pCounter];
      array74->refC++;
      DEBUG_COPY(array74->id);
   } else {
      array74 = (array_t*)malloc(sizeof(array_t));
      array74->size = 936;
      array74->refC = 1;
      array74->id = 74;
      array74->data = (unsigned int*)malloc(array74->size*sizeof(unsigned int));
      memset(array74->data, 0, array74->size*sizeof(unsigned int));
      DEBUG_NEW(array74->id);
   }
   for (int i = 0; i < array73->size; i++) {
      array73->data[i]++;
   }
   unsigned int loop17 = 0;
   unsigned int loopLimit17 = (rand()%loopsFactor)/1 + 1;
   for(; loop17 < loopLimit17; loop17++) {
      for (int i = 0; i < array74->size; i++) {
         array74->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 6;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array63;
   params1.data[1] = array64;
   params1.data[2] = array65;
   params1.data[3] = array66;
   params1.data[4] = array73;
   params1.data[5] = array74;
   array_t* array75 = func8(&params1, loopsFactor);
   DEBUG_RETURN(array75->id);
   free(params1.data);
   for (int i = 0; i < array65->size; i++) {
      if (array65->data[i] == 7) { 
         return array65;
      }
   }
   array75->refC--;
   if(array75->refC == 0) {
      free(array75->data);
      free(array75);
      DEBUG_FREE(array75->id);
   }
   array73->refC--;
   if(array73->refC == 0) {
      free(array73->data);
      free(array73);
      DEBUG_FREE(array73->id);
   }
   array66->refC--;
   if(array66->refC == 0) {
      free(array66->data);
      free(array66);
      DEBUG_FREE(array66->id);
   }
   array65->refC--;
   if(array65->refC == 0) {
      free(array65->data);
      free(array65);
      DEBUG_FREE(array65->id);
   }
   array64->refC--;
   if(array64->refC == 0) {
      free(array64->data);
      free(array64);
      DEBUG_FREE(array64->id);
   }
   array63->refC--;
   if(array63->refC == 0) {
      free(array63->data);
      free(array63);
      DEBUG_FREE(array63->id);
   }
   return array74;
}

