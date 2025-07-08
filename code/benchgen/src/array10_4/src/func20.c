#include "array10_4.h" 
array_t* func20(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop12 = 0;
   unsigned int loopLimit12 = (rand()%loopsFactor)/5 + 1;
   for(; loop12 < loopLimit12; loop12++) {
      array_t* array51;
      if (pCounter > 0) {
         array51 = vars->data[--pCounter];
         array51->refC++;
         DEBUG_COPY(array51->id);
      } else {
         array51 = (array_t*)malloc(sizeof(array_t));
         array51->size = 618;
         array51->refC = 1;
         array51->id = 51;
         array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
         memset(array51->data, 0, array51->size*sizeof(unsigned int));
         DEBUG_NEW(array51->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array51;
      array_t* array52 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array52->id);
      free(params0.data);
      array52->refC--;
      if(array52->refC == 0) {
         free(array52->data);
         free(array52);
         DEBUG_FREE(array52->id);
      }
      array51->refC--;
      if(array51->refC == 0) {
         free(array51->data);
         free(array51);
         DEBUG_FREE(array51->id);
      }
   }
   array_t* array69;
   if (pCounter > 0) {
      array69 = vars->data[--pCounter];
      array69->refC++;
      DEBUG_COPY(array69->id);
   } else {
      array69 = (array_t*)malloc(sizeof(array_t));
      array69->size = 904;
      array69->refC = 1;
      array69->id = 69;
      array69->data = (unsigned int*)malloc(array69->size*sizeof(unsigned int));
      memset(array69->data, 0, array69->size*sizeof(unsigned int));
      DEBUG_NEW(array69->id);
   }
   return array69;
}

