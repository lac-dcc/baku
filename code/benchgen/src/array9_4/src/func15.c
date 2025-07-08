#include "array9_4.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array48;
   if (pCounter > 0) {
      array48 = vars->data[--pCounter];
      array48->refC++;
      DEBUG_COPY(array48->id);
   } else {
      array48 = (array_t*)malloc(sizeof(array_t));
      array48->size = 708;
      array48->refC = 1;
      array48->id = 48;
      array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
      memset(array48->data, 0, array48->size*sizeof(unsigned int));
      DEBUG_NEW(array48->id);
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/4 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array48;
      array_t* array49 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array49->id);
      free(params0.data);
      array49->refC--;
      if(array49->refC == 0) {
         free(array49->data);
         free(array49);
         DEBUG_FREE(array49->id);
      }
   }
   return array48;
}

