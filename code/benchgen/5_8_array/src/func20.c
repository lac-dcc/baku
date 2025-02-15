#include "outs/5_8_array.h" 
array_t* func20(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t* array49;
      if (pCounter > 0) {
         array49 = vars->data[--pCounter];
         array49->refC++;
         DEBUG_COPY(array49->id);
      } else {
         array49 = (array_t*)malloc(sizeof(array_t));
         array49->size = 987;
         array49->refC = 1;
         array49->id = 49;
         array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
         memset(array49->data, 0, array49->size*sizeof(unsigned int));
         DEBUG_NEW(array49->id);
      }
      unsigned int loop16 = 0;
      unsigned int loopLimit16 = (rand()%loopsFactor)/3 + 1;
      for(; loop16 < loopLimit16; loop16++) {
         for (int i = 0; i < array49->size; i++) {
            array49->data[i]--;
         }
         for (int i = 0; i < array49->size; i++) {
            if (array49->data[i] == 91) { 
               return array49;
            }
         }
      }
      array49->refC--;
      if(array49->refC == 0) {
         free(array49->data);
         free(array49);
         DEBUG_FREE(array49->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array50 = func22(&params0, loopsFactor);
      DEBUG_RETURN(array50->id);
      free(params0.data);
      array50->refC--;
      if(array50->refC == 0) {
         free(array50->data);
         free(array50);
         DEBUG_FREE(array50->id);
      }
   }
   array_t* array51;
   if (pCounter > 0) {
      array51 = vars->data[--pCounter];
      array51->refC++;
      DEBUG_COPY(array51->id);
   } else {
      array51 = (array_t*)malloc(sizeof(array_t));
      array51->size = 859;
      array51->refC = 1;
      array51->id = 51;
      array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
      memset(array51->data, 0, array51->size*sizeof(unsigned int));
      DEBUG_NEW(array51->id);
   }
   return array51;
}

