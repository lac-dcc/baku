#include "array7_8.h" 
array_t* func0(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      array_t* array1;
      if (pCounter > 0) {
         array1 = vars->data[--pCounter];
         array1->refC++;
         DEBUG_COPY(array1->id);
      } else {
         array1 = (array_t*)malloc(sizeof(array_t));
         array1->size = 386;
         array1->refC = 1;
         array1->id = 1;
         array1->data = (unsigned int*)malloc(array1->size*sizeof(unsigned int));
         memset(array1->data, 0, array1->size*sizeof(unsigned int));
         DEBUG_NEW(array1->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array1;
      array_t* array2 = func5(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array2->id);
      free(params0.data);
      array2->refC--;
      if(array2->refC == 0) {
         free(array2->data);
         free(array2);
         DEBUG_FREE(array2->id);
      }
      array1->refC--;
      if(array1->refC == 0) {
         free(array1->data);
         free(array1);
         DEBUG_FREE(array1->id);
      }
   }
   array_t* array18;
   if (pCounter > 0) {
      array18 = vars->data[--pCounter];
      array18->refC++;
      DEBUG_COPY(array18->id);
   } else {
      array18 = (array_t*)malloc(sizeof(array_t));
      array18->size = 873;
      array18->refC = 1;
      array18->id = 18;
      array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
      memset(array18->data, 0, array18->size*sizeof(unsigned int));
      DEBUG_NEW(array18->id);
   }
   return array18;
}

