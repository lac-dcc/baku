#include "outs/5_2_array.h" 
array_t* func19(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/4 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      array_t* array49;
      if (pCounter > 0) {
         array49 = vars->data[--pCounter];
         array49->refC++;
         DEBUG_COPY(array49->id);
      } else {
         array49 = (array_t*)malloc(sizeof(array_t));
         array49->size = 675;
         array49->refC = 1;
         array49->id = 49;
         array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
         memset(array49->data, 0, array49->size*sizeof(unsigned int));
         DEBUG_NEW(array49->id);
      }
      if(PATH0 & 1) {
      }
      else {
      }
      for (int i = 0; i < array49->size; i++) {
         if (array49->data[i] == 27) { 
            return array49;
         }
      }
      array_t* array50;
      if (pCounter > 0) {
         array50 = vars->data[--pCounter];
         array50->refC++;
         DEBUG_COPY(array50->id);
      } else {
         array50 = (array_t*)malloc(sizeof(array_t));
         array50->size = 567;
         array50->refC = 1;
         array50->id = 50;
         array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
         memset(array50->data, 0, array50->size*sizeof(unsigned int));
         DEBUG_NEW(array50->id);
      }
      array50->refC--;
      if(array50->refC == 0) {
         free(array50->data);
         free(array50);
         DEBUG_FREE(array50->id);
      }
      array49->refC--;
      if(array49->refC == 0) {
         free(array49->data);
         free(array49);
         DEBUG_FREE(array49->id);
      }
   }
   array_t* array51;
   if (pCounter > 0) {
      array51 = vars->data[--pCounter];
      array51->refC++;
      DEBUG_COPY(array51->id);
   } else {
      array51 = (array_t*)malloc(sizeof(array_t));
      array51->size = 856;
      array51->refC = 1;
      array51->id = 51;
      array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
      memset(array51->data, 0, array51->size*sizeof(unsigned int));
      DEBUG_NEW(array51->id);
   }
   return array51;
}

