
            
            int f(int a) {
                int arr[] = {1, 2, 3, 4, 5};
                int prev = arr[0];
                int max = arr[0];
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
                    if (i > 1 && i < 4 && arr[i] == 3 && arr[i-1] == 2) {
                        arr[i] = arr[i] * 2;
                        arr[i-1] = arr[i-1] + 1;
                    }
                    if (i == 3 && arr[i] == 4 && arr[i-1] == 3) {
                        arr[i] = arr[i] * 2;
                        arr[i-1] = arr[i-1] + 1;
                    }
                    if (i == 2 && i == 3) {
                        arr[i] = arr[i] * 3;
                    }
                }
                return max;
            }

            int main() {
                int result = f(0);
                printf("%d\n", result);
                return 0;
            }
            
            