#include "array8_2.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      array_t* array45;
      if (pCounter > 0) {
         array45 = vars->data[--pCounter];
         array45->refC++;
         DEBUG_COPY(array45->id);
      } else {
         array45 = (array_t*)malloc(sizeof(array_t));
         array45->size = 306;
         array45->refC = 1;
         array45->id = 45;
         array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
         memset(array45->data, 0, array45->size*sizeof(unsigned int));
         DEBUG_NEW(array45->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array45;
      array_t* array46 = func20(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array46->id);
      free(params0.data);
      for (int i = 0; i < array45->size; i++) {
         array45->data[i]++;
      }
      array46->refC--;
      if(array46->refC == 0) {
         free(array46->data);
         free(array46);
         DEBUG_FREE(array46->id);
      }
      array45->refC--;
      if(array45->refC == 0) {
         free(array45->data);
         free(array45);
         DEBUG_FREE(array45->id);
      }
   }
   array_t* array53;
   if (pCounter > 0) {
      array53 = vars->data[--pCounter];
      array53->refC++;
      DEBUG_COPY(array53->id);
   } else {
      array53 = (array_t*)malloc(sizeof(array_t));
      array53->size = 451;
      array53->refC = 1;
      array53->id = 53;
      array53->data = (unsigned int*)malloc(array53->size*sizeof(unsigned int));
      memset(array53->data, 0, array53->size*sizeof(unsigned int));
      DEBUG_NEW(array53->id);
   }
   return array53;
}

