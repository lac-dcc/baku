#include<stdio.h> 

int f(int a) {
        int i = 0; // Add a variable to increment
        while (a > 0 || a < 0) {
                // Add a nested loop with a complex condition and a statement inside
                for (int j = 0; a % 2 == 0 && a % 3 == 0; j++) {
                        printf("%d\n", a);
                        j++; // Add a statement that increments j
                        }
                if (a > 0) {
                        return 0;
                        }
                return 0;
                }
        return 0;
        }

            
            
    void main(){
        printf("%d",f(7));
    }
    