#include "array5_6.h" 
array_t* func0(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
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
   array_t* array8;
   if (pCounter > 0) {
      array8 = vars->data[--pCounter];
      array8->refC++;
      DEBUG_COPY(array8->id);
   } else {
      array8 = (array_t*)malloc(sizeof(array_t));
      array8->size = 530;
      array8->refC = 1;
      array8->id = 8;
      array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
      memset(array8->data, 0, array8->size*sizeof(unsigned int));
      DEBUG_NEW(array8->id);
   }
   return array8;
}

