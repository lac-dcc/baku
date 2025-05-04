/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;
 
int t, n, m;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b; 
        g[a].pb({b, c});
        
 
    }
    const ll inf = 1e18;
    vl dis(n, inf);
    dis[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;
    pq.push({0ll, 0ll});
    vector<bool> vis(n, 0);
    while(!pq.empty()) {
        int a = pq.top().se; pq.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        for(auto x:g[a]) {
            ll b = x.fi, w = x.se;
            if(dis[b] > dis[a] + w) {
                dis[b] = dis[a] + w;
                pq.push({-dis[b], b});
            }
        }
    }
    rep(i, n) {
        cout << dis[i] << ' ';
    }
 
 
 
}
