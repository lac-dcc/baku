
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 6 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6 && n % 2 == 0 && a[0] > a[1] && a[2] < a[3]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[j]);
            }
            printf("\n");
        }
    } else {
        printf("Condition is not met\n");
    }
    free(a);
    return 0;
}
            