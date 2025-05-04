#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N=2e5+30;
int n, m, t, lt=0;
vector<int> x[N];
int dist[N], ans[N];
void solve(int v, int p){
    if(v!=p)
        dist[v]=dist[p]+1;
    for(auto u: x[v]){
        if(u==p)
            continue;
        solve(u, v);
    }
}
void dfs(int v, int p){
    if(v!=p)
        ans[v]=ans[p]+1;
    for(auto u: x[v]){
        if(u==p)
            continue;
        dfs(u, v);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    solve(1, 1);
    int id=0;
    for(int i=1; i<=n; i++){
        // cout << dist[i] << ' ';
        if(dist[i]>dist[id])
            id=i;
    }
    // cout << '\n';
    dfs(id, id);
    for(int i=1; i<=n; i++){
        if(ans[i]>ans[id])
            id=i;
    }
    cout << ans[id] << '\n';
    return 0;
}
