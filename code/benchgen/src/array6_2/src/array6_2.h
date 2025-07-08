#ifndef array6_2
#define array6_2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef DEBUG
    #define DEBUG_NEW(id) printf("[NEW]\t\tId %d created\n", id)
    #define DEBUG_COPY(id) printf("[COPY]\t\tId %d copied\n", id)
    #define DEBUG_RETURN(id) printf("[RETURN]\tId %d returned\n", id)
    #define DEBUG_FREE(id) printf("[FREE]\t\tId %d freed\n", id)
#else
    #define DEBUG_NEW(id)
    #define DEBUG_COPY(id)
    #define DEBUG_RETURN(id)
    #define DEBUG_FREE(id)
#endif
typedef struct {
   unsigned int* data;
   size_t size;
   size_t refC;
    int id;
} array_t;
typedef struct {
   array_t** data;
   size_t size;
} array_t_param;

unsigned long get_path();
array_t* func0(array_t_param* vars, int loopsFactor);
array_t* func5(array_t_param* vars, const unsigned long PATH0, int loopsFactor);
array_t* func6(array_t_param* vars, int loopsFactor);
array_t* func7(array_t_param* vars, int loopsFactor);
array_t* func11(array_t_param* vars, const unsigned long PATH0, int loopsFactor);
array_t* func12(array_t_param* vars, int loopsFactor);
array_t* func13(array_t_param* vars, int loopsFactor);
array_t* func17(array_t_param* vars, const unsigned long PATH0, int loopsFactor);
array_t* func18(array_t_param* vars, int loopsFactor);
array_t* func19(array_t_param* vars, int loopsFactor);
array_t* func1(array_t_param* vars, int loopsFactor);
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor);
array_t* func3(array_t_param* vars, int loopsFactor);
array_t* func4(array_t_param* vars, int loopsFactor);
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor);
array_t* func9(array_t_param* vars, int loopsFactor);
array_t* func10(array_t_param* vars, int loopsFactor);
array_t* func14(array_t_param* vars, const unsigned long PATH0, int loopsFactor);
array_t* func15(array_t_param* vars, int loopsFactor);
array_t* func16(array_t_param* vars, int loopsFactor);
#endif