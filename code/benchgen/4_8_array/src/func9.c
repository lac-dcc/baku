#include "outs/4_8_array.h" 
array_t* func9(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array50;
   if (pCounter > 0) {
      array50 = vars->data[--pCounter];
      array50->refC++;
      DEBUG_COPY(array50->id);
   } else {
      array50 = (array_t*)malloc(sizeof(array_t));
      array50->size = 856;
      array50->refC = 1;
      array50->id = 50;
      array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
      memset(array50->data, 0, array50->size*sizeof(unsigned int));
      DEBUG_NEW(array50->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array50;
   array_t* array51 = func15(&params0, loopsFactor);
   DEBUG_RETURN(array51->id);
   free(params0.data);
   if(PATH0 & 1) {
      array_t* array54;
      if (pCounter > 0) {
         array54 = vars->data[--pCounter];
         array54->refC++;
         DEBUG_COPY(array54->id);
      } else {
         array54 = (array_t*)malloc(sizeof(array_t));
         array54->size = 407;
         array54->refC = 1;
         array54->id = 54;
         array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
         memset(array54->data, 0, array54->size*sizeof(unsigned int));
         DEBUG_NEW(array54->id);
      }
      unsigned int loop16 = 0;
      unsigned int loopLimit16 = (rand()%loopsFactor)/2 + 1;
      for(; loop16 < loopLimit16; loop16++) {
         for (int i = 0; i < array50->size; i++) {
            array50->data[i]--;
         }
         for (int i = 0; i < array51->size; i++) {
            if (array51->data[i] == 58) { 
               return array51;
            }
         }
      }
      array54->refC--;
      if(array54->refC == 0) {
         free(array54->data);
         free(array54);
         DEBUG_FREE(array54->id);
      }
   }
   else {
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array50;
      params1.data[1] = array51;
      array_t* array55 = func16(&params1, loopsFactor);
      DEBUG_RETURN(array55->id);
      free(params1.data);
      array55->refC--;
      if(array55->refC == 0) {
         free(array55->data);
         free(array55);
         DEBUG_FREE(array55->id);
      }
   }
   array50->refC--;
   if(array50->refC == 0) {
      free(array50->data);
      free(array50);
      DEBUG_FREE(array50->id);
   }
   return array51;
}

