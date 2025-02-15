#include "outs/5_2_array.h" 
array_t* func20(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array63 = func25(&params0, loopsFactor);
   DEBUG_RETURN(array63->id);
   free(params0.data);
   for (int i = 0; i < array63->size; i++) {
      if (array63->data[i] == 46) { 
         return array63;
      }
   }
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/3 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      for (int i = 0; i < array63->size; i++) {
         array63->data[i]--;
      }
      for (int i = 0; i < array63->size; i++) {
         if (array63->data[i] == 55) { 
            return array63;
         }
      }
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array63;
   array_t* array64 = func26(&params1, loopsFactor);
   DEBUG_RETURN(array64->id);
   free(params1.data);
   array_t* array65;
   if (pCounter > 0) {
      array65 = vars->data[--pCounter];
      array65->refC++;
      DEBUG_COPY(array65->id);
   } else {
      array65 = (array_t*)malloc(sizeof(array_t));
      array65->size = 764;
      array65->refC = 1;
      array65->id = 65;
      array65->data = (unsigned int*)malloc(array65->size*sizeof(unsigned int));
      memset(array65->data, 0, array65->size*sizeof(unsigned int));
      DEBUG_NEW(array65->id);
   }
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
   array63->refC--;
   if(array63->refC == 0) {
      free(array63->data);
      free(array63);
      DEBUG_FREE(array63->id);
   }
   return array64;
}

