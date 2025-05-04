#include <iostream>
#include <cmath>
#include <vector>
 
using namespace std;
 
long long MOD = 1000000007;
 
vector<long long> factorial(2000002);
 
long long square(long long b) {
    return b*b;
}
 
long long powow(long long b, long long e) {
    if(e == 0) {
        return 1;
    }
    if(e == 1) {
        return b;
    }
    return (square(powow(b, e/2)%MOD)%MOD)*((e%2)*(b-1)+1);
}
 
long long n, k;
long long counter = 0;
vector<long long> primes;
 
void solve(long long divisor, long long depth, int pcounter) {
    if(depth == k) {
        counter += ((pcounter%2)*2-1) * (long long)(n / (divisor));
        return;
    }
    if(log10(divisor)+log10(primes[depth]) > 18) {
        solve(divisor, depth + 1, pcounter);
    } else {
        solve(divisor, depth + 1, pcounter);
        solve(divisor*primes[depth], depth + 1, pcounter + 1);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    factorial[0] = 1;
    for(int i = 1; i < 2000002; i ++) {
        factorial[i] = ((factorial[i - 1]) * i) % MOD; 
    }
 
    cin >> n >> k;
    
    primes = vector<long long>(k);
 
    for(int i = 0; i < k; i ++) {
        cin >> primes[i];
    }
    for(int i = 0; i < k; i ++) {
        solve(primes[i], i + 1, 1);
    }
    cout << counter << endl;
}