#include <cstdio>
using namespace std;
 
const int MOD = 1000000007;
int main() {
    long long n, a = 0;
    scanf("%lld", &n);
    for (long long i=1, j; i<=n; i=j) {
        long long q = n/i; j = n/q+1; 
        long long x = j-i, y = i+j-1;
        if (x%2 == 0) x /= 2;
        else y /= 2;
        x %= MOD, y %= MOD;
        a = (a+q%MOD*x%MOD*y%MOD)%MOD;
    }
    printf("%lld\n", a);
}