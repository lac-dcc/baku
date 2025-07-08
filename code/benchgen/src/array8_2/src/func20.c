#include "array8_2.h" 
array_t* func20(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array47 = func21(&params0, loopsFactor);
      DEBUG_RETURN(array47->id);
      free(params0.data);
      array47->refC--;
      if(array47->refC == 0) {
         free(array47->data);
         free(array47);
         DEBUG_FREE(array47->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array49 = func22(&params0, loopsFactor);
      DEBUG_RETURN(array49->id);
      free(params0.data);
      array49->refC--;
      if(array49->refC == 0) {
         free(array49->data);
         free(array49);
         DEBUG_FREE(array49->id);
      }
   }
   array_t* array52;
   if (pCounter > 0) {
      array52 = vars->data[--pCounter];
      array52->refC++;
      DEBUG_COPY(array52->id);
   } else {
      array52 = (array_t*)malloc(sizeof(array_t));
      array52->size = 618;
      array52->refC = 1;
      array52->id = 52;
      array52->data = (unsigned int*)malloc(array52->size*sizeof(unsigned int));
      memset(array52->data, 0, array52->size*sizeof(unsigned int));
      DEBUG_NEW(array52->id);
   }
   return array52;
}

