#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define li long int
const int N = 1e7+10;
const int M = 1e9+7;
 
int n,m;
vector<int>g[N];
int vis[N];
int par[N];
int dist[N];
 
bool bfs(int src,int p){
    par[src] = p;
    dist[src] = 1;
    vis[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr==n){
            return true;
        }
        for(auto child : g[curr]){
            if(!vis[child]){
                q.push(child);
                dist[child] = 1 + dist[curr];
                par[child] = curr;
                vis[child] = 1;
            }
        }
    }
 
    return false;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(bfs(1, -1)){
 
        cout << dist[n] << endl;
 
        vector<int> ans;
        int temp = 1;
        ans.push_back(n);
        while (n != 1)
        {
            ans.push_back(par[n]);
            n = par[n];
        }
 
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
 
    
}
