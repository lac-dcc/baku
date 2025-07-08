#include "array10_2.h" 
array_t* func22(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/4 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      array_t* array57;
      if (pCounter > 0) {
         array57 = vars->data[--pCounter];
         array57->refC++;
         DEBUG_COPY(array57->id);
      } else {
         array57 = (array_t*)malloc(sizeof(array_t));
         array57->size = 914;
         array57->refC = 1;
         array57->id = 57;
         array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
         memset(array57->data, 0, array57->size*sizeof(unsigned int));
         DEBUG_NEW(array57->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array57;
      array_t* array58 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array58->id);
      free(params0.data);
      for (int i = 0; i < array58->size; i++) {
         array58->data[i]++;
      }
      array58->refC--;
      if(array58->refC == 0) {
         free(array58->data);
         free(array58);
         DEBUG_FREE(array58->id);
      }
      array57->refC--;
      if(array57->refC == 0) {
         free(array57->data);
         free(array57);
         DEBUG_FREE(array57->id);
      }
   }
   array_t* array65;
   if (pCounter > 0) {
      array65 = vars->data[--pCounter];
      array65->refC++;
      DEBUG_COPY(array65->id);
   } else {
      array65 = (array_t*)malloc(sizeof(array_t));
      array65->size = 235;
      array65->refC = 1;
      array65->id = 65;
      array65->data = (unsigned int*)malloc(array65->size*sizeof(unsigned int));
      memset(array65->data, 0, array65->size*sizeof(unsigned int));
      DEBUG_NEW(array65->id);
   }
   return array65;
}

