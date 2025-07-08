#include "array8_8.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      array_t* array33;
      if (pCounter > 0) {
         array33 = vars->data[--pCounter];
         array33->refC++;
         DEBUG_COPY(array33->id);
      } else {
         array33 = (array_t*)malloc(sizeof(array_t));
         array33->size = 467;
         array33->refC = 1;
         array33->id = 33;
         array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
         memset(array33->data, 0, array33->size*sizeof(unsigned int));
         DEBUG_NEW(array33->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array33;
      array_t* array34 = func18(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array34->id);
      free(params0.data);
      array34->refC--;
      if(array34->refC == 0) {
         free(array34->data);
         free(array34);
         DEBUG_FREE(array34->id);
      }
      array33->refC--;
      if(array33->refC == 0) {
         free(array33->data);
         free(array33);
         DEBUG_FREE(array33->id);
      }
   }
   array_t* array41;
   if (pCounter > 0) {
      array41 = vars->data[--pCounter];
      array41->refC++;
      DEBUG_COPY(array41->id);
   } else {
      array41 = (array_t*)malloc(sizeof(array_t));
      array41->size = 709;
      array41->refC = 1;
      array41->id = 41;
      array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
      memset(array41->data, 0, array41->size*sizeof(unsigned int));
      DEBUG_NEW(array41->id);
   }
   return array41;
}

