
int f(int a) {
    int* p = &a;
    if (a >= 0) {
        if (a == 5) {
            return 10;
        } else if (a > 5) {
            return a * 2;
        } else {
            return a + 1;
        }
    } else {
        return a - 1;
    }
}

int main() {
    int i = 0;
    while (i < 10) {
        if (i % 2 == 0 && i > 5) {
            int* p = &i;
            printf("Hello World!\n");
            printf("Value of i: %d\n", *p);
            printf("Address of i: %p\n", (void*)p);
        }
        i++;
    }
    return 0;
}
