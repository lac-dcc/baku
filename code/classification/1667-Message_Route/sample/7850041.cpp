#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int dx[] = {0, -1, 0, 1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
char di[] = {'R', 'U', 'L', 'D'};
void Almahrouky() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
const int N = 1e5 + 1;
int n, m;
vector<int>adj[N];
vector<int>dist, par;
void bfs(){
    queue<int>q;
    q.emplace(1);
    dist[1] = 1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for(auto &v: adj[u]){
 
            if(dist[v] == 1e8){
                dist[v] = dist[u] + 1;
                q.emplace(v);
                par[v] = u;
            }
        }
    }
    
 
}
void sol(){
    
}
signed main() { Almahrouky();
    // int t; cin >> t;
    // while(t--){
    //     sol();
    //     cout<<'\n';
    // }
    cin>>n>>m;
    dist = vector<int>(n + 1, 1e8);
    par = vector<int>(n + 1, -1);
    for(int i = 0; i < m; ++i){
        int u, v; cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    bfs();
 
    if(dist[n] == 1e8)
        return cout<<"IMPOSSIBLE", 0;
 
    cout<<dist[n]<<'\n';
 
    vector<int>ans;
    ans.emplace_back(n);
    int x = n;
    while(par[x] != -1)
        ans.emplace_back(x = par[x]);
    
    reverse(ans.begin(), ans.end());
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
