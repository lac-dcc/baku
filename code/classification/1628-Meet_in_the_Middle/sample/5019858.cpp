#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
constexpr int N = int(1e2) + 5;
constexpr int MOD = int(1e9) + 7;
 
unordered_map<int, int> mp;
 
int main() {
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    int n, x;
    cin >> n >> x;
 
    int a[n];
    for(auto& i : a) cin >> i;
    sort(a, a + n);
 
    mp.reserve(1 << 24);
    for(int i = 0; i < 1 << (n >> 1); i++){
        int b = 0;
        for(int j = 0; j < (n >> 1); j++){
            if((i >> j) & 1){
                b += a[j];
                if(b > x) break;
            }
        }
        if(b <= x) mp[b]++;
    }
    ll ans = 0;
    for(int i = 0; i < 1 << n - (n >> 1); i++){
        int b = 0;
        for(int j = 0; j < n - (n >> 1); j++){
            if((i >> j) & 1){
                b += a[j + (n >> 1)];
                if(b > x) break;
            }
        }
        if(b <= x) ans += mp[x - b];
    }
    cout << ans;
}   
