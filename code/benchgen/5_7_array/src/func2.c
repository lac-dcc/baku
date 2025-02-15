#include "outs/5_7_array.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array78;
   if (pCounter > 0) {
      array78 = vars->data[--pCounter];
      array78->refC++;
      DEBUG_COPY(array78->id);
   } else {
      array78 = (array_t*)malloc(sizeof(array_t));
      array78->size = 237;
      array78->refC = 1;
      array78->id = 78;
      array78->data = (unsigned int*)malloc(array78->size*sizeof(unsigned int));
      memset(array78->data, 0, array78->size*sizeof(unsigned int));
      DEBUG_NEW(array78->id);
   }
   for (int i = 0; i < array78->size; i++) {
      if (array78->data[i] == 93) { 
         return array78;
      }
   }
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
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array78;
   params0.data[1] = array79;
   array_t* array80 = func11(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array80->id);
   free(params0.data);
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
   if(PATH0 & 1) {
      unsigned int loop19 = 0;
      unsigned int loopLimit19 = (rand()%loopsFactor)/1 + 1;
      for(; loop19 < loopLimit19; loop19++) {
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
         for (int i = 0; i < array82->size; i++) {
            if (array82->data[i] == 76) { 
               return array82;
            }
         }
         array82->refC--;
         if(array82->refC == 0) {
            free(array82->data);
            free(array82);
            DEBUG_FREE(array82->id);
         }
      }
   }
   else {
      array_t* array83;
      if (pCounter > 0) {
         array83 = vars->data[--pCounter];
         array83->refC++;
         DEBUG_COPY(array83->id);
      } else {
         array83 = (array_t*)malloc(sizeof(array_t));
         array83->size = 404;
         array83->refC = 1;
         array83->id = 83;
         array83->data = (unsigned int*)malloc(array83->size*sizeof(unsigned int));
         memset(array83->data, 0, array83->size*sizeof(unsigned int));
         DEBUG_NEW(array83->id);
      }
      array_t* array84;
      if (pCounter > 0) {
         array84 = vars->data[--pCounter];
         array84->refC++;
         DEBUG_COPY(array84->id);
      } else {
         array84 = (array_t*)malloc(sizeof(array_t));
         array84->size = 443;
         array84->refC = 1;
         array84->id = 84;
         array84->data = (unsigned int*)malloc(array84->size*sizeof(unsigned int));
         memset(array84->data, 0, array84->size*sizeof(unsigned int));
         DEBUG_NEW(array84->id);
      }
      array_t* array85;
      if (pCounter > 0) {
         array85 = vars->data[--pCounter];
         array85->refC++;
         DEBUG_COPY(array85->id);
      } else {
         array85 = (array_t*)malloc(sizeof(array_t));
         array85->size = 763;
         array85->refC = 1;
         array85->id = 85;
         array85->data = (unsigned int*)malloc(array85->size*sizeof(unsigned int));
         memset(array85->data, 0, array85->size*sizeof(unsigned int));
         DEBUG_NEW(array85->id);
      }
      for (int i = 0; i < array85->size; i++) {
         array85->data[i]++;
      }
      unsigned int loop20 = 0;
      unsigned int loopLimit20 = (rand()%loopsFactor)/1 + 1;
      for(; loop20 < loopLimit20; loop20++) {
         for (int i = 0; i < array80->size; i++) {
            array80->data[i]--;
         }
      }
      array_t_param params1;
      params1.size = 7;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array78;
      params1.data[1] = array79;
      params1.data[2] = array80;
      params1.data[3] = array81;
      params1.data[4] = array83;
      params1.data[5] = array84;
      params1.data[6] = array85;
      array_t* array86 = func14(&params1, loopsFactor);
      DEBUG_RETURN(array86->id);
      free(params1.data);
      array_t_param params2;
      params2.size = 8;
      params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
      params2.data[0] = array78;
      params2.data[1] = array79;
      params2.data[2] = array80;
      params2.data[3] = array81;
      params2.data[4] = array83;
      params2.data[5] = array84;
      params2.data[6] = array85;
      params2.data[7] = array86;
      array_t* array87 = func9(&params2, loopsFactor);
      DEBUG_RETURN(array87->id);
      free(params2.data);
      array87->refC--;
      if(array87->refC == 0) {
         free(array87->data);
         free(array87);
         DEBUG_FREE(array87->id);
      }
      array86->refC--;
      if(array86->refC == 0) {
         free(array86->data);
         free(array86);
         DEBUG_FREE(array86->id);
      }
      array85->refC--;
      if(array85->refC == 0) {
         free(array85->data);
         free(array85);
         DEBUG_FREE(array85->id);
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
   for (int i = 0; i < array78->size; i++) {
      if (array78->data[i] == 88) { 
         return array78;
      }
   }
   array_t* array88;
   if (pCounter > 0) {
      array88 = vars->data[--pCounter];
      array88->refC++;
      DEBUG_COPY(array88->id);
   } else {
      array88 = (array_t*)malloc(sizeof(array_t));
      array88->size = 369;
      array88->refC = 1;
      array88->id = 88;
      array88->data = (unsigned int*)malloc(array88->size*sizeof(unsigned int));
      memset(array88->data, 0, array88->size*sizeof(unsigned int));
      DEBUG_NEW(array88->id);
   }
   array_t* array89;
   if (pCounter > 0) {
      array89 = vars->data[--pCounter];
      array89->refC++;
      DEBUG_COPY(array89->id);
   } else {
      array89 = (array_t*)malloc(sizeof(array_t));
      array89->size = 917;
      array89->refC = 1;
      array89->id = 89;
      array89->data = (unsigned int*)malloc(array89->size*sizeof(unsigned int));
      memset(array89->data, 0, array89->size*sizeof(unsigned int));
      DEBUG_NEW(array89->id);
   }
   for (int i = 0; i < array89->size; i++) {
      array89->data[i]++;
   }
   unsigned int loop21 = 0;
   unsigned int loopLimit21 = (rand()%loopsFactor)/1 + 1;
   for(; loop21 < loopLimit21; loop21++) {
      for (int i = 0; i < array78->size; i++) {
         array78->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 6;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array78;
   params1.data[1] = array79;
   params1.data[2] = array80;
   params1.data[3] = array81;
   params1.data[4] = array88;
   params1.data[5] = array89;
   array_t* array90 = func10(&params1, loopsFactor);
   DEBUG_RETURN(array90->id);
   free(params1.data);
   array_t* array91;
   if (pCounter > 0) {
      array91 = vars->data[--pCounter];
      array91->refC++;
      DEBUG_COPY(array91->id);
   } else {
      array91 = (array_t*)malloc(sizeof(array_t));
      array91->size = 470;
      array91->refC = 1;
      array91->id = 91;
      array91->data = (unsigned int*)malloc(array91->size*sizeof(unsigned int));
      memset(array91->data, 0, array91->size*sizeof(unsigned int));
      DEBUG_NEW(array91->id);
   }
   array_t_param params2;
   params2.size = 8;
   params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
   params2.data[0] = array78;
   params2.data[1] = array79;
   params2.data[2] = array80;
   params2.data[3] = array81;
   params2.data[4] = array88;
   params2.data[5] = array89;
   params2.data[6] = array90;
   params2.data[7] = array91;
   array_t* array92 = func5(&params2, rng(), loopsFactor);
   DEBUG_RETURN(array92->id);
   free(params2.data);
   array92->refC--;
   if(array92->refC == 0) {
      free(array92->data);
      free(array92);
      DEBUG_FREE(array92->id);
   }
   array90->refC--;
   if(array90->refC == 0) {
      free(array90->data);
      free(array90);
      DEBUG_FREE(array90->id);
   }
   array89->refC--;
   if(array89->refC == 0) {
      free(array89->data);
      free(array89);
      DEBUG_FREE(array89->id);
   }
   array88->refC--;
   if(array88->refC == 0) {
      free(array88->data);
      free(array88);
      DEBUG_FREE(array88->id);
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
   array78->refC--;
   if(array78->refC == 0) {
      free(array78->data);
      free(array78);
      DEBUG_FREE(array78->id);
   }
   return array91;
}

