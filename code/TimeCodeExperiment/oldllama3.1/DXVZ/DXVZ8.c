#include<stdio.h> 

int f(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p) {
    int max = a;
    for (int x = 1; x < 16; x++) {
        if (a > max) {
            max = a;
        }
        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = h;
        h = i;
        i = j;
        j = k;
        k = l;
        l = m;
        m = n;
        n = o;
        o = p;
    }
    if (x == 10 && a == 10) {
        return max + a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + 1;
    }
    return max + a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p;
}

    void main(){
        printf("%d",f(7));
    }
    