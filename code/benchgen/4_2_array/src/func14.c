#include "outs/4_2_array.h" 
array_t* func14(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/4 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      array_t* array36;
      if (pCounter > 0) {
         array36 = vars->data[--pCounter];
         array36->refC++;
         DEBUG_COPY(array36->id);
      } else {
         array36 = (array_t*)malloc(sizeof(array_t));
         array36->size = 12;
         array36->refC = 1;
         array36->id = 36;
         array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
         memset(array36->data, 0, array36->size*sizeof(unsigned int));
         DEBUG_NEW(array36->id);
      }
      if(PATH0 & 1) {
      }
      else {
      }
      for (int i = 0; i < array36->size; i++) {
         if (array36->data[i] == 86) { 
            return array36;
         }
      }
      array_t* array37;
      if (pCounter > 0) {
         array37 = vars->data[--pCounter];
         array37->refC++;
         DEBUG_COPY(array37->id);
      } else {
         array37 = (array_t*)malloc(sizeof(array_t));
         array37->size = 94;
         array37->refC = 1;
         array37->id = 37;
         array37->data = (unsigned int*)malloc(array37->size*sizeof(unsigned int));
         memset(array37->data, 0, array37->size*sizeof(unsigned int));
         DEBUG_NEW(array37->id);
      }
      array37->refC--;
      if(array37->refC == 0) {
         free(array37->data);
         free(array37);
         DEBUG_FREE(array37->id);
      }
      array36->refC--;
      if(array36->refC == 0) {
         free(array36->data);
         free(array36);
         DEBUG_FREE(array36->id);
      }
   }
   array_t* array38;
   if (pCounter > 0) {
      array38 = vars->data[--pCounter];
      array38->refC++;
      DEBUG_COPY(array38->id);
   } else {
      array38 = (array_t*)malloc(sizeof(array_t));
      array38->size = 539;
      array38->refC = 1;
      array38->id = 38;
      array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
      memset(array38->data, 0, array38->size*sizeof(unsigned int));
      DEBUG_NEW(array38->id);
   }
   return array38;
}

