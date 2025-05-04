#include<bits/stdc++.h>
using namespace std;
 
#define int         int
#define double      double
#define pb          push_back
#define fr(n)       for(int i=0;i<n;i++)
#define FAST        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
const int MOD = 1e9+7;
const int INF = 1e9+100;
const int NINF = -1e9-100;
 
void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> pa(n+1);
    vector<int> pr(n+1);
 
    for(int i=1; i<=n; i++) cin >> pr[i];
    for(int i=1; i<=n; i++) cin >> pa[i];
 
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = max( ((j-pr[i] < 0) ? 0 : dp[i-1][j-pr[i]] + pa[i]), dp[i-1][j]);
        }
    }
 
    for(auto it: dp) {
        debug(it);
    }
 
    cout << dp[n][m] << "\n";
}
 
int32_t main() {
    FAST
    int t=1;
    //cin >> t;
 
    while(t--) {
        solve();
    }
    
    return 0;
}