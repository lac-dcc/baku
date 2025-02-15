#include "outs/1_7_array.h" 
unsigned long rng() {
   unsigned long n = rand();
   return (n << 32) | rand();
}

