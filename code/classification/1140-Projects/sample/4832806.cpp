#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7;
const int M = 2e5 + 1;
 
bool sort_by_sec(pair<pll, ll> a, pair<pll, ll> b){
    return a.first.second<b.first.second;
}
 
 
void solve() {
    int n; cin>>n;
    vector<pair<pll, ll>>inp;
    vector<ll>lst;
    inp.pb({{0, 0}, 0}); lst.pb(0);
    for (int i = 0; i < n; ++i)
    {
        ll a, b, p; cin>>a>>b>>p;
        inp.pb({{a, b}, p});
    }
    sort(inp.begin(), inp.end(), sort_by_sec);
    for (int i = 1; i <= n; ++i) lst.pb(inp[i].first.second);
    ll dp[n+1]; dp[0] = 0;
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout<<inp[i].first.first<<" "<<inp[i].first.second<<" "<<inp[i].second<<endl;
    // }
    for (int i = 1; i <=n; ++i)
    {
        auto it = lower_bound(lst.begin(), lst.begin()+i-1, inp[i].first.first);
        if(*it>=inp[i].first.first) it--;
        // it--;
        dp[i] = fmax(dp[i-1], dp[it-lst.begin()]+inp[i].second);
    }
    cout<<dp[n]<<endl;
 
 
}
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outfile.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--) {
        solve();
 
    }
    return 0;
}
