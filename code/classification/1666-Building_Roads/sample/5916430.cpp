#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int mx = 1e5+5;
 
vector<int> adj[mx];
vector<int> vis(mx, 0);
// vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
 
void dfs(int s, int val){
    if(vis[s] > 0) return;
    vis[s] = val;
 
    for(auto neig : adj[s]){
        dfs(neig, val);
    }
}
 
int32_t main(){
    int n, m; cin >> n >> m;
 
    for(int i = 0 ; i < m ; i++){
        int a, b; cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int cnt = 0;
    vector<int> add;
 
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            ++cnt;
            dfs(i, cnt);
 
            add.push_back(i);
        }
    }
 
    cout << --cnt << "\n";
    for(int i = 0 ; i < add.size() - 1 ; i++){
        cout << add[i]+1 << " " << add[i+1]+1 << "\n";
    }
 
    return 0;
}
