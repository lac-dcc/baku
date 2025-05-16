
            #include <stdio.h>
            int main() {
                int count = 0;
                while (count < 10) {
                    if (count == 5 && count == 3) {
                        printf("This will never be printed\n");
                    }
                    printf("5 is greater than 3\n");
                    count++;
                }
                return 0;
            }
        