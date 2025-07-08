#include "array10_2.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      array_t* array47;
      if (pCounter > 0) {
         array47 = vars->data[--pCounter];
         array47->refC++;
         DEBUG_COPY(array47->id);
      } else {
         array47 = (array_t*)malloc(sizeof(array_t));
         array47->size = 871;
         array47->refC = 1;
         array47->id = 47;
         array47->data = (unsigned int*)malloc(array47->size*sizeof(unsigned int));
         memset(array47->data, 0, array47->size*sizeof(unsigned int));
         DEBUG_NEW(array47->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array47;
      array_t* array48 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array48->id);
      free(params0.data);
      for (int i = 0; i < array47->size; i++) {
         array47->data[i]++;
      }
      array48->refC--;
      if(array48->refC == 0) {
         free(array48->data);
         free(array48);
         DEBUG_FREE(array48->id);
      }
      array47->refC--;
      if(array47->refC == 0) {
         free(array47->data);
         free(array47);
         DEBUG_FREE(array47->id);
      }
   }
   array_t* array69;
   if (pCounter > 0) {
      array69 = vars->data[--pCounter];
      array69->refC++;
      DEBUG_COPY(array69->id);
   } else {
      array69 = (array_t*)malloc(sizeof(array_t));
      array69->size = 443;
      array69->refC = 1;
      array69->id = 69;
      array69->data = (unsigned int*)malloc(array69->size*sizeof(unsigned int));
      memset(array69->data, 0, array69->size*sizeof(unsigned int));
      DEBUG_NEW(array69->id);
   }
   return array69;
}

