
            
int f(int *a, int *b) {
    int c = *a + *b;
    return c;
}
int main() {
    int x = 5;
    int y = 10;
    int *p = &x;
    int *q = &y;
    printf("%d\n", f(p, q));
    int c; // declare c here
    while ((x > 0) && (y < 20) && (c < 15)) {
        c = x + y;
    }
    printf("%d\n", c);
}

            