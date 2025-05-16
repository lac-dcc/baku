
int f(int a) {
        return 0;
        }
int main() {
        int a = 5;
        int *p1 = &a;
        int *p2 = &a;
        if (p1 == p2) {
                printf("p1 and p2 point to the same memory location\n");
        } else {
                printf("p1 and p2 do not point to the same memory location\n");
        }
        return 0;
}
