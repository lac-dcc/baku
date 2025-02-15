#include "outs/5_7_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array64;
   if (pCounter > 0) {
      array64 = vars->data[--pCounter];
      array64->refC++;
      DEBUG_COPY(array64->id);
   } else {
      array64 = (array_t*)malloc(sizeof(array_t));
      array64->size = 451;
      array64->refC = 1;
      array64->id = 64;
      array64->data = (unsigned int*)malloc(array64->size*sizeof(unsigned int));
      memset(array64->data, 0, array64->size*sizeof(unsigned int));
      DEBUG_NEW(array64->id);
   }
   for (int i = 0; i < array64->size; i++) {
      if (array64->data[i] == 55) { 
         return array64;
      }
   }
   array_t* array65;
   if (pCounter > 0) {
      array65 = vars->data[--pCounter];
      array65->refC++;
      DEBUG_COPY(array65->id);
   } else {
      array65 = (array_t*)malloc(sizeof(array_t));
      array65->size = 379;
      array65->refC = 1;
      array65->id = 65;
      array65->data = (unsigned int*)malloc(array65->size*sizeof(unsigned int));
      memset(array65->data, 0, array65->size*sizeof(unsigned int));
      DEBUG_NEW(array65->id);
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array64;
   params0.data[1] = array65;
   array_t* array66 = func11(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array66->id);
   free(params0.data);
   array_t* array67;
   if (pCounter > 0) {
      array67 = vars->data[--pCounter];
      array67->refC++;
      DEBUG_COPY(array67->id);
   } else {
      array67 = (array_t*)malloc(sizeof(array_t));
      array67->size = 228;
      array67->refC = 1;
      array67->id = 67;
      array67->data = (unsigned int*)malloc(array67->size*sizeof(unsigned int));
      memset(array67->data, 0, array67->size*sizeof(unsigned int));
      DEBUG_NEW(array67->id);
   }
   if(PATH0 & 1) {
      unsigned int loop16 = 0;
      unsigned int loopLimit16 = (rand()%loopsFactor)/1 + 1;
      for(; loop16 < loopLimit16; loop16++) {
         array_t* array68;
         if (pCounter > 0) {
            array68 = vars->data[--pCounter];
            array68->refC++;
            DEBUG_COPY(array68->id);
         } else {
            array68 = (array_t*)malloc(sizeof(array_t));
            array68->size = 841;
            array68->refC = 1;
            array68->id = 68;
            array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
            memset(array68->data, 0, array68->size*sizeof(unsigned int));
            DEBUG_NEW(array68->id);
         }
         for (int i = 0; i < array64->size; i++) {
            if (array64->data[i] == 93) { 
               return array64;
            }
         }
         array68->refC--;
         if(array68->refC == 0) {
            free(array68->data);
            free(array68);
            DEBUG_FREE(array68->id);
         }
      }
   }
   else {
      array_t* array69;
      if (pCounter > 0) {
         array69 = vars->data[--pCounter];
         array69->refC++;
         DEBUG_COPY(array69->id);
      } else {
         array69 = (array_t*)malloc(sizeof(array_t));
         array69->size = 500;
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
         array70->size = 34;
         array70->refC = 1;
         array70->id = 70;
         array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
         memset(array70->data, 0, array70->size*sizeof(unsigned int));
         DEBUG_NEW(array70->id);
      }
      array_t* array71;
      if (pCounter > 0) {
         array71 = vars->data[--pCounter];
         array71->refC++;
         DEBUG_COPY(array71->id);
      } else {
         array71 = (array_t*)malloc(sizeof(array_t));
         array71->size = 764;
         array71->refC = 1;
         array71->id = 71;
         array71->data = (unsigned int*)malloc(array71->size*sizeof(unsigned int));
         memset(array71->data, 0, array71->size*sizeof(unsigned int));
         DEBUG_NEW(array71->id);
      }
      for (int i = 0; i < array69->size; i++) {
         array69->data[i]++;
      }
      unsigned int loop17 = 0;
      unsigned int loopLimit17 = (rand()%loopsFactor)/1 + 1;
      for(; loop17 < loopLimit17; loop17++) {
         for (int i = 0; i < array67->size; i++) {
            array67->data[i]--;
         }
      }
      array_t_param params1;
      params1.size = 7;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array64;
      params1.data[1] = array65;
      params1.data[2] = array66;
      params1.data[3] = array67;
      params1.data[4] = array69;
      params1.data[5] = array70;
      params1.data[6] = array71;
      array_t* array72 = func14(&params1, loopsFactor);
      DEBUG_RETURN(array72->id);
      free(params1.data);
      array_t_param params2;
      params2.size = 8;
      params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
      params2.data[0] = array64;
      params2.data[1] = array65;
      params2.data[2] = array66;
      params2.data[3] = array67;
      params2.data[4] = array69;
      params2.data[5] = array70;
      params2.data[6] = array71;
      params2.data[7] = array72;
      array_t* array73 = func9(&params2, loopsFactor);
      DEBUG_RETURN(array73->id);
      free(params2.data);
      array73->refC--;
      if(array73->refC == 0) {
         free(array73->data);
         free(array73);
         DEBUG_FREE(array73->id);
      }
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
   }
   for (int i = 0; i < array67->size; i++) {
      if (array67->data[i] == 65) { 
         return array67;
      }
   }
   array_t* array74;
   if (pCounter > 0) {
      array74 = vars->data[--pCounter];
      array74->refC++;
      DEBUG_COPY(array74->id);
   } else {
      array74 = (array_t*)malloc(sizeof(array_t));
      array74->size = 859;
      array74->refC = 1;
      array74->id = 74;
      array74->data = (unsigned int*)malloc(array74->size*sizeof(unsigned int));
      memset(array74->data, 0, array74->size*sizeof(unsigned int));
      DEBUG_NEW(array74->id);
   }
   array_t* array75;
   if (pCounter > 0) {
      array75 = vars->data[--pCounter];
      array75->refC++;
      DEBUG_COPY(array75->id);
   } else {
      array75 = (array_t*)malloc(sizeof(array_t));
      array75->size = 936;
      array75->refC = 1;
      array75->id = 75;
      array75->data = (unsigned int*)malloc(array75->size*sizeof(unsigned int));
      memset(array75->data, 0, array75->size*sizeof(unsigned int));
      DEBUG_NEW(array75->id);
   }
   for (int i = 0; i < array74->size; i++) {
      array74->data[i]++;
   }
   unsigned int loop18 = 0;
   unsigned int loopLimit18 = (rand()%loopsFactor)/1 + 1;
   for(; loop18 < loopLimit18; loop18++) {
      for (int i = 0; i < array75->size; i++) {
         array75->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 6;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array64;
   params1.data[1] = array65;
   params1.data[2] = array66;
   params1.data[3] = array67;
   params1.data[4] = array74;
   params1.data[5] = array75;
   array_t* array76 = func10(&params1, loopsFactor);
   DEBUG_RETURN(array76->id);
   free(params1.data);
   for (int i = 0; i < array66->size; i++) {
      if (array66->data[i] == 7) { 
         return array66;
      }
   }
   array76->refC--;
   if(array76->refC == 0) {
      free(array76->data);
      free(array76);
      DEBUG_FREE(array76->id);
   }
   array74->refC--;
   if(array74->refC == 0) {
      free(array74->data);
      free(array74);
      DEBUG_FREE(array74->id);
   }
   array67->refC--;
   if(array67->refC == 0) {
      free(array67->data);
      free(array67);
      DEBUG_FREE(array67->id);
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
   return array75;
}

