
            
int f(int *a, int length) {
    if (length < 10 || length == 0) {
        printf("Error: array must have at least 10 elements and not be empty\n");
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }
    int max = a[0];
    int max_index = 0;
    for (int i = 1; i < length; i++) {
        if (a[i] > max) {
            max = a[i];
            max_index = i;
            printf("New maximum value found at index %d: %d\n", max_index, max);
        }
    }
    int min = a[0];
    int min_index = 0;
    for (int i = 1; i < length; i++) {
        if (a[i] < min) {
            min = a[i];
            min_index = i;
            printf("New minimum value found at index %d: %d\n", min_index, min);
        }
    }
    return sum + max + min;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(a) / sizeof(a[0]);
    int result = f(a, length);
    printf("Result: %d\n", result);
    return 0;
}

            