#include "array8_2.h" 
array_t* func13(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      array_t* array11;
      if (pCounter > 0) {
         array11 = vars->data[--pCounter];
         array11->refC++;
         DEBUG_COPY(array11->id);
      } else {
         array11 = (array_t*)malloc(sizeof(array_t));
         array11->size = 393;
         array11->refC = 1;
         array11->id = 11;
         array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
         memset(array11->data, 0, array11->size*sizeof(unsigned int));
         DEBUG_NEW(array11->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array11;
      array_t* array12 = func17(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array12->id);
      free(params0.data);
      for (int i = 0; i < array12->size; i++) {
         array12->data[i]++;
      }
      array12->refC--;
      if(array12->refC == 0) {
         free(array12->data);
         free(array12);
         DEBUG_FREE(array12->id);
      }
      array11->refC--;
      if(array11->refC == 0) {
         free(array11->data);
         free(array11);
         DEBUG_FREE(array11->id);
      }
   }
   array_t* array25;
   if (pCounter > 0) {
      array25 = vars->data[--pCounter];
      array25->refC++;
      DEBUG_COPY(array25->id);
   } else {
      array25 = (array_t*)malloc(sizeof(array_t));
      array25->size = 434;
      array25->refC = 1;
      array25->id = 25;
      array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
      memset(array25->data, 0, array25->size*sizeof(unsigned int));
      DEBUG_NEW(array25->id);
   }
   return array25;
}

