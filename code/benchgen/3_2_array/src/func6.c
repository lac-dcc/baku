#include "outs/3_2_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array192;
   if (pCounter > 0) {
      array192 = vars->data[--pCounter];
      array192->refC++;
      DEBUG_COPY(array192->id);
   } else {
      array192 = (array_t*)malloc(sizeof(array_t));
      array192->size = 908;
      array192->refC = 1;
      array192->id = 192;
      array192->data = (unsigned int*)malloc(array192->size*sizeof(unsigned int));
      memset(array192->data, 0, array192->size*sizeof(unsigned int));
      DEBUG_NEW(array192->id);
   }
   unsigned int loop35 = 0;
   unsigned int loopLimit35 = (rand()%loopsFactor)/2 + 1;
   for(; loop35 < loopLimit35; loop35++) {
      for (int i = 0; i < array192->size; i++) {
         array192->data[i]--;
      }
      unsigned int loop36 = 0;
      unsigned int loopLimit36 = (rand()%loopsFactor)/3 + 1;
      for(; loop36 < loopLimit36; loop36++) {
         array_t* array193;
         if (pCounter > 0) {
            array193 = vars->data[--pCounter];
            array193->refC++;
            DEBUG_COPY(array193->id);
         } else {
            array193 = (array_t*)malloc(sizeof(array_t));
            array193->size = 498;
            array193->refC = 1;
            array193->id = 193;
            array193->data = (unsigned int*)malloc(array193->size*sizeof(unsigned int));
            memset(array193->data, 0, array193->size*sizeof(unsigned int));
            DEBUG_NEW(array193->id);
         }
         if(PATH0 & 1) {
            array_t* array194;
            if (pCounter > 0) {
               array194 = vars->data[--pCounter];
               array194->refC++;
               DEBUG_COPY(array194->id);
            } else {
               array194 = (array_t*)malloc(sizeof(array_t));
               array194->size = 36;
               array194->refC = 1;
               array194->id = 194;
               array194->data = (unsigned int*)malloc(array194->size*sizeof(unsigned int));
               memset(array194->data, 0, array194->size*sizeof(unsigned int));
               DEBUG_NEW(array194->id);
            }
            array_t_param params0;
            params0.size = 3;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array192;
            params0.data[1] = array193;
            params0.data[2] = array194;
            array_t* array195 = func12(&params0, loopsFactor);
            DEBUG_RETURN(array195->id);
            free(params0.data);
            array_t* array196;
            if (pCounter > 0) {
               array196 = vars->data[--pCounter];
               array196->refC++;
               DEBUG_COPY(array196->id);
            } else {
               array196 = (array_t*)malloc(sizeof(array_t));
               array196->size = 248;
               array196->refC = 1;
               array196->id = 196;
               array196->data = (unsigned int*)malloc(array196->size*sizeof(unsigned int));
               memset(array196->data, 0, array196->size*sizeof(unsigned int));
               DEBUG_NEW(array196->id);
            }
            array_t* array197;
            if (pCounter > 0) {
               array197 = vars->data[--pCounter];
               array197->refC++;
               DEBUG_COPY(array197->id);
            } else {
               array197 = (array_t*)malloc(sizeof(array_t));
               array197->size = 303;
               array197->refC = 1;
               array197->id = 197;
               array197->data = (unsigned int*)malloc(array197->size*sizeof(unsigned int));
               memset(array197->data, 0, array197->size*sizeof(unsigned int));
               DEBUG_NEW(array197->id);
            }
            array197->refC--;
            if(array197->refC == 0) {
               free(array197->data);
               free(array197);
               DEBUG_FREE(array197->id);
            }
            array196->refC--;
            if(array196->refC == 0) {
               free(array196->data);
               free(array196);
               DEBUG_FREE(array196->id);
            }
            array195->refC--;
            if(array195->refC == 0) {
               free(array195->data);
               free(array195);
               DEBUG_FREE(array195->id);
            }
            array194->refC--;
            if(array194->refC == 0) {
               free(array194->data);
               free(array194);
               DEBUG_FREE(array194->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array192;
            params0.data[1] = array193;
            array_t* array198 = func13(&params0, loopsFactor);
            DEBUG_RETURN(array198->id);
            free(params0.data);
            array_t* array199;
            if (pCounter > 0) {
               array199 = vars->data[--pCounter];
               array199->refC++;
               DEBUG_COPY(array199->id);
            } else {
               array199 = (array_t*)malloc(sizeof(array_t));
               array199->size = 648;
               array199->refC = 1;
               array199->id = 199;
               array199->data = (unsigned int*)malloc(array199->size*sizeof(unsigned int));
               memset(array199->data, 0, array199->size*sizeof(unsigned int));
               DEBUG_NEW(array199->id);
            }
            array199->refC--;
            if(array199->refC == 0) {
               free(array199->data);
               free(array199);
               DEBUG_FREE(array199->id);
            }
            array198->refC--;
            if(array198->refC == 0) {
               free(array198->data);
               free(array198);
               DEBUG_FREE(array198->id);
            }
         }
         if(PATH0 & 2) {
            array_t* array200;
            if (pCounter > 0) {
               array200 = vars->data[--pCounter];
               array200->refC++;
               DEBUG_COPY(array200->id);
            } else {
               array200 = (array_t*)malloc(sizeof(array_t));
               array200->size = 890;
               array200->refC = 1;
               array200->id = 200;
               array200->data = (unsigned int*)malloc(array200->size*sizeof(unsigned int));
               memset(array200->data, 0, array200->size*sizeof(unsigned int));
               DEBUG_NEW(array200->id);
            }
            unsigned int loop37 = 0;
            unsigned int loopLimit37 = (rand()%loopsFactor)/4 + 1;
            for(; loop37 < loopLimit37; loop37++) {
               for (int i = 0; i < array192->size; i++) {
                  array192->data[i]++;
               }
               for (int i = 0; i < array193->size; i++) {
                  if (array193->data[i] == 46) { 
                     return array193;
                  }
               }
               if(PATH0 & 4) {
                  array_t_param params0;
                  params0.size = 3;
                  params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                  params0.data[0] = array192;
                  params0.data[1] = array193;
                  params0.data[2] = array200;
                  array_t* array201 = func14(&params0, loopsFactor);
                  DEBUG_RETURN(array201->id);
                  free(params0.data);
                  array_t* array202;
                  if (pCounter > 0) {
                     array202 = vars->data[--pCounter];
                     array202->refC++;
                     DEBUG_COPY(array202->id);
                  } else {
                     array202 = (array_t*)malloc(sizeof(array_t));
                     array202->size = 500;
                     array202->refC = 1;
                     array202->id = 202;
                     array202->data = (unsigned int*)malloc(array202->size*sizeof(unsigned int));
                     memset(array202->data, 0, array202->size*sizeof(unsigned int));
                     DEBUG_NEW(array202->id);
                  }
                  array202->refC--;
                  if(array202->refC == 0) {
                     free(array202->data);
                     free(array202);
                     DEBUG_FREE(array202->id);
                  }
                  array201->refC--;
                  if(array201->refC == 0) {
                     free(array201->data);
                     free(array201);
                     DEBUG_FREE(array201->id);
                  }
               }
               else {
               }
            }
            array_t* array203;
            if (pCounter > 0) {
               array203 = vars->data[--pCounter];
               array203->refC++;
               DEBUG_COPY(array203->id);
            } else {
               array203 = (array_t*)malloc(sizeof(array_t));
               array203->size = 46;
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
            array200->refC--;
            if(array200->refC == 0) {
               free(array200->data);
               free(array200);
               DEBUG_FREE(array200->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array192;
            params0.data[1] = array193;
            array_t* array204 = func15(&params0, loopsFactor);
            DEBUG_RETURN(array204->id);
            free(params0.data);
            for (int i = 0; i < array204->size; i++) {
               if (array204->data[i] == 90) { 
                  return array204;
               }
            }
            unsigned int loop38 = 0;
            unsigned int loopLimit38 = (rand()%loopsFactor)/4 + 1;
            for(; loop38 < loopLimit38; loop38++) {
               for (int i = 0; i < array193->size; i++) {
                  array193->data[i]--;
               }
               for (int i = 0; i < array193->size; i++) {
                  if (array193->data[i] == 63) { 
                     return array193;
                  }
               }
            }
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array192;
            params1.data[1] = array193;
            params1.data[2] = array204;
            array_t* array205 = func16(&params1, loopsFactor);
            DEBUG_RETURN(array205->id);
            free(params1.data);
            array_t* array206;
            if (pCounter > 0) {
               array206 = vars->data[--pCounter];
               array206->refC++;
               DEBUG_COPY(array206->id);
            } else {
               array206 = (array_t*)malloc(sizeof(array_t));
               array206->size = 892;
               array206->refC = 1;
               array206->id = 206;
               array206->data = (unsigned int*)malloc(array206->size*sizeof(unsigned int));
               memset(array206->data, 0, array206->size*sizeof(unsigned int));
               DEBUG_NEW(array206->id);
            }
            array_t* array207;
            if (pCounter > 0) {
               array207 = vars->data[--pCounter];
               array207->refC++;
               DEBUG_COPY(array207->id);
            } else {
               array207 = (array_t*)malloc(sizeof(array_t));
               array207->size = 686;
               array207->refC = 1;
               array207->id = 207;
               array207->data = (unsigned int*)malloc(array207->size*sizeof(unsigned int));
               memset(array207->data, 0, array207->size*sizeof(unsigned int));
               DEBUG_NEW(array207->id);
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
         }
         for (int i = 0; i < array193->size; i++) {
            if (array193->data[i] == 52) { 
               return array193;
            }
         }
         array_t* array208;
         if (pCounter > 0) {
            array208 = vars->data[--pCounter];
            array208->refC++;
            DEBUG_COPY(array208->id);
         } else {
            array208 = (array_t*)malloc(sizeof(array_t));
            array208->size = 996;
            array208->refC = 1;
            array208->id = 208;
            array208->data = (unsigned int*)malloc(array208->size*sizeof(unsigned int));
            memset(array208->data, 0, array208->size*sizeof(unsigned int));
            DEBUG_NEW(array208->id);
         }
         array208->refC--;
         if(array208->refC == 0) {
            free(array208->data);
            free(array208);
            DEBUG_FREE(array208->id);
         }
         array193->refC--;
         if(array193->refC == 0) {
            free(array193->data);
            free(array193);
            DEBUG_FREE(array193->id);
         }
      }
   }
   return array192;
}

