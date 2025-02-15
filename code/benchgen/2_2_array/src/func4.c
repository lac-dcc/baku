#include "outs/2_2_array.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array27;
   if (pCounter > 0) {
      array27 = vars->data[--pCounter];
      array27->refC++;
      DEBUG_COPY(array27->id);
   } else {
      array27 = (array_t*)malloc(sizeof(array_t));
      array27->size = 545;
      array27->refC = 1;
      array27->id = 27;
      array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
      memset(array27->data, 0, array27->size*sizeof(unsigned int));
      DEBUG_NEW(array27->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array27;
   array_t* array28 = func10(&params0, loopsFactor);
   DEBUG_RETURN(array28->id);
   free(params0.data);
   for (int i = 0; i < array28->size; i++) {
      if (array28->data[i] == 8) { 
         return array28;
      }
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/2 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      for (int i = 0; i < array27->size; i++) {
         array27->data[i]--;
      }
      for (int i = 0; i < array27->size; i++) {
         if (array27->data[i] == 88) { 
            return array27;
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array27;
   params1.data[1] = array28;
   array_t* array30 = func11(&params1, loopsFactor);
   DEBUG_RETURN(array30->id);
   free(params1.data);
   array_t* array32;
   if (pCounter > 0) {
      array32 = vars->data[--pCounter];
      array32->refC++;
      DEBUG_COPY(array32->id);
   } else {
      array32 = (array_t*)malloc(sizeof(array_t));
      array32->size = 60;
      array32->refC = 1;
      array32->id = 32;
      array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
      memset(array32->data, 0, array32->size*sizeof(unsigned int));
      DEBUG_NEW(array32->id);
   }
   array_t* array33;
   if (pCounter > 0) {
      array33 = vars->data[--pCounter];
      array33->refC++;
      DEBUG_COPY(array33->id);
   } else {
      array33 = (array_t*)malloc(sizeof(array_t));
      array33->size = 676;
      array33->refC = 1;
      array33->id = 33;
      array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
      memset(array33->data, 0, array33->size*sizeof(unsigned int));
      DEBUG_NEW(array33->id);
   }
   array33->refC--;
   if(array33->refC == 0) {
      free(array33->data);
      free(array33);
      DEBUG_FREE(array33->id);
   }
   array30->refC--;
   if(array30->refC == 0) {
      free(array30->data);
      free(array30);
      DEBUG_FREE(array30->id);
   }
   array28->refC--;
   if(array28->refC == 0) {
      free(array28->data);
      free(array28);
      DEBUG_FREE(array28->id);
   }
   array27->refC--;
   if(array27->refC == 0) {
      free(array27->data);
      free(array27);
      DEBUG_FREE(array27->id);
   }
   return array32;
}

