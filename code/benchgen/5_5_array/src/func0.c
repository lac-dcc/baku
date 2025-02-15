#include "outs/5_5_array.h" 
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
      array_t* array25;
      if (pCounter > 0) {
         array25 = vars->data[--pCounter];
         array25->refC++;
         DEBUG_COPY(array25->id);
      } else {
         array25 = (array_t*)malloc(sizeof(array_t));
         array25->size = 750;
         array25->refC = 1;
         array25->id = 25;
         array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
         memset(array25->data, 0, array25->size*sizeof(unsigned int));
         DEBUG_NEW(array25->id);
      }
      unsigned int loop14 = 0;
      unsigned int loopLimit14 = (rand()%loopsFactor)/3 + 1;
      for(; loop14 < loopLimit14; loop14++) {
         for (int i = 0; i < array25->size; i++) {
            array25->data[i]++;
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array25;
         array_t* array26 = func2(&params1, loopsFactor);
         DEBUG_RETURN(array26->id);
         free(params1.data);
         for (int i = 0; i < array25->size; i++) {
            if (array25->data[i] == 32) { 
               return array25;
            }
         }
         for (int i = 0; i < array1->size; i++) {
            if (array1->data[i] == 76) { 
               return array1;
            }
         }
         array26->refC--;
         if(array26->refC == 0) {
            free(array26->data);
            free(array26);
            DEBUG_FREE(array26->id);
         }
      }
      array25->refC--;
      if(array25->refC == 0) {
         free(array25->data);
         free(array25);
         DEBUG_FREE(array25->id);
      }
      array1->refC--;
      if(array1->refC == 0) {
         free(array1->data);
         free(array1);
         DEBUG_FREE(array1->id);
      }
   }
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 368;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   return array29;
}

