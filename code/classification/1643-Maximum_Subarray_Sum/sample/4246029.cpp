#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define nl "\n"
#define pb push_back
#define f first
#define s second
#define ii int, int
#define all(x) x.begin(), x.end()
#define pv(x) for(int k : x){cout << k << " ";} cout << nl;
#define pp(x) cout << x.f << " " << x.s << nl;
typedef vector<tuple<int, int, int>> vt;
typedef vector<vector<int>> vvi;    
typedef vector<pair<ii>> vp;
const int INF = 1e17; 
const int mod = 1e9 + 7;
const int SIZE = 2505;
 
void solve(){
    int n;
    cin >> n;
    int a[n];
    int dp[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        dp[i] = -INF;
    dp[0] = a[0];
    int ans = a[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i-1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << nl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}