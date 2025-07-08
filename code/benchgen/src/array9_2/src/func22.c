#include "array9_2.h" 
array_t* func22(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/4 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      array_t* array51;
      if (pCounter > 0) {
         array51 = vars->data[--pCounter];
         array51->refC++;
         DEBUG_COPY(array51->id);
      } else {
         array51 = (array_t*)malloc(sizeof(array_t));
         array51->size = 796;
         array51->refC = 1;
         array51->id = 51;
         array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
         memset(array51->data, 0, array51->size*sizeof(unsigned int));
         DEBUG_NEW(array51->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array51;
      array_t* array52 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array52->id);
      free(params0.data);
      for (int i = 0; i < array51->size; i++) {
         array51->data[i]++;
      }
      array52->refC--;
      if(array52->refC == 0) {
         free(array52->data);
         free(array52);
         DEBUG_FREE(array52->id);
      }
      array51->refC--;
      if(array51->refC == 0) {
         free(array51->data);
         free(array51);
         DEBUG_FREE(array51->id);
      }
   }
   array_t* array58;
   if (pCounter > 0) {
      array58 = vars->data[--pCounter];
      array58->refC++;
      DEBUG_COPY(array58->id);
   } else {
      array58 = (array_t*)malloc(sizeof(array_t));
      array58->size = 987;
      array58->refC = 1;
      array58->id = 58;
      array58->data = (unsigned int*)malloc(array58->size*sizeof(unsigned int));
      memset(array58->data, 0, array58->size*sizeof(unsigned int));
      DEBUG_NEW(array58->id);
   }
   return array58;
}

