#include "outs/3_2_array.h" 
array_t* func7(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      array_t* array28;
      if (pCounter > 0) {
         array28 = vars->data[--pCounter];
         array28->refC++;
         DEBUG_COPY(array28->id);
      } else {
         array28 = (array_t*)malloc(sizeof(array_t));
         array28->size = 364;
         array28->refC = 1;
         array28->id = 28;
         array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
         memset(array28->data, 0, array28->size*sizeof(unsigned int));
         DEBUG_NEW(array28->id);
      }
      if(PATH0 & 1) {
      }
      else {
      }
      for (int i = 0; i < array28->size; i++) {
         if (array28->data[i] == 50) { 
            return array28;
         }
      }
      array_t* array29;
      if (pCounter > 0) {
         array29 = vars->data[--pCounter];
         array29->refC++;
         DEBUG_COPY(array29->id);
      } else {
         array29 = (array_t*)malloc(sizeof(array_t));
         array29->size = 87;
         array29->refC = 1;
         array29->id = 29;
         array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
         memset(array29->data, 0, array29->size*sizeof(unsigned int));
         DEBUG_NEW(array29->id);
      }
      array29->refC--;
      if(array29->refC == 0) {
         free(array29->data);
         free(array29);
         DEBUG_FREE(array29->id);
      }
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
   }
   array_t* array30;
   if (pCounter > 0) {
      array30 = vars->data[--pCounter];
      array30->refC++;
      DEBUG_COPY(array30->id);
   } else {
      array30 = (array_t*)malloc(sizeof(array_t));
      array30->size = 808;
      array30->refC = 1;
      array30->id = 30;
      array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
      memset(array30->data, 0, array30->size*sizeof(unsigned int));
      DEBUG_NEW(array30->id);
   }
   return array30;
}

