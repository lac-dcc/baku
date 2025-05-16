#include<stdio.h> 

            int f(int a) {
                int b = a + 1;
                int c = b + 1;
                int d = c + 1;
                int e = d + 1;
                int f = e + 1;
                int g = f + 1;
                int h = g + 1;
                int i = h + 1;
                int j = i + 1;
                int k = j + 1;
                int l = k + 1;
                int m = l + 1;
                return a + b + c + d + e + f + g + h + i + j + k + l + m;
            }
            
    void main(){
        printf("%d",f(7));
    }
    