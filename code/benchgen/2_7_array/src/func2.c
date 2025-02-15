#include "outs/2_7_array.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array9;
   if (pCounter > 0) {
      array9 = vars->data[--pCounter];
      array9->refC++;
      DEBUG_COPY(array9->id);
   } else {
      array9 = (array_t*)malloc(sizeof(array_t));
      array9->size = 530;
      array9->refC = 1;
      array9->id = 9;
      array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
      memset(array9->data, 0, array9->size*sizeof(unsigned int));
      DEBUG_NEW(array9->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array9;
   array_t* array10 = func5(&params0, loopsFactor);
   DEBUG_RETURN(array10->id);
   free(params0.data);
   array10->refC--;
   if(array10->refC == 0) {
      free(array10->data);
      free(array10);
      DEBUG_FREE(array10->id);
   }
   return array9;
}

