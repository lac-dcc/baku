#include "outs/5_2_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array233;
   if (pCounter > 0) {
      array233 = vars->data[--pCounter];
      array233->refC++;
      DEBUG_COPY(array233->id);
   } else {
      array233 = (array_t*)malloc(sizeof(array_t));
      array233->size = 292;
      array233->refC = 1;
      array233->id = 233;
      array233->data = (unsigned int*)malloc(array233->size*sizeof(unsigned int));
      memset(array233->data, 0, array233->size*sizeof(unsigned int));
      DEBUG_NEW(array233->id);
   }
   unsigned int loop44 = 0;
   unsigned int loopLimit44 = (rand()%loopsFactor)/2 + 1;
   for(; loop44 < loopLimit44; loop44++) {
      for (int i = 0; i < array233->size; i++) {
         array233->data[i]++;
      }
      for (int i = 0; i < array233->size; i++) {
         if (array233->data[i] == 44) { 
            return array233;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array233;
         array_t* array234 = func7(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array234->id);
         free(params0.data);
         array_t* array235;
         if (pCounter > 0) {
            array235 = vars->data[--pCounter];
            array235->refC++;
            DEBUG_COPY(array235->id);
         } else {
            array235 = (array_t*)malloc(sizeof(array_t));
            array235->size = 682;
            array235->refC = 1;
            array235->id = 235;
            array235->data = (unsigned int*)malloc(array235->size*sizeof(unsigned int));
            memset(array235->data, 0, array235->size*sizeof(unsigned int));
            DEBUG_NEW(array235->id);
         }
         array235->refC--;
         if(array235->refC == 0) {
            free(array235->data);
            free(array235);
            DEBUG_FREE(array235->id);
         }
         array234->refC--;
         if(array234->refC == 0) {
            free(array234->data);
            free(array234);
            DEBUG_FREE(array234->id);
         }
      }
      else {
         array_t* array236;
         if (pCounter > 0) {
            array236 = vars->data[--pCounter];
            array236->refC++;
            DEBUG_COPY(array236->id);
         } else {
            array236 = (array_t*)malloc(sizeof(array_t));
            array236->size = 340;
            array236->refC = 1;
            array236->id = 236;
            array236->data = (unsigned int*)malloc(array236->size*sizeof(unsigned int));
            memset(array236->data, 0, array236->size*sizeof(unsigned int));
            DEBUG_NEW(array236->id);
         }
         unsigned int loop45 = 0;
         unsigned int loopLimit45 = (rand()%loopsFactor)/3 + 1;
         for(; loop45 < loopLimit45; loop45++) {
            for (int i = 0; i < array236->size; i++) {
               array236->data[i]++;
            }
            for (int i = 0; i < array236->size; i++) {
               if (array236->data[i] == 26) { 
                  return array236;
               }
            }
            if(PATH0 & 2) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array233;
               params0.data[1] = array236;
               array_t* array237 = func14(&params0, rng(), loopsFactor);
               DEBUG_RETURN(array237->id);
               free(params0.data);
               array_t* array238;
               if (pCounter > 0) {
                  array238 = vars->data[--pCounter];
                  array238->refC++;
                  DEBUG_COPY(array238->id);
               } else {
                  array238 = (array_t*)malloc(sizeof(array_t));
                  array238->size = 42;
                  array238->refC = 1;
                  array238->id = 238;
                  array238->data = (unsigned int*)malloc(array238->size*sizeof(unsigned int));
                  memset(array238->data, 0, array238->size*sizeof(unsigned int));
                  DEBUG_NEW(array238->id);
               }
               array238->refC--;
               if(array238->refC == 0) {
                  free(array238->data);
                  free(array238);
                  DEBUG_FREE(array238->id);
               }
               array237->refC--;
               if(array237->refC == 0) {
                  free(array237->data);
                  free(array237);
                  DEBUG_FREE(array237->id);
               }
            }
            else {
               array_t* array239;
               if (pCounter > 0) {
                  array239 = vars->data[--pCounter];
                  array239->refC++;
                  DEBUG_COPY(array239->id);
               } else {
                  array239 = (array_t*)malloc(sizeof(array_t));
                  array239->size = 360;
                  array239->refC = 1;
                  array239->id = 239;
                  array239->data = (unsigned int*)malloc(array239->size*sizeof(unsigned int));
                  memset(array239->data, 0, array239->size*sizeof(unsigned int));
                  DEBUG_NEW(array239->id);
               }
               unsigned int loop46 = 0;
               unsigned int loopLimit46 = (rand()%loopsFactor)/4 + 1;
               for(; loop46 < loopLimit46; loop46++) {
                  for (int i = 0; i < array233->size; i++) {
                     array233->data[i]++;
                  }
                  for (int i = 0; i < array233->size; i++) {
                     if (array233->data[i] == 61) { 
                        return array233;
                     }
                  }
                  if(PATH0 & 4) {
                     array_t_param params0;
                     params0.size = 3;
                     params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                     params0.data[0] = array233;
                     params0.data[1] = array236;
                     params0.data[2] = array239;
                     array_t* array240 = func19(&params0, rng(), loopsFactor);
                     DEBUG_RETURN(array240->id);
                     free(params0.data);
                     array_t* array241;
                     if (pCounter > 0) {
                        array241 = vars->data[--pCounter];
                        array241->refC++;
                        DEBUG_COPY(array241->id);
                     } else {
                        array241 = (array_t*)malloc(sizeof(array_t));
                        array241->size = 190;
                        array241->refC = 1;
                        array241->id = 241;
                        array241->data = (unsigned int*)malloc(array241->size*sizeof(unsigned int));
                        memset(array241->data, 0, array241->size*sizeof(unsigned int));
                        DEBUG_NEW(array241->id);
                     }
                     array241->refC--;
                     if(array241->refC == 0) {
                        free(array241->data);
                        free(array241);
                        DEBUG_FREE(array241->id);
                     }
                     array240->refC--;
                     if(array240->refC == 0) {
                        free(array240->data);
                        free(array240);
                        DEBUG_FREE(array240->id);
                     }
                  }
                  else {
                     array_t* array242;
                     if (pCounter > 0) {
                        array242 = vars->data[--pCounter];
                        array242->refC++;
                        DEBUG_COPY(array242->id);
                     } else {
                        array242 = (array_t*)malloc(sizeof(array_t));
                        array242->size = 425;
                        array242->refC = 1;
                        array242->id = 242;
                        array242->data = (unsigned int*)malloc(array242->size*sizeof(unsigned int));
                        memset(array242->data, 0, array242->size*sizeof(unsigned int));
                        DEBUG_NEW(array242->id);
                     }
                     unsigned int loop47 = 0;
                     unsigned int loopLimit47 = (rand()%loopsFactor)/5 + 1;
                     for(; loop47 < loopLimit47; loop47++) {
                        for (int i = 0; i < array233->size; i++) {
                           array233->data[i]++;
                        }
                        for (int i = 0; i < array242->size; i++) {
                           if (array242->data[i] == 77) { 
                              return array242;
                           }
                        }
                        if(PATH0 & 8) {
                           array_t_param params0;
                           params0.size = 4;
                           params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                           params0.data[0] = array233;
                           params0.data[1] = array236;
                           params0.data[2] = array239;
                           params0.data[3] = array242;
                           array_t* array243 = func24(&params0, loopsFactor);
                           DEBUG_RETURN(array243->id);
                           free(params0.data);
                           array_t* array244;
                           if (pCounter > 0) {
                              array244 = vars->data[--pCounter];
                              array244->refC++;
                              DEBUG_COPY(array244->id);
                           } else {
                              array244 = (array_t*)malloc(sizeof(array_t));
                              array244->size = 626;
                              array244->refC = 1;
                              array244->id = 244;
                              array244->data = (unsigned int*)malloc(array244->size*sizeof(unsigned int));
                              memset(array244->data, 0, array244->size*sizeof(unsigned int));
                              DEBUG_NEW(array244->id);
                           }
                           array244->refC--;
                           if(array244->refC == 0) {
                              free(array244->data);
                              free(array244);
                              DEBUG_FREE(array244->id);
                           }
                           array243->refC--;
                           if(array243->refC == 0) {
                              free(array243->data);
                              free(array243);
                              DEBUG_FREE(array243->id);
                           }
                        }
                        else {
                        }
                     }
                     array_t* array245;
                     if (pCounter > 0) {
                        array245 = vars->data[--pCounter];
                        array245->refC++;
                        DEBUG_COPY(array245->id);
                     } else {
                        array245 = (array_t*)malloc(sizeof(array_t));
                        array245->size = 524;
                        array245->refC = 1;
                        array245->id = 245;
                        array245->data = (unsigned int*)malloc(array245->size*sizeof(unsigned int));
                        memset(array245->data, 0, array245->size*sizeof(unsigned int));
                        DEBUG_NEW(array245->id);
                     }
                     array245->refC--;
                     if(array245->refC == 0) {
                        free(array245->data);
                        free(array245);
                        DEBUG_FREE(array245->id);
                     }
                     array242->refC--;
                     if(array242->refC == 0) {
                        free(array242->data);
                        free(array242);
                        DEBUG_FREE(array242->id);
                     }
                  }
               }
               array_t* array246;
               if (pCounter > 0) {
                  array246 = vars->data[--pCounter];
                  array246->refC++;
                  DEBUG_COPY(array246->id);
               } else {
                  array246 = (array_t*)malloc(sizeof(array_t));
                  array246->size = 57;
                  array246->refC = 1;
                  array246->id = 246;
                  array246->data = (unsigned int*)malloc(array246->size*sizeof(unsigned int));
                  memset(array246->data, 0, array246->size*sizeof(unsigned int));
                  DEBUG_NEW(array246->id);
               }
               array246->refC--;
               if(array246->refC == 0) {
                  free(array246->data);
                  free(array246);
                  DEBUG_FREE(array246->id);
               }
               array239->refC--;
               if(array239->refC == 0) {
                  free(array239->data);
                  free(array239);
                  DEBUG_FREE(array239->id);
               }
            }
         }
         array_t* array247;
         if (pCounter > 0) {
            array247 = vars->data[--pCounter];
            array247->refC++;
            DEBUG_COPY(array247->id);
         } else {
            array247 = (array_t*)malloc(sizeof(array_t));
            array247->size = 614;
            array247->refC = 1;
            array247->id = 247;
            array247->data = (unsigned int*)malloc(array247->size*sizeof(unsigned int));
            memset(array247->data, 0, array247->size*sizeof(unsigned int));
            DEBUG_NEW(array247->id);
         }
         array247->refC--;
         if(array247->refC == 0) {
            free(array247->data);
            free(array247);
            DEBUG_FREE(array247->id);
         }
         array236->refC--;
         if(array236->refC == 0) {
            free(array236->data);
            free(array236);
            DEBUG_FREE(array236->id);
         }
      }
   }
   array_t* array248;
   if (pCounter > 0) {
      array248 = vars->data[--pCounter];
      array248->refC++;
      DEBUG_COPY(array248->id);
   } else {
      array248 = (array_t*)malloc(sizeof(array_t));
      array248->size = 168;
      array248->refC = 1;
      array248->id = 248;
      array248->data = (unsigned int*)malloc(array248->size*sizeof(unsigned int));
      memset(array248->data, 0, array248->size*sizeof(unsigned int));
      DEBUG_NEW(array248->id);
   }
   array233->refC--;
   if(array233->refC == 0) {
      free(array233->data);
      free(array233);
      DEBUG_FREE(array233->id);
   }
   return array248;
}

