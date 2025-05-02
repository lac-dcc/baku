
            
int f(int a, int b) {
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        if (i % b == 0) {
            sum += i;
        }
    }
    return sum;
}

int g(int a, int b) {
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        if (i % b!= 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int a = 10;
    int b = f(a, 3);
    int c = g(a, 3);
    printf("f(a, 3) = %d, g(a, 3) = %d\n", b, c);
    return 0;
}

            
            