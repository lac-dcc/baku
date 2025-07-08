#include "array9_4.h" 
array_t* func29(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array26;
   if (pCounter > 0) {
      array26 = vars->data[--pCounter];
      array26->refC++;
      DEBUG_COPY(array26->id);
   } else {
      array26 = (array_t*)malloc(sizeof(array_t));
      array26->size = 750;
      array26->refC = 1;
      array26->id = 26;
      array26->data = (unsigned int*)malloc(array26->size*sizeof(unsigned int));
      memset(array26->data, 0, array26->size*sizeof(unsigned int));
      DEBUG_NEW(array26->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array26;
      array_t* array27 = func31(&params0, loopsFactor);
      DEBUG_RETURN(array27->id);
      free(params0.data);
      array27->refC--;
      if(array27->refC == 0) {
         free(array27->data);
         free(array27);
         DEBUG_FREE(array27->id);
      }
   }
   return array26;
}

