#include "outs/2_5_array.h" 
array_t* func0(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array1 = func3(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array1->id);
      free(params0.data);
      array_t* array5;
      if (pCounter > 0) {
         array5 = vars->data[--pCounter];
         array5->refC++;
         DEBUG_COPY(array5->id);
      } else {
         array5 = (array_t*)malloc(sizeof(array_t));
         array5->size = 763;
         array5->refC = 1;
         array5->id = 5;
         array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
         memset(array5->data, 0, array5->size*sizeof(unsigned int));
         DEBUG_NEW(array5->id);
      }
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/3 + 1;
      for(; loop4 < loopLimit4; loop4++) {
         for (int i = 0; i < array1->size; i++) {
            array1->data[i]++;
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array5;
         array_t* array6 = func2(&params1, loopsFactor);
         DEBUG_RETURN(array6->id);
         free(params1.data);
         for (int i = 0; i < array6->size; i++) {
            if (array6->data[i] == 30) { 
               return array6;
            }
         }
         for (int i = 0; i < array6->size; i++) {
            if (array6->data[i] == 23) { 
               return array6;
            }
         }
         array6->refC--;
         if(array6->refC == 0) {
            free(array6->data);
            free(array6);
            DEBUG_FREE(array6->id);
         }
      }
      array5->refC--;
      if(array5->refC == 0) {
         free(array5->data);
         free(array5);
         DEBUG_FREE(array5->id);
      }
      array1->refC--;
      if(array1->refC == 0) {
         free(array1->data);
         free(array1);
         DEBUG_FREE(array1->id);
      }
   }
   array_t* array9;
   if (pCounter > 0) {
      array9 = vars->data[--pCounter];
      array9->refC++;
      DEBUG_COPY(array9->id);
   } else {
      array9 = (array_t*)malloc(sizeof(array_t));
      array9->size = 67;
      array9->refC = 1;
      array9->id = 9;
      array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
      memset(array9->data, 0, array9->size*sizeof(unsigned int));
      DEBUG_NEW(array9->id);
   }
   return array9;
}

