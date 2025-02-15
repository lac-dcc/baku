#include "outs/4_8_array.h" 
array_t* func1(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array66;
   if (pCounter > 0) {
      array66 = vars->data[--pCounter];
      array66->refC++;
      DEBUG_COPY(array66->id);
   } else {
      array66 = (array_t*)malloc(sizeof(array_t));
      array66->size = 590;
      array66->refC = 1;
      array66->id = 66;
      array66->data = (unsigned int*)malloc(array66->size*sizeof(unsigned int));
      memset(array66->data, 0, array66->size*sizeof(unsigned int));
      DEBUG_NEW(array66->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array66;
   array_t* array67 = func3(&params0, loopsFactor);
   DEBUG_RETURN(array67->id);
   free(params0.data);
   if(PATH0 & 1) {
      array_t* array70;
      if (pCounter > 0) {
         array70 = vars->data[--pCounter];
         array70->refC++;
         DEBUG_COPY(array70->id);
      } else {
         array70 = (array_t*)malloc(sizeof(array_t));
         array70->size = 804;
         array70->refC = 1;
         array70->id = 70;
         array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
         memset(array70->data, 0, array70->size*sizeof(unsigned int));
         DEBUG_NEW(array70->id);
      }
      unsigned int loop21 = 0;
      unsigned int loopLimit21 = (rand()%loopsFactor)/2 + 1;
      for(; loop21 < loopLimit21; loop21++) {
         for (int i = 0; i < array70->size; i++) {
            array70->data[i]--;
         }
         for (int i = 0; i < array70->size; i++) {
            if (array70->data[i] == 22) { 
               return array70;
            }
         }
      }
      array_t_param params1;
      params1.size = 3;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array66;
      params1.data[1] = array67;
      params1.data[2] = array70;
      array_t* array71 = func10(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array71->id);
      free(params1.data);
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
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array66;
      params1.data[1] = array67;
      array_t* array72 = func4(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array72->id);
      free(params1.data);
      array72->refC--;
      if(array72->refC == 0) {
         free(array72->data);
         free(array72);
         DEBUG_FREE(array72->id);
      }
   }
   array67->refC--;
   if(array67->refC == 0) {
      free(array67->data);
      free(array67);
      DEBUG_FREE(array67->id);
   }
   return array66;
}

