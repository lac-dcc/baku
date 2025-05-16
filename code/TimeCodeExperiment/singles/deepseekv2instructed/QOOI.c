 tags.
        

```c
#include <stdio.h>

int f(int a[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int result = f(a, size);
    printf("%d\n", result);
    return 0;
}
