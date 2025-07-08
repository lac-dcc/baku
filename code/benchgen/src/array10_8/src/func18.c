#include "array10_8.h" 
array_t* func18(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array37 = func19(&params0, loopsFactor);
      DEBUG_RETURN(array37->id);
      free(params0.data);
      array37->refC--;
      if(array37->refC == 0) {
         free(array37->data);
         free(array37);
         DEBUG_FREE(array37->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array47 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array47->id);
      free(params0.data);
      array47->refC--;
      if(array47->refC == 0) {
         free(array47->data);
         free(array47);
         DEBUG_FREE(array47->id);
      }
   }
   array_t* array49;
   if (pCounter > 0) {
      array49 = vars->data[--pCounter];
      array49->refC++;
      DEBUG_COPY(array49->id);
   } else {
      array49 = (array_t*)malloc(sizeof(array_t));
      array49->size = 149;
      array49->refC = 1;
      array49->id = 49;
      array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
      memset(array49->data, 0, array49->size*sizeof(unsigned int));
      DEBUG_NEW(array49->id);
   }
   return array49;
}

