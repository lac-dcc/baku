
            
            int f(int a) {
                // Find the maximum value in the array, ignoring the input parameter a
                int arr[] = {1, 2, 3, 4, 5};
                int prev = 0;
                int max = 0;
                for (int i = 0; i < 5; i++) {
                    if (i == 0) {
                        prev = arr[i];
                        max = arr[i];
                    } else if (arr[i] > prev) {
                        prev = arr[i];
                        if (arr[i] > max) {
                            max = arr[i];
                        }
                    }
                    if (i == 2) {
                        if (arr[i] == 3) {
                            arr[i] = 0;
                        }
                    }
                }
                return max;
            }

            int main() {
                int result = f(0);
                printf("%d\n", result);
                return 0;
            }
            
            