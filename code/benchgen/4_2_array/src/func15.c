#include "outs/4_2_array.h" 
array_t* func15(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array46;
   if (pCounter > 0) {
      array46 = vars->data[--pCounter];
      array46->refC++;
      DEBUG_COPY(array46->id);
   } else {
      array46 = (array_t*)malloc(sizeof(array_t));
      array46->size = 441;
      array46->refC = 1;
      array46->id = 46;
      array46->data = (unsigned int*)malloc(array46->size*sizeof(unsigned int));
      memset(array46->data, 0, array46->size*sizeof(unsigned int));
      DEBUG_NEW(array46->id);
   }
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/3 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      for (int i = 0; i < array46->size; i++) {
         array46->data[i]++;
      }
      for (int i = 0; i < array46->size; i++) {
         if (array46->data[i] == 44) { 
            return array46;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array46;
         array_t* array47 = func19(&params0, loopsFactor);
         DEBUG_RETURN(array47->id);
         free(params0.data);
         array_t* array48;
         if (pCounter > 0) {
            array48 = vars->data[--pCounter];
            array48->refC++;
            DEBUG_COPY(array48->id);
         } else {
            array48 = (array_t*)malloc(sizeof(array_t));
            array48->size = 729;
            array48->refC = 1;
            array48->id = 48;
            array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
            memset(array48->data, 0, array48->size*sizeof(unsigned int));
            DEBUG_NEW(array48->id);
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
      else {
      }
   }
   array_t* array49;
   if (pCounter > 0) {
      array49 = vars->data[--pCounter];
      array49->refC++;
      DEBUG_COPY(array49->id);
   } else {
      array49 = (array_t*)malloc(sizeof(array_t));
      array49->size = 31;
      array49->refC = 1;
      array49->id = 49;
      array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
      memset(array49->data, 0, array49->size*sizeof(unsigned int));
      DEBUG_NEW(array49->id);
   }
   array46->refC--;
   if(array46->refC == 0) {
      free(array46->data);
      free(array46);
      DEBUG_FREE(array46->id);
   }
   return array49;
}

