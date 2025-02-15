#include "outs/4_2_array.h" 
array_t* func4(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array186;
   if (pCounter > 0) {
      array186 = vars->data[--pCounter];
      array186->refC++;
      DEBUG_COPY(array186->id);
   } else {
      array186 = (array_t*)malloc(sizeof(array_t));
      array186->size = 189;
      array186->refC = 1;
      array186->id = 186;
      array186->data = (unsigned int*)malloc(array186->size*sizeof(unsigned int));
      memset(array186->data, 0, array186->size*sizeof(unsigned int));
      DEBUG_NEW(array186->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array186;
   array_t* array187 = func10(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array187->id);
   free(params0.data);
   for (int i = 0; i < array187->size; i++) {
      if (array187->data[i] == 49) { 
         return array187;
      }
   }
   unsigned int loop39 = 0;
   unsigned int loopLimit39 = (rand()%loopsFactor)/2 + 1;
   for(; loop39 < loopLimit39; loop39++) {
      for (int i = 0; i < array186->size; i++) {
         array186->data[i]--;
      }
      for (int i = 0; i < array187->size; i++) {
         if (array187->data[i] == 33) { 
            return array187;
         }
      }
      if(PATH0 & 1) {
         array_t* array196;
         if (pCounter > 0) {
            array196 = vars->data[--pCounter];
            array196->refC++;
            DEBUG_COPY(array196->id);
         } else {
            array196 = (array_t*)malloc(sizeof(array_t));
            array196->size = 363;
            array196->refC = 1;
            array196->id = 196;
            array196->data = (unsigned int*)malloc(array196->size*sizeof(unsigned int));
            memset(array196->data, 0, array196->size*sizeof(unsigned int));
            DEBUG_NEW(array196->id);
         }
         unsigned int loop40 = 0;
         unsigned int loopLimit40 = (rand()%loopsFactor)/3 + 1;
         for(; loop40 < loopLimit40; loop40++) {
            array_t* array197;
            if (pCounter > 0) {
               array197 = vars->data[--pCounter];
               array197->refC++;
               DEBUG_COPY(array197->id);
            } else {
               array197 = (array_t*)malloc(sizeof(array_t));
               array197->size = 497;
               array197->refC = 1;
               array197->id = 197;
               array197->data = (unsigned int*)malloc(array197->size*sizeof(unsigned int));
               memset(array197->data, 0, array197->size*sizeof(unsigned int));
               DEBUG_NEW(array197->id);
            }
            if(PATH0 & 2) {
            }
            else {
            }
            for (int i = 0; i < array187->size; i++) {
               if (array187->data[i] == 92) { 
                  return array187;
               }
            }
            array_t* array198;
            if (pCounter > 0) {
               array198 = vars->data[--pCounter];
               array198->refC++;
               DEBUG_COPY(array198->id);
            } else {
               array198 = (array_t*)malloc(sizeof(array_t));
               array198->size = 686;
               array198->refC = 1;
               array198->id = 198;
               array198->data = (unsigned int*)malloc(array198->size*sizeof(unsigned int));
               memset(array198->data, 0, array198->size*sizeof(unsigned int));
               DEBUG_NEW(array198->id);
            }
            array198->refC--;
            if(array198->refC == 0) {
               free(array198->data);
               free(array198);
               DEBUG_FREE(array198->id);
            }
            array197->refC--;
            if(array197->refC == 0) {
               free(array197->data);
               free(array197);
               DEBUG_FREE(array197->id);
            }
         }
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array186;
         params1.data[1] = array187;
         params1.data[2] = array196;
         array_t* array199 = func12(&params1, loopsFactor);
         DEBUG_RETURN(array199->id);
         free(params1.data);
         array_t* array200;
         if (pCounter > 0) {
            array200 = vars->data[--pCounter];
            array200->refC++;
            DEBUG_COPY(array200->id);
         } else {
            array200 = (array_t*)malloc(sizeof(array_t));
            array200->size = 996;
            array200->refC = 1;
            array200->id = 200;
            array200->data = (unsigned int*)malloc(array200->size*sizeof(unsigned int));
            memset(array200->data, 0, array200->size*sizeof(unsigned int));
            DEBUG_NEW(array200->id);
         }
         array_t* array201;
         if (pCounter > 0) {
            array201 = vars->data[--pCounter];
            array201->refC++;
            DEBUG_COPY(array201->id);
         } else {
            array201 = (array_t*)malloc(sizeof(array_t));
            array201->size = 975;
            array201->refC = 1;
            array201->id = 201;
            array201->data = (unsigned int*)malloc(array201->size*sizeof(unsigned int));
            memset(array201->data, 0, array201->size*sizeof(unsigned int));
            DEBUG_NEW(array201->id);
         }
         unsigned int loop41 = 0;
         unsigned int loopLimit41 = (rand()%loopsFactor)/3 + 1;
         for(; loop41 < loopLimit41; loop41++) {
            for (int i = 0; i < array196->size; i++) {
               array196->data[i]++;
            }
            for (int i = 0; i < array199->size; i++) {
               if (array199->data[i] == 29) { 
                  return array199;
               }
            }
            if(PATH0 & 4) {
               array_t_param params2;
               params2.size = 6;
               params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
               params2.data[0] = array186;
               params2.data[1] = array187;
               params2.data[2] = array196;
               params2.data[3] = array199;
               params2.data[4] = array200;
               params2.data[5] = array201;
               array_t* array202 = func19(&params2, loopsFactor);
               DEBUG_RETURN(array202->id);
               free(params2.data);
               array_t* array203;
               if (pCounter > 0) {
                  array203 = vars->data[--pCounter];
                  array203->refC++;
                  DEBUG_COPY(array203->id);
               } else {
                  array203 = (array_t*)malloc(sizeof(array_t));
                  array203->size = 414;
                  array203->refC = 1;
                  array203->id = 203;
                  array203->data = (unsigned int*)malloc(array203->size*sizeof(unsigned int));
                  memset(array203->data, 0, array203->size*sizeof(unsigned int));
                  DEBUG_NEW(array203->id);
               }
               array203->refC--;
               if(array203->refC == 0) {
                  free(array203->data);
                  free(array203);
                  DEBUG_FREE(array203->id);
               }
               array202->refC--;
               if(array202->refC == 0) {
                  free(array202->data);
                  free(array202);
                  DEBUG_FREE(array202->id);
               }
            }
            else {
            }
         }
         array_t* array204;
         if (pCounter > 0) {
            array204 = vars->data[--pCounter];
            array204->refC++;
            DEBUG_COPY(array204->id);
         } else {
            array204 = (array_t*)malloc(sizeof(array_t));
            array204->size = 921;
            array204->refC = 1;
            array204->id = 204;
            array204->data = (unsigned int*)malloc(array204->size*sizeof(unsigned int));
            memset(array204->data, 0, array204->size*sizeof(unsigned int));
            DEBUG_NEW(array204->id);
         }
         array_t* array205;
         if (pCounter > 0) {
            array205 = vars->data[--pCounter];
            array205->refC++;
            DEBUG_COPY(array205->id);
         } else {
            array205 = (array_t*)malloc(sizeof(array_t));
            array205->size = 460;
            array205->refC = 1;
            array205->id = 205;
            array205->data = (unsigned int*)malloc(array205->size*sizeof(unsigned int));
            memset(array205->data, 0, array205->size*sizeof(unsigned int));
            DEBUG_NEW(array205->id);
         }
         array205->refC--;
         if(array205->refC == 0) {
            free(array205->data);
            free(array205);
            DEBUG_FREE(array205->id);
         }
         array204->refC--;
         if(array204->refC == 0) {
            free(array204->data);
            free(array204);
            DEBUG_FREE(array204->id);
         }
         array201->refC--;
         if(array201->refC == 0) {
            free(array201->data);
            free(array201);
            DEBUG_FREE(array201->id);
         }
         array200->refC--;
         if(array200->refC == 0) {
            free(array200->data);
            free(array200);
            DEBUG_FREE(array200->id);
         }
         array199->refC--;
         if(array199->refC == 0) {
            free(array199->data);
            free(array199);
            DEBUG_FREE(array199->id);
         }
         array196->refC--;
         if(array196->refC == 0) {
            free(array196->data);
            free(array196);
            DEBUG_FREE(array196->id);
         }
      }
      else {
         if(PATH0 & 8) {
            array_t* array206;
            if (pCounter > 0) {
               array206 = vars->data[--pCounter];
               array206->refC++;
               DEBUG_COPY(array206->id);
            } else {
               array206 = (array_t*)malloc(sizeof(array_t));
               array206->size = 304;
               array206->refC = 1;
               array206->id = 206;
               array206->data = (unsigned int*)malloc(array206->size*sizeof(unsigned int));
               memset(array206->data, 0, array206->size*sizeof(unsigned int));
               DEBUG_NEW(array206->id);
            }
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array186;
            params1.data[1] = array187;
            params1.data[2] = array206;
            array_t* array207 = func20(&params1, loopsFactor);
            DEBUG_RETURN(array207->id);
            free(params1.data);
            array_t* array208;
            if (pCounter > 0) {
               array208 = vars->data[--pCounter];
               array208->refC++;
               DEBUG_COPY(array208->id);
            } else {
               array208 = (array_t*)malloc(sizeof(array_t));
               array208->size = 50;
               array208->refC = 1;
               array208->id = 208;
               array208->data = (unsigned int*)malloc(array208->size*sizeof(unsigned int));
               memset(array208->data, 0, array208->size*sizeof(unsigned int));
               DEBUG_NEW(array208->id);
            }
            array_t* array209;
            if (pCounter > 0) {
               array209 = vars->data[--pCounter];
               array209->refC++;
               DEBUG_COPY(array209->id);
            } else {
               array209 = (array_t*)malloc(sizeof(array_t));
               array209->size = 748;
               array209->refC = 1;
               array209->id = 209;
               array209->data = (unsigned int*)malloc(array209->size*sizeof(unsigned int));
               memset(array209->data, 0, array209->size*sizeof(unsigned int));
               DEBUG_NEW(array209->id);
            }
            array209->refC--;
            if(array209->refC == 0) {
               free(array209->data);
               free(array209);
               DEBUG_FREE(array209->id);
            }
            array208->refC--;
            if(array208->refC == 0) {
               free(array208->data);
               free(array208);
               DEBUG_FREE(array208->id);
            }
            array207->refC--;
            if(array207->refC == 0) {
               free(array207->data);
               free(array207);
               DEBUG_FREE(array207->id);
            }
            array206->refC--;
            if(array206->refC == 0) {
               free(array206->data);
               free(array206);
               DEBUG_FREE(array206->id);
            }
         }
         else {
            array_t_param params1;
            params1.size = 2;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array186;
            params1.data[1] = array187;
            array_t* array210 = func21(&params1, loopsFactor);
            DEBUG_RETURN(array210->id);
            free(params1.data);
            array_t* array211;
            if (pCounter > 0) {
               array211 = vars->data[--pCounter];
               array211->refC++;
               DEBUG_COPY(array211->id);
            } else {
               array211 = (array_t*)malloc(sizeof(array_t));
               array211->size = 794;
               array211->refC = 1;
               array211->id = 211;
               array211->data = (unsigned int*)malloc(array211->size*sizeof(unsigned int));
               memset(array211->data, 0, array211->size*sizeof(unsigned int));
               DEBUG_NEW(array211->id);
            }
            array211->refC--;
            if(array211->refC == 0) {
               free(array211->data);
               free(array211);
               DEBUG_FREE(array211->id);
            }
            array210->refC--;
            if(array210->refC == 0) {
               free(array210->data);
               free(array210);
               DEBUG_FREE(array210->id);
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array186;
         params1.data[1] = array187;
         array_t* array212 = func13(&params1, rng(), loopsFactor);
         DEBUG_RETURN(array212->id);
         free(params1.data);
         array_t* array213;
         if (pCounter > 0) {
            array213 = vars->data[--pCounter];
            array213->refC++;
            DEBUG_COPY(array213->id);
         } else {
            array213 = (array_t*)malloc(sizeof(array_t));
            array213->size = 43;
            array213->refC = 1;
            array213->id = 213;
            array213->data = (unsigned int*)malloc(array213->size*sizeof(unsigned int));
            memset(array213->data, 0, array213->size*sizeof(unsigned int));
            DEBUG_NEW(array213->id);
         }
         array213->refC--;
         if(array213->refC == 0) {
            free(array213->data);
            free(array213);
            DEBUG_FREE(array213->id);
         }
         array212->refC--;
         if(array212->refC == 0) {
            free(array212->data);
            free(array212);
            DEBUG_FREE(array212->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array186;
   params1.data[1] = array187;
   array_t* array214 = func11(&params1, rng(), loopsFactor);
   DEBUG_RETURN(array214->id);
   free(params1.data);
   array_t* array226;
   if (pCounter > 0) {
      array226 = vars->data[--pCounter];
      array226->refC++;
      DEBUG_COPY(array226->id);
   } else {
      array226 = (array_t*)malloc(sizeof(array_t));
      array226->size = 900;
      array226->refC = 1;
      array226->id = 226;
      array226->data = (unsigned int*)malloc(array226->size*sizeof(unsigned int));
      memset(array226->data, 0, array226->size*sizeof(unsigned int));
      DEBUG_NEW(array226->id);
   }
   array_t* array227;
   if (pCounter > 0) {
      array227 = vars->data[--pCounter];
      array227->refC++;
      DEBUG_COPY(array227->id);
   } else {
      array227 = (array_t*)malloc(sizeof(array_t));
      array227->size = 238;
      array227->refC = 1;
      array227->id = 227;
      array227->data = (unsigned int*)malloc(array227->size*sizeof(unsigned int));
      memset(array227->data, 0, array227->size*sizeof(unsigned int));
      DEBUG_NEW(array227->id);
   }
   array227->refC--;
   if(array227->refC == 0) {
      free(array227->data);
      free(array227);
      DEBUG_FREE(array227->id);
   }
   array226->refC--;
   if(array226->refC == 0) {
      free(array226->data);
      free(array226);
      DEBUG_FREE(array226->id);
   }
   array214->refC--;
   if(array214->refC == 0) {
      free(array214->data);
      free(array214);
      DEBUG_FREE(array214->id);
   }
   array186->refC--;
   if(array186->refC == 0) {
      free(array186->data);
      free(array186);
      DEBUG_FREE(array186->id);
   }
   return array187;
}

