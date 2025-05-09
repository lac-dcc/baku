

int f(int a) {
    int sum = 0;
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
        for (int j = 0; j < i; j++) {
            if (j % 3 == 0) {
                sum += j;
            }
        }
    }
    return sum;
}

int main() {
    int result = f(30);
    printf("Result: %d\n", result);
    return 0;
}

