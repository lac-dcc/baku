#include<bits/stdc++.h>
#define st frist
#define nd second
#define ll long long
#define vec vector
 
using namespace std;
 
const int N = 1e5+2, mod =2e9+7;
int n, m, u, v, vis[N], a[N];
vec<int>g[N];
 
void dfs(int u, int t){
    for(auto v : g[u]){
        if(a[v] && t%2+1!=a[v]){
            cout << "IMPOSSIBLE";
            exit(0);
        }
        if(vis[v] || a[v]) continue;
        vis[v]=1;
        a[v]=t%2+1;
        dfs(v,a[v]);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        a[i]=1;
        vis[i]=1;
        dfs(i,1);
    }
    for(int i=1; i<=n; i++) cout << a[i] << " " ;
}
