#include "outs/5_8_array.h" 
array_t* func13(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array25;
   if (pCounter > 0) {
      array25 = vars->data[--pCounter];
      array25->refC++;
      DEBUG_COPY(array25->id);
   } else {
      array25 = (array_t*)malloc(sizeof(array_t));
      array25->size = 739;
      array25->refC = 1;
      array25->id = 25;
      array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
      memset(array25->data, 0, array25->size*sizeof(unsigned int));
      DEBUG_NEW(array25->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array25;
   array_t* array26 = func17(&params0, loopsFactor);
   DEBUG_RETURN(array26->id);
   free(params0.data);
   if(PATH0 & 1) {
      array_t* array29;
      if (pCounter > 0) {
         array29 = vars->data[--pCounter];
         array29->refC++;
         DEBUG_COPY(array29->id);
      } else {
         array29 = (array_t*)malloc(sizeof(array_t));
         array29->size = 97;
         array29->refC = 1;
         array29->id = 29;
         array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
         memset(array29->data, 0, array29->size*sizeof(unsigned int));
         DEBUG_NEW(array29->id);
      }
      unsigned int loop9 = 0;
      unsigned int loopLimit9 = (rand()%loopsFactor)/3 + 1;
      for(; loop9 < loopLimit9; loop9++) {
         for (int i = 0; i < array29->size; i++) {
            array29->data[i]--;
         }
         for (int i = 0; i < array25->size; i++) {
            if (array25->data[i] == 92) { 
               return array25;
            }
         }
      }
      array29->refC--;
      if(array29->refC == 0) {
         free(array29->data);
         free(array29);
         DEBUG_FREE(array29->id);
      }
   }
   else {
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array25;
      params1.data[1] = array26;
      array_t* array30 = func22(&params1, loopsFactor);
      DEBUG_RETURN(array30->id);
      free(params1.data);
      array30->refC--;
      if(array30->refC == 0) {
         free(array30->data);
         free(array30);
         DEBUG_FREE(array30->id);
      }
   }
   array25->refC--;
   if(array25->refC == 0) {
      free(array25->data);
      free(array25);
      DEBUG_FREE(array25->id);
   }
   return array26;
}

