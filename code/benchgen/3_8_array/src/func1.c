#include "outs/3_8_array.h" 
array_t* func1(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array39;
   if (pCounter > 0) {
      array39 = vars->data[--pCounter];
      array39->refC++;
      DEBUG_COPY(array39->id);
   } else {
      array39 = (array_t*)malloc(sizeof(array_t));
      array39->size = 528;
      array39->refC = 1;
      array39->id = 39;
      array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
      memset(array39->data, 0, array39->size*sizeof(unsigned int));
      DEBUG_NEW(array39->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array39;
   array_t* array40 = func3(&params0, loopsFactor);
   DEBUG_RETURN(array40->id);
   free(params0.data);
   if(PATH0 & 1) {
      array_t* array43;
      if (pCounter > 0) {
         array43 = vars->data[--pCounter];
         array43->refC++;
         DEBUG_COPY(array43->id);
      } else {
         array43 = (array_t*)malloc(sizeof(array_t));
         array43->size = 796;
         array43->refC = 1;
         array43->id = 43;
         array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
         memset(array43->data, 0, array43->size*sizeof(unsigned int));
         DEBUG_NEW(array43->id);
      }
      unsigned int loop13 = 0;
      unsigned int loopLimit13 = (rand()%loopsFactor)/2 + 1;
      for(; loop13 < loopLimit13; loop13++) {
         for (int i = 0; i < array43->size; i++) {
            array43->data[i]--;
         }
         for (int i = 0; i < array43->size; i++) {
            if (array43->data[i] == 45) { 
               return array43;
            }
         }
      }
      array_t_param params1;
      params1.size = 3;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array39;
      params1.data[1] = array40;
      params1.data[2] = array43;
      array_t* array44 = func10(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array44->id);
      free(params1.data);
      array44->refC--;
      if(array44->refC == 0) {
         free(array44->data);
         free(array44);
         DEBUG_FREE(array44->id);
      }
      array43->refC--;
      if(array43->refC == 0) {
         free(array43->data);
         free(array43);
         DEBUG_FREE(array43->id);
      }
   }
   else {
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array39;
      params1.data[1] = array40;
      array_t* array45 = func4(&params1, loopsFactor);
      DEBUG_RETURN(array45->id);
      free(params1.data);
      array45->refC--;
      if(array45->refC == 0) {
         free(array45->data);
         free(array45);
         DEBUG_FREE(array45->id);
      }
   }
   array39->refC--;
   if(array39->refC == 0) {
      free(array39->data);
      free(array39);
      DEBUG_FREE(array39->id);
   }
   return array40;
}

