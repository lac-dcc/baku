#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl "\n"
#define print(x) cout<<x<<endl
#define printt(x,y) cout<<x<<" "<<y<<"\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define sz(x) (int)x.size()
#define maxq priority_queue<int>
#define minq priority_queue<int,vector<int>,greater<int>>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod = 1e9 + 7;
const int N = 1000005;
int dp[N];
vi v;
int n;
int solve(int x) {
    if (x == 0)
        return 0;
 
    if (dp[x] != -1)
        return dp[x];
 
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        if (x >= v[i])
            ans = min(ans, 1 + solve(x - v[i]));
 
    return dp[x] = ans;
}
 
void solve() {
 
    int x;
    cin >> n >> x;
 
    v.clear();
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> v[i];
 
    int d = solve(x);
    if (d == INT_MAX)
        d = -1;
    print(d);
 
}
 
int32_t main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}