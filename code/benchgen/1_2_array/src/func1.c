#include "outs/1_2_array.h" 
array_t* func1(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array14;
      if (pCounter > 0) {
         array14 = vars->data[--pCounter];
         array14->refC++;
         DEBUG_COPY(array14->id);
      } else {
         array14 = (array_t*)malloc(sizeof(array_t));
         array14->size = 919;
         array14->refC = 1;
         array14->id = 14;
         array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
         memset(array14->data, 0, array14->size*sizeof(unsigned int));
         DEBUG_NEW(array14->id);
      }
      if(PATH0 & 1) {
      }
      else {
      }
      for (int i = 0; i < array14->size; i++) {
         if (array14->data[i] == 37) { 
            return array14;
         }
      }
      array_t* array15;
      if (pCounter > 0) {
         array15 = vars->data[--pCounter];
         array15->refC++;
         DEBUG_COPY(array15->id);
      } else {
         array15 = (array_t*)malloc(sizeof(array_t));
         array15->size = 198;
         array15->refC = 1;
         array15->id = 15;
         array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
         memset(array15->data, 0, array15->size*sizeof(unsigned int));
         DEBUG_NEW(array15->id);
      }
      array15->refC--;
      if(array15->refC == 0) {
         free(array15->data);
         free(array15);
         DEBUG_FREE(array15->id);
      }
      array14->refC--;
      if(array14->refC == 0) {
         free(array14->data);
         free(array14);
         DEBUG_FREE(array14->id);
      }
   }
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      if(PATH0 & 2) {
         array_t* array16;
         if (pCounter > 0) {
            array16 = vars->data[--pCounter];
            array16->refC++;
            DEBUG_COPY(array16->id);
         } else {
            array16 = (array_t*)malloc(sizeof(array_t));
            array16->size = 324;
            array16->refC = 1;
            array16->id = 16;
            array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
            memset(array16->data, 0, array16->size*sizeof(unsigned int));
            DEBUG_NEW(array16->id);
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array16;
         array_t* array17 = func5(&params0, loopsFactor);
         DEBUG_RETURN(array17->id);
         free(params0.data);
         array_t* array19;
         if (pCounter > 0) {
            array19 = vars->data[--pCounter];
            array19->refC++;
            DEBUG_COPY(array19->id);
         } else {
            array19 = (array_t*)malloc(sizeof(array_t));
            array19->size = 956;
            array19->refC = 1;
            array19->id = 19;
            array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
            memset(array19->data, 0, array19->size*sizeof(unsigned int));
            DEBUG_NEW(array19->id);
         }
         array_t* array20;
         if (pCounter > 0) {
            array20 = vars->data[--pCounter];
            array20->refC++;
            DEBUG_COPY(array20->id);
         } else {
            array20 = (array_t*)malloc(sizeof(array_t));
            array20->size = 873;
            array20->refC = 1;
            array20->id = 20;
            array20->data = (unsigned int*)malloc(array20->size*sizeof(unsigned int));
            memset(array20->data, 0, array20->size*sizeof(unsigned int));
            DEBUG_NEW(array20->id);
         }
         array20->refC--;
         if(array20->refC == 0) {
            free(array20->data);
            free(array20);
            DEBUG_FREE(array20->id);
         }
         array19->refC--;
         if(array19->refC == 0) {
            free(array19->data);
            free(array19);
            DEBUG_FREE(array19->id);
         }
         array17->refC--;
         if(array17->refC == 0) {
            free(array17->data);
            free(array17);
            DEBUG_FREE(array17->id);
         }
         array16->refC--;
         if(array16->refC == 0) {
            free(array16->data);
            free(array16);
            DEBUG_FREE(array16->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 0;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         array_t* array21 = func6(&params0, loopsFactor);
         DEBUG_RETURN(array21->id);
         free(params0.data);
         array_t* array23;
         if (pCounter > 0) {
            array23 = vars->data[--pCounter];
            array23->refC++;
            DEBUG_COPY(array23->id);
         } else {
            array23 = (array_t*)malloc(sizeof(array_t));
            array23->size = 327;
            array23->refC = 1;
            array23->id = 23;
            array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
            memset(array23->data, 0, array23->size*sizeof(unsigned int));
            DEBUG_NEW(array23->id);
         }
         array23->refC--;
         if(array23->refC == 0) {
            free(array23->data);
            free(array23);
            DEBUG_FREE(array23->id);
         }
         array21->refC--;
         if(array21->refC == 0) {
            free(array21->data);
            free(array21);
            DEBUG_FREE(array21->id);
         }
      }
   }
   array_t* array24;
   if (pCounter > 0) {
      array24 = vars->data[--pCounter];
      array24->refC++;
      DEBUG_COPY(array24->id);
   } else {
      array24 = (array_t*)malloc(sizeof(array_t));
      array24->size = 336;
      array24->refC = 1;
      array24->id = 24;
      array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
      memset(array24->data, 0, array24->size*sizeof(unsigned int));
      DEBUG_NEW(array24->id);
   }
   return array24;
}

