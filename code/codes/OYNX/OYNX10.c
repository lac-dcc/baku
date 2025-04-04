
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
        return 0;
}
