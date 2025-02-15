#include "outs/3_7_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 43;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   array_t* array30;
   if (pCounter > 0) {
      array30 = vars->data[--pCounter];
      array30->refC++;
      DEBUG_COPY(array30->id);
   } else {
      array30 = (array_t*)malloc(sizeof(array_t));
      array30->size = 750;
      array30->refC = 1;
      array30->id = 30;
      array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
      memset(array30->data, 0, array30->size*sizeof(unsigned int));
      DEBUG_NEW(array30->id);
   }
   for (int i = 0; i < array30->size; i++) {
      array30->data[i]++;
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/1 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      for (int i = 0; i < array29->size; i++) {
         array29->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array29;
   params0.data[1] = array30;
   array_t* array31 = func3(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array31->id);
   free(params0.data);
   array30->refC--;
   if(array30->refC == 0) {
      free(array30->data);
      free(array30);
      DEBUG_FREE(array30->id);
   }
   array29->refC--;
   if(array29->refC == 0) {
      free(array29->data);
      free(array29);
      DEBUG_FREE(array29->id);
   }
   return array31;
}

