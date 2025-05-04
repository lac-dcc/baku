/*void __dbg() { cout << endl; }
template<typename Arg, typename... Args> void __dbg(Arg A, Args... B) { cout << " " << A; __dbg(B...); }
#define dbg(...)  cout << "(" << #__VA_ARGS__ << "):", __dbg(__VA_ARGS__)*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define mod (ll)1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(int i=a;i<(int)b;i+=1)
#define rrep(i,a,b) for(int i=a;i>=(int)b;i-=1)
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
 
vector < int > adj[200005];
vector < int > subt(200005);
 
void sub(int u, int p)
{
    subt[u]=1;
    
    for(int v:adj[u])
    {
        if(v==p) continue;
        
        sub(v,u);
        subt[u]+=subt[v];
    }
}
 
void solve()
{
    int n; cin>>n;
    
    vector < int > par(n+1);
    par[1]=-1;
    
    rep(i,2,n+1) cin>>par[i];
    
    //every edge is a parent child relationship 
    
    rep(i,2,n+1)
    {
        adj[i].pb(par[i]),adj[par[i]].pb(i);
    }
    
    sub(1,-1);
    
    rep(i,1,n+1) cout<<subt[i]-1<<" ";
    cout<<"\n";
}
 
int main()
{
    fio;
    int tc=1;//cin>>tc;
    
    while(tc--)
    {
        solve();
    }
    return 0;
}
 
