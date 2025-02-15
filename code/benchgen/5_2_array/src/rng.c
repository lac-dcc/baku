#include "outs/5_2_array.h" 
unsigned long rng() {
   unsigned long n = rand();
   return (n << 32) | rand();
}

