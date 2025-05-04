#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100005
#define X first
#define Y second
#define mod 1000000007
#define inf 1e18
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
ll n,i,j,k;
 
int main()
{
    fastio;
    ll m;
    cin>>n>>m;
    ll u,v;
    vector<vector<ll > > adj(n+1,vector<ll >());
    for(i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll > c(n+1,0);
    vector<bool > used(n+1,false);
    for(i=1;i<=n;i++){
        if(!used[i]){
            c[i]=1;
            used[i]=true;
            queue<ll > q;
            q.push(i);
            while(!q.empty()){
                u=q.front(); q.pop();
                for(auto to:adj[u]){
                    if(c[to]==c[u]){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                    if(!used[to]){
                        used[to]=true;
                        c[to]=3-c[u];
                        q.push(to);
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++) cout<<c[i]<<" ";
    cout<<endl;
}
