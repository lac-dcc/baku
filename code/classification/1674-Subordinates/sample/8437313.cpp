#pragma GCC optimize("03")
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ln '\n'
#define F first 
#define S second 
#define pb push_back
#define ins insert
#define all(v) v.begin(), v.end()
#define whole(a, n) a + 1, a + n + 1
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int sz = 2e5 + 5;
const int inf = 1e9 + 7;
vector<int>g[sz];
int cnt[sz];
void dfs(int u){
    cnt[u] = 1;
    for(auto &to: g[u]){
        dfs(to);
        cnt[u] += cnt[to];
    }
}
void solve(){
    int n, x;
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> x;
        g[x].pb(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << cnt[i] - 1 << ln;
}
signed main(){
    fastio
    int T = 1; 
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
