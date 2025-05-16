
            
int f(int a, int b, int c, int d) {
    while ((a > 0 && b < 10) || (c == 5 && a < 5 && b > 2) || (d > 0 && a > b && c < 10)) {
        printf("Looping...\n");
        a++;
        b--;
        c++;
        d--;
    }
    if (a > b && c < a && d > 0 && c > 2) {
        c = 0;
    }
    while (a > b && c > a && d < 10 && a % 2 == 0) {
        printf("Nested Looping...\n");
        a++;
        b++;
        c--;
        d++;
    }
    return a + b + c + d;
}

int main() {
    printf("%d\n", f(1, 2, 3, 4));
    return 0;
}

            