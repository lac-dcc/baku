#include<stdio.h> 

# int f(int a, int b, int c, int d) {
#     int new_b = a;
#     new_b = new_b * b;  // Use the new argument b
#     for (int i = 0; i < 10; i++) {
#         if (new_b == new_b + 1) {
#             new_b++;
#         }
#         else {
#             new_b = new_b * 2;
#             if (new_b > 5) {
#                 new_b = new_b + 10;
#             }
#         }
#     }
#     return new_b;
# }
# 
# /* Dead code */
# if (0 > 1) {
#     new_b = new_b + 10;
# }
# 
# 
# 

    void main(){
        printf("%d",f(7));
    }
    