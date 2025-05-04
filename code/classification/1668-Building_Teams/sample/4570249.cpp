#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int n, m;
vector<int> adj[int(1e5)+1];
bool vis[int(1e5)+1];
int team[int(1e5)+1];
bool np = false;
 
void dfs(int x, int flag){
    if(vis[x]){
        if(team[x] != flag)
            np = true;
        return;
    }
    vis[x] = true;
    // cout << x << flag << " ";
    team[x] = flag;
    if(flag == 1) flag = 2;
    else flag = 1;
    for(int &v : adj[x]){
        dfs(v, flag);
    }
}
 
int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int source, dest;
        cin >> source >> dest;
        adj[source].push_back(dest);
        adj[dest].push_back(source);
    }
 
    int flag = 1;
    for(int i=1; i<=n; i++){
        // cout << vis[i] << " ";
        if(!vis[i]){
            dfs(i, flag);
        }
    }
 
    if(np){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    for(int i=1; i<=n; i++){
        cout << team[i] << " ";
    }
    cout << "\n";
}
