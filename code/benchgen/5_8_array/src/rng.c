#include "outs/5_8_array.h" 
unsigned long rng() {
   unsigned long n = rand();
   return (n << 32) | rand();
}

