#include "array8_2.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      array_t* array35;
      if (pCounter > 0) {
         array35 = vars->data[--pCounter];
         array35->refC++;
         DEBUG_COPY(array35->id);
      } else {
         array35 = (array_t*)malloc(sizeof(array_t));
         array35->size = 97;
         array35->refC = 1;
         array35->id = 35;
         array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
         memset(array35->data, 0, array35->size*sizeof(unsigned int));
         DEBUG_NEW(array35->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array35;
      array_t* array36 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array36->id);
      free(params0.data);
      for (int i = 0; i < array36->size; i++) {
         array36->data[i]++;
      }
      array36->refC--;
      if(array36->refC == 0) {
         free(array36->data);
         free(array36);
         DEBUG_FREE(array36->id);
      }
      array35->refC--;
      if(array35->refC == 0) {
         free(array35->data);
         free(array35);
         DEBUG_FREE(array35->id);
      }
   }
   array_t* array57;
   if (pCounter > 0) {
      array57 = vars->data[--pCounter];
      array57->refC++;
      DEBUG_COPY(array57->id);
   } else {
      array57 = (array_t*)malloc(sizeof(array_t));
      array57->size = 500;
      array57->refC = 1;
      array57->id = 57;
      array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
      memset(array57->data, 0, array57->size*sizeof(unsigned int));
      DEBUG_NEW(array57->id);
   }
   return array57;
}

