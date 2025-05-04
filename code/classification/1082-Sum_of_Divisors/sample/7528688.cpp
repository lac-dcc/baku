#include <bits/stdc++.h>
#define N 100000
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define reprev(i, l, r) for(int i = l; i >= r; i--)
 
using namespace std;
 
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef pair<ii, ii> iv;
typedef unsigned long long ull;
 
const int MOD = 1e9 + 7;
const int inf = 1e9;
const bool multi_test = false;
 
string NAME = "bt";
 
int n, ans;
 
const int minv2 = 500000004;
 
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ){
        int x = n / i;
        int next = n / x;
        ans = (ans + x % MOD * ((next - i + 1) % MOD) % MOD * ((next + i) % MOD) % MOD) % MOD;
        i = next + 1;
    }
    cout << ans * minv2 % MOD;
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen((NAME + ".inp").c_str(), "r", stdin);
        freopen((NAME + ".out").c_str(), "w", stdout);
    #endif // ONLINE_JUDGE
    int t = 1;
    if (multi_test) cin >> t;
    while (t--) solve();
}
