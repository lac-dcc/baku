#include "outs/5_7_array.h" 
array_t* func5(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop22 = 0;
      unsigned int loopLimit22 = (rand()%loopsFactor)/1 + 1;
      for(; loop22 < loopLimit22; loop22++) {
         array_t* array93;
         if (pCounter > 0) {
            array93 = vars->data[--pCounter];
            array93->refC++;
            DEBUG_COPY(array93->id);
         } else {
            array93 = (array_t*)malloc(sizeof(array_t));
            array93->size = 725;
            array93->refC = 1;
            array93->id = 93;
            array93->data = (unsigned int*)malloc(array93->size*sizeof(unsigned int));
            memset(array93->data, 0, array93->size*sizeof(unsigned int));
            DEBUG_NEW(array93->id);
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array93;
         array_t* array94 = func12(&params0, loopsFactor);
         DEBUG_RETURN(array94->id);
         free(params0.data);
         array_t* array95;
         if (pCounter > 0) {
            array95 = vars->data[--pCounter];
            array95->refC++;
            DEBUG_COPY(array95->id);
         } else {
            array95 = (array_t*)malloc(sizeof(array_t));
            array95->size = 505;
            array95->refC = 1;
            array95->id = 95;
            array95->data = (unsigned int*)malloc(array95->size*sizeof(unsigned int));
            memset(array95->data, 0, array95->size*sizeof(unsigned int));
            DEBUG_NEW(array95->id);
         }
         if(PATH0 & 2) {
            unsigned int loop23 = 0;
            unsigned int loopLimit23 = (rand()%loopsFactor)/2 + 1;
            for(; loop23 < loopLimit23; loop23++) {
            }
         }
         else {
            array_t* array96;
            if (pCounter > 0) {
               array96 = vars->data[--pCounter];
               array96->refC++;
               DEBUG_COPY(array96->id);
            } else {
               array96 = (array_t*)malloc(sizeof(array_t));
               array96->size = 139;
               array96->refC = 1;
               array96->id = 96;
               array96->data = (unsigned int*)malloc(array96->size*sizeof(unsigned int));
               memset(array96->data, 0, array96->size*sizeof(unsigned int));
               DEBUG_NEW(array96->id);
            }
            array_t_param params1;
            params1.size = 4;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array93;
            params1.data[1] = array94;
            params1.data[2] = array95;
            params1.data[3] = array96;
            array_t* array97 = func13(&params1, loopsFactor);
            DEBUG_RETURN(array97->id);
            free(params1.data);
            array97->refC--;
            if(array97->refC == 0) {
               free(array97->data);
               free(array97);
               DEBUG_FREE(array97->id);
            }
            array96->refC--;
            if(array96->refC == 0) {
               free(array96->data);
               free(array96);
               DEBUG_FREE(array96->id);
            }
         }
         for (int i = 0; i < array93->size; i++) {
            if (array93->data[i] == 82) { 
               return array93;
            }
         }
         array_t* array98;
         if (pCounter > 0) {
            array98 = vars->data[--pCounter];
            array98->refC++;
            DEBUG_COPY(array98->id);
         } else {
            array98 = (array_t*)malloc(sizeof(array_t));
            array98->size = 542;
            array98->refC = 1;
            array98->id = 98;
            array98->data = (unsigned int*)malloc(array98->size*sizeof(unsigned int));
            memset(array98->data, 0, array98->size*sizeof(unsigned int));
            DEBUG_NEW(array98->id);
         }
         array_t* array99;
         if (pCounter > 0) {
            array99 = vars->data[--pCounter];
            array99->refC++;
            DEBUG_COPY(array99->id);
         } else {
            array99 = (array_t*)malloc(sizeof(array_t));
            array99->size = 464;
            array99->refC = 1;
            array99->id = 99;
            array99->data = (unsigned int*)malloc(array99->size*sizeof(unsigned int));
            memset(array99->data, 0, array99->size*sizeof(unsigned int));
            DEBUG_NEW(array99->id);
         }
         for (int i = 0; i < array95->size; i++) {
            array95->data[i]++;
         }
         unsigned int loop24 = 0;
         unsigned int loopLimit24 = (rand()%loopsFactor)/2 + 1;
         for(; loop24 < loopLimit24; loop24++) {
            for (int i = 0; i < array95->size; i++) {
               array95->data[i]--;
            }
         }
         array_t_param params1;
         params1.size = 5;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array93;
         params1.data[1] = array94;
         params1.data[2] = array95;
         params1.data[3] = array98;
         params1.data[4] = array99;
         array_t* array100 = func14(&params1, loopsFactor);
         DEBUG_RETURN(array100->id);
         free(params1.data);
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
         array98->refC--;
         if(array98->refC == 0) {
            free(array98->data);
            free(array98);
            DEBUG_FREE(array98->id);
         }
         array95->refC--;
         if(array95->refC == 0) {
            free(array95->data);
            free(array95);
            DEBUG_FREE(array95->id);
         }
         array94->refC--;
         if(array94->refC == 0) {
            free(array94->data);
            free(array94);
            DEBUG_FREE(array94->id);
         }
         array93->refC--;
         if(array93->refC == 0) {
            free(array93->data);
            free(array93);
            DEBUG_FREE(array93->id);
         }
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
         array101->size = 348;
         array101->refC = 1;
         array101->id = 101;
         array101->data = (unsigned int*)malloc(array101->size*sizeof(unsigned int));
         memset(array101->data, 0, array101->size*sizeof(unsigned int));
         DEBUG_NEW(array101->id);
      }
      array_t* array102;
      if (pCounter > 0) {
         array102 = vars->data[--pCounter];
         array102->refC++;
         DEBUG_COPY(array102->id);
      } else {
         array102 = (array_t*)malloc(sizeof(array_t));
         array102->size = 611;
         array102->refC = 1;
         array102->id = 102;
         array102->data = (unsigned int*)malloc(array102->size*sizeof(unsigned int));
         memset(array102->data, 0, array102->size*sizeof(unsigned int));
         DEBUG_NEW(array102->id);
      }
      array_t* array103;
      if (pCounter > 0) {
         array103 = vars->data[--pCounter];
         array103->refC++;
         DEBUG_COPY(array103->id);
      } else {
         array103 = (array_t*)malloc(sizeof(array_t));
         array103->size = 622;
         array103->refC = 1;
         array103->id = 103;
         array103->data = (unsigned int*)malloc(array103->size*sizeof(unsigned int));
         memset(array103->data, 0, array103->size*sizeof(unsigned int));
         DEBUG_NEW(array103->id);
      }
      for (int i = 0; i < array101->size; i++) {
         array101->data[i]++;
      }
      unsigned int loop25 = 0;
      unsigned int loopLimit25 = (rand()%loopsFactor)/1 + 1;
      for(; loop25 < loopLimit25; loop25++) {
         for (int i = 0; i < array103->size; i++) {
            array103->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array101;
      params0.data[1] = array102;
      params0.data[2] = array103;
      array_t* array104 = func10(&params0, loopsFactor);
      DEBUG_RETURN(array104->id);
      free(params0.data);
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array101;
      params1.data[1] = array102;
      params1.data[2] = array103;
      params1.data[3] = array104;
      array_t* array105 = func7(&params1, loopsFactor);
      DEBUG_RETURN(array105->id);
      free(params1.data);
      array105->refC--;
      if(array105->refC == 0) {
         free(array105->data);
         free(array105);
         DEBUG_FREE(array105->id);
      }
      array104->refC--;
      if(array104->refC == 0) {
         free(array104->data);
         free(array104);
         DEBUG_FREE(array104->id);
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
      array101->refC--;
      if(array101->refC == 0) {
         free(array101->data);
         free(array101);
         DEBUG_FREE(array101->id);
      }
   }
   array_t* array106;
   if (pCounter > 0) {
      array106 = vars->data[--pCounter];
      array106->refC++;
      DEBUG_COPY(array106->id);
   } else {
      array106 = (array_t*)malloc(sizeof(array_t));
      array106->size = 422;
      array106->refC = 1;
      array106->id = 106;
      array106->data = (unsigned int*)malloc(array106->size*sizeof(unsigned int));
      memset(array106->data, 0, array106->size*sizeof(unsigned int));
      DEBUG_NEW(array106->id);
   }
   array_t* array107;
   if (pCounter > 0) {
      array107 = vars->data[--pCounter];
      array107->refC++;
      DEBUG_COPY(array107->id);
   } else {
      array107 = (array_t*)malloc(sizeof(array_t));
      array107->size = 311;
      array107->refC = 1;
      array107->id = 107;
      array107->data = (unsigned int*)malloc(array107->size*sizeof(unsigned int));
      memset(array107->data, 0, array107->size*sizeof(unsigned int));
      DEBUG_NEW(array107->id);
   }
   for (int i = 0; i < array106->size; i++) {
      array106->data[i]++;
   }
   unsigned int loop26 = 0;
   unsigned int loopLimit26 = (rand()%loopsFactor)/1 + 1;
   for(; loop26 < loopLimit26; loop26++) {
      for (int i = 0; i < array107->size; i++) {
         array107->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array106;
   params0.data[1] = array107;
   array_t* array108 = func8(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array108->id);
   free(params0.data);
   array108->refC--;
   if(array108->refC == 0) {
      free(array108->data);
      free(array108);
      DEBUG_FREE(array108->id);
   }
   array107->refC--;
   if(array107->refC == 0) {
      free(array107->data);
      free(array107);
      DEBUG_FREE(array107->id);
   }
   return array106;
}

