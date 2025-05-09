
int f(int a[], int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return a[0];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = f(arr, n);
    printf("Sum: %d\n", result);
    return 0;
}
