

int f(int a, int b) {
    if (a > 0) {
        if (b > 0) {
            return a + b;
        } else {
            return a - b;
        }
    } else {
        if (a + b > 0) {
            if (a > b) {
                return a * b;
            } else {
                return a / b;
            }
        } else {
            for (int i = 0; i < 1000000; i++) {
                for (int j = 0; j < 1000000; j++) {
                    // Complex condition and statement inside
                    if ((i + j) % 2 == 0 && (i * j) % 3 == 0) {
                        printf("Dead loop condition met\n");
                    }
                }
            }
            return a - b;
        }
    }
    return a - b;
}

int main() {
    int x = 5;
    int y = 10;
    printf("%d\n", f(x, y));
    return 0;
}

