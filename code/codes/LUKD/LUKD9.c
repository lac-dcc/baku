
        
        int f(int a, int b) {
                if (a>0) {
                printf("a is greater than 0\n");
                }
                else if (a==0) {
                printf("a is equal to 0\n");
                }
                else if (a<0) {
                printf("a is less than 0\n");
                }
                if (a%2==0) {
                printf("a is even\n");
                }
                else {
                printf("a is odd\n");
                }
                if (b > 10) {
                printf("b is greater than 10\n");
                }
                if (b % 2 == 0) {
                printf("b is even\n");
                }
                else {
                printf("b is odd\n");
                }
                if (a > b) {
                printf("a is greater than b\n");
                }
                else if (a == b) {
                printf("a is equal to b\n");
                }
                else {
                printf("a is less than b\n");
                }
                if (a + b > 10) {
                printf("a + b is greater than 10\n");
                }
                return 0;
                }
        int main() {
        f(1, 10);
        f(0, 20);
        f(-1, 30);
        f(2, 40);
        f(3, 50);
        return 0;
        }
        
        