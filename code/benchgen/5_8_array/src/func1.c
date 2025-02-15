#include "outs/5_8_array.h" 
array_t* func1(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array97;
   if (pCounter > 0) {
      array97 = vars->data[--pCounter];
      array97->refC++;
      DEBUG_COPY(array97->id);
   } else {
      array97 = (array_t*)malloc(sizeof(array_t));
      array97->size = 206;
      array97->refC = 1;
      array97->id = 97;
      array97->data = (unsigned int*)malloc(array97->size*sizeof(unsigned int));
      memset(array97->data, 0, array97->size*sizeof(unsigned int));
      DEBUG_NEW(array97->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array97;
   array_t* array98 = func3(&params0, loopsFactor);
   DEBUG_RETURN(array98->id);
   free(params0.data);
   if(PATH0 & 1) {
      array_t* array101;
      if (pCounter > 0) {
         array101 = vars->data[--pCounter];
         array101->refC++;
         DEBUG_COPY(array101->id);
      } else {
         array101 = (array_t*)malloc(sizeof(array_t));
         array101->size = 940;
         array101->refC = 1;
         array101->id = 101;
         array101->data = (unsigned int*)malloc(array101->size*sizeof(unsigned int));
         memset(array101->data, 0, array101->size*sizeof(unsigned int));
         DEBUG_NEW(array101->id);
      }
      unsigned int loop30 = 0;
      unsigned int loopLimit30 = (rand()%loopsFactor)/2 + 1;
      for(; loop30 < loopLimit30; loop30++) {
         for (int i = 0; i < array101->size; i++) {
            array101->data[i]--;
         }
         for (int i = 0; i < array101->size; i++) {
            if (array101->data[i] == 28) { 
               return array101;
            }
         }
      }
      array_t_param params1;
      params1.size = 3;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array97;
      params1.data[1] = array98;
      params1.data[2] = array101;
      array_t* array102 = func10(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array102->id);
      free(params1.data);
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
   else {
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array97;
      params1.data[1] = array98;
      array_t* array103 = func4(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array103->id);
      free(params1.data);
      array103->refC--;
      if(array103->refC == 0) {
         free(array103->data);
         free(array103);
         DEBUG_FREE(array103->id);
      }
   }
   array98->refC--;
   if(array98->refC == 0) {
      free(array98->data);
      free(array98);
      DEBUG_FREE(array98->id);
   }
   return array97;
}

