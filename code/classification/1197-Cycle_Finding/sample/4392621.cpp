#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
struct tri{
    int u, v, w;
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<tri> adj;
    for(int i = 0; i < m; ++i){
        tri a; 
        cin >> a.u >> a.v >> a.w;
        adj.push_back(a);
    }
    ll dis[n+1];
    //int par[n+1] = {-1}; 
    vector<int> par(n + 1, -1); 
    int x;
    fill(dis, dis+(n+1), 1e18);
    dis[1] = 0;
    for(int i = 0; i < n; ++i){
        x = -1;
        for(auto u:adj){
            int a, b, w;
            a = u.u, b = u.v, w = u.w;
            if(dis[b] > dis[a] + w){
                dis[b] = dis[a] + w;
                par[b] = a;
                x = b;
            }
        }
    }
    if(x == -1){
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i) x = par[x];
    vector<int> ans;
    for(int v = x; ; v = par[v]){
        ans.push_back(v);
        if(v == x and ans.size() > 1)break;
    }
    reverse(ans.begin(), ans.end());
    for(auto i:ans)cout << i << ' ';
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; ++i)
        solve();
    
    return 0;
}
