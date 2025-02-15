#include "outs/5_8_array.h" 
array_t* func7(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop20 = 0;
   unsigned int loopLimit20 = (rand()%loopsFactor)/2 + 1;
   for(; loop20 < loopLimit20; loop20++) {
      if(PATH0 & 1) {
         array_t* array65;
         if (pCounter > 0) {
            array65 = vars->data[--pCounter];
            array65->refC++;
            DEBUG_COPY(array65->id);
         } else {
            array65 = (array_t*)malloc(sizeof(array_t));
            array65->size = 590;
            array65->refC = 1;
            array65->id = 65;
            array65->data = (unsigned int*)malloc(array65->size*sizeof(unsigned int));
            memset(array65->data, 0, array65->size*sizeof(unsigned int));
            DEBUG_NEW(array65->id);
         }
         unsigned int loop21 = 0;
         unsigned int loopLimit21 = (rand()%loopsFactor)/3 + 1;
         for(; loop21 < loopLimit21; loop21++) {
            for (int i = 0; i < array65->size; i++) {
               array65->data[i]--;
            }
            for (int i = 0; i < array65->size; i++) {
               if (array65->data[i] == 54) { 
                  return array65;
               }
            }
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array65;
         array_t* array66 = func24(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array66->id);
         free(params0.data);
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
      }
      else {
         array_t_param params0;
         params0.size = 0;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         array_t* array67 = func16(&params0, loopsFactor);
         DEBUG_RETURN(array67->id);
         free(params0.data);
         array67->refC--;
         if(array67->refC == 0) {
            free(array67->data);
            free(array67);
            DEBUG_FREE(array67->id);
         }
      }
      array_t* array68;
      if (pCounter > 0) {
         array68 = vars->data[--pCounter];
         array68->refC++;
         DEBUG_COPY(array68->id);
      } else {
         array68 = (array_t*)malloc(sizeof(array_t));
         array68->size = 464;
         array68->refC = 1;
         array68->id = 68;
         array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
         memset(array68->data, 0, array68->size*sizeof(unsigned int));
         DEBUG_NEW(array68->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array68;
      array_t* array69 = func17(&params0, loopsFactor);
      DEBUG_RETURN(array69->id);
      free(params0.data);
      if(PATH0 & 2) {
         array_t* array70;
         if (pCounter > 0) {
            array70 = vars->data[--pCounter];
            array70->refC++;
            DEBUG_COPY(array70->id);
         } else {
            array70 = (array_t*)malloc(sizeof(array_t));
            array70->size = 355;
            array70->refC = 1;
            array70->id = 70;
            array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
            memset(array70->data, 0, array70->size*sizeof(unsigned int));
            DEBUG_NEW(array70->id);
         }
         unsigned int loop22 = 0;
         unsigned int loopLimit22 = (rand()%loopsFactor)/3 + 1;
         for(; loop22 < loopLimit22; loop22++) {
            for (int i = 0; i < array69->size; i++) {
               array69->data[i]--;
            }
            for (int i = 0; i < array70->size; i++) {
               if (array70->data[i] == 11) { 
                  return array70;
               }
            }
         }
         array70->refC--;
         if(array70->refC == 0) {
            free(array70->data);
            free(array70);
            DEBUG_FREE(array70->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array68;
         params1.data[1] = array69;
         array_t* array71 = func22(&params1, loopsFactor);
         DEBUG_RETURN(array71->id);
         free(params1.data);
         array71->refC--;
         if(array71->refC == 0) {
            free(array71->data);
            free(array71);
            DEBUG_FREE(array71->id);
         }
      }
      for (int i = 0; i < array69->size; i++) {
         if (array69->data[i] == 43) { 
            return array69;
         }
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
   array_t* array72;
   if (pCounter > 0) {
      array72 = vars->data[--pCounter];
      array72->refC++;
      DEBUG_COPY(array72->id);
   } else {
      array72 = (array_t*)malloc(sizeof(array_t));
      array72->size = 746;
      array72->refC = 1;
      array72->id = 72;
      array72->data = (unsigned int*)malloc(array72->size*sizeof(unsigned int));
      memset(array72->data, 0, array72->size*sizeof(unsigned int));
      DEBUG_NEW(array72->id);
   }
   return array72;
}

