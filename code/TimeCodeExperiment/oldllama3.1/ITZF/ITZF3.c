
            
int f(int a) {
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        if (i % 3 == 0) {
            sum += i;
        }
    }
    return sum;
}

int g(int a) {
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        if (i % 3!= 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int a = 10;
    int b = f(a);
    int c = g(a);
    printf("f(a) = %d, g(a) = %d\n", b, c);
    return 0;
}

            
            