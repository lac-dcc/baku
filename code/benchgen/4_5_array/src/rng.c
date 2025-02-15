#include "outs/4_5_array.h" 
unsigned long rng() {
   unsigned long n = rand();
   return (n << 32) | rand();
}

