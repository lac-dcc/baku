#include "outs/3_2_array.h" 
array_t* func11(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array86;
   if (pCounter > 0) {
      array86 = vars->data[--pCounter];
      array86->refC++;
      DEBUG_COPY(array86->id);
   } else {
      array86 = (array_t*)malloc(sizeof(array_t));
      array86->size = 606;
      array86->refC = 1;
      array86->id = 86;
      array86->data = (unsigned int*)malloc(array86->size*sizeof(unsigned int));
      memset(array86->data, 0, array86->size*sizeof(unsigned int));
      DEBUG_NEW(array86->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array86;
   array_t* array87 = func15(&params0, loopsFactor);
   DEBUG_RETURN(array87->id);
   free(params0.data);
   for (int i = 0; i < array86->size; i++) {
      if (array86->data[i] == 28) { 
         return array86;
      }
   }
   unsigned int loop19 = 0;
   unsigned int loopLimit19 = (rand()%loopsFactor)/2 + 1;
   for(; loop19 < loopLimit19; loop19++) {
      for (int i = 0; i < array86->size; i++) {
         array86->data[i]--;
      }
      for (int i = 0; i < array87->size; i++) {
         if (array87->data[i] == 17) { 
            return array87;
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array86;
   params1.data[1] = array87;
   array_t* array88 = func16(&params1, loopsFactor);
   DEBUG_RETURN(array88->id);
   free(params1.data);
   array_t* array89;
   if (pCounter > 0) {
      array89 = vars->data[--pCounter];
      array89->refC++;
      DEBUG_COPY(array89->id);
   } else {
      array89 = (array_t*)malloc(sizeof(array_t));
      array89->size = 324;
      array89->refC = 1;
      array89->id = 89;
      array89->data = (unsigned int*)malloc(array89->size*sizeof(unsigned int));
      memset(array89->data, 0, array89->size*sizeof(unsigned int));
      DEBUG_NEW(array89->id);
   }
   array_t* array90;
   if (pCounter > 0) {
      array90 = vars->data[--pCounter];
      array90->refC++;
      DEBUG_COPY(array90->id);
   } else {
      array90 = (array_t*)malloc(sizeof(array_t));
      array90->size = 743;
      array90->refC = 1;
      array90->id = 90;
      array90->data = (unsigned int*)malloc(array90->size*sizeof(unsigned int));
      memset(array90->data, 0, array90->size*sizeof(unsigned int));
      DEBUG_NEW(array90->id);
   }
   array90->refC--;
   if(array90->refC == 0) {
      free(array90->data);
      free(array90);
      DEBUG_FREE(array90->id);
   }
   array89->refC--;
   if(array89->refC == 0) {
      free(array89->data);
      free(array89);
      DEBUG_FREE(array89->id);
   }
   array88->refC--;
   if(array88->refC == 0) {
      free(array88->data);
      free(array88);
      DEBUG_FREE(array88->id);
   }
   array87->refC--;
   if(array87->refC == 0) {
      free(array87->data);
      free(array87);
      DEBUG_FREE(array87->id);
   }
   return array86;
}

