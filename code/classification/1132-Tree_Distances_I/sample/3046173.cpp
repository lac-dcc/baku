#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));
 
const int mxN = 2e5+5;
int n,dist[2][mxN];
vector<int>adj[mxN];
int dfs(int u, int a, int d, int p){
    int ret = -1;
    dist[a][u] = d;
    for(int &v: adj[u]){
        if(v == p) continue;
        int res = dfs(v,a,d+1,u);
        if(ret==-1||dist[a][ret]<dist[a][res])
            ret = res;
    }
    return ret == -1 ? u : ret; 
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a = dfs(1,0,0,-1);
    int b = dfs(a,0,0,-1);
    dfs(b,1,0,-1);
    for(int i = 1; i <= n; i++){
        cout << max(dist[0][i],dist[1][i]) << ' ';
    }
}
