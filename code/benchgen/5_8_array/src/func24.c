#include "outs/5_8_array.h" 
array_t* func24(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array15 = func25(&params0, loopsFactor);
      DEBUG_RETURN(array15->id);
      free(params0.data);
      array15->refC--;
      if(array15->refC == 0) {
         free(array15->data);
         free(array15);
         DEBUG_FREE(array15->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array17 = func26(&params0, loopsFactor);
      DEBUG_RETURN(array17->id);
      free(params0.data);
      array17->refC--;
      if(array17->refC == 0) {
         free(array17->data);
         free(array17);
         DEBUG_FREE(array17->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array19 = func27(&params0, loopsFactor);
   DEBUG_RETURN(array19->id);
   free(params0.data);
   return array19;
}

