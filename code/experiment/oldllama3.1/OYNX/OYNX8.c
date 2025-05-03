
            int f(int a) {
                    if (a < 0) {
                            printf("Error: Input is negative.\n");
                            return 0;
                    }
                    if (a > 1000) {
                            printf("Error: Input is too large.\n");
                            return 0;
                    }
                    return a;
            }

            int main() {
                    int b = f(5);
                    if (b < 0) {
                            b = -b;
                    } else {
                            printf("Input is valid.\n");
                    }
                    printf("%d\n", b);
                    return 0;
            }
            