
            int f(int a) {
                int sum = 0;
                for (int i = 0; i < a; i++) {
                    if (i > 2) {
                        for (int j = 0; j < i; j++) {
                            if (j == 0) {
                                sum = sum + i + j; // Calculate sum of i and j
                            } else {
                                sum = sum + i + j; // Calculate sum of i and j
                                sum = sum + 1; // Add 1 to sum
                            }
                        }
                    } else {
                        for (int j = 0; j < i; j++) {
                            sum = sum + i + j; // Calculate sum of i and j
                            sum = sum + 1; // Add 1 to sum
                        }
                    }
                }
                return sum + 1; // Return sum + 1
            }
            int main() {
                return f(4);
            }
            