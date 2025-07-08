#include "array9_8.h" 
array_t* func8(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array30;
      if (pCounter > 0) {
         array30 = vars->data[--pCounter];
         array30->refC++;
         DEBUG_COPY(array30->id);
      } else {
         array30 = (array_t*)malloc(sizeof(array_t));
         array30->size = 226;
         array30->refC = 1;
         array30->id = 30;
         array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
         memset(array30->data, 0, array30->size*sizeof(unsigned int));
         DEBUG_NEW(array30->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array30;
      array_t* array31 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array31->id);
      free(params0.data);
      array31->refC--;
      if(array31->refC == 0) {
         free(array31->data);
         free(array31);
         DEBUG_FREE(array31->id);
      }
      array30->refC--;
      if(array30->refC == 0) {
         free(array30->data);
         free(array30);
         DEBUG_FREE(array30->id);
      }
   }
   array_t* array47;
   if (pCounter > 0) {
      array47 = vars->data[--pCounter];
      array47->refC++;
      DEBUG_COPY(array47->id);
   } else {
      array47 = (array_t*)malloc(sizeof(array_t));
      array47->size = 19;
      array47->refC = 1;
      array47->id = 47;
      array47->data = (unsigned int*)malloc(array47->size*sizeof(unsigned int));
      memset(array47->data, 0, array47->size*sizeof(unsigned int));
      DEBUG_NEW(array47->id);
   }
   return array47;
}

