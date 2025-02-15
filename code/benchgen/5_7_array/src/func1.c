#include "outs/5_7_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array111;
   if (pCounter > 0) {
      array111 = vars->data[--pCounter];
      array111->refC++;
      DEBUG_COPY(array111->id);
   } else {
      array111 = (array_t*)malloc(sizeof(array_t));
      array111->size = 465;
      array111->refC = 1;
      array111->id = 111;
      array111->data = (unsigned int*)malloc(array111->size*sizeof(unsigned int));
      memset(array111->data, 0, array111->size*sizeof(unsigned int));
      DEBUG_NEW(array111->id);
   }
   array_t* array112;
   if (pCounter > 0) {
      array112 = vars->data[--pCounter];
      array112->refC++;
      DEBUG_COPY(array112->id);
   } else {
      array112 = (array_t*)malloc(sizeof(array_t));
      array112->size = 708;
      array112->refC = 1;
      array112->id = 112;
      array112->data = (unsigned int*)malloc(array112->size*sizeof(unsigned int));
      memset(array112->data, 0, array112->size*sizeof(unsigned int));
      DEBUG_NEW(array112->id);
   }
   for (int i = 0; i < array111->size; i++) {
      array111->data[i]++;
   }
   unsigned int loop27 = 0;
   unsigned int loopLimit27 = (rand()%loopsFactor)/1 + 1;
   for(; loop27 < loopLimit27; loop27++) {
      for (int i = 0; i < array111->size; i++) {
         array111->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array111;
   params0.data[1] = array112;
   array_t* array113 = func3(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array113->id);
   free(params0.data);
   array113->refC--;
   if(array113->refC == 0) {
      free(array113->data);
      free(array113);
      DEBUG_FREE(array113->id);
   }
   array111->refC--;
   if(array111->refC == 0) {
      free(array111->data);
      free(array111);
      DEBUG_FREE(array111->id);
   }
   return array112;
}

