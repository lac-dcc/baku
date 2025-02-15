#include "outs/1_8_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array7;
   if (pCounter > 0) {
      array7 = vars->data[--pCounter];
      array7->refC++;
      DEBUG_COPY(array7->id);
   } else {
      array7 = (array_t*)malloc(sizeof(array_t));
      array7->size = 67;
      array7->refC = 1;
      array7->id = 7;
      array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
      memset(array7->data, 0, array7->size*sizeof(unsigned int));
      DEBUG_NEW(array7->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array7;
   array_t* array8 = func3(&params0, loopsFactor);
   DEBUG_RETURN(array8->id);
   free(params0.data);
   array7->refC--;
   if(array7->refC == 0) {
      free(array7->data);
      free(array7);
      DEBUG_FREE(array7->id);
   }
   return array8;
}

