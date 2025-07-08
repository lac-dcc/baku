#include "array9_4.h" 
array_t* func20(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/5 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      array_t* array50;
      if (pCounter > 0) {
         array50 = vars->data[--pCounter];
         array50->refC++;
         DEBUG_COPY(array50->id);
      } else {
         array50 = (array_t*)malloc(sizeof(array_t));
         array50->size = 723;
         array50->refC = 1;
         array50->id = 50;
         array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
         memset(array50->data, 0, array50->size*sizeof(unsigned int));
         DEBUG_NEW(array50->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array50;
      array_t* array51 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array51->id);
      free(params0.data);
      array51->refC--;
      if(array51->refC == 0) {
         free(array51->data);
         free(array51);
         DEBUG_FREE(array51->id);
      }
      array50->refC--;
      if(array50->refC == 0) {
         free(array50->data);
         free(array50);
         DEBUG_FREE(array50->id);
      }
   }
   array_t* array61;
   if (pCounter > 0) {
      array61 = vars->data[--pCounter];
      array61->refC++;
      DEBUG_COPY(array61->id);
   } else {
      array61 = (array_t*)malloc(sizeof(array_t));
      array61->size = 275;
      array61->refC = 1;
      array61->id = 61;
      array61->data = (unsigned int*)malloc(array61->size*sizeof(unsigned int));
      memset(array61->data, 0, array61->size*sizeof(unsigned int));
      DEBUG_NEW(array61->id);
   }
   return array61;
}

