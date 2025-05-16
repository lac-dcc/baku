
            
            int f(int a[], int n) {
                if (n == 0) {
                    return 0;
                } else if (n == 1) {
                    return a[0];
                } else if (n == 6 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6 && n % 2 == 0 && a[0] > a[1] && a[2] < a[3]) {
                    return 0; // Dead conditional statement with more conditions
                }
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += a[i];
                }
                return sum;
            }

            int main() {
                int arr[] = {1, 2, 3, 4, 5, 6};
                int n = sizeof(arr) / sizeof(arr[0]);
                int result = f(arr, n);
                printf("Sum: %d\n", result);
                return 0;
            }
            
            