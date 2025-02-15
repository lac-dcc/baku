#include "outs/4_9_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array47;
   if (pCounter > 0) {
      array47 = vars->data[--pCounter];
      array47->refC++;
      DEBUG_COPY(array47->id);
   } else {
      array47 = (array_t*)malloc(sizeof(array_t));
      array47->size = 365;
      array47->refC = 1;
      array47->id = 47;
      array47->data = (unsigned int*)malloc(array47->size*sizeof(unsigned int));
      memset(array47->data, 0, array47->size*sizeof(unsigned int));
      DEBUG_NEW(array47->id);
   }
   if(PATH0 & 1) {
      unsigned int loop21 = 0;
      unsigned int loopLimit21 = (rand()%loopsFactor)/2 + 1;
      for(; loop21 < loopLimit21; loop21++) {
         for (int i = 0; i < array47->size; i++) {
            array47->data[i]--;
         }
      }
      array_t* array48;
      if (pCounter > 0) {
         array48 = vars->data[--pCounter];
         array48->refC++;
         DEBUG_COPY(array48->id);
      } else {
         array48 = (array_t*)malloc(sizeof(array_t));
         array48->size = 936;
         array48->refC = 1;
         array48->id = 48;
         array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
         memset(array48->data, 0, array48->size*sizeof(unsigned int));
         DEBUG_NEW(array48->id);
      }
      if(PATH0 & 2) {
         unsigned int loop22 = 0;
         unsigned int loopLimit22 = (rand()%loopsFactor)/2 + 1;
         for(; loop22 < loopLimit22; loop22++) {
            array_t* array49;
            if (pCounter > 0) {
               array49 = vars->data[--pCounter];
               array49->refC++;
               DEBUG_COPY(array49->id);
            } else {
               array49 = (array_t*)malloc(sizeof(array_t));
               array49->size = 432;
               array49->refC = 1;
               array49->id = 49;
               array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
               memset(array49->data, 0, array49->size*sizeof(unsigned int));
               DEBUG_NEW(array49->id);
            }
            for (int i = 0; i < array49->size; i++) {
               array49->data[i]--;
            }
            for (int i = 0; i < array49->size; i++) {
               if (array49->data[i] == 28) { 
                  return array49;
               }
            }
            array49->refC--;
            if(array49->refC == 0) {
               free(array49->data);
               free(array49);
               DEBUG_FREE(array49->id);
            }
         }
      }
      else {
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array47;
         params0.data[1] = array48;
         array_t* array50 = func11(&params0, loopsFactor);
         DEBUG_RETURN(array50->id);
         free(params0.data);
         array50->refC--;
         if(array50->refC == 0) {
            free(array50->data);
            free(array50);
            DEBUG_FREE(array50->id);
         }
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array47;
      params0.data[1] = array48;
      array_t* array51 = func8(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array51->id);
      free(params0.data);
      unsigned int loop23 = 0;
      unsigned int loopLimit23 = (rand()%loopsFactor)/2 + 1;
      for(; loop23 < loopLimit23; loop23++) {
         for (int i = 0; i < array51->size; i++) {
            array51->data[i]++;
         }
      }
      array_t_param params1;
      params1.size = 3;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array47;
      params1.data[1] = array48;
      params1.data[2] = array51;
      array_t* array52 = func5(&params1, loopsFactor);
      DEBUG_RETURN(array52->id);
      free(params1.data);
      array52->refC--;
      if(array52->refC == 0) {
         free(array52->data);
         free(array52);
         DEBUG_FREE(array52->id);
      }
      array51->refC--;
      if(array51->refC == 0) {
         free(array51->data);
         free(array51);
         DEBUG_FREE(array51->id);
      }
      array48->refC--;
      if(array48->refC == 0) {
         free(array48->data);
         free(array48);
         DEBUG_FREE(array48->id);
      }
   }
   else {
      array_t* array53;
      if (pCounter > 0) {
         array53 = vars->data[--pCounter];
         array53->refC++;
         DEBUG_COPY(array53->id);
      } else {
         array53 = (array_t*)malloc(sizeof(array_t));
         array53->size = 237;
         array53->refC = 1;
         array53->id = 53;
         array53->data = (unsigned int*)malloc(array53->size*sizeof(unsigned int));
         memset(array53->data, 0, array53->size*sizeof(unsigned int));
         DEBUG_NEW(array53->id);
      }
      for (int i = 0; i < array53->size; i++) {
         array53->data[i]++;
      }
      for (int i = 0; i < array53->size; i++) {
         if (array53->data[i] == 18) { 
            return array53;
         }
      }
      for (int i = 0; i < array47->size; i++) {
         array47->data[i]--;
      }
      array_t* array54;
      if (pCounter > 0) {
         array54 = vars->data[--pCounter];
         array54->refC++;
         DEBUG_COPY(array54->id);
      } else {
         array54 = (array_t*)malloc(sizeof(array_t));
         array54->size = 143;
         array54->refC = 1;
         array54->id = 54;
         array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
         memset(array54->data, 0, array54->size*sizeof(unsigned int));
         DEBUG_NEW(array54->id);
      }
      if(PATH0 & 4) {
         unsigned int loop24 = 0;
         unsigned int loopLimit24 = (rand()%loopsFactor)/2 + 1;
         for(; loop24 < loopLimit24; loop24++) {
            array_t* array55;
            if (pCounter > 0) {
               array55 = vars->data[--pCounter];
               array55->refC++;
               DEBUG_COPY(array55->id);
            } else {
               array55 = (array_t*)malloc(sizeof(array_t));
               array55->size = 11;
               array55->refC = 1;
               array55->id = 55;
               array55->data = (unsigned int*)malloc(array55->size*sizeof(unsigned int));
               memset(array55->data, 0, array55->size*sizeof(unsigned int));
               DEBUG_NEW(array55->id);
            }
            for (int i = 0; i < array47->size; i++) {
               array47->data[i]--;
            }
            for (int i = 0; i < array53->size; i++) {
               if (array53->data[i] == 76) { 
                  return array53;
               }
            }
            array55->refC--;
            if(array55->refC == 0) {
               free(array55->data);
               free(array55);
               DEBUG_FREE(array55->id);
            }
         }
      }
      else {
         array_t_param params0;
         params0.size = 3;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array47;
         params0.data[1] = array53;
         params0.data[2] = array54;
         array_t* array56 = func11(&params0, loopsFactor);
         DEBUG_RETURN(array56->id);
         free(params0.data);
         array56->refC--;
         if(array56->refC == 0) {
            free(array56->data);
            free(array56);
            DEBUG_FREE(array56->id);
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array47;
      params0.data[1] = array53;
      params0.data[2] = array54;
      array_t* array57 = func8(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array57->id);
      free(params0.data);
      array57->refC--;
      if(array57->refC == 0) {
         free(array57->data);
         free(array57);
         DEBUG_FREE(array57->id);
      }
      array54->refC--;
      if(array54->refC == 0) {
         free(array54->data);
         free(array54);
         DEBUG_FREE(array54->id);
      }
      array53->refC--;
      if(array53->refC == 0) {
         free(array53->data);
         free(array53);
         DEBUG_FREE(array53->id);
      }
   }
   unsigned int loop25 = 0;
   unsigned int loopLimit25 = (rand()%loopsFactor)/2 + 1;
   for(; loop25 < loopLimit25; loop25++) {
      for (int i = 0; i < array47->size; i++) {
         array47->data[i]++;
      }
      array_t* array58;
      if (pCounter > 0) {
         array58 = vars->data[--pCounter];
         array58->refC++;
         DEBUG_COPY(array58->id);
      } else {
         array58 = (array_t*)malloc(sizeof(array_t));
         array58->size = 606;
         array58->refC = 1;
         array58->id = 58;
         array58->data = (unsigned int*)malloc(array58->size*sizeof(unsigned int));
         memset(array58->data, 0, array58->size*sizeof(unsigned int));
         DEBUG_NEW(array58->id);
      }
      for (int i = 0; i < array47->size; i++) {
         array47->data[i]++;
      }
      for (int i = 0; i < array47->size; i++) {
         if (array47->data[i] == 18) { 
            return array47;
         }
      }
      for (int i = 0; i < array47->size; i++) {
         array47->data[i]--;
      }
      array_t* array59;
      if (pCounter > 0) {
         array59 = vars->data[--pCounter];
         array59->refC++;
         DEBUG_COPY(array59->id);
      } else {
         array59 = (array_t*)malloc(sizeof(array_t));
         array59->size = 688;
         array59->refC = 1;
         array59->id = 59;
         array59->data = (unsigned int*)malloc(array59->size*sizeof(unsigned int));
         memset(array59->data, 0, array59->size*sizeof(unsigned int));
         DEBUG_NEW(array59->id);
      }
      if(PATH0 & 8) {
         unsigned int loop26 = 0;
         unsigned int loopLimit26 = (rand()%loopsFactor)/3 + 1;
         for(; loop26 < loopLimit26; loop26++) {
            array_t* array60;
            if (pCounter > 0) {
               array60 = vars->data[--pCounter];
               array60->refC++;
               DEBUG_COPY(array60->id);
            } else {
               array60 = (array_t*)malloc(sizeof(array_t));
               array60->size = 369;
               array60->refC = 1;
               array60->id = 60;
               array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
               memset(array60->data, 0, array60->size*sizeof(unsigned int));
               DEBUG_NEW(array60->id);
            }
            for (int i = 0; i < array58->size; i++) {
               array58->data[i]--;
            }
            for (int i = 0; i < array58->size; i++) {
               if (array58->data[i] == 96) { 
                  return array58;
               }
            }
            array60->refC--;
            if(array60->refC == 0) {
               free(array60->data);
               free(array60);
               DEBUG_FREE(array60->id);
            }
         }
      }
      else {
         array_t_param params0;
         params0.size = 3;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array47;
         params0.data[1] = array58;
         params0.data[2] = array59;
         array_t* array61 = func11(&params0, loopsFactor);
         DEBUG_RETURN(array61->id);
         free(params0.data);
         array61->refC--;
         if(array61->refC == 0) {
            free(array61->data);
            free(array61);
            DEBUG_FREE(array61->id);
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array47;
      params0.data[1] = array58;
      params0.data[2] = array59;
      array_t* array62 = func8(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array62->id);
      free(params0.data);
      array62->refC--;
      if(array62->refC == 0) {
         free(array62->data);
         free(array62);
         DEBUG_FREE(array62->id);
      }
      array59->refC--;
      if(array59->refC == 0) {
         free(array59->data);
         free(array59);
         DEBUG_FREE(array59->id);
      }
      array58->refC--;
      if(array58->refC == 0) {
         free(array58->data);
         free(array58);
         DEBUG_FREE(array58->id);
      }
   }
   return array47;
}

