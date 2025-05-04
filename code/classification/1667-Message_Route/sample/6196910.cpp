#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2*1e5+5, INF = 1e9+9;
long long n, m;
vector<long long> adj[maxn];
void inp(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
queue<long long> q;
bool visited[maxn];
int previous[maxn];
bool ok = false;
void bfs(){
    while(!q.empty()){
        int u = q.front();
        for(auto v : adj[u]){
            if(visited[v]){continue;}
            q.push(v);
            visited[v] = true;
            previous[v] = u;
            if(v == n){
                ok = true;
                return;
            }
        }
        q.pop();
    }
}
vector<int> ans;
void solve(){
    for(int i = 1; i <= n; i++){visited[i] = false;}
    q.push(1);
    visited[1] = true;
    previous[1] = 0;
    bfs();
    int v = n, u = n;
    while(u != 0){
        ans.push_back(u);
        u = previous[u];
    }
    if(!ok){
        cout << "IMPOSSIBLE";
        return;
    }
    cout << ans.size() << "\n";
    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	solve();
}
