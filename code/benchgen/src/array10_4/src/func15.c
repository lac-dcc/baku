#include "array10_4.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array49;
   if (pCounter > 0) {
      array49 = vars->data[--pCounter];
      array49->refC++;
      DEBUG_COPY(array49->id);
   } else {
      array49 = (array_t*)malloc(sizeof(array_t));
      array49->size = 715;
      array49->refC = 1;
      array49->id = 49;
      array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
      memset(array49->data, 0, array49->size*sizeof(unsigned int));
      DEBUG_NEW(array49->id);
   }
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/4 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array49;
      array_t* array50 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array50->id);
      free(params0.data);
      array50->refC--;
      if(array50->refC == 0) {
         free(array50->data);
         free(array50);
         DEBUG_FREE(array50->id);
      }
   }
   return array49;
}

