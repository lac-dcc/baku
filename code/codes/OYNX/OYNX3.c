
int f(int a) {
        if (a > 0)
        {
        return a;
        }
        else
        {
        return -a;
        }
}

int main() {
        int *ptr = &f(5);
        int b = *ptr;
        printf("%d\n", b);
        return 0;
}

