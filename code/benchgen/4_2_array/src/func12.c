#include "outs/4_2_array.h" 
array_t* func12(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array8 = func17(&params0, loopsFactor);
   DEBUG_RETURN(array8->id);
   free(params0.data);
   for (int i = 0; i < array8->size; i++) {
      if (array8->data[i] == 2) { 
         return array8;
      }
   }
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/3 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      for (int i = 0; i < array8->size; i++) {
         array8->data[i]--;
      }
      for (int i = 0; i < array8->size; i++) {
         if (array8->data[i] == 69) { 
            return array8;
         }
      }
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array8;
   array_t* array10 = func18(&params1, loopsFactor);
   DEBUG_RETURN(array10->id);
   free(params1.data);
   array_t* array12;
   if (pCounter > 0) {
      array12 = vars->data[--pCounter];
      array12->refC++;
      DEBUG_COPY(array12->id);
   } else {
      array12 = (array_t*)malloc(sizeof(array_t));
      array12->size = 373;
      array12->refC = 1;
      array12->id = 12;
      array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
      memset(array12->data, 0, array12->size*sizeof(unsigned int));
      DEBUG_NEW(array12->id);
   }
   array_t* array13;
   if (pCounter > 0) {
      array13 = vars->data[--pCounter];
      array13->refC++;
      DEBUG_COPY(array13->id);
   } else {
      array13 = (array_t*)malloc(sizeof(array_t));
      array13->size = 421;
      array13->refC = 1;
      array13->id = 13;
      array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
      memset(array13->data, 0, array13->size*sizeof(unsigned int));
      DEBUG_NEW(array13->id);
   }
   array12->refC--;
   if(array12->refC == 0) {
      free(array12->data);
      free(array12);
      DEBUG_FREE(array12->id);
   }
   array10->refC--;
   if(array10->refC == 0) {
      free(array10->data);
      free(array10);
      DEBUG_FREE(array10->id);
   }
   array8->refC--;
   if(array8->refC == 0) {
      free(array8->data);
      free(array8);
      DEBUG_FREE(array8->id);
   }
   return array13;
}

