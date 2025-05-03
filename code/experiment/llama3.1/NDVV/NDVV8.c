
            int f(int a, int b) {
                int sum = 0;
                for (int i = 0; i < a; i++) {
                    if (i > 2) {
                        for (int j = 0; j < i; j++) {
                            sum = sum + i + j; // Calculate sum of i and j
                            sum = sum + b; // Add b to sum
                        }
                    } else {
                        for (int j = 0; j < i; j++) {
                            sum = sum + i + j; // Calculate sum of i and j
                            sum = sum + b; // Add b to sum
                        }
                    }
                }
                return sum + 1; // Return sum + 1
            }
            int main() {
                return f(4, 5);
            }
            