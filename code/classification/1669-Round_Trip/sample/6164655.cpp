#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
vector<int>vis;
vector<vector<int>>adj;
vector<int>ans;
 
int node1 = -1;
int node2 = -1;
void dfs(int node, int par) {
    vis[node] = 1;
    ans[node] = par;
    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            dfs(it, node);
        }
        else{
            if( it!=par &&  node1 == -1) {
                node2 = it;
                node1 = node;
                
            }
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    vis = vector<int>(n+1, 0);
    ans = vector<int>(n+1);
    int p;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        p = a;
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, -1);
            if(node1 != -1) {
                break;
            }
        }
    }
    if(node1 == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
   
    vector<int>v;
    v.push_back(node1);
    int x = node1;
   
    while(ans[node1] != node2 ) {
        v.push_back(ans[node1]);
        node1 = ans[node1];
    } 
    v.push_back(node2);
    v.push_back(x);
    
    cout << v.size() << endl;
    for(auto it: v) {
        cout << it << " " ;
    }
    cout << endl;
 
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
