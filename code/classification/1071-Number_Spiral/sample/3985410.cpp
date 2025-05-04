#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
template<typename T> bool ckmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool ckmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
const char el = '\n';
 
void solve() {
    int x, y;
    cin >> x >> y;
    if (x <= y) {
        int s = 0;
        if (y & 1) s = y * y;
        else s = (y - 1) * (y - 1) + 1;
        
        if (y & 1) cout << s - x + 1 << el;
        else cout << s + x - 1 << el;
        return;
    }
    
    int s = 0;
    if (x & 1) s = (x - 1) * (x - 1) + 1;
    else s = x * x;
    if (x & 1) cout << s + y - 1 << el;
    else cout << s - y + 1 << el;
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int testcase = 1; cin >> testcase;
    while (testcase--) {
        solve();
    }
    
    return 0;
}