
int main() {
    int a = 5;
    int b = 10;
    int *ptr_a = &a;
    int *ptr_b = &b;
    int result = f(ptr_a, ptr_b);
    printf("The sum of %d and %d is %d\n", a, b, result);
    return 0;
}

int f(int *a, int *b) {
    return *a + *b;
}
