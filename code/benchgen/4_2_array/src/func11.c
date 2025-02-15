#include "outs/4_2_array.h" 
array_t* func11(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array215;
   if (pCounter > 0) {
      array215 = vars->data[--pCounter];
      array215->refC++;
      DEBUG_COPY(array215->id);
   } else {
      array215 = (array_t*)malloc(sizeof(array_t));
      array215->size = 500;
      array215->refC = 1;
      array215->id = 215;
      array215->data = (unsigned int*)malloc(array215->size*sizeof(unsigned int));
      memset(array215->data, 0, array215->size*sizeof(unsigned int));
      DEBUG_NEW(array215->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array215;
   array_t* array216 = func15(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array216->id);
   free(params0.data);
   for (int i = 0; i < array215->size; i++) {
      if (array215->data[i] == 59) { 
         return array215;
      }
   }
   unsigned int loop42 = 0;
   unsigned int loopLimit42 = (rand()%loopsFactor)/2 + 1;
   for(; loop42 < loopLimit42; loop42++) {
      for (int i = 0; i < array216->size; i++) {
         array216->data[i]--;
      }
      for (int i = 0; i < array216->size; i++) {
         if (array216->data[i] == 34) { 
            return array216;
         }
      }
      if(PATH0 & 1) {
         array_t* array217;
         if (pCounter > 0) {
            array217 = vars->data[--pCounter];
            array217->refC++;
            DEBUG_COPY(array217->id);
         } else {
            array217 = (array_t*)malloc(sizeof(array_t));
            array217->size = 339;
            array217->refC = 1;
            array217->id = 217;
            array217->data = (unsigned int*)malloc(array217->size*sizeof(unsigned int));
            memset(array217->data, 0, array217->size*sizeof(unsigned int));
            DEBUG_NEW(array217->id);
         }
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array215;
         params1.data[1] = array216;
         params1.data[2] = array217;
         array_t* array218 = func20(&params1, loopsFactor);
         DEBUG_RETURN(array218->id);
         free(params1.data);
         array_t* array219;
         if (pCounter > 0) {
            array219 = vars->data[--pCounter];
            array219->refC++;
            DEBUG_COPY(array219->id);
         } else {
            array219 = (array_t*)malloc(sizeof(array_t));
            array219->size = 127;
            array219->refC = 1;
            array219->id = 219;
            array219->data = (unsigned int*)malloc(array219->size*sizeof(unsigned int));
            memset(array219->data, 0, array219->size*sizeof(unsigned int));
            DEBUG_NEW(array219->id);
         }
         array_t* array220;
         if (pCounter > 0) {
            array220 = vars->data[--pCounter];
            array220->refC++;
            DEBUG_COPY(array220->id);
         } else {
            array220 = (array_t*)malloc(sizeof(array_t));
            array220->size = 504;
            array220->refC = 1;
            array220->id = 220;
            array220->data = (unsigned int*)malloc(array220->size*sizeof(unsigned int));
            memset(array220->data, 0, array220->size*sizeof(unsigned int));
            DEBUG_NEW(array220->id);
         }
         array220->refC--;
         if(array220->refC == 0) {
            free(array220->data);
            free(array220);
            DEBUG_FREE(array220->id);
         }
         array219->refC--;
         if(array219->refC == 0) {
            free(array219->data);
            free(array219);
            DEBUG_FREE(array219->id);
         }
         array218->refC--;
         if(array218->refC == 0) {
            free(array218->data);
            free(array218);
            DEBUG_FREE(array218->id);
         }
         array217->refC--;
         if(array217->refC == 0) {
            free(array217->data);
            free(array217);
            DEBUG_FREE(array217->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array215;
         params1.data[1] = array216;
         array_t* array221 = func21(&params1, loopsFactor);
         DEBUG_RETURN(array221->id);
         free(params1.data);
         array_t* array222;
         if (pCounter > 0) {
            array222 = vars->data[--pCounter];
            array222->refC++;
            DEBUG_COPY(array222->id);
         } else {
            array222 = (array_t*)malloc(sizeof(array_t));
            array222->size = 964;
            array222->refC = 1;
            array222->id = 222;
            array222->data = (unsigned int*)malloc(array222->size*sizeof(unsigned int));
            memset(array222->data, 0, array222->size*sizeof(unsigned int));
            DEBUG_NEW(array222->id);
         }
         array222->refC--;
         if(array222->refC == 0) {
            free(array222->data);
            free(array222);
            DEBUG_FREE(array222->id);
         }
         array221->refC--;
         if(array221->refC == 0) {
            free(array221->data);
            free(array221);
            DEBUG_FREE(array221->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array215;
   params1.data[1] = array216;
   array_t* array223 = func16(&params1, loopsFactor);
   DEBUG_RETURN(array223->id);
   free(params1.data);
   array_t* array224;
   if (pCounter > 0) {
      array224 = vars->data[--pCounter];
      array224->refC++;
      DEBUG_COPY(array224->id);
   } else {
      array224 = (array_t*)malloc(sizeof(array_t));
      array224->size = 343;
      array224->refC = 1;
      array224->id = 224;
      array224->data = (unsigned int*)malloc(array224->size*sizeof(unsigned int));
      memset(array224->data, 0, array224->size*sizeof(unsigned int));
      DEBUG_NEW(array224->id);
   }
   array_t* array225;
   if (pCounter > 0) {
      array225 = vars->data[--pCounter];
      array225->refC++;
      DEBUG_COPY(array225->id);
   } else {
      array225 = (array_t*)malloc(sizeof(array_t));
      array225->size = 335;
      array225->refC = 1;
      array225->id = 225;
      array225->data = (unsigned int*)malloc(array225->size*sizeof(unsigned int));
      memset(array225->data, 0, array225->size*sizeof(unsigned int));
      DEBUG_NEW(array225->id);
   }
   array225->refC--;
   if(array225->refC == 0) {
      free(array225->data);
      free(array225);
      DEBUG_FREE(array225->id);
   }
   array224->refC--;
   if(array224->refC == 0) {
      free(array224->data);
      free(array224);
      DEBUG_FREE(array224->id);
   }
   array216->refC--;
   if(array216->refC == 0) {
      free(array216->data);
      free(array216);
      DEBUG_FREE(array216->id);
   }
   array215->refC--;
   if(array215->refC == 0) {
      free(array215->data);
      free(array215);
      DEBUG_FREE(array215->id);
   }
   return array223;
}

