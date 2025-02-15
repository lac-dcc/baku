#include "outs/4_2_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array98;
   if (pCounter > 0) {
      array98 = vars->data[--pCounter];
      array98->refC++;
      DEBUG_COPY(array98->id);
   } else {
      array98 = (array_t*)malloc(sizeof(array_t));
      array98->size = 505;
      array98->refC = 1;
      array98->id = 98;
      array98->data = (unsigned int*)malloc(array98->size*sizeof(unsigned int));
      memset(array98->data, 0, array98->size*sizeof(unsigned int));
      DEBUG_NEW(array98->id);
   }
   unsigned int loop21 = 0;
   unsigned int loopLimit21 = (rand()%loopsFactor)/2 + 1;
   for(; loop21 < loopLimit21; loop21++) {
      for (int i = 0; i < array98->size; i++) {
         array98->data[i]++;
      }
      for (int i = 0; i < array98->size; i++) {
         if (array98->data[i] == 86) { 
            return array98;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array98;
         array_t* array99 = func7(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array99->id);
         free(params0.data);
         array_t* array100;
         if (pCounter > 0) {
            array100 = vars->data[--pCounter];
            array100->refC++;
            DEBUG_COPY(array100->id);
         } else {
            array100 = (array_t*)malloc(sizeof(array_t));
            array100->size = 542;
            array100->refC = 1;
            array100->id = 100;
            array100->data = (unsigned int*)malloc(array100->size*sizeof(unsigned int));
            memset(array100->data, 0, array100->size*sizeof(unsigned int));
            DEBUG_NEW(array100->id);
         }
         array100->refC--;
         if(array100->refC == 0) {
            free(array100->data);
            free(array100);
            DEBUG_FREE(array100->id);
         }
         array99->refC--;
         if(array99->refC == 0) {
            free(array99->data);
            free(array99);
            DEBUG_FREE(array99->id);
         }
      }
      else {
         array_t* array101;
         if (pCounter > 0) {
            array101 = vars->data[--pCounter];
            array101->refC++;
            DEBUG_COPY(array101->id);
         } else {
            array101 = (array_t*)malloc(sizeof(array_t));
            array101->size = 464;
            array101->refC = 1;
            array101->id = 101;
            array101->data = (unsigned int*)malloc(array101->size*sizeof(unsigned int));
            memset(array101->data, 0, array101->size*sizeof(unsigned int));
            DEBUG_NEW(array101->id);
         }
         unsigned int loop22 = 0;
         unsigned int loopLimit22 = (rand()%loopsFactor)/3 + 1;
         for(; loop22 < loopLimit22; loop22++) {
            for (int i = 0; i < array101->size; i++) {
               array101->data[i]++;
            }
            for (int i = 0; i < array101->size; i++) {
               if (array101->data[i] == 55) { 
                  return array101;
               }
            }
            if(PATH0 & 2) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array98;
               params0.data[1] = array101;
               array_t* array102 = func14(&params0, rng(), loopsFactor);
               DEBUG_RETURN(array102->id);
               free(params0.data);
               array_t* array103;
               if (pCounter > 0) {
                  array103 = vars->data[--pCounter];
                  array103->refC++;
                  DEBUG_COPY(array103->id);
               } else {
                  array103 = (array_t*)malloc(sizeof(array_t));
                  array103->size = 611;
                  array103->refC = 1;
                  array103->id = 103;
                  array103->data = (unsigned int*)malloc(array103->size*sizeof(unsigned int));
                  memset(array103->data, 0, array103->size*sizeof(unsigned int));
                  DEBUG_NEW(array103->id);
               }
               array103->refC--;
               if(array103->refC == 0) {
                  free(array103->data);
                  free(array103);
                  DEBUG_FREE(array103->id);
               }
               array102->refC--;
               if(array102->refC == 0) {
                  free(array102->data);
                  free(array102);
                  DEBUG_FREE(array102->id);
               }
            }
            else {
               array_t* array104;
               if (pCounter > 0) {
                  array104 = vars->data[--pCounter];
                  array104->refC++;
                  DEBUG_COPY(array104->id);
               } else {
                  array104 = (array_t*)malloc(sizeof(array_t));
                  array104->size = 622;
                  array104->refC = 1;
                  array104->id = 104;
                  array104->data = (unsigned int*)malloc(array104->size*sizeof(unsigned int));
                  memset(array104->data, 0, array104->size*sizeof(unsigned int));
                  DEBUG_NEW(array104->id);
               }
               unsigned int loop23 = 0;
               unsigned int loopLimit23 = (rand()%loopsFactor)/4 + 1;
               for(; loop23 < loopLimit23; loop23++) {
                  for (int i = 0; i < array98->size; i++) {
                     array98->data[i]++;
                  }
                  for (int i = 0; i < array104->size; i++) {
                     if (array104->data[i] == 43) { 
                        return array104;
                     }
                  }
                  if(PATH0 & 4) {
                     array_t_param params0;
                     params0.size = 3;
                     params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                     params0.data[0] = array98;
                     params0.data[1] = array101;
                     params0.data[2] = array104;
                     array_t* array105 = func19(&params0, loopsFactor);
                     DEBUG_RETURN(array105->id);
                     free(params0.data);
                     array_t* array106;
                     if (pCounter > 0) {
                        array106 = vars->data[--pCounter];
                        array106->refC++;
                        DEBUG_COPY(array106->id);
                     } else {
                        array106 = (array_t*)malloc(sizeof(array_t));
                        array106->size = 340;
                        array106->refC = 1;
                        array106->id = 106;
                        array106->data = (unsigned int*)malloc(array106->size*sizeof(unsigned int));
                        memset(array106->data, 0, array106->size*sizeof(unsigned int));
                        DEBUG_NEW(array106->id);
                     }
                     array106->refC--;
                     if(array106->refC == 0) {
                        free(array106->data);
                        free(array106);
                        DEBUG_FREE(array106->id);
                     }
                     array105->refC--;
                     if(array105->refC == 0) {
                        free(array105->data);
                        free(array105);
                        DEBUG_FREE(array105->id);
                     }
                  }
                  else {
                  }
               }
               array_t* array107;
               if (pCounter > 0) {
                  array107 = vars->data[--pCounter];
                  array107->refC++;
                  DEBUG_COPY(array107->id);
               } else {
                  array107 = (array_t*)malloc(sizeof(array_t));
                  array107->size = 422;
                  array107->refC = 1;
                  array107->id = 107;
                  array107->data = (unsigned int*)malloc(array107->size*sizeof(unsigned int));
                  memset(array107->data, 0, array107->size*sizeof(unsigned int));
                  DEBUG_NEW(array107->id);
               }
               array107->refC--;
               if(array107->refC == 0) {
                  free(array107->data);
                  free(array107);
                  DEBUG_FREE(array107->id);
               }
               array104->refC--;
               if(array104->refC == 0) {
                  free(array104->data);
                  free(array104);
                  DEBUG_FREE(array104->id);
               }
            }
         }
         array_t* array108;
         if (pCounter > 0) {
            array108 = vars->data[--pCounter];
            array108->refC++;
            DEBUG_COPY(array108->id);
         } else {
            array108 = (array_t*)malloc(sizeof(array_t));
            array108->size = 311;
            array108->refC = 1;
            array108->id = 108;
            array108->data = (unsigned int*)malloc(array108->size*sizeof(unsigned int));
            memset(array108->data, 0, array108->size*sizeof(unsigned int));
            DEBUG_NEW(array108->id);
         }
         array108->refC--;
         if(array108->refC == 0) {
            free(array108->data);
            free(array108);
            DEBUG_FREE(array108->id);
         }
         array101->refC--;
         if(array101->refC == 0) {
            free(array101->data);
            free(array101);
            DEBUG_FREE(array101->id);
         }
      }
   }
   array_t* array109;
   if (pCounter > 0) {
      array109 = vars->data[--pCounter];
      array109->refC++;
      DEBUG_COPY(array109->id);
   } else {
      array109 = (array_t*)malloc(sizeof(array_t));
      array109->size = 810;
      array109->refC = 1;
      array109->id = 109;
      array109->data = (unsigned int*)malloc(array109->size*sizeof(unsigned int));
      memset(array109->data, 0, array109->size*sizeof(unsigned int));
      DEBUG_NEW(array109->id);
   }
   array98->refC--;
   if(array98->refC == 0) {
      free(array98->data);
      free(array98);
      DEBUG_FREE(array98->id);
   }
   return array109;
}

