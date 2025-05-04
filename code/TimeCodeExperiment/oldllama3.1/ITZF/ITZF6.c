
            
            int f(int a, int b) {
                int sum = 0;
                for (int i = 1; i <= a; i++) {
                    if (i % b == 0) {
                        sum += i;
                    }
                }
                return sum;
            }

            int g(int a, int b) {
                int sum = 0;
                for (int i = 1; i <= a; i++) {
                    if (i % b!= 0) {
                        sum += i;
                    }
                }
                return sum;
            }

            int main() {
                int a = 10;
                int b = f(a, 3);
                int c = g(a, 3);
                printf("f(a, 3) = %d, g(a, 3) = %d\n", b, c);
                // Add a dead loop with a complex condition and statement inside
                for (int i = 1; i <= 1000000; i++) {
                    if (i % 2 == 0 && i % 3 == 0 && i % 5 == 0 && i % 7 == 0 && i % 11 == 0) {
                        printf("i = %d\n", i);
                        break;
                    }
                    printf("Loop iteration: %d\n", i);
                }
                return 0;
            }
            
            