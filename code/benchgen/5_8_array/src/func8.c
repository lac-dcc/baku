#include "outs/5_8_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t* array74;
      if (pCounter > 0) {
         array74 = vars->data[--pCounter];
         array74->refC++;
         DEBUG_COPY(array74->id);
      } else {
         array74 = (array_t*)malloc(sizeof(array_t));
         array74->size = 605;
         array74->refC = 1;
         array74->id = 74;
         array74->data = (unsigned int*)malloc(array74->size*sizeof(unsigned int));
         memset(array74->data, 0, array74->size*sizeof(unsigned int));
         DEBUG_NEW(array74->id);
      }
      unsigned int loop23 = 0;
      unsigned int loopLimit23 = (rand()%loopsFactor)/2 + 1;
      for(; loop23 < loopLimit23; loop23++) {
         for (int i = 0; i < array74->size; i++) {
            array74->data[i]--;
         }
         for (int i = 0; i < array74->size; i++) {
            if (array74->data[i] == 30) { 
               return array74;
            }
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array74;
      array_t* array75 = func18(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array75->id);
      free(params0.data);
      array75->refC--;
      if(array75->refC == 0) {
         free(array75->data);
         free(array75);
         DEBUG_FREE(array75->id);
      }
      array74->refC--;
      if(array74->refC == 0) {
         free(array74->data);
         free(array74);
         DEBUG_FREE(array74->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array76 = func14(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array76->id);
      free(params0.data);
      array76->refC--;
      if(array76->refC == 0) {
         free(array76->data);
         free(array76);
         DEBUG_FREE(array76->id);
      }
   }
   array_t* array77;
   if (pCounter > 0) {
      array77 = vars->data[--pCounter];
      array77->refC++;
      DEBUG_COPY(array77->id);
   } else {
      array77 = (array_t*)malloc(sizeof(array_t));
      array77->size = 444;
      array77->refC = 1;
      array77->id = 77;
      array77->data = (unsigned int*)malloc(array77->size*sizeof(unsigned int));
      memset(array77->data, 0, array77->size*sizeof(unsigned int));
      DEBUG_NEW(array77->id);
   }
   return array77;
}

