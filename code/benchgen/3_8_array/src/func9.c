#include "outs/3_8_array.h" 
array_t* func9(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 467;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array29;
   array_t* array30 = func15(&params0, loopsFactor);
   DEBUG_RETURN(array30->id);
   free(params0.data);
   array30->refC--;
   if(array30->refC == 0) {
      free(array30->data);
      free(array30);
      DEBUG_FREE(array30->id);
   }
   return array29;
}

