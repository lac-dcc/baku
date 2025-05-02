
int f(int a, int b, int c) {
    while ((a > 0 && b < 10) || (c == 5 && a < 5)) {
        printf("Looping...\n");
        a++;
        b--;
        c++;
    }
    while (a > b && c > a) {
        printf("Nested Looping...\n");
        a++;
        b++;
    }
    return a + b + c;
}

int main() {
    printf("%d\n", f(1, 2, 3));
    return 0;
}
