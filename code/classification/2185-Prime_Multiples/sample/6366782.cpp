#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("fma")
#include <stdio.h>
#include <stdlib.h>
 
#define N 20
 
static inline long getint() {
    long x, y;
    while((x = getchar_unlocked()) < '0') {}
    x -= '0';
    while((y = getchar_unlocked()) >= '0') { x = x * 10 + y - '0'; }
    return x;
}
 
int main() {
	static long p[N], pf[N + 1];
	long r = 0;
 
	long n = getint(), k = getint();
 
	for(int i = 0; i < k; i++) {
		p[i] = getint();
		pf[i] = n;
	}
	pf[k] = n;
 
	for(int j = (1 << k) + 1; j < (2 << k); j++) {
		int d = __builtin_ctz(j);
		int j0 = j & (j - 1);
		long a = pf[__builtin_ctz(j0)];
		long b = -p[d];
 
		if(a / b) {
			pf[d] = a / b;
			r -= pf[d];
		} else {
			j += (j ^ j0) - 1; // Skip over products that will be greater than n
		}
	}
 
	printf("%ld\n", r);
}