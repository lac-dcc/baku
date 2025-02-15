#include "outs/5_2_array.h" 
array_t* func17(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array28;
   if (pCounter > 0) {
      array28 = vars->data[--pCounter];
      array28->refC++;
      DEBUG_COPY(array28->id);
   } else {
      array28 = (array_t*)malloc(sizeof(array_t));
      array28->size = 434;
      array28->refC = 1;
      array28->id = 28;
      array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
      memset(array28->data, 0, array28->size*sizeof(unsigned int));
      DEBUG_NEW(array28->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      for (int i = 0; i < array28->size; i++) {
         array28->data[i]++;
      }
      for (int i = 0; i < array28->size; i++) {
         if (array28->data[i] == 50) { 
            return array28;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array28;
         array_t* array29 = func24(&params0, loopsFactor);
         DEBUG_RETURN(array29->id);
         free(params0.data);
         array_t* array30;
         if (pCounter > 0) {
            array30 = vars->data[--pCounter];
            array30->refC++;
            DEBUG_COPY(array30->id);
         } else {
            array30 = (array_t*)malloc(sizeof(array_t));
            array30->size = 276;
            array30->refC = 1;
            array30->id = 30;
            array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
            memset(array30->data, 0, array30->size*sizeof(unsigned int));
            DEBUG_NEW(array30->id);
         }
         array30->refC--;
         if(array30->refC == 0) {
            free(array30->data);
            free(array30);
            DEBUG_FREE(array30->id);
         }
         array29->refC--;
         if(array29->refC == 0) {
            free(array29->data);
            free(array29);
            DEBUG_FREE(array29->id);
         }
      }
      else {
      }
   }
   array_t* array31;
   if (pCounter > 0) {
      array31 = vars->data[--pCounter];
      array31->refC++;
      DEBUG_COPY(array31->id);
   } else {
      array31 = (array_t*)malloc(sizeof(array_t));
      array31->size = 178;
      array31->refC = 1;
      array31->id = 31;
      array31->data = (unsigned int*)malloc(array31->size*sizeof(unsigned int));
      memset(array31->data, 0, array31->size*sizeof(unsigned int));
      DEBUG_NEW(array31->id);
   }
   array31->refC--;
   if(array31->refC == 0) {
      free(array31->data);
      free(array31);
      DEBUG_FREE(array31->id);
   }
   return array28;
}

