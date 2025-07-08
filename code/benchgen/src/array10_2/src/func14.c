#include "array10_2.h" 
array_t* func14(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array49 = func15(&params0, loopsFactor);
      DEBUG_RETURN(array49->id);
      free(params0.data);
      array49->refC--;
      if(array49->refC == 0) {
         free(array49->data);
         free(array49);
         DEBUG_FREE(array49->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array51 = func16(&params0, loopsFactor);
      DEBUG_RETURN(array51->id);
      free(params0.data);
      array51->refC--;
      if(array51->refC == 0) {
         free(array51->data);
         free(array51);
         DEBUG_FREE(array51->id);
      }
   }
   array_t* array68;
   if (pCounter > 0) {
      array68 = vars->data[--pCounter];
      array68->refC++;
      DEBUG_COPY(array68->id);
   } else {
      array68 = (array_t*)malloc(sizeof(array_t));
      array68->size = 529;
      array68->refC = 1;
      array68->id = 68;
      array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
      memset(array68->data, 0, array68->size*sizeof(unsigned int));
      DEBUG_NEW(array68->id);
   }
   return array68;
}

