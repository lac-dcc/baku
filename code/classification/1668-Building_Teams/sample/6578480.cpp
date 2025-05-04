#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5+5;
 
bool vis[lim], ok = false;
int ans[lim];
int n, m; 
 
void bfs(int nd, vector<int> adj[]){
    queue<pair<int, int>> q;
    q.push({nd, 1});
    ans[nd] = 1;
    int nextcolor;
    vis[nd] = 1;
    while(!q.empty()){
        int a = q.front().first;
        int color = q.front().second;
        q.pop();
        if(color == 1){
            nextcolor = 2;
        } else {
            nextcolor = 1;
        }
        for(auto it : adj[a]){
            if(ans[it]!=0 && ans[it] != nextcolor){
                ok = true; 
                return;
            } 
            if(!vis[it]){
                ans[it] = nextcolor;
                vis[it] = true;
                q.push({it, nextcolor});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    vector<int> adj[n+1];
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(ans[i] == 0){
            bfs(i, adj);
        }
    }
    if(!ok)for(int i=1;i<=n;i++) cout << ans[i] << " ";
    else cout<<"IMPOSSIBLE" << endl;
}
