/// 1:12 AM 07/07/20
/// Author: t_bone_289 (An Immature Programmer.... I'm still developing !!)
 
#include<bits/stdc++.h>
 
using namespace std;
#define endl '\n'
typedef long long ll;
 
void dfs(ll node, vector<vector<ll>> &G, vector<bool> &visited) {
    visited[node] = true;
    for (ll &vertex:G[node]) {
        if (!visited[vertex]) {
            dfs(vertex, G, visited);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > G(n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    vector<bool> visited(n);
    vector<ll> ans;
    for (ll i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, G, visited);
            ans.emplace_back(i);
        }
    }
    ll minValue = (ll) ans.size() - 1;
    cout << minValue << endl;
    for (ll i = 1; i < (ll) ans.size(); i++) {
        cout << ans[i] + 1 << ' ' << ans[i - 1] + 1 << endl;
    }
    return 0;
}
