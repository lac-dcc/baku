#include "array9_4.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/3 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      array_t* array41;
      if (pCounter > 0) {
         array41 = vars->data[--pCounter];
         array41->refC++;
         DEBUG_COPY(array41->id);
      } else {
         array41 = (array_t*)malloc(sizeof(array_t));
         array41->size = 675;
         array41->refC = 1;
         array41->id = 41;
         array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
         memset(array41->data, 0, array41->size*sizeof(unsigned int));
         DEBUG_NEW(array41->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array41;
      array_t* array42 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array42->id);
      free(params0.data);
      array42->refC--;
      if(array42->refC == 0) {
         free(array42->data);
         free(array42);
         DEBUG_FREE(array42->id);
      }
      array41->refC--;
      if(array41->refC == 0) {
         free(array41->data);
         free(array41);
         DEBUG_FREE(array41->id);
      }
   }
   array_t* array62;
   if (pCounter > 0) {
      array62 = vars->data[--pCounter];
      array62->refC++;
      DEBUG_COPY(array62->id);
   } else {
      array62 = (array_t*)malloc(sizeof(array_t));
      array62->size = 858;
      array62->refC = 1;
      array62->id = 62;
      array62->data = (unsigned int*)malloc(array62->size*sizeof(unsigned int));
      memset(array62->data, 0, array62->size*sizeof(unsigned int));
      DEBUG_NEW(array62->id);
   }
   return array62;
}

