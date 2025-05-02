
        # #include <stdio.h>

        # int f(int a, int b[]) {
        # int sum = 0;
        # for (int i = 0; i < a; i++) {
        #     sum += b[i];
        #     for (int j = 0; j < a; j++) {
        #         sum++;
        #     }
        # }
        # return sum;
        # }

        # int main() {
        #     int arr[] = {1, 2, 3, 4, 5};
        #     int n = sizeof(arr)/sizeof(arr[0]);
        #     printf("%d\n", f(n, arr));
        #     return 0;
        # }
        # 