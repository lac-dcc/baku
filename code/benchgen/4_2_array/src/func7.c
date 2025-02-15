#include "outs/4_2_array.h" 
array_t* func7(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop15 = 0;
   unsigned int loopLimit15 = (rand()%loopsFactor)/3 + 1;
   for(; loop15 < loopLimit15; loop15++) {
      array_t* array69;
      if (pCounter > 0) {
         array69 = vars->data[--pCounter];
         array69->refC++;
         DEBUG_COPY(array69->id);
      } else {
         array69 = (array_t*)malloc(sizeof(array_t));
         array69->size = 124;
         array69->refC = 1;
         array69->id = 69;
         array69->data = (unsigned int*)malloc(array69->size*sizeof(unsigned int));
         memset(array69->data, 0, array69->size*sizeof(unsigned int));
         DEBUG_NEW(array69->id);
      }
      if(PATH0 & 1) {
         array_t* array70;
         if (pCounter > 0) {
            array70 = vars->data[--pCounter];
            array70->refC++;
            DEBUG_COPY(array70->id);
         } else {
            array70 = (array_t*)malloc(sizeof(array_t));
            array70->size = 914;
            array70->refC = 1;
            array70->id = 70;
            array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
            memset(array70->data, 0, array70->size*sizeof(unsigned int));
            DEBUG_NEW(array70->id);
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array69;
         params0.data[1] = array70;
         array_t* array71 = func20(&params0, loopsFactor);
         DEBUG_RETURN(array71->id);
         free(params0.data);
         array_t* array72;
         if (pCounter > 0) {
            array72 = vars->data[--pCounter];
            array72->refC++;
            DEBUG_COPY(array72->id);
         } else {
            array72 = (array_t*)malloc(sizeof(array_t));
            array72->size = 743;
            array72->refC = 1;
            array72->id = 72;
            array72->data = (unsigned int*)malloc(array72->size*sizeof(unsigned int));
            memset(array72->data, 0, array72->size*sizeof(unsigned int));
            DEBUG_NEW(array72->id);
         }
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
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array69;
         array_t* array74 = func21(&params0, loopsFactor);
         DEBUG_RETURN(array74->id);
         free(params0.data);
         array_t* array75;
         if (pCounter > 0) {
            array75 = vars->data[--pCounter];
            array75->refC++;
            DEBUG_COPY(array75->id);
         } else {
            array75 = (array_t*)malloc(sizeof(array_t));
            array75->size = 859;
            array75->refC = 1;
            array75->id = 75;
            array75->data = (unsigned int*)malloc(array75->size*sizeof(unsigned int));
            memset(array75->data, 0, array75->size*sizeof(unsigned int));
            DEBUG_NEW(array75->id);
         }
         array75->refC--;
         if(array75->refC == 0) {
            free(array75->data);
            free(array75);
            DEBUG_FREE(array75->id);
         }
         array74->refC--;
         if(array74->refC == 0) {
            free(array74->data);
            free(array74);
            DEBUG_FREE(array74->id);
         }
      }
      if(PATH0 & 2) {
         array_t* array76;
         if (pCounter > 0) {
            array76 = vars->data[--pCounter];
            array76->refC++;
            DEBUG_COPY(array76->id);
         } else {
            array76 = (array_t*)malloc(sizeof(array_t));
            array76->size = 936;
            array76->refC = 1;
            array76->id = 76;
            array76->data = (unsigned int*)malloc(array76->size*sizeof(unsigned int));
            memset(array76->data, 0, array76->size*sizeof(unsigned int));
            DEBUG_NEW(array76->id);
         }
         unsigned int loop16 = 0;
         unsigned int loopLimit16 = (rand()%loopsFactor)/4 + 1;
         for(; loop16 < loopLimit16; loop16++) {
            for (int i = 0; i < array69->size; i++) {
               array69->data[i]++;
            }
            for (int i = 0; i < array76->size; i++) {
               if (array76->data[i] == 37) { 
                  return array76;
               }
            }
            if(PATH0 & 4) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array69;
               params0.data[1] = array76;
               array_t* array77 = func19(&params0, loopsFactor);
               DEBUG_RETURN(array77->id);
               free(params0.data);
               array_t* array78;
               if (pCounter > 0) {
                  array78 = vars->data[--pCounter];
                  array78->refC++;
                  DEBUG_COPY(array78->id);
               } else {
                  array78 = (array_t*)malloc(sizeof(array_t));
                  array78->size = 407;
                  array78->refC = 1;
                  array78->id = 78;
                  array78->data = (unsigned int*)malloc(array78->size*sizeof(unsigned int));
                  memset(array78->data, 0, array78->size*sizeof(unsigned int));
                  DEBUG_NEW(array78->id);
               }
               array78->refC--;
               if(array78->refC == 0) {
                  free(array78->data);
                  free(array78);
                  DEBUG_FREE(array78->id);
               }
               array77->refC--;
               if(array77->refC == 0) {
                  free(array77->data);
                  free(array77);
                  DEBUG_FREE(array77->id);
               }
            }
            else {
            }
         }
         array_t* array79;
         if (pCounter > 0) {
            array79 = vars->data[--pCounter];
            array79->refC++;
            DEBUG_COPY(array79->id);
         } else {
            array79 = (array_t*)malloc(sizeof(array_t));
            array79->size = 474;
            array79->refC = 1;
            array79->id = 79;
            array79->data = (unsigned int*)malloc(array79->size*sizeof(unsigned int));
            memset(array79->data, 0, array79->size*sizeof(unsigned int));
            DEBUG_NEW(array79->id);
         }
         array79->refC--;
         if(array79->refC == 0) {
            free(array79->data);
            free(array79);
            DEBUG_FREE(array79->id);
         }
         array76->refC--;
         if(array76->refC == 0) {
            free(array76->data);
            free(array76);
            DEBUG_FREE(array76->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array69;
         array_t* array80 = func17(&params0, loopsFactor);
         DEBUG_RETURN(array80->id);
         free(params0.data);
         for (int i = 0; i < array80->size; i++) {
            if (array80->data[i] == 29) { 
               return array80;
            }
         }
         unsigned int loop17 = 0;
         unsigned int loopLimit17 = (rand()%loopsFactor)/4 + 1;
         for(; loop17 < loopLimit17; loop17++) {
            for (int i = 0; i < array80->size; i++) {
               array80->data[i]--;
            }
            for (int i = 0; i < array80->size; i++) {
               if (array80->data[i] == 93) { 
                  return array80;
               }
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array69;
         params1.data[1] = array80;
         array_t* array81 = func18(&params1, loopsFactor);
         DEBUG_RETURN(array81->id);
         free(params1.data);
         array_t* array82;
         if (pCounter > 0) {
            array82 = vars->data[--pCounter];
            array82->refC++;
            DEBUG_COPY(array82->id);
         } else {
            array82 = (array_t*)malloc(sizeof(array_t));
            array82->size = 143;
            array82->refC = 1;
            array82->id = 82;
            array82->data = (unsigned int*)malloc(array82->size*sizeof(unsigned int));
            memset(array82->data, 0, array82->size*sizeof(unsigned int));
            DEBUG_NEW(array82->id);
         }
         array_t* array83;
         if (pCounter > 0) {
            array83 = vars->data[--pCounter];
            array83->refC++;
            DEBUG_COPY(array83->id);
         } else {
            array83 = (array_t*)malloc(sizeof(array_t));
            array83->size = 11;
            array83->refC = 1;
            array83->id = 83;
            array83->data = (unsigned int*)malloc(array83->size*sizeof(unsigned int));
            memset(array83->data, 0, array83->size*sizeof(unsigned int));
            DEBUG_NEW(array83->id);
         }
         array83->refC--;
         if(array83->refC == 0) {
            free(array83->data);
            free(array83);
            DEBUG_FREE(array83->id);
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
      }
      for (int i = 0; i < array69->size; i++) {
         if (array69->data[i] == 29) { 
            return array69;
         }
      }
      array_t* array84;
      if (pCounter > 0) {
         array84 = vars->data[--pCounter];
         array84->refC++;
         DEBUG_COPY(array84->id);
      } else {
         array84 = (array_t*)malloc(sizeof(array_t));
         array84->size = 776;
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
      array69->refC--;
      if(array69->refC == 0) {
         free(array69->data);
         free(array69);
         DEBUG_FREE(array69->id);
      }
   }
   array_t* array85;
   if (pCounter > 0) {
      array85 = vars->data[--pCounter];
      array85->refC++;
      DEBUG_COPY(array85->id);
   } else {
      array85 = (array_t*)malloc(sizeof(array_t));
      array85->size = 404;
      array85->refC = 1;
      array85->id = 85;
      array85->data = (unsigned int*)malloc(array85->size*sizeof(unsigned int));
      memset(array85->data, 0, array85->size*sizeof(unsigned int));
      DEBUG_NEW(array85->id);
   }
   return array85;
}

