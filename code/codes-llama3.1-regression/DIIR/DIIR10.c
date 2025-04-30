
          
          #include <stdio.h>
          #include <stdlib.h>

          int f(int *a) {
              if (a == NULL) {
                  return -1;
              }
              if ((*a > 5) && (*a % 2 == 0)) {
                  return *a;
              } else if ((*a < 5) && (*a % 2!= 0)) {
                  return *a;
              } else if (*a == 7) {
                  return *a;
              } else {
                  return *a;
              }
              /* Dead conditional statement */
              if (0) {
                  printf("This will never be printed\n");
              }
          }

          int main() {
              int a = 10;
              int result = f(&a);
              if (result == -1) {
                  fprintf(stderr, "Error: Invalid input\n");
                  return 1;
              }
              printf("Value of a: %d\n", result);
              return 0;
          }

          
          