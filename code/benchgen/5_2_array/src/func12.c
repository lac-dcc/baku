#include "outs/5_2_array.h" 
array_t* func12(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array27 = func17(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array27->id);
   free(params0.data);
   for (int i = 0; i < array27->size; i++) {
      if (array27->data[i] == 3) { 
         return array27;
      }
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      for (int i = 0; i < array27->size; i++) {
         array27->data[i]--;
      }
      for (int i = 0; i < array27->size; i++) {
         if (array27->data[i] == 99) { 
            return array27;
         }
      }
      if(PATH0 & 1) {
         array_t* array32;
         if (pCounter > 0) {
            array32 = vars->data[--pCounter];
            array32->refC++;
            DEBUG_COPY(array32->id);
         } else {
            array32 = (array_t*)malloc(sizeof(array_t));
            array32->size = 932;
            array32->refC = 1;
            array32->id = 32;
            array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
            memset(array32->data, 0, array32->size*sizeof(unsigned int));
            DEBUG_NEW(array32->id);
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array27;
         params1.data[1] = array32;
         array_t* array33 = func22(&params1, loopsFactor);
         DEBUG_RETURN(array33->id);
         free(params1.data);
         array_t* array34;
         if (pCounter > 0) {
            array34 = vars->data[--pCounter];
            array34->refC++;
            DEBUG_COPY(array34->id);
         } else {
            array34 = (array_t*)malloc(sizeof(array_t));
            array34->size = 368;
            array34->refC = 1;
            array34->id = 34;
            array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
            memset(array34->data, 0, array34->size*sizeof(unsigned int));
            DEBUG_NEW(array34->id);
         }
         array_t* array35;
         if (pCounter > 0) {
            array35 = vars->data[--pCounter];
            array35->refC++;
            DEBUG_COPY(array35->id);
         } else {
            array35 = (array_t*)malloc(sizeof(array_t));
            array35->size = 739;
            array35->refC = 1;
            array35->id = 35;
            array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
            memset(array35->data, 0, array35->size*sizeof(unsigned int));
            DEBUG_NEW(array35->id);
         }
         array35->refC--;
         if(array35->refC == 0) {
            free(array35->data);
            free(array35);
            DEBUG_FREE(array35->id);
         }
         array34->refC--;
         if(array34->refC == 0) {
            free(array34->data);
            free(array34);
            DEBUG_FREE(array34->id);
         }
         array33->refC--;
         if(array33->refC == 0) {
            free(array33->data);
            free(array33);
            DEBUG_FREE(array33->id);
         }
         array32->refC--;
         if(array32->refC == 0) {
            free(array32->data);
            free(array32);
            DEBUG_FREE(array32->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 1;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array27;
         array_t* array36 = func23(&params1, loopsFactor);
         DEBUG_RETURN(array36->id);
         free(params1.data);
         array_t* array37;
         if (pCounter > 0) {
            array37 = vars->data[--pCounter];
            array37->refC++;
            DEBUG_COPY(array37->id);
         } else {
            array37 = (array_t*)malloc(sizeof(array_t));
            array37->size = 586;
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
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array27;
   array_t* array38 = func18(&params1, loopsFactor);
   DEBUG_RETURN(array38->id);
   free(params1.data);
   array_t* array44;
   if (pCounter > 0) {
      array44 = vars->data[--pCounter];
      array44->refC++;
      DEBUG_COPY(array44->id);
   } else {
      array44 = (array_t*)malloc(sizeof(array_t));
      array44->size = 441;
      array44->refC = 1;
      array44->id = 44;
      array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
      memset(array44->data, 0, array44->size*sizeof(unsigned int));
      DEBUG_NEW(array44->id);
   }
   array_t* array45;
   if (pCounter > 0) {
      array45 = vars->data[--pCounter];
      array45->refC++;
      DEBUG_COPY(array45->id);
   } else {
      array45 = (array_t*)malloc(sizeof(array_t));
      array45->size = 865;
      array45->refC = 1;
      array45->id = 45;
      array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
      memset(array45->data, 0, array45->size*sizeof(unsigned int));
      DEBUG_NEW(array45->id);
   }
   array45->refC--;
   if(array45->refC == 0) {
      free(array45->data);
      free(array45);
      DEBUG_FREE(array45->id);
   }
   array44->refC--;
   if(array44->refC == 0) {
      free(array44->data);
      free(array44);
      DEBUG_FREE(array44->id);
   }
   array27->refC--;
   if(array27->refC == 0) {
      free(array27->data);
      free(array27);
      DEBUG_FREE(array27->id);
   }
   return array38;
}

