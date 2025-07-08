#include "array5_7.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array3;
   if (pCounter > 0) {
      array3 = vars->data[--pCounter];
      array3->refC++;
      DEBUG_COPY(array3->id);
   } else {
      array3 = (array_t*)malloc(sizeof(array_t));
      array3->size = 690;
      array3->refC = 1;
      array3->id = 3;
      array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
      memset(array3->data, 0, array3->size*sizeof(unsigned int));
      DEBUG_NEW(array3->id);
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      for (int i = 0; i < array3->size; i++) {
         array3->data[i]++;
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array3;
      array_t* array4 = func2(&params0, loopsFactor);
      DEBUG_RETURN(array4->id);
      free(params0.data);
      array4->refC--;
      if(array4->refC == 0) {
         free(array4->data);
         free(array4);
         DEBUG_FREE(array4->id);
      }
   }
   return array3;
}

