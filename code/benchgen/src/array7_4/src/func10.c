#include "array7_4.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      array_t* array32;
      if (pCounter > 0) {
         array32 = vars->data[--pCounter];
         array32->refC++;
         DEBUG_COPY(array32->id);
      } else {
         array32 = (array_t*)malloc(sizeof(array_t));
         array32->size = 94;
         array32->refC = 1;
         array32->id = 32;
         array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
         memset(array32->data, 0, array32->size*sizeof(unsigned int));
         DEBUG_NEW(array32->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array32;
      array_t* array33 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array33->id);
      free(params0.data);
      array33->refC--;
      if(array33->refC == 0) {
         free(array33->data);
         free(array33);
         DEBUG_FREE(array33->id);
      }
      array32->refC--;
      if(array32->refC == 0) {
         free(array32->data);
         free(array32);
         DEBUG_FREE(array32->id);
      }
   }
   array_t* array50;
   if (pCounter > 0) {
      array50 = vars->data[--pCounter];
      array50->refC++;
      DEBUG_COPY(array50->id);
   } else {
      array50 = (array_t*)malloc(sizeof(array_t));
      array50->size = 796;
      array50->refC = 1;
      array50->id = 50;
      array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
      memset(array50->data, 0, array50->size*sizeof(unsigned int));
      DEBUG_NEW(array50->id);
   }
   return array50;
}

