
            
int f(int a) {
    if (a > 0) {
        return a + 1;
    } else {
        if (a < 0) {
            return a - 1;
        } else {
            return 0;
        }
    }
}

void printNumbers() {
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            printf("Even number: %d\n", i);
        } else {
            printf("Odd number: %d\n", i);
        }
        if (i % 2 == 0 && i > 2) {
            printf("Number %d is both even and greater than 2\n", i);
        }
        if (i % 2 == 0 && i > 3) {
            printf("Number %d is both even and greater than 3\n", i);
        }
    }
}

int main() {
    printNumbers();
    return f(5);
}
            
            