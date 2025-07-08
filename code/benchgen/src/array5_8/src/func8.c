#include "array5_8.h" 
array_t* func8(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/1 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      array_t* array21;
      if (pCounter > 0) {
         array21 = vars->data[--pCounter];
         array21->refC++;
         DEBUG_COPY(array21->id);
      } else {
         array21 = (array_t*)malloc(sizeof(array_t));
         array21->size = 729;
         array21->refC = 1;
         array21->id = 21;
         array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
         memset(array21->data, 0, array21->size*sizeof(unsigned int));
         DEBUG_NEW(array21->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array21;
      array_t* array22 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array22->id);
      free(params0.data);
      array22->refC--;
      if(array22->refC == 0) {
         free(array22->data);
         free(array22);
         DEBUG_FREE(array22->id);
      }
      array21->refC--;
      if(array21->refC == 0) {
         free(array21->data);
         free(array21);
         DEBUG_FREE(array21->id);
      }
   }
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 60;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   return array29;
}

