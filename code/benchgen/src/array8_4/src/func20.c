#include "array8_4.h" 
array_t* func20(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/5 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      array_t* array48;
      if (pCounter > 0) {
         array48 = vars->data[--pCounter];
         array48->refC++;
         DEBUG_COPY(array48->id);
      } else {
         array48 = (array_t*)malloc(sizeof(array_t));
         array48->size = 368;
         array48->refC = 1;
         array48->id = 48;
         array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
         memset(array48->data, 0, array48->size*sizeof(unsigned int));
         DEBUG_NEW(array48->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array48;
      array_t* array49 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array49->id);
      free(params0.data);
      array49->refC--;
      if(array49->refC == 0) {
         free(array49->data);
         free(array49);
         DEBUG_FREE(array49->id);
      }
      array48->refC--;
      if(array48->refC == 0) {
         free(array48->data);
         free(array48);
         DEBUG_FREE(array48->id);
      }
   }
   array_t* array58;
   if (pCounter > 0) {
      array58 = vars->data[--pCounter];
      array58->refC++;
      DEBUG_COPY(array58->id);
   } else {
      array58 = (array_t*)malloc(sizeof(array_t));
      array58->size = 365;
      array58->refC = 1;
      array58->id = 58;
      array58->data = (unsigned int*)malloc(array58->size*sizeof(unsigned int));
      memset(array58->data, 0, array58->size*sizeof(unsigned int));
      DEBUG_NEW(array58->id);
   }
   return array58;
}

