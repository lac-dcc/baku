
#define MAX_ALLOWED 1000

int f(int a) {
        if (a < 0) {
                printf("Error: Input is negative.\n");
                return 0;
        }
        if (a > MAX_ALLOWED) {
                printf("Error: Input is too large.\n");
                return 0;
        }
        return a;
}

int main() {
        if (5 > MAX_ALLOWED) {
                printf("Input is too large.\n");
        } else {
                int b = f(5);
                int c = 10;
                while (c > 0) {
                        if (b > 100) {
                                printf("Input is too large.\n");
                                break;
                        } else {
                                printf("%d\n", b);
                                c--;
                        }
                }
                if (0 > 0) {
                        printf("This statement will never be executed.\n");
                }
                if (1 == 2) {
                        printf("This statement will never be executed.\n");
                }
        }
        return 0;
}

int main() {
    int i = 0;
    while (i < 10 && i > 5 || i == 7) {
        printf("i is: %d\n", i);
        if (i == 7) {
            printf("i is equal to 7\n");
        }
        i++;
    }
    return 0;
}
