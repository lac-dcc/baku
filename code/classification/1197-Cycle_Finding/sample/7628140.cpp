#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (ll)(1e18)
#define MX (int)2e5 + 5
#define ll long long int
#define MOD (ll)(1e8)
#define PRIME 13
#define N (int)(2e5+5)
#define M (int)(1e9+7)
 
void solve(int,vector<vector<int>>&,vector<ll>&);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges;
        vector<ll> cost;
        for(int i=0,a,b,c;i<m;i++){
            cin>>a>>b>>c;
            edges.push_back({a,b});
            cost.push_back(c);
        }
        solve(n,edges,cost);
    }
    return 0;
}
 
void solve(int n,vector<vector<int>> &edges,vector<ll> &cost){
    int m=(int)edges.size();
    vector<ll> dis(n+1,INF);
    dis[0]=0;
    vector<int> par(n+1,0);
    int x=-1;
    for(int i=1;i<=n;i++){
        x=-1;
        for(int j=0;j<m;j++){
            int u=edges[j][0],v=edges[j][1];
            if(dis[v]>dis[u]+cost[j]){
                dis[v]=dis[u]+cost[j];
                par[v]=u;
                x=u;
            }
        }
    }
    if(x==-1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        vector<int> path;
        for(int i=1;i<=n;i++) x=par[x];
        int cur=x;
        while(path.size()==0||cur!=x){
            path.push_back(cur);
            cur=par[cur];
        }
        path.push_back(x);
        reverse(path.begin(),path.end());
        for(auto u:path) cout<<u<<" ";
        cout<<"\n";
    }
    return;
}
