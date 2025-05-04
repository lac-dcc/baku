#include <bits/stdc++.h>
#define NFS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define int int64_t
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int,int>
#define pb emplace_back
#define endl "\n"
#define all(v) v.begin(),v.end()
#define REP(i,a,n) for(int i=a;i<n;i++)
#define deb(x) cout<<"["#x<<":"<<x<<"]"<<"  "<<endl;
#define deb2(x,y) cout<<"["#x<<":"<<x<<" "#y<<":"<<y<<"]"<<endl;
#define out(a) for(auto x:a)cout<<x<<" ";cout<<endl;
#define outyes cout<<"Yes"<<endl;
#define outno cout<<"No"<<endl;
#define mod 1000000007
using namespace std; 
 
vi adj[200005];
vi vis(200005);
vi par(200005);
int c;
int cycle_end;
int cycle_start;
 
bool dfs(int v, int pr) {
    vis[v] = true;
    par[v] = pr;
    for (int u : adj[v]) {
        if(!vis[u]){
           if (dfs(u,v))
            return true; 
        }
        else if(u != pr){
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    return false;
}
 
void SOLVE__MAIN() 
{
    int n,m;
    cin>>n>>m;
    par.resize(n+1,-1);
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cycle_start = -1;
    for (int v=1;v<=n; v++) {
        if (!vis[v] && dfs(v, par[v]))
            break;
    }
    if(cycle_start==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
        vi cycle;
        cycle.pb(cycle_start);
        while(cycle_end!=cycle_start){
            cycle.push_back(cycle_end);
            cycle_end=par[cycle_end];
        }
        cycle.pb(cycle_start);
        cout<<cycle.size()<<endl;
        out(cycle);
}
 
 
int32_t main()
{
    NFS;
    cout<<fixed;
    cout.precision(5);
    int __TESTCASES=1;
    //cin>>__TESTCASES;
    while(__TESTCASES--){ 
        SOLVE__MAIN();
}
}
