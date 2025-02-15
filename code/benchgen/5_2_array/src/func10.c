#include "outs/5_2_array.h" 
array_t* func10(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array417;
   if (pCounter > 0) {
      array417 = vars->data[--pCounter];
      array417->refC++;
      DEBUG_COPY(array417->id);
   } else {
      array417 = (array_t*)malloc(sizeof(array_t));
      array417->size = 171;
      array417->refC = 1;
      array417->id = 417;
      array417->data = (unsigned int*)malloc(array417->size*sizeof(unsigned int));
      memset(array417->data, 0, array417->size*sizeof(unsigned int));
      DEBUG_NEW(array417->id);
   }
   unsigned int loop75 = 0;
   unsigned int loopLimit75 = (rand()%loopsFactor)/2 + 1;
   for(; loop75 < loopLimit75; loop75++) {
      for (int i = 0; i < array417->size; i++) {
         array417->data[i]++;
      }
      for (int i = 0; i < array417->size; i++) {
         if (array417->data[i] == 6) { 
            return array417;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array417;
         array_t* array418 = func14(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array418->id);
         free(params0.data);
         array_t* array419;
         if (pCounter > 0) {
            array419 = vars->data[--pCounter];
            array419->refC++;
            DEBUG_COPY(array419->id);
         } else {
            array419 = (array_t*)malloc(sizeof(array_t));
            array419->size = 224;
            array419->refC = 1;
            array419->id = 419;
            array419->data = (unsigned int*)malloc(array419->size*sizeof(unsigned int));
            memset(array419->data, 0, array419->size*sizeof(unsigned int));
            DEBUG_NEW(array419->id);
         }
         array419->refC--;
         if(array419->refC == 0) {
            free(array419->data);
            free(array419);
            DEBUG_FREE(array419->id);
         }
         array418->refC--;
         if(array418->refC == 0) {
            free(array418->data);
            free(array418);
            DEBUG_FREE(array418->id);
         }
      }
      else {
         array_t* array420;
         if (pCounter > 0) {
            array420 = vars->data[--pCounter];
            array420->refC++;
            DEBUG_COPY(array420->id);
         } else {
            array420 = (array_t*)malloc(sizeof(array_t));
            array420->size = 109;
            array420->refC = 1;
            array420->id = 420;
            array420->data = (unsigned int*)malloc(array420->size*sizeof(unsigned int));
            memset(array420->data, 0, array420->size*sizeof(unsigned int));
            DEBUG_NEW(array420->id);
         }
         unsigned int loop76 = 0;
         unsigned int loopLimit76 = (rand()%loopsFactor)/3 + 1;
         for(; loop76 < loopLimit76; loop76++) {
            for (int i = 0; i < array420->size; i++) {
               array420->data[i]++;
            }
            for (int i = 0; i < array417->size; i++) {
               if (array417->data[i] == 78) { 
                  return array417;
               }
            }
            if(PATH0 & 2) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array417;
               params0.data[1] = array420;
               array_t* array421 = func19(&params0, rng(), loopsFactor);
               DEBUG_RETURN(array421->id);
               free(params0.data);
               array_t* array422;
               if (pCounter > 0) {
                  array422 = vars->data[--pCounter];
                  array422->refC++;
                  DEBUG_COPY(array422->id);
               } else {
                  array422 = (array_t*)malloc(sizeof(array_t));
                  array422->size = 81;
                  array422->refC = 1;
                  array422->id = 422;
                  array422->data = (unsigned int*)malloc(array422->size*sizeof(unsigned int));
                  memset(array422->data, 0, array422->size*sizeof(unsigned int));
                  DEBUG_NEW(array422->id);
               }
               array422->refC--;
               if(array422->refC == 0) {
                  free(array422->data);
                  free(array422);
                  DEBUG_FREE(array422->id);
               }
               array421->refC--;
               if(array421->refC == 0) {
                  free(array421->data);
                  free(array421);
                  DEBUG_FREE(array421->id);
               }
            }
            else {
               array_t* array423;
               if (pCounter > 0) {
                  array423 = vars->data[--pCounter];
                  array423->refC++;
                  DEBUG_COPY(array423->id);
               } else {
                  array423 = (array_t*)malloc(sizeof(array_t));
                  array423->size = 114;
                  array423->refC = 1;
                  array423->id = 423;
                  array423->data = (unsigned int*)malloc(array423->size*sizeof(unsigned int));
                  memset(array423->data, 0, array423->size*sizeof(unsigned int));
                  DEBUG_NEW(array423->id);
               }
               unsigned int loop77 = 0;
               unsigned int loopLimit77 = (rand()%loopsFactor)/4 + 1;
               for(; loop77 < loopLimit77; loop77++) {
                  for (int i = 0; i < array417->size; i++) {
                     array417->data[i]++;
                  }
                  for (int i = 0; i < array423->size; i++) {
                     if (array423->data[i] == 26) { 
                        return array423;
                     }
                  }
                  if(PATH0 & 4) {
                     array_t_param params0;
                     params0.size = 3;
                     params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                     params0.data[0] = array417;
                     params0.data[1] = array420;
                     params0.data[2] = array423;
                     array_t* array424 = func24(&params0, loopsFactor);
                     DEBUG_RETURN(array424->id);
                     free(params0.data);
                     array_t* array425;
                     if (pCounter > 0) {
                        array425 = vars->data[--pCounter];
                        array425->refC++;
                        DEBUG_COPY(array425->id);
                     } else {
                        array425 = (array_t*)malloc(sizeof(array_t));
                        array425->size = 223;
                        array425->refC = 1;
                        array425->id = 425;
                        array425->data = (unsigned int*)malloc(array425->size*sizeof(unsigned int));
                        memset(array425->data, 0, array425->size*sizeof(unsigned int));
                        DEBUG_NEW(array425->id);
                     }
                     array425->refC--;
                     if(array425->refC == 0) {
                        free(array425->data);
                        free(array425);
                        DEBUG_FREE(array425->id);
                     }
                     array424->refC--;
                     if(array424->refC == 0) {
                        free(array424->data);
                        free(array424);
                        DEBUG_FREE(array424->id);
                     }
                  }
                  else {
                  }
               }
               array_t* array426;
               if (pCounter > 0) {
                  array426 = vars->data[--pCounter];
                  array426->refC++;
                  DEBUG_COPY(array426->id);
               } else {
                  array426 = (array_t*)malloc(sizeof(array_t));
                  array426->size = 787;
                  array426->refC = 1;
                  array426->id = 426;
                  array426->data = (unsigned int*)malloc(array426->size*sizeof(unsigned int));
                  memset(array426->data, 0, array426->size*sizeof(unsigned int));
                  DEBUG_NEW(array426->id);
               }
               array426->refC--;
               if(array426->refC == 0) {
                  free(array426->data);
                  free(array426);
                  DEBUG_FREE(array426->id);
               }
               array423->refC--;
               if(array423->refC == 0) {
                  free(array423->data);
                  free(array423);
                  DEBUG_FREE(array423->id);
               }
            }
         }
         array_t* array427;
         if (pCounter > 0) {
            array427 = vars->data[--pCounter];
            array427->refC++;
            DEBUG_COPY(array427->id);
         } else {
            array427 = (array_t*)malloc(sizeof(array_t));
            array427->size = 231;
            array427->refC = 1;
            array427->id = 427;
            array427->data = (unsigned int*)malloc(array427->size*sizeof(unsigned int));
            memset(array427->data, 0, array427->size*sizeof(unsigned int));
            DEBUG_NEW(array427->id);
         }
         array427->refC--;
         if(array427->refC == 0) {
            free(array427->data);
            free(array427);
            DEBUG_FREE(array427->id);
         }
         array420->refC--;
         if(array420->refC == 0) {
            free(array420->data);
            free(array420);
            DEBUG_FREE(array420->id);
         }
      }
   }
   array_t* array428;
   if (pCounter > 0) {
      array428 = vars->data[--pCounter];
      array428->refC++;
      DEBUG_COPY(array428->id);
   } else {
      array428 = (array_t*)malloc(sizeof(array_t));
      array428->size = 532;
      array428->refC = 1;
      array428->id = 428;
      array428->data = (unsigned int*)malloc(array428->size*sizeof(unsigned int));
      memset(array428->data, 0, array428->size*sizeof(unsigned int));
      DEBUG_NEW(array428->id);
   }
   array428->refC--;
   if(array428->refC == 0) {
      free(array428->data);
      free(array428);
      DEBUG_FREE(array428->id);
   }
   return array417;
}

