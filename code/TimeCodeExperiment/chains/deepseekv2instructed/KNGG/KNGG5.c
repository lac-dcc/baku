
        
        int f(int a) {
            int sum = 0;
            for (int i = 0; i < a; i++) {
                if (i % 2 == 0) {
                    sum += i;
                }
            }
            return sum;
        }

        int main() {
            int result = f(30);
            printf("Result: %d\n", result);
            return 0;
        }
        
        