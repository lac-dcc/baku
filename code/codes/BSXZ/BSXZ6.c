
#include <stdio.h>
int main() {
    int i = 0;
    int j = 0;
    while (i < 5) {
        i++;
        while (j < 5 && i + j < 10) {
            j++;
            printf("%d + %d = %d\n", i, j, i + j);
            if (j > 3) {
                printf("j is greater than 3\n");
            }
        }
    }
    return 0;
}
