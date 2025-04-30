
            
int f(int a) {
    if (a < 2 || a % 2!= 0) {
        return 0;
    }
    int b = 0;
    while (a > 1 && a % 2 == 0 && b < 10) {
        if (a % 2 == 0) {
            b++;
            a = a / 2;
        } else {
            break;
        }
    }
    return b;
}

int main() {
    int num;
    if (scanf("%d", &num)!= 1) {
        printf("Error: Input is not an integer.\n");
        return 1;
    }
    if (num < 0) {
        printf("Error: Input is a negative number.\n");
        return 1;
    }
    int result = f(num);
    printf("The number %d is divisible by 2 %d times.\n", num, result);
    return 0;
}

            