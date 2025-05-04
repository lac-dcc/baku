#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
 
#define N 200000
#define M 1000000007
 
long long n;
void input() {
	scanf("%lld", &n);
}
 
int sum(long long i, long long j, long long q) {
	long long x = i+j-1;
	long long y = j-i;
 
	if (x % 2 == 0) x /= 2;
	else y /= 2;
 
	x %= M;
	y %= M;
	q %= M;
	long long s = x * y % M * q;
 
	//printf("q=%lld [%lld %lld] s=%lld\n", q, k1, k2, s);
	return s % M;
}
 
int solve() {
	int r = 0;
	for (long long i=1; i <= n; ) {
		long long q = n/i;
		long long j = n/q+1;
		r += sum(i, j, q);
		r %= M;
		i = j;
	}
	return r;
}
 
void output(int result) {
	printf("%d\n", result);
}
 
int main() {
	input();
	output(solve());
}