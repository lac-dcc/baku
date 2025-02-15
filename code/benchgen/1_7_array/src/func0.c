#include "outs/1_7_array.h" 
array_t* func0(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop0 = 0;
      unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
      for(; loop0 < loopLimit0; loop0++) {
      }
   }
   else {
      array_t* array2;
      if (pCounter > 0) {
         array2 = vars->data[--pCounter];
         array2->refC++;
         DEBUG_COPY(array2->id);
      } else {
         array2 = (array_t*)malloc(sizeof(array_t));
         array2->size = 492;
         array2->refC = 1;
         array2->id = 2;
         array2->data = (unsigned int*)malloc(array2->size*sizeof(unsigned int));
         memset(array2->data, 0, array2->size*sizeof(unsigned int));
         DEBUG_NEW(array2->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array2;
      array_t* array3 = func2(&params0, loopsFactor);
      DEBUG_RETURN(array3->id);
      free(params0.data);
      array3->refC--;
      if(array3->refC == 0) {
         free(array3->data);
         free(array3);
         DEBUG_FREE(array3->id);
      }
      array2->refC--;
      if(array2->refC == 0) {
         free(array2->data);
         free(array2);
         DEBUG_FREE(array2->id);
      }
   }
   array_t* array5;
   if (pCounter > 0) {
      array5 = vars->data[--pCounter];
      array5->refC++;
      DEBUG_COPY(array5->id);
   } else {
      array5 = (array_t*)malloc(sizeof(array_t));
      array5->size = 763;
      array5->refC = 1;
      array5->id = 5;
      array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
      memset(array5->data, 0, array5->size*sizeof(unsigned int));
      DEBUG_NEW(array5->id);
   }
   return array5;
}

