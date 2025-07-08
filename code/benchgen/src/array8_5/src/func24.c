#include "array8_5.h" 
array_t* func24(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array33 = func25(&params0, loopsFactor);
      DEBUG_RETURN(array33->id);
      free(params0.data);
      array33->refC--;
      if(array33->refC == 0) {
         free(array33->data);
         free(array33);
         DEBUG_FREE(array33->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array35 = func26(&params0, loopsFactor);
      DEBUG_RETURN(array35->id);
      free(params0.data);
      array35->refC--;
      if(array35->refC == 0) {
         free(array35->data);
         free(array35);
         DEBUG_FREE(array35->id);
      }
   }
   array_t* array37;
   if (pCounter > 0) {
      array37 = vars->data[--pCounter];
      array37->refC++;
      DEBUG_COPY(array37->id);
   } else {
      array37 = (array_t*)malloc(sizeof(array_t));
      array37->size = 771;
      array37->refC = 1;
      array37->id = 37;
      array37->data = (unsigned int*)malloc(array37->size*sizeof(unsigned int));
      memset(array37->data, 0, array37->size*sizeof(unsigned int));
      DEBUG_NEW(array37->id);
   }
   return array37;
}

