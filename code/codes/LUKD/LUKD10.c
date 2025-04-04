
            
        
        int f(int a, int b, int c, int d) {
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
                if (c > 10) {
                printf("c is greater than 10\n");
                }
                if (c % 2 == 0) {
                printf("c is even\n");
                }
                else {
                printf("c is odd\n");
                }
                if (d > 10) {
                printf("d is greater than 10\n");
                }
                if (d % 2 == 0) {
                printf("d is even\n");
                }
                else {
                printf("d is odd\n");
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
                if (b > c) {
                printf("b is greater than c\n");
                }
                else if (b == c) {
                printf("b is equal to c\n");
                }
                else {
                printf("b is less than c\n");
                }
                if (a > d) {
                printf("a is greater than d\n");
                }
                else if (a == d) {
                printf("a is equal to d\n");
                }
                else {
                printf("a is less than d\n");
                }
                if (c > d) {
                printf("c is greater than d\n");
                }
                else if (c == d) {
                printf("c is equal to d\n");
                }
                else {
                printf("c is less than d\n");
                }
                if (b + c > 10) {
                printf("b + c is greater than 10\n");
                }
                if (a + d > 10) {
                printf("a + d is greater than 10\n");
                }
                return 0;
                }
        int main() {
        f(1, 10, 20, 30);
        f(0, 20, 30, 40);
        f(-1, 30, 40, 50);
        f(2, 40, 50, 60);
        f(3, 50, 60, 70);
        return 0;
        }
        
        
            