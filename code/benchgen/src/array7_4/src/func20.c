#include "array7_4.h" 
array_t* func20(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/5 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      array_t* array41;
      if (pCounter > 0) {
         array41 = vars->data[--pCounter];
         array41->refC++;
         DEBUG_COPY(array41->id);
      } else {
         array41 = (array_t*)malloc(sizeof(array_t));
         array41->size = 97;
         array41->refC = 1;
         array41->id = 41;
         array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
         memset(array41->data, 0, array41->size*sizeof(unsigned int));
         DEBUG_NEW(array41->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array41;
      array_t* array42 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array42->id);
      free(params0.data);
      array42->refC--;
      if(array42->refC == 0) {
         free(array42->data);
         free(array42);
         DEBUG_FREE(array42->id);
      }
      array41->refC--;
      if(array41->refC == 0) {
         free(array41->data);
         free(array41);
         DEBUG_FREE(array41->id);
      }
   }
   array_t* array49;
   if (pCounter > 0) {
      array49 = vars->data[--pCounter];
      array49->refC++;
      DEBUG_COPY(array49->id);
   } else {
      array49 = (array_t*)malloc(sizeof(array_t));
      array49->size = 708;
      array49->refC = 1;
      array49->id = 49;
      array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
      memset(array49->data, 0, array49->size*sizeof(unsigned int));
      DEBUG_NEW(array49->id);
   }
   return array49;
}

