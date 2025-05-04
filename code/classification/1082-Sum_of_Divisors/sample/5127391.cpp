#include <bits/stdc++.h>
using namespace std;
 
void solve();
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1; // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
 
void solve() {    
    long long n; cin >> n;
    long long count = 0;
    long long mid = (long long) sqrt(n) + 1011;
    long long x;
    long long i;
    
    // first few numbers
    for(i=1; i<=mid; i++){
        x = n/i;
        count += x*i;
        count %= 1000000007;
    }
 
    for(x = n/i;x>=1; x--) {
        long long j = n/x;
        long long temp;
        if ((i+j)%2 == 1) {
            temp = (j - i + 1) / 2;
            temp %= 1000000007;
            temp *= (x % 1000000007);
            temp %= 1000000007;
            temp *= ((i + j) % 1000000007);
            temp %= 1000000007;
            count += temp;
        } else {
            temp = (i + j) / 2;
            temp %= 1000000007;
            temp *= (x % 1000000007);
            temp %= 1000000007;
            temp *= ((j - i + 1) % 1000000007);
            temp %= 1000000007;
            count += temp;
        }
        
        // count += x * (i + j) * (j-i+1) / 2;
        count %= 1000000007;
        if (count < 0) {
            cout << i << ' ' << j << endl;
            cout << count << endl;
        }
        i = j + 1;
    }
 
    count %= 1000000007;
    cout << count << endl;
}
 
 
// n = 100
// 100, 50, 33, 25, 20, 16, 14, ..., 2, 1, ... ,