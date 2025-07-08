#include "array8_1.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array2;
   if (pCounter > 0) {
      array2 = vars->data[--pCounter];
      array2->refC++;
      DEBUG_COPY(array2->id);
   } else {
      array2 = (array_t*)malloc(sizeof(array_t));
      array2->size = 362;
      array2->refC = 1;
      array2->id = 2;
      array2->data = (unsigned int*)malloc(array2->size*sizeof(unsigned int));
      memset(array2->data, 0, array2->size*sizeof(unsigned int));
      DEBUG_NEW(array2->id);
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array2;
      array_t* array3 = func2(&params0, loopsFactor);
      DEBUG_RETURN(array3->id);
      free(params0.data);
      array3->refC--;
      if(array3->refC == 0) {
         free(array3->data);
         free(array3);
         DEBUG_FREE(array3->id);
      }
   }
   return array2;
}

