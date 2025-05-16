
            #include <stdio.h>
            
            int f(int a) {
                return a;  // Return the sum of a
            }
            
            int main() {
                int x = 10;
                int y = 5;
                if(x > y) {
                    printf("x is greater than y");
                } else if (x < y) {
                    printf("x is less than y");
                } else {
                    printf("x is equal to y");
                }
                printf("x is not greater than y");
                int result = f(x + y);  // Call f with the sum of x and y
                printf("%d", result);
                int i = 0;
                while(i < 1000000) {
                    if(i % 2 == 0) {
                        printf("i is even: %d", i);
                    } else {
                        printf("i is odd: %d", i);
                    }
                    i++;
                }
                return 0;
            }
        