
            #include <stdio.h>
            
            int f(int a) {
                return a;  // Return the sum of a
            }
            
            int main() {
                int x = 10;
                int y = 5;
                int result = f(x + y);  // Call f with the sum of x and y
                printf("%d", result);
                return 0;
            }
        