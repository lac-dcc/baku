#include<stdio.h> 

            
            int f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
                    if (a > b && a > c && a > d && a > e && a > f && a > g && a > h && a > i && a > j && a > k && a > l && a > m && a > n && a > o && a > p) {
                            return a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p;
                    }
                    return 0;
            }
            
            
    void main(){
        printf("%d",f(7));
    }
    