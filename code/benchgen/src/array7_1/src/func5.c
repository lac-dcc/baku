#include "array7_1.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array8;
   if (pCounter > 0) {
      array8 = vars->data[--pCounter];
      array8->refC++;
      DEBUG_COPY(array8->id);
   } else {
      array8 = (array_t*)malloc(sizeof(array_t));
      array8->size = 67;
      array8->refC = 1;
      array8->id = 8;
      array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
      memset(array8->data, 0, array8->size*sizeof(unsigned int));
      DEBUG_NEW(array8->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array8;
      array_t* array9 = func6(&params0, loopsFactor);
      DEBUG_RETURN(array9->id);
      free(params0.data);
      array9->refC--;
      if(array9->refC == 0) {
         free(array9->data);
         free(array9);
         DEBUG_FREE(array9->id);
      }
   }
   return array8;
}

