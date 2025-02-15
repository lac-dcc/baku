#include "outs/4_2_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array128 = func15(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array128->id);
   free(params0.data);
   for (int i = 0; i < array128->size; i++) {
      if (array128->data[i] == 95) { 
         return array128;
      }
   }
   unsigned int loop28 = 0;
   unsigned int loopLimit28 = (rand()%loopsFactor)/3 + 1;
   for(; loop28 < loopLimit28; loop28++) {
      for (int i = 0; i < array128->size; i++) {
         array128->data[i]--;
      }
      for (int i = 0; i < array128->size; i++) {
         if (array128->data[i] == 84) { 
            return array128;
         }
      }
      if(PATH0 & 1) {
         array_t* array129;
         if (pCounter > 0) {
            array129 = vars->data[--pCounter];
            array129->refC++;
            DEBUG_COPY(array129->id);
         } else {
            array129 = (array_t*)malloc(sizeof(array_t));
            array129->size = 340;
            array129->refC = 1;
            array129->id = 129;
            array129->data = (unsigned int*)malloc(array129->size*sizeof(unsigned int));
            memset(array129->data, 0, array129->size*sizeof(unsigned int));
            DEBUG_NEW(array129->id);
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array128;
         params1.data[1] = array129;
         array_t* array130 = func20(&params1, loopsFactor);
         DEBUG_RETURN(array130->id);
         free(params1.data);
         array_t* array131;
         if (pCounter > 0) {
            array131 = vars->data[--pCounter];
            array131->refC++;
            DEBUG_COPY(array131->id);
         } else {
            array131 = (array_t*)malloc(sizeof(array_t));
            array131->size = 376;
            array131->refC = 1;
            array131->id = 131;
            array131->data = (unsigned int*)malloc(array131->size*sizeof(unsigned int));
            memset(array131->data, 0, array131->size*sizeof(unsigned int));
            DEBUG_NEW(array131->id);
         }
         array_t* array132;
         if (pCounter > 0) {
            array132 = vars->data[--pCounter];
            array132->refC++;
            DEBUG_COPY(array132->id);
         } else {
            array132 = (array_t*)malloc(sizeof(array_t));
            array132->size = 542;
            array132->refC = 1;
            array132->id = 132;
            array132->data = (unsigned int*)malloc(array132->size*sizeof(unsigned int));
            memset(array132->data, 0, array132->size*sizeof(unsigned int));
            DEBUG_NEW(array132->id);
         }
         array132->refC--;
         if(array132->refC == 0) {
            free(array132->data);
            free(array132);
            DEBUG_FREE(array132->id);
         }
         array131->refC--;
         if(array131->refC == 0) {
            free(array131->data);
            free(array131);
            DEBUG_FREE(array131->id);
         }
         array130->refC--;
         if(array130->refC == 0) {
            free(array130->data);
            free(array130);
            DEBUG_FREE(array130->id);
         }
         array129->refC--;
         if(array129->refC == 0) {
            free(array129->data);
            free(array129);
            DEBUG_FREE(array129->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 1;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array128;
         array_t* array133 = func21(&params1, loopsFactor);
         DEBUG_RETURN(array133->id);
         free(params1.data);
         array_t* array134;
         if (pCounter > 0) {
            array134 = vars->data[--pCounter];
            array134->refC++;
            DEBUG_COPY(array134->id);
         } else {
            array134 = (array_t*)malloc(sizeof(array_t));
            array134->size = 445;
            array134->refC = 1;
            array134->id = 134;
            array134->data = (unsigned int*)malloc(array134->size*sizeof(unsigned int));
            memset(array134->data, 0, array134->size*sizeof(unsigned int));
            DEBUG_NEW(array134->id);
         }
         array134->refC--;
         if(array134->refC == 0) {
            free(array134->data);
            free(array134);
            DEBUG_FREE(array134->id);
         }
         array133->refC--;
         if(array133->refC == 0) {
            free(array133->data);
            free(array133);
            DEBUG_FREE(array133->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array128;
   array_t* array135 = func16(&params1, loopsFactor);
   DEBUG_RETURN(array135->id);
   free(params1.data);
   array_t* array136;
   if (pCounter > 0) {
      array136 = vars->data[--pCounter];
      array136->refC++;
      DEBUG_COPY(array136->id);
   } else {
      array136 = (array_t*)malloc(sizeof(array_t));
      array136->size = 418;
      array136->refC = 1;
      array136->id = 136;
      array136->data = (unsigned int*)malloc(array136->size*sizeof(unsigned int));
      memset(array136->data, 0, array136->size*sizeof(unsigned int));
      DEBUG_NEW(array136->id);
   }
   array_t* array137;
   if (pCounter > 0) {
      array137 = vars->data[--pCounter];
      array137->refC++;
      DEBUG_COPY(array137->id);
   } else {
      array137 = (array_t*)malloc(sizeof(array_t));
      array137->size = 887;
      array137->refC = 1;
      array137->id = 137;
      array137->data = (unsigned int*)malloc(array137->size*sizeof(unsigned int));
      memset(array137->data, 0, array137->size*sizeof(unsigned int));
      DEBUG_NEW(array137->id);
   }
   array137->refC--;
   if(array137->refC == 0) {
      free(array137->data);
      free(array137);
      DEBUG_FREE(array137->id);
   }
   array136->refC--;
   if(array136->refC == 0) {
      free(array136->data);
      free(array136);
      DEBUG_FREE(array136->id);
   }
   array135->refC--;
   if(array135->refC == 0) {
      free(array135->data);
      free(array135);
      DEBUG_FREE(array135->id);
   }
   return array128;
}

