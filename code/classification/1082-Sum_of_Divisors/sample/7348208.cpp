/**
* Author: Purvesh Doud
*/
#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
 
const int mod = 1e9+7;
const int two_mod_inv = 500000004;
 
int total_sum(int start, int end) {
    return ((((end - start + 1) % mod) * ((start + end) % mod) % mod) * two_mod_inv % mod);
}
 
signed main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int n;
    cin >> n;
    int total = 0;
    int at = 1;    
    while (at <= n) {
        int add_amt = n/at;
        int last_same = n/add_amt;
        total = (total + add_amt * total_sum(at, last_same))%mod;
        at = last_same+1;
    }
    cout << total << '\n';
    
    return 0;
}
