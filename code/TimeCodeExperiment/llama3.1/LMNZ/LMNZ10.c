
#include <stdio.h>

int main() {
    int i, j, k;
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            for (k = 1; k <= 10; k++) {
                if ((i!= j && j!= k && i!= k && i + j == k) && (i > j && i > k)) {
                    printf("%d + %d = %d\n", i, j, k);
                    printf("i is greater than j and k\n");
                }
            }
        }
    }
    return 0;
}
