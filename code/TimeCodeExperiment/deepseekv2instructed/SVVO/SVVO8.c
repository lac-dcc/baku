

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

