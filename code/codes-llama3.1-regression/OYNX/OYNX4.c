
            
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
        int b = f(5);
        if (b < 0) {
                b = -b;
        }
        printf("%d\n", b);
        return 0;
}


            