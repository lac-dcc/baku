#include "outs/4_2_array.h" 
array_t* func9(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array167;
   if (pCounter > 0) {
      array167 = vars->data[--pCounter];
      array167->refC++;
      DEBUG_COPY(array167->id);
   } else {
      array167 = (array_t*)malloc(sizeof(array_t));
      array167->size = 524;
      array167->refC = 1;
      array167->id = 167;
      array167->data = (unsigned int*)malloc(array167->size*sizeof(unsigned int));
      memset(array167->data, 0, array167->size*sizeof(unsigned int));
      DEBUG_NEW(array167->id);
   }
   unsigned int loop33 = 0;
   unsigned int loopLimit33 = (rand()%loopsFactor)/3 + 1;
   for(; loop33 < loopLimit33; loop33++) {
      for (int i = 0; i < array167->size; i++) {
         array167->data[i]--;
      }
      unsigned int loop34 = 0;
      unsigned int loopLimit34 = (rand()%loopsFactor)/4 + 1;
      for(; loop34 < loopLimit34; loop34++) {
         array_t* array168;
         if (pCounter > 0) {
            array168 = vars->data[--pCounter];
            array168->refC++;
            DEBUG_COPY(array168->id);
         } else {
            array168 = (array_t*)malloc(sizeof(array_t));
            array168->size = 209;
            array168->refC = 1;
            array168->id = 168;
            array168->data = (unsigned int*)malloc(array168->size*sizeof(unsigned int));
            memset(array168->data, 0, array168->size*sizeof(unsigned int));
            DEBUG_NEW(array168->id);
         }
         if(PATH0 & 1) {
            array_t* array169;
            if (pCounter > 0) {
               array169 = vars->data[--pCounter];
               array169->refC++;
               DEBUG_COPY(array169->id);
            } else {
               array169 = (array_t*)malloc(sizeof(array_t));
               array169->size = 581;
               array169->refC = 1;
               array169->id = 169;
               array169->data = (unsigned int*)malloc(array169->size*sizeof(unsigned int));
               memset(array169->data, 0, array169->size*sizeof(unsigned int));
               DEBUG_NEW(array169->id);
            }
            array_t_param params0;
            params0.size = 3;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array167;
            params0.data[1] = array168;
            params0.data[2] = array169;
            array_t* array170 = func20(&params0, loopsFactor);
            DEBUG_RETURN(array170->id);
            free(params0.data);
            array_t* array171;
            if (pCounter > 0) {
               array171 = vars->data[--pCounter];
               array171->refC++;
               DEBUG_COPY(array171->id);
            } else {
               array171 = (array_t*)malloc(sizeof(array_t));
               array171->size = 732;
               array171->refC = 1;
               array171->id = 171;
               array171->data = (unsigned int*)malloc(array171->size*sizeof(unsigned int));
               memset(array171->data, 0, array171->size*sizeof(unsigned int));
               DEBUG_NEW(array171->id);
            }
            array_t* array172;
            if (pCounter > 0) {
               array172 = vars->data[--pCounter];
               array172->refC++;
               DEBUG_COPY(array172->id);
            } else {
               array172 = (array_t*)malloc(sizeof(array_t));
               array172->size = 155;
               array172->refC = 1;
               array172->id = 172;
               array172->data = (unsigned int*)malloc(array172->size*sizeof(unsigned int));
               memset(array172->data, 0, array172->size*sizeof(unsigned int));
               DEBUG_NEW(array172->id);
            }
            array172->refC--;
            if(array172->refC == 0) {
               free(array172->data);
               free(array172);
               DEBUG_FREE(array172->id);
            }
            array171->refC--;
            if(array171->refC == 0) {
               free(array171->data);
               free(array171);
               DEBUG_FREE(array171->id);
            }
            array170->refC--;
            if(array170->refC == 0) {
               free(array170->data);
               free(array170);
               DEBUG_FREE(array170->id);
            }
            array169->refC--;
            if(array169->refC == 0) {
               free(array169->data);
               free(array169);
               DEBUG_FREE(array169->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array167;
            params0.data[1] = array168;
            array_t* array173 = func21(&params0, loopsFactor);
            DEBUG_RETURN(array173->id);
            free(params0.data);
            array_t* array174;
            if (pCounter > 0) {
               array174 = vars->data[--pCounter];
               array174->refC++;
               DEBUG_COPY(array174->id);
            } else {
               array174 = (array_t*)malloc(sizeof(array_t));
               array174->size = 379;
               array174->refC = 1;
               array174->id = 174;
               array174->data = (unsigned int*)malloc(array174->size*sizeof(unsigned int));
               memset(array174->data, 0, array174->size*sizeof(unsigned int));
               DEBUG_NEW(array174->id);
            }
            array174->refC--;
            if(array174->refC == 0) {
               free(array174->data);
               free(array174);
               DEBUG_FREE(array174->id);
            }
            array173->refC--;
            if(array173->refC == 0) {
               free(array173->data);
               free(array173);
               DEBUG_FREE(array173->id);
            }
         }
         if(PATH0 & 2) {
            array_t* array175;
            if (pCounter > 0) {
               array175 = vars->data[--pCounter];
               array175->refC++;
               DEBUG_COPY(array175->id);
            } else {
               array175 = (array_t*)malloc(sizeof(array_t));
               array175->size = 769;
               array175->refC = 1;
               array175->id = 175;
               array175->data = (unsigned int*)malloc(array175->size*sizeof(unsigned int));
               memset(array175->data, 0, array175->size*sizeof(unsigned int));
               DEBUG_NEW(array175->id);
            }
            unsigned int loop35 = 0;
            unsigned int loopLimit35 = (rand()%loopsFactor)/5 + 1;
            for(; loop35 < loopLimit35; loop35++) {
               for (int i = 0; i < array167->size; i++) {
                  array167->data[i]++;
               }
               for (int i = 0; i < array175->size; i++) {
                  if (array175->data[i] == 50) { 
                     return array175;
                  }
               }
               if(PATH0 & 4) {
                  array_t_param params0;
                  params0.size = 3;
                  params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                  params0.data[0] = array167;
                  params0.data[1] = array168;
                  params0.data[2] = array175;
                  array_t* array176 = func19(&params0, loopsFactor);
                  DEBUG_RETURN(array176->id);
                  free(params0.data);
                  array_t* array177;
                  if (pCounter > 0) {
                     array177 = vars->data[--pCounter];
                     array177->refC++;
                     DEBUG_COPY(array177->id);
                  } else {
                     array177 = (array_t*)malloc(sizeof(array_t));
                     array177->size = 142;
                     array177->refC = 1;
                     array177->id = 177;
                     array177->data = (unsigned int*)malloc(array177->size*sizeof(unsigned int));
                     memset(array177->data, 0, array177->size*sizeof(unsigned int));
                     DEBUG_NEW(array177->id);
                  }
                  array177->refC--;
                  if(array177->refC == 0) {
                     free(array177->data);
                     free(array177);
                     DEBUG_FREE(array177->id);
                  }
                  array176->refC--;
                  if(array176->refC == 0) {
                     free(array176->data);
                     free(array176);
                     DEBUG_FREE(array176->id);
                  }
               }
               else {
               }
            }
            array_t* array178;
            if (pCounter > 0) {
               array178 = vars->data[--pCounter];
               array178->refC++;
               DEBUG_COPY(array178->id);
            } else {
               array178 = (array_t*)malloc(sizeof(array_t));
               array178->size = 579;
               array178->refC = 1;
               array178->id = 178;
               array178->data = (unsigned int*)malloc(array178->size*sizeof(unsigned int));
               memset(array178->data, 0, array178->size*sizeof(unsigned int));
               DEBUG_NEW(array178->id);
            }
            array178->refC--;
            if(array178->refC == 0) {
               free(array178->data);
               free(array178);
               DEBUG_FREE(array178->id);
            }
            array175->refC--;
            if(array175->refC == 0) {
               free(array175->data);
               free(array175);
               DEBUG_FREE(array175->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array167;
            params0.data[1] = array168;
            array_t* array179 = func17(&params0, loopsFactor);
            DEBUG_RETURN(array179->id);
            free(params0.data);
            for (int i = 0; i < array168->size; i++) {
               if (array168->data[i] == 21) { 
                  return array168;
               }
            }
            unsigned int loop36 = 0;
            unsigned int loopLimit36 = (rand()%loopsFactor)/5 + 1;
            for(; loop36 < loopLimit36; loop36++) {
               for (int i = 0; i < array168->size; i++) {
                  array168->data[i]--;
               }
               for (int i = 0; i < array179->size; i++) {
                  if (array179->data[i] == 13) { 
                     return array179;
                  }
               }
            }
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array167;
            params1.data[1] = array168;
            params1.data[2] = array179;
            array_t* array180 = func18(&params1, loopsFactor);
            DEBUG_RETURN(array180->id);
            free(params1.data);
            array_t* array181;
            if (pCounter > 0) {
               array181 = vars->data[--pCounter];
               array181->refC++;
               DEBUG_COPY(array181->id);
            } else {
               array181 = (array_t*)malloc(sizeof(array_t));
               array181->size = 326;
               array181->refC = 1;
               array181->id = 181;
               array181->data = (unsigned int*)malloc(array181->size*sizeof(unsigned int));
               memset(array181->data, 0, array181->size*sizeof(unsigned int));
               DEBUG_NEW(array181->id);
            }
            array_t* array182;
            if (pCounter > 0) {
               array182 = vars->data[--pCounter];
               array182->refC++;
               DEBUG_COPY(array182->id);
            } else {
               array182 = (array_t*)malloc(sizeof(array_t));
               array182->size = 259;
               array182->refC = 1;
               array182->id = 182;
               array182->data = (unsigned int*)malloc(array182->size*sizeof(unsigned int));
               memset(array182->data, 0, array182->size*sizeof(unsigned int));
               DEBUG_NEW(array182->id);
            }
            array182->refC--;
            if(array182->refC == 0) {
               free(array182->data);
               free(array182);
               DEBUG_FREE(array182->id);
            }
            array181->refC--;
            if(array181->refC == 0) {
               free(array181->data);
               free(array181);
               DEBUG_FREE(array181->id);
            }
            array180->refC--;
            if(array180->refC == 0) {
               free(array180->data);
               free(array180);
               DEBUG_FREE(array180->id);
            }
            array179->refC--;
            if(array179->refC == 0) {
               free(array179->data);
               free(array179);
               DEBUG_FREE(array179->id);
            }
         }
         for (int i = 0; i < array167->size; i++) {
            if (array167->data[i] == 2) { 
               return array167;
            }
         }
         array_t* array183;
         if (pCounter > 0) {
            array183 = vars->data[--pCounter];
            array183->refC++;
            DEBUG_COPY(array183->id);
         } else {
            array183 = (array_t*)malloc(sizeof(array_t));
            array183->size = 202;
            array183->refC = 1;
            array183->id = 183;
            array183->data = (unsigned int*)malloc(array183->size*sizeof(unsigned int));
            memset(array183->data, 0, array183->size*sizeof(unsigned int));
            DEBUG_NEW(array183->id);
         }
         array183->refC--;
         if(array183->refC == 0) {
            free(array183->data);
            free(array183);
            DEBUG_FREE(array183->id);
         }
         array168->refC--;
         if(array168->refC == 0) {
            free(array168->data);
            free(array168);
            DEBUG_FREE(array168->id);
         }
      }
   }
   return array167;
}

