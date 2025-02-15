#include "outs/5_8_array.h" 
array_t* func11(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/3 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      if(PATH0 & 1) {
         array_t* array5;
         if (pCounter > 0) {
            array5 = vars->data[--pCounter];
            array5->refC++;
            DEBUG_COPY(array5->id);
         } else {
            array5 = (array_t*)malloc(sizeof(array_t));
            array5->size = 736;
            array5->refC = 1;
            array5->id = 5;
            array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
            memset(array5->data, 0, array5->size*sizeof(unsigned int));
            DEBUG_NEW(array5->id);
         }
         unsigned int loop4 = 0;
         unsigned int loopLimit4 = (rand()%loopsFactor)/4 + 1;
         for(; loop4 < loopLimit4; loop4++) {
            for (int i = 0; i < array5->size; i++) {
               array5->data[i]--;
            }
            for (int i = 0; i < array5->size; i++) {
               if (array5->data[i] == 67) { 
                  return array5;
               }
            }
         }
         array5->refC--;
         if(array5->refC == 0) {
            free(array5->data);
            free(array5);
            DEBUG_FREE(array5->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 0;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         array_t* array6 = func22(&params0, loopsFactor);
         DEBUG_RETURN(array6->id);
         free(params0.data);
         array6->refC--;
         if(array6->refC == 0) {
            free(array6->data);
            free(array6);
            DEBUG_FREE(array6->id);
         }
      }
      array_t* array8;
      if (pCounter > 0) {
         array8 = vars->data[--pCounter];
         array8->refC++;
         DEBUG_COPY(array8->id);
      } else {
         array8 = (array_t*)malloc(sizeof(array_t));
         array8->size = 22;
         array8->refC = 1;
         array8->id = 8;
         array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
         memset(array8->data, 0, array8->size*sizeof(unsigned int));
         DEBUG_NEW(array8->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array8;
      array_t* array9 = func23(&params0, loopsFactor);
      DEBUG_RETURN(array9->id);
      free(params0.data);
      for (int i = 0; i < array9->size; i++) {
         if (array9->data[i] == 19) { 
            return array9;
         }
      }
      array9->refC--;
      if(array9->refC == 0) {
         free(array9->data);
         free(array9);
         DEBUG_FREE(array9->id);
      }
      array8->refC--;
      if(array8->refC == 0) {
         free(array8->data);
         free(array8);
         DEBUG_FREE(array8->id);
      }
   }
   array_t* array11;
   if (pCounter > 0) {
      array11 = vars->data[--pCounter];
      array11->refC++;
      DEBUG_COPY(array11->id);
   } else {
      array11 = (array_t*)malloc(sizeof(array_t));
      array11->size = 784;
      array11->refC = 1;
      array11->id = 11;
      array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
      memset(array11->data, 0, array11->size*sizeof(unsigned int));
      DEBUG_NEW(array11->id);
   }
   return array11;
}

