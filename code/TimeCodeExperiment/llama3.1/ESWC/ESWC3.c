
int f(int a) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < i; j++) {
            if (i + j > 5) {
                return i + j;
            }
        }
    }
    return 0;
}

int main() {
    int result = f(0);
    printf("%d\n", result);
    return 0;
}
